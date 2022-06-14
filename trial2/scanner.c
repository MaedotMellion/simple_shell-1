#include "shell.h"
#include "scanner.h"
#include "source.h"

/**
 * add_to_buf - adds a single character to the token buffer
 * @c: takes in a character
 * Return: returns nothing
 */

void add_to_buf(char c)
{
	char *tmp;

	tok_buf[tok_bufindex++] = c;

	if (tok_bufindex >= tok_bufsize)
	{
		tmp = realloc(tok_buf, tok_bufsize * 2);

		if (!tmp)
		{
			errno = ENOMEM;
			return;
		}

		tok_buf = tmp;
		tok_bufsize *= 2;
	}
}

/**
 * create_token - takes a string and converts it to a struct token_s structure
 * @str: takes in a string
 * Return: returns a struct token_s structure
 */

struct token_s *create_token(char *str)
{
	struct token_s *tok = malloc(sizeof(struct token_s));
	char *nstr;

	if (!tok)
	{
		return (NULL);
	}

	memset(tok, 0, sizeof(struct token_s));
	tok->text_len = strlen(str);
	nstr = malloc(tok->text_len + 1);
	if (!nstr)
	{
		free(tok);
		return (NULL);
	}
	_strcpy(nstr, str);
	tok->text = nstr;
	return (tok);
}

/**
 * free_token - frees the memory used by a token structure, as well as the
 *              memory used to store the token's text.
 * @tok: takes in a token
 * Return: returns nothing
 */

void free_token(struct token_s *tok)
{
	if (tok->text)
	{
		free(tok->text);
	}
	free(tok);
}

/**
 * tokenize - it does the lexical scanning
 * @src: takes in a string
 * Return: returns a struct token_s structure
 */


struct token_s *tokenize(struct source_s *src)
{
	int  endloop = 0;
	cha nc;
	struct token_s *tok;

	if (!src || !src->buffer || !src->bufsize)
	{
		errno = ENODATA;
		return (&eof_token);
	}
	if (!tok_buf)
	{
		tok_bufsize = 1024;
		tok_buf = malloc(tok_bufsize);
		if (!tok_buf)
		{
			errno = ENOMEM;
			return (&eof_token);
		}
	}
	tok_bufindex     = 0;
	tok_buf[0]       = '\0';
	nc = next_char(src);
	if (nc == ERRCHAR || nc == EOF)
		return (&eof_token);
	do {
		switch (nc)
		{
		case ' ':
		case '\t':
			if (tok_bufindex > 0)
				endloop = 1;
			break;
		case '\n':
			if (tok_bufindex > 0)
				unget_char(src);
			else
				add_to_buf(nc);
			endloop = 1;
			break;
		default:
			add_to_buf(nc);
			break;
		}
		if (endloop)
			break;
	} while ((nc = next_char(src)) != EOF);
	if (tok_bufindex == 0)
		return (&eof_token);
	if (tok_bufindex >= tok_bufsize)
		tok_bufindex--;
	tok_buf[tok_bufindex] = '\0';
	tok = create_token(tok_buf);
	if (!tok)
	{
		_printf("error: failed to alloc buffer:\n");
		return (&eof_token);
	}
	tok->src = src;
	return (tok);
}

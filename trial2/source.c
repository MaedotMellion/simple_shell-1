#include "shell.h"
#include "source.h"

/**
 * unget_char - function returns (or ungets) the last character we've retrieved
 *              from input, back to the input source.
 * @src: a structure source string
 * Return: returns nothing
 */

void unget_char(struct source_s *src)
{
	if (src->curpos < 0)
	{
		return;
	}

	src->curpos--;
}

/**
 * next_char - function returns the next character of input and updates the
 *             source pointer, so that the next call to
 *             next_char() returns the following input character.
 * @src: a structure source string
 * Return: returns the next character of input
 */

char next_char(struct source_s *src)
{
	char c1 = 0;

	if (!src || !src->buffer)
	{
		errno = ENODATA;
		return (-1 * ERRCHAR);
	}

	if (src->curpos == INIT_SRC_POS)
	{
		src->curpos  = -1;
	}
	else
	{
		c1 = src->buffer[src->curpos];
	}

	if (++src->curpos >= src->bufsize)
	{
		src->curpos = src->bufsize;
		return (EOF);
	}

	return (src->buffer[src->curpos]);
}

/**
 * peek_char - function returns the next character of input
 * @src: a structure source string
 * Return: returns the next character of input
 */

char peek_char(struct source_s *src)
{
	long pos;

	if (!src || !src->buffer)
	{
		errno = ENODATA;
		return (-1 * ERRCHAR);
	}

	if (pos == INIT_SRC_POS)
	{
		pos++;
	}
	pos++;

	if (pos >= src->bufsize)
	{
		return (EOF);
	}

	return (src->buffer[pos]);
}

/**
 * skip_white_spaces - function skips all whitespace characters.
 * @src: a structure source string
 * Return: returns nothing
 */

void skip_white_spaces(struct source_s *src)
{
	char c;

	if (!src || !src->buffer)
	{
		return;
	}

	while (((c = peek_char(src)) != EOF) && (c == ' ' || c == '\t'))
	{
		next_char(src);
	}
}

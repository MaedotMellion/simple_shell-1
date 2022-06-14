#ifndef SCANNER_H
#define SCANNER_H

/**
 * struct token_s - structure for an input text
 * @src: source of input
 * @text_len:  length of token text
 * @text: token text
 * Description: structure called "struct token_s" that helps for the tokenizing
 *              process
 */

char *tok_buf = NULL;
int   tok_bufsize  = 0;
int   tok_bufindex = -1;

struct token_s
{
	struct source_s *src;
	int    text_len;
	char   *text;
};

/* the special EOF token, which indicates the end of input */
extern struct token_s eof_token;

struct token_s *tokenize(struct source_s *src);
void free_token(struct token_s *tok);

#endif /* SCANNER_H */

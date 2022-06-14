#ifndef SOURCE_H
#define SOURCE_H

#define ERRCHAR (0)
#define EOF (-1)
#define INIT_SRC_POS (-2)

/**
 * struct source_s - structure for an input text
 * @buffer: the input text
 * @bufsize: size of the input text
 * @curpos: absolute char position in source
 * Description: structure called "source_s" that stores the buffer, buffer size
 * and the current position in a string.
 */

struct source_s
{
	char *buffer;
	long bufsize;
	long curpos;
};

char next_char(struct source_s *src);
void unget_char(struct source_s *src);
char peek_char(struct source_s *src);
void skip_white_spaces(struct source_s *src);

#endif /* SOURCE_H */

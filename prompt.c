#include <stdio.h>
#include "shell.h"

/**
 * prompt - prompts user to enter commnad
 *
 * Return: list of command and arguments
 */

char **prompt(ssize_t *noc, int *is_pipe)
{
        char *buf, *parsed1, *parsed2, **spch;
        size_t s = 0;
        int b, cnt, pipe_cnt;
	printf(":> ");

	spch = NULL;
	*noc = getline(&buf, &s, stdin);
	cnt = wrd_cnt(buf, ' ');
	pipe_cnt = wrd_cnt(buf, '|');
        if (*noc > 0)
        {
                if (pipe_cnt > 1)
                {
                        spch = split(buf, '|');	
			b =_strlen(spch[pipe_cnt - 1]);
			spch[pipe_cnt - 1][b - 1] = '\0';
			parsed1 = parse(spch[0]);
			parsed2 = parse(spch[1]);
			printf("%s\n%s\n", parsed1, parsed2);
			*is_pipe = 1;
                }
                else
                {
			parsed1 = parse(buf);
                        spch = split(parsed1, ' ');
			/*b =_strlen(spch[cnt - 1]);
			spch[cnt - 1][b - 1] = '\0';*/
			*is_pipe = 0;
                }
	}
	return (spch);
}

#include "shell.h"

int main(void)
{
	char **spch, **spch2, **spch3, ex[] = "exit";
	ssize_t *noc;
	int *is_pipe;
	
	noc = malloc(sizeof(ssize_t *));
	is_pipe = malloc(sizeof(int *));
	while (1)
	{
		spch = prompt(noc, is_pipe);
		if (!*is_pipe)
		{
			if (_strcmp(spch[0], ex) == 0)
			{
				exit(0);
			}
		}
		if (*is_pipe)
		{
			spch2 = split(spch[0], ' ');
			spch3 = split(spch[1], ' ');
			exec_com_pipe(spch2, spch3, noc);
				
		}
		else
		{
			exec_com(spch, noc);
		}
	}
	free(noc);
	free(is_pipe);
	return (0);
}

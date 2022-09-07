#include "shell.h"



/**
 * exec_com - executes commnad
 * @com: command arguments
 * @noc: no of chars read
 */
void exec_com(char **com, ssize_t *noc)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		printf("Fork error!");
	}
	else if (pid == 0)
	{
		if (execve(com[0], com, NULL) < 0 && *noc <= 0)
		{
			printf("Execution error!");
		}
		exit(0);
	}
	else
	{
		wait(NULL);
		return;
	}
}
/**
 * pipe_exe2 - pipe in
 * @pid2: pid
 * @fd: file desctiptor
 * @com2: commnad str
 * @noc: no of char
 */
void pipe_exe2(pid_t pid2, int *fd, char **com2, ssize_t *noc)
{
	close(fd[1]);
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	if (execve(com2[0], com2, NULL) < 0 && *noc <= 0)
	{
		printf("Execution error!");
	}
	exit(0);
}
/**
 * pipe_exe1 - pipe out
 * @pid: pid
 * @fd: file desctiptor
 * @com: commnad str
 * @noc: no of chars
 */

void pipe_exe1(pid_t pid, int *fd, char **com, ssize_t *noc)
{
	close(fd[0]);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	if (execve(com[0], com, NULL) < 0 && *noc <= 0)
	{
		printf("Execution error!");
	}
	exit(0);
}
/**
 * exec_com_pipe - executes commnad with pipe
 * @com: command arguments
 * @com2: command arguments
 * @noc: number of chars read
 */
void exec_com_pipe(char **com, char **com2, ssize_t *noc)
{
	pid_t pid, pid2;
	int pfd[2];

	if (pipe(pfd) < 0)
	{
		printf("Pipe not initialized!");
		return;
	}
	pid = fork();
	if (pid == -1)
	{
		printf("Fork error!");
		return;
	}
	else if (pid == 0)
	{
		pipe_exe1(pid, pfd, com, noc);
	}
	else
	{
		pid2 = fork();
		if (pid2 == -1)
		{
			printf("Fork error!");
			return;
		}
		if (pid2 == 0)
		{
			pipe_exe2(pid2, pfd, com2, noc);
		}
		else
		{
			wait(NULL);
			wait(NULL);
		}
	}
}

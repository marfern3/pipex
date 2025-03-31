#include "pipex.h"

void	child1(int *fd, int infile, char *cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(infile, STDIN_FILENO);
		dup2(fd[1], STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec_cmd(cmd, envp);
	}
}

void	child2(int *fd, int outfile, char *cmd, char **envp)
{
	pid_t	pid;

	pid = fork();
	if (pid == 0)
	{
		dup2(fd[0], STDIN_FILENO);
		dup2(outfile, STDOUT_FILENO);
		close(fd[0]);
		close(fd[1]);
		exec_cmd(cmd, envp);
	}
}

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <sys/wait.h>
# include <string.h>
# include "libft/libft.h"


void	child1(int *fd, int infile, char *cmd, char **envp);
void	child2(int *fd, int outfile, char *cmd, char **envp);
void	exec_cmd(char *cmd, char **envp);
char	**get_paths(char **envp);
char	*get_cmd_path(char *cmd, char **envp);
int		msg_error(char *msg);
void	free_split(char **split);

#endif

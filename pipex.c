#include "pipex.h"
#include "libft/libft.h"


void	exec_cmd(char *cmd, char **envp)
{
	char	**args;
	char	*path;

	args = ft_split(cmd, ' ');
	if (!args || !args[0])
	{
		write(2, "Error: comando vacío\n", 22);
		free_split(args);
		exit(1);
	}
	path = get_cmd_path(args[0], envp);
	if (!path)
	{
		write(2, "Comando no encontrado\n", 22);
		free_split(args);
		exit(127);
	}
	execve(path, args, envp);
	perror("execve");
	free_split(args);
	free(path);
	exit(1);
}

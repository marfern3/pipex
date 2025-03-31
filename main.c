#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	int	fd[2];
	int	infile;
	int	outfile;

	if (argc != 5)
		return (msg_error("Uso: ./pipex infile cmd1 cmd2 outfile"));
	infile = open(argv[1], O_RDONLY);
	if (infile < 0)
		return (msg_error("Error al abrir infile"));
	outfile = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
		return (msg_error("Error al abrir outfile"));
	if (pipe(fd) == -1)
		return (msg_error("Error al crear pipe"));
	child1(fd, infile, argv[2], envp);
	child2(fd, outfile, argv[3], envp);
	close(fd[0]);
	close(fd[1]);
	wait(NULL);
	wait(NULL);
	return (0);
}

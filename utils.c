#include "pipex.h"

int	msg_error(char *msg)
{
	perror(msg);
	return (1);
}

void	free_split(char **split)
{
	int	i = 0;

	if (!split)
		return;
	while (split[i])
		free(split[i++]);
	free(split);
}

#include "pipex.h"

char	**get_paths(char **envp)
{
	while (*envp && ft_strncmp(*envp, "PATH=", 5) != 0)
		envp++;
	if (*envp)
		return (ft_split(*envp + 5, ':'));
	return (NULL);
}

char	*get_cmd_path(char *cmd, char **envp)
{
	char	**paths;
	char	*full_path;
	size_t	len;
	int		i;

	if (access(cmd, X_OK) == 0)
		return (ft_strdup(cmd));
	paths = get_paths(envp);
	if (!paths)
		return (NULL);
	i = -1;
	while (paths[++i])
	{
		len = ft_strlen(paths[i]) + ft_strlen(cmd) + 2;
		full_path = malloc(len);
		if (!full_path)
			return (free_split(paths), NULL);
		ft_strlcpy(full_path, paths[i], len);
		ft_strlcat(full_path, "/", len);
		ft_strlcat(full_path, cmd, len);
		if (access(full_path, X_OK) == 0)
			return (free_split(paths), full_path);
		free(full_path);
	}
	return (free_split(paths), NULL);
}

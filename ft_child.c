/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_child.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 14:07:52 by pleblond          #+#    #+#             */
/*   Updated: 2024/11/27 14:07:52 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	free_cmd(char **cmd)
{
	int	i;

	i = 0;
	while (cmd[i] != NULL)
	{
		free(cmd[i]);
		i++;
	}
	free(cmd);
}

static void	ft_execute_command(char **cmd, char **envp)
{
	char	*cmd_path;

	cmd_path = ft_path(cmd[0], envp);
	if (!cmd_path)
	{
		free_cmd(cmd);
		error_handler("Command not found.\n");
	}
	if (execve(cmd_path, cmd, envp) == -1)
	{
		free(cmd_path);
		free_cmd(cmd);
		error_handler("Command execution failed.\n");
	}
}

void	child(int *filefd, char **argv, char **envp)
{
	int	infile_fd;
	char	**cmd1;

	infile_fd = open(argv[1], O_RDONLY);
	if (infile_fd == -1)
		error_handler("Error opening input file.\n");
	if (dup2(infile_fd, STDIN_FILENO) == -1)
		error_handler("dup2 infile_fd failed.\n");
	if (dup2(filefd[1], STDOUT_FILENO) == -1)
		error_handler("dup2 filefd[1] failed.\n");
	close(filefd[0]);
	close(filefd[1]);
	close(infile_fd);
	cmd1 = ft_split(argv[2], ' ');
	if (cmd1 == NULL)
		error_handler("Split failed.\n");
	ft_execute_command(cmd1, envp);
}
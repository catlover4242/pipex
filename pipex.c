/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:00:56 by pleblond          #+#    #+#             */
/*   Updated: 2024/11/26 14:00:56 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

int main(int argc, char **argv, char **envp)
{
	int		filefd[2];
	pid_t	pid;

	if (argc != 5)
		error_handler("Usage: ./pipex infile cmd1 cmd2 outfile\n");
	if (pipe(filefd) == -1)
		error_handler("Pipe Error\n");
	pid = fork();
	if (pid == -1)
		error_handler("Fork Error\n");
	if (pid == 0)
		child_1(filefd, argv, envp);
	
	waitpid(pid, NULL, 0);
	parent(filefd, argv, envp);
	return (0);
}
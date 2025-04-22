/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:07:15 by pleblond          #+#    #+#             */
/*   Updated: 2025/01/30 00:07:15 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_pipex *pipex;

	if (argc != 5)
		(ft_putstr_fd("Usage: <infile> <cmd1> <cmd2> <outfile>\n", 2), exit(1));
	pipex = init_struct(argv, envp);
	if (pipe(pipex->pipe_fd) == -1)
		(close(pipex->infiles), close(pipex->outfiles), free(pipex));
}
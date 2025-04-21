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

#include "pipex.h"

int	main(int argc, char **argv, char **envp)
{
	t_args *arg;
	bool	here_doc;
	int		exit_status;

	if (argc < 5)
		return (ft_putstr_fd("Too few arguments.\n", STDOUT_FILENO), 1);
	here_doc = (ft_strncmp(argv[1], "here_doc", 9) == 0);
	if (here_doc && argc < 6)
		return (ft_putstr_fd("Too few arguments\n", STDOUT_FILENO), 1);
	arg = malloc(sizeof(t_args));
	arg->c = argc;
	arg->v = argv;
	arg->here_doc = here_doc;
	exit_status = pipex(arg);
	free(arg);
	if (here_doc)
		unlink("/tmp/here_doc_pipex");
	return (exit_status);
}
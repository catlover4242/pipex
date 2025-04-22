/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:45:10 by pleblond          #+#    #+#             */
/*   Updated: 2025/01/30 00:45:10 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include "libft.h"
# include <sys/wait.h> 
# include <errno.h>
# include <fcntl.h>
# include <string.h>

typedef struct s_pipex
{
	int		infiles;
	int		outfiles;
	int		pipe_fd[2];
	char	**cmd;
	char	**env;
	char	*path;
}	t_pipex;

// Utils
void	free_split(char **tab);
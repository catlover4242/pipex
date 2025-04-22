/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/30 00:43:14 by pleblond          #+#    #+#             */
/*   Updated: 2025/01/30 00:43:14 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	free_split(char **tab)
{
	int		i;

	if (!tab)
		return ;
	i = 0;
	while(tab[i])
		free(tab[i++]);
	free(tab);
}

void	free_all(t_pipex *pipex)
{
	if (pipex->cmd[0] != pipex->path)
		free(pipex->path);
	if (pipex->cmd)
		free_split(pipex->cmd);
}

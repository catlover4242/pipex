/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_path.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/11 21:01:36 by pleblond          #+#    #+#             */
/*   Updated: 2024/12/11 21:04:03 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*join_path(const char *dir, const char *cmd)
{
	char	*full_path;
	int		len_dir;
	int		len_cmd;

	len_dir = ft_strlen(dir);
	len_cmd = ft_strlen(cmd);
	full_path = malloc(len_cmd + len_dir + 2);
	if (!full_path)
		return (NULL);
	ft_strlcpy(full_path, dir, len_dir + 1);
	full_path[len_dir = '/'];
	ft_strlcpy(full_path + len_dir + 1, cmd, len_cmd + 1);
	return (full_path);
}
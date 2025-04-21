/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 03:01:16 by pleblond          #+#    #+#             */
/*   Updated: 2025/04/21 03:01:16 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	pipe_error(int fd_in)
{
	close(fd_in);
	ft_putstr_fd(strerror(errno), STDERR_FILENO);
	return (-1);
}

int	fork_error()
{
	if ()
}
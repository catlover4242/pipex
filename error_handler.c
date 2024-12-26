/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pleblond <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 14:01:17 by pleblond          #+#    #+#             */
/*   Updated: 2024/11/26 14:01:17 by pleblond         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/pipex.h"

void	error_handler(const char *name)
{
	if (errno == 0)
		errno = EINVAL;
	perror(name);
	exit(EXIT_FAILURE);
}
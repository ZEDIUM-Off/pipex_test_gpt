/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By:  mchenava < mchenava@student.42lyon.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 10:36:05 by  mchenava         #+#    #+#             */
/*   Updated: 2023/05/09 16:21:00 by  mchenava        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	newfd(int oldfd, int newfd, t_pipex **pipex)
{
	(void)pipex;
	if (oldfd != newfd)
	{
		if (dup2(oldfd, newfd) == -1)
			exit(3);
		close_fd(oldfd, pipex);
	}
}

void	exit_with_error(int err, t_pipex **pipex)
{
	ft_printf(2, "pipex: %s\n", strerror(err));
	free_pipex(pipex);
	exit(EXIT_FAILURE);
}

void	close_fd(int fd, t_pipex **pipex)
{
	if (close(fd) == -1)
		exit_with_error(errno, pipex);
}

void	piping(t_pipex **pipex)
{
	if (pipe((*pipex)->processes->pipefd) == -1)
		exit_with_error(errno, pipex);
}

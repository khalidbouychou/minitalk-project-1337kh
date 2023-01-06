/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:19:24 by khbouych          #+#    #+#             */
/*   Updated: 2023/01/06 15:34:48 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_respond(int sig)
{
	if (sig == SIGUSR1)
		write(1, "\tMessage recieved!\n", 20);
}

void	ft_char_to_bit(char c, int pid)
{
	int	i;

	i = 7;
	while (i >= 0)
	{
		if (c >> i & 1)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(500);
		i--;
	}
}

void	ft_transfer_data(char *str, int pid)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_char_to_bit(str[i], pid);
		i++;
	}
	ft_char_to_bit('\0', pid);
}

void	ft_handel_error(void)
{
	write(2, "\tError!\n", 8);
	exit(1);
}

int	main(int argc, char *argv[])
{
	int	pid;

	signal(SIGUSR1, ft_respond);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (!pid || !argv[2])
			ft_handel_error();
		ft_transfer_data(argv[2], pid);
	}
	else
		ft_handel_error();
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:19:24 by khbouych          #+#    #+#             */
/*   Updated: 2023/01/03 18:25:54 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_error(void)
{
	write(2, " \tError!❌\n", 14);
	exit(1);
}

void	ft_respond(int sig)
{
	if (sig == SIGUSR1)
		write(1, "\t Message recieved!-📧\n", 26);
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
		usleep(600);
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

int	main(int argc, char *argv[])
{
	int	pid;

	signal(SIGUSR1, ft_respond);
	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if (!pid || !argv[2])
			ft_error();
		ft_transfer_data(argv[2], pid);
	}
	else
	{
		write(2, "\t Error!❌\n", 13);
		exit(1);
	}
}

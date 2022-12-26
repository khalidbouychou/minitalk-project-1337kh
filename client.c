/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:02:33 by khbouych          #+#    #+#             */
/*   Updated: 2022/12/26 14:39:22 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int		g_data;

void	ft_char_to_binary(char c, int pid)
{
	int	bits;

	bits = 8;
	while (bits--)
	{
		if (c & 128) 
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		c <<= 1;
		pause();
		usleep(100);
	}
}

void	ft_respond(int user_signal)
{
	static int	count_signal;

	if (++count_signal == (g_data) * 8 && user_signal == SIGUSR1)
	{
		ft_printf("\t[ %d ]  Signals sent successfully \n", count_signal);
		ft_printf(" \t[%d ] Characters sent successfully \n", g_data);
	}
}

int	main(int ac, char **av)
{
	int	index;
	int	server_pid;

	if (ac != 3)
		return (1);
	index = 0;
	g_data = ft_strlen(av[2]);
	server_pid = ft_atoi(av[1]);
	signal(SIGUSR1, ft_respond);
	while (av[2][index])
		ft_char_to_binary(av[2][index++], server_pid);
	ft_char_to_binary('\n', server_pid);
	return (0);
}

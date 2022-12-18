/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:02:33 by khbouych          #+#    #+#             */
/*   Updated: 2022/12/18 15:12:47 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	len_data;

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
		usleep(10);
	}
}

void	ft_respond(int user_signal)
{
	static int	count;

	if (++count == (len_data) * 8 && user_signal == SIGUSR1)
	{
		ft_printf("%d  { Signals sent successfully }      \n", count);
		ft_printf("%d  { Characters sent successfully }\n", len_data);
	}
}

int	main(int ac, char **av)
{
	int	index;
	int	server_pid;

	if (ac != 3)
		return (1);
	index = 0;
	len_data = strlen(av[2]);
	server_pid = atoi(av[1]);
	signal(SIGUSR1, ft_respond);
	while (av[2][index])
		ft_char_to_binary(av[2][index++], server_pid);
	ft_char_to_binary('\n', server_pid);
	return (0);
}
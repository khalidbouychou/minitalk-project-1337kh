/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:02:43 by khbouych          #+#    #+#             */
/*   Updated: 2022/12/18 18:04:59 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_reset(char *a, int *b)
{
	*a = 0;
	*b = 0;
}

void	ft_signal_handler(int signal_received, siginfo_t *info_signal ,void *context)
{
	static char	c;
	static int	bits;
	static int	current_pid;
	int			new_pid;

	(void)context;
	if (!current_pid)
		current_pid = info_signal->si_pid;
	new_pid = info_signal->si_pid;
	if (new_pid != current_pid)
	{
		current_pid = new_pid;
		ft_reset(&c, &bits);
	}
	c = c | (signal_received == SIGUSR1);
	bits++;
	if (bits == 8)
	{
		ft_printf("%c", c);
		ft_reset(&c, &bits);
	}
	c <<= 1;
	usleep(100);
	kill(current_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction action;
 
	action.sa_sigaction = ft_signal_handler;
	action.sa_flags = SA_SIGINFO;
	sigemptyset(&action.sa_mask);
	ft_printf(" *** This My PID  ==>[ %d ] *** \n", getpid());
	while (1)
	{
		sigaction(SIGUSR1, &action, NULL);
		sigaction(SIGUSR2, &action, NULL);
		pause();
	}
	return (0);
}
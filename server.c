/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:02:43 by khbouych          #+#    #+#             */
/*   Updated: 2023/01/03 18:11:06 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

t_data	g_data;

void	signal_handler(int sig, siginfo_t *info, void *p)
{
	(void)p;
	if (g_data.s_pid != info->si_pid)
	{
		g_data.bits = 0;
		g_data.c = 0;
	}
	sig -= 30;
	g_data.bits = g_data.bits << 1 | sig;
	g_data.c++;
	if (g_data.c == 8)
	{
		if (g_data.bits == 0)
			kill(info->si_pid, SIGUSR1);
		write(1, &g_data.bits, 1);
		g_data.bits = 0;
		g_data.c = 0;
	}
	g_data.s_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sgn;

	g_data.bits = 0;
	g_data.c = 0;
	write(1, "💳 The PID is: ", 18);
	ft_putnbr(getpid());
	write(1, "\n", 1);
	sgn.sa_sigaction = &signal_handler;
	sgn.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sgn, NULL);
	sigaction(SIGUSR2, &sgn, NULL);
	while (pause())
		;
}

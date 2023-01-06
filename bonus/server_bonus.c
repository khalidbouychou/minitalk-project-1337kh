/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:02:43 by khbouych          #+#    #+#             */
/*   Updated: 2023/01/06 15:27:38 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk_bonus.h"

t_data_bonus	g_data_bonus;

void	signal_handler(int sig, siginfo_t *info, void *p)
{
	(void)p;
	if (g_data_bonus.s_pid != info->si_pid)
	{
		g_data_bonus.bits = 0;
		g_data_bonus.c = 0;
	}
	sig -= 30;
	g_data_bonus.bits = g_data_bonus.bits << 1 | sig;
	g_data_bonus.c++;
	if (g_data_bonus.c == 8)
	{
		if (g_data_bonus.bits == 0)
			kill(info->si_pid, SIGUSR1);
		write(1, &g_data_bonus.bits, 1);
		g_data_bonus.bits = 0;
		g_data_bonus.c = 0;
	}
	g_data_bonus.s_pid = info->si_pid;
}

int	main(void)
{
	struct sigaction	sgn_bonus;

	g_data_bonus.bits = 0;
	g_data_bonus.c = 0;
	write(1, "PID \t: ", 7);
	ft_putnbr_bonus(getpid());
	write(1, "\n", 1);
	sgn_bonus.sa_sigaction = &signal_handler;
	sgn_bonus.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sgn_bonus, NULL);
	sigaction(SIGUSR2, &sgn_bonus, NULL);
	while (1)
		pause();
}

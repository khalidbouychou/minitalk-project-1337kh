/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 15:07:51 by khbouych          #+#    #+#             */
/*   Updated: 2023/01/06 09:28:16 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_BONUS_H
# define MINITALK_BONUS_H

# include <signal.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

typedef struct data
{
	int		bits;
	int		s_pid;
	char	c;
}			t_data_bonus;
void		ft_putnbr_bonus(int n);
int			ft_atoi_bonus(const char *str);

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khbouych <khbouych@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 12:32:23 by khbouych          #+#    #+#             */
/*   Updated: 2023/01/06 13:27:43 by khbouych         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minitalk_bonus.h"

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnbr_bonus(int n)
{
	if (n == -2147483648)
		write(1, "-2147483648", 12);
	else if (n < 0)
	{
		write(1, "-", 1);
		ft_putnbr_bonus(-n);
	}
	else if (n >= 10)
	{
		ft_putnbr_bonus(n / 10);
		ft_putchar(n % 10 + 48);
	}
	else
		ft_putchar(n + 48);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:14:51 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/11/11 18:40:43 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_putc(t_pf *st, char c)
{
	ssize_t	i;

	i = write(1, &c, 1);
	if (i == -1)
	{
		st->written = (size_t) - 1;
		return ;
	}
	st->written++;
}

void	pf_puts(t_pf *st, char *s)
{
	while (*s)
	{
		pf_putc(st, *s);
		s++;
	}
}

void	pf_putu(t_pf *st, unsigned long long nb)
{
	char	c;

	if (nb / 10 > 0)
		pf_putu(st, nb / 10);
	c = (nb % 10) + '0';
	pf_putc(st, c);
}

void	pf_put_hex(t_pf *st, unsigned long long u, char *list)
{
	if (u / 16 > 0)
		pf_put_hex(st, u / 16, list);
	pf_putc(st, list[u % 16]);
}

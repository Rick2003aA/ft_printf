/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_any2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 18:09:18 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/10/29 10:26:44 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_print_c(t_pf *st)
{
	char	c;

	c = va_arg(st->ap, int);
	pf_putc(st, c);
}

void	pf_print_s(t_pf *st)
{
	char	*s;

	s = va_arg(st->ap, char *);
	if (s == NULL)
		s = "(null)";
	while (*s)
		pf_putc(st, *s++);
}

void	pf_print_di(t_pf *st)
{
	long long			n;
	unsigned long long	nb;

	n = va_arg(st->ap, int);
	if (n < 0)
	{
		pf_putc(st, '-');
		nb = (unsigned long long)-n;
	}
	else
		nb = (unsigned long long)n;
	pf_putu(st, nb);
}

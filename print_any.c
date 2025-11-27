/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_any.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:16:50 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/10/29 12:43:17 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_print_u(t_pf *st)
{
	unsigned long long				n;

	n = va_arg(st->ap, unsigned int);
	pf_putu(st, n);
}

void	pf_print_x(t_pf *st)
{
	char					*list;
	unsigned long long		u;

	u = va_arg(st->ap, unsigned int);
	if (u == 0)
	{
		pf_putc(st, '0');
		return ;
	}
	if (st->spec == 'X')
		list = "0123456789ABCDEF";
	else
		list = "0123456789abcdef";
	pf_put_hex(st, u, list);
}

static void	pf_print_p2(t_pf *st, uintptr_t ptr)
{
	const char	*list;

	list = "0123456789abcdef";
	if (ptr / 16 > 0)
		pf_print_p2(st, ptr / 16);
	pf_putc(st, list[ptr % 16]);
}

void	pf_print_p(t_pf *st)
{
	uintptr_t	ptr;
	void		*p;

	p = va_arg(st->ap, void *);
	ptr = (uintptr_t)p;
	if (ptr == 0)
	{
		pf_puts(st, "(nil)");
		return ;
	}
	pf_putc(st, '0');
	pf_putc(st, 'x');
	if (ptr == 0)
	{
		pf_putc(st, '0');
		return ;
	}
	pf_print_p2(st, ptr);
}

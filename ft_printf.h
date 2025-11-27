/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 09:24:27 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/10/29 12:45:57 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_pf
{
	const char	*fmt;
	int			i;
	size_t		written;
	va_list		ap;
	char		spec;
}	t_pf;
int		ft_printf(const char *fmt, ...);
void	pf_putc(t_pf *st, char c);
void	pf_puts(t_pf *st, char *s);
void	pf_putu(t_pf *st, unsigned long long nb);
void	pf_put_hex(t_pf *st, unsigned long long u, char *list);
void	pf_parse(t_pf *st);
void	pf_dispatch(t_pf *st);
void	pf_print_c(t_pf *st);
void	pf_print_s(t_pf *st);
void	pf_print_di(t_pf *st);
void	pf_print_u(t_pf *st);
void	pf_print_x(t_pf *st);
void	pf_print_p(t_pf *st);
#endif

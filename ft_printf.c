/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rtsubuku <rtsubuku@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 13:04:55 by rtsubuku          #+#    #+#             */
/*   Updated: 2025/11/13 10:30:17 by rtsubuku         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_parse(t_pf *st)
{
	const char	*fmt;
	char		next;

	fmt = st->fmt;
	next = fmt[st->i + 1];
	if (!next)
	{
		st->written = -1;
		st->i += 1;
		st->spec = 0;
		return ;
	}
	if (next == 'c' || next == 's' || next == 'd' || next == 'i'
		|| next == 'u' || next == 'x' || next == 'X'
		|| next == 'p' || next == '%')
	{
		st->spec = fmt[st-> i + 1];
		st->i += 2;
		return ;
	}
	pf_putc(st, '%');
	st->spec = next;
	st->i += 2;
}

void	pf_dispatch(t_pf *st)
{
	if (st->spec == 0)
		return ;
	else if (st->spec == 'c')
		pf_print_c(st);
	else if (st->spec == 'd' || st->spec == 'i')
		pf_print_di(st);
	else if (st->spec == 's')
		pf_print_s(st);
	else if (st->spec == 'u')
		pf_print_u(st);
	else if (st->spec == 'x' || st->spec == 'X')
		pf_print_x(st);
	else if (st->spec == 'p')
		pf_print_p(st);
	else if (st->spec == '%')
		pf_putc(st, '%');
	else if (st->spec)
		pf_putc(st, st->spec);
}

int	ft_printf(const char *fmt, ...)
{
	t_pf		st;

	va_start(st.ap, fmt);
	if (!fmt)
		return (-1);
	st.fmt = fmt;
	st.i = 0;
	st.written = 0;
	st.spec = 0;
	while (st.fmt[st.i])
	{
		if (st.fmt[st.i] != '%')
			pf_putc(&st, st.fmt[st.i++]);
		else
		{
			pf_parse(&st);
			pf_dispatch(&st);
		}
	}
	if ((int)st.written == -1)
		va_end(st.ap);
	va_end(st.ap);
	return (st.written);
}

// int	main(void)
// {
// 	int ret1, ret2;
// 	int x = 42;
// 	void *p = &x;

// 	printf("===== %% TESTS =====\n");
// 	ret1 = ft_printf("%%");
// 	printf("\n");
// 	ret2 = printf("%%");
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	ret1 = ft_printf("%%%");
// 	printf("\n");
// 	ret2 = printf("%%%");
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	ret1 = ft_printf("%");
// 	printf("\n");
// 	ret2 = printf("%");
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	ret1 = ft_printf("%v");
// 	printf("\n");
// 	ret2 = printf("%v");
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	ret1 = ft_printf("%\n");
// 	printf("\n");
// 	ret2 = printf("%\n");
// 	printf("ret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	printf("===== CHARACTER =====\n");
// 	ret1 = ft_printf("%c", 'A');
// 	printf("\n");
// 	ret2 = printf("%c", 'A');
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	ret1 = ft_printf("%c", '\0');
// 	printf("\n");
// 	ret2 = printf("%c", '\0');
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	printf("===== STRING =====\n");
// 	ret1 = ft_printf("%s", "hello");
// 	printf("\n");
// 	ret2 = printf("%s", "hello");
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	ret1 = ft_printf("%s", "");
// 	printf("\n");
// 	ret2 = printf("%s", "");
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	ret1 = ft_printf("%s", (char *)NULL);
// 	printf("\n");
// 	ret2 = printf("%s", (char *)NULL);
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	printf("===== POINTER =====\n");
// 	ret1 = ft_printf("%p", (void *)0);
// 	printf("\n");
// 	ret2 = printf("%p", (void *)0);
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	ret1 = ft_printf("%p", p);
// 	printf("\n");
// 	ret2 = printf("%p", p);
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	printf("===== INTEGER =====\n");
// 	ret1 = ft_printf("%d", 42);
// 	printf("\n");
// 	ret2 = printf("%d", 42);
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	ret1 = ft_printf("%d", -42);
// 	printf("\n");
// 	ret2 = printf("%d", -42);
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	ret1 = ft_printf("%d", INT_MIN);
// 	printf("\n");
// 	ret2 = printf("%d", INT_MIN);
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	ret1 = ft_printf("%d", INT_MAX);
// 	printf("\n");
// 	ret2 = printf("%d", INT_MAX);
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	printf("===== UNSIGNED =====\n");
// 	ret1 = ft_printf("%u", 0u);
// 	printf("\n");
// 	ret2 = printf("%u", 0u);
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	ret1 = ft_printf("%u", 4294967295u);
// 	printf("\n");
// 	ret2 = printf("%u", 4294967295u);
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	printf("===== HEX =====\n");
// 	ret1 = ft_printf("%x", 255);
// 	printf("\n");
// 	ret2 = printf("%x", 255);
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	ret1 = ft_printf("%X", 255);
// 	printf("\n");
// 	ret2 = printf("%X", 255);
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	ret1 = ft_printf("%x", -1);
// 	printf("\n");
// 	ret2 = printf("%x", -1);
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	ret1 = ft_printf("%x", INT_MIN);
// 	printf("\n");
// 	ret2 = printf("%x", INT_MIN);
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	printf("===== MIXED =====\n");
// 	ret1 = ft_printf("%c%s%d%u%x%p%%", 'A', "abc", -42, 123u, 255, p);
// 	printf("\n");
// 	ret2 = printf("%c%s%d%u%x%p%%", 'A', "abc", -42, 123u, 255, p);
// 	printf("\nret_ft: %d | ret_lib: %d\n\n", ret1, ret2);

// 	return (0);
// }

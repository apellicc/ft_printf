#include "ft_printf.h"

static void	ft_is_x4(t_en *e, long long int *nb, char *tmp)
{
	e->d > 0 && e->z == 0 ? e->r += write(1, "0x", 2) : 0;
	e->d > 0 && e->pr < e->print ? e->print += 2 : 0;
	if (e->pr > e->print)
	{
		while (e->pr > e->print)
		{
			e->r += write(1, "0", 1);
			e->pr--;
		}
	}
	e->w > e->pr && e->w > e->print && e->pr > 0 ? e->print++ : 0;
	*nb == 0 && e->w > 0 && e->z == 0 ? e->r += ft_putchar(' ') : 0;
	e->pr >= 0 || *nb != 0 ? e->r += ft_putstr_minimizer(tmp) : 0;
	while (e->w > e->print)
	{
		e->z > 0 ? write(1, "0", 1) : 0;
		e->z == 0 ? write(1, " ", 1) : 0;
		--e->w;
		e->r = e->r + 1;
	}
}

static void	ft_is_x3(t_en *e, long long int *nb, int *test)
{
	if (e->d != 0 && (e->w <= e->print || e->w <= e->pr || e->z != 0)
	&& *nb != 0)
	{
		e->r += write(1, "0x", 2);
		e->pr < e->print ? e->print += 2 : 0;
	}
	else if (e->d != 0 && (e->w > e->print || e->w > e->pr) && *nb != 0)
	{
		*test = 2;
		e->w -= 2;
	}
	while ((e->w > e->pr) && (e->w > e->print))
	{
		if (e->z > 0)
			write(1, "0", 1);
		else
			write(1, " ", 1);
		--e->w;
		e->r = e->r + 1;
	}
	if (*test == 2)
	{
		e->r += write(1, "0x", 2);
		e->pr < e->print ? e->print += 2 : 0;
	}
}

static void	ft_is_x2(t_en *e, long long int *nb, char **tmp)
{
	e->c == 0 ? *nb = va_arg(e->a, long long int) : 0;
	e->c == 'H' ? *nb = (unsigned char)va_arg(e->a, int) : 0;
	e->c == 'h' ? *nb = (unsigned short int)va_arg(e->a, int) : 0;
	e->c == 'l' ? *nb = (ULL)va_arg(e->a, ULL) : 0;
	e->c == 'L' ? *nb = (ULL)va_arg(e->a, ULL) : 0;
	e->c == 'j' ? *nb = (uintmax_t)va_arg(e->a, uintmax_t) : 0;
	e->c == 'z' ? *nb = (size_t)va_arg(e->a, size_t) : 0;
	if (e->c == 'L' || e->c == 'l' || e->c == 'z' || e->c == 'j')
		*tmp = ft_uitoa_base(*nb, 16);
	else
		*tmp = ft_itoa_base(*nb, 16);
	e->print = ft_strlen(*tmp);
}

void	ft_is_x(int *i, t_en *e)
{
	long long int		nb;
	char				*tmp;
	int					test;

	tmp = NULL;
	test = 0;
	ft_is_x2(e, &nb, &tmp);
	if (e->m == 0)
	{
		if (e->w != 0 || e->d != 0 || e->pr > e->print)
		{
			e->s != 0 && e->z != 0 ? e->print += 1 : 0;
			e->z != 0 && e->w > (e->print - e->pr) && e->pr > 0 ? e->z = 0 : 0;
			ft_is_x3(e, &nb, &test);
		}
		e->pr++;
		while (--e->pr > e->print)
			e->r += write(1, "0", 1);
		e->pr >= 0 || nb != 0 ? e->r += ft_putstr_minimizer(tmp) : 0;
		nb == 0 && e->w > 0 && e->z == 0 ? e->r += ft_putchar(' ') : 0;
	}
	else
		ft_is_x4(e, &nb, tmp);
	free(tmp);
	*i += 1;
}

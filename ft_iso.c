#include "ft_printf.h"

static void	ft_is_o4(t_en *e, char *tmp, ULL *nb)
{
	e->d > 0 && e->z == 0 ? e->r += write(1, "0", 1) : 0;
	e->d > 0 && e->z == 0 ? e->print += 1 : 0;
	if (e->pr > e->print)
	{
		while (e->pr > e->print)
		{
			e->r += write(1, "0", 1);
			e->pr--;
		}
	}
	e->w > e->pr && e->w > e->print && e->pr > 0 ? e->print++ : 0;
	e->pr >= 0 || *nb != 0 ? e->r += ft_putstr(tmp) : 0;
	*nb == 0 && e->w > 0 && e->z == 0 ? e->r += ft_putchar(' ') : 0;
	while (e->w > e->print || e->z > 0)
	{
		e->z > 0 ? write(1, "0", 1) : 0;
		e->z == 0 ? write(1, " ", 1) : 0;
		--e->w;
		e->r = e->r + 1;
	}
}

static void	ft_is_o3(int *test, t_en *e, ULL *nb)
{
	if (e->d != 0 && (e->w > e->print || e->w > e->pr) && *nb != 0)
	{
		*test = 2;
		e->w -= 1;
	}
	else if (e->d != 0 && (e->w <= e->print || e->w <= e->pr || e->z != 0)
	&& *nb != 0)
	{
		e->r += write(1, "0", 1);
		e->print += 1;
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
		e->r += write(1, "0", 1);
		e->print += 1;
	}
}

static void	ft_is_o2(t_en *e, char *tmp, ULL *nb)
{
	int	test;

	test = 0;
	if (e->w != 0 || e->d != 0 || e->pr > e->print)
	{
		e->s != 0 && e->z != 0 ? e->print += 1 : 0;
		e->z != 0 && e->w > (e->print - e->pr) && e->pr > 0 ? e->z = 0 : 0;
		ft_is_o3(&test, e, nb);
	}
	while (e->pr > e->print)
	{
		e->r += write(1, "0", 1);
		e->pr--;
	}
	e->pr >= 0 || *nb != 0 ? e->r += ft_putstr(tmp) : 0;
	*nb == 0 && e->w > 0 && e->z == 0 ? e->r += ft_putchar(' ') : 0;
}

void	ft_is_o(int *i, t_en *e)
{
	ULL						nb;
	char					*tmp;

	e->c == 0 ? nb = va_arg(e->a, unsigned int) : 0;
	e->c == 'H' ? nb = (unsigned char)va_arg(e->a, unsigned int) : 0;
	e->c == 'h' ? nb = (unsigned short int)va_arg(e->a, unsigned int) : 0;
	e->c == 'l' ? nb = (unsigned long int)va_arg(e->a, ULL) : 0;
	e->c == 'L' ? nb = (ULL)va_arg(e->a, ULL) : 0;
	e->c == 'j' ? nb = (uintmax_t)va_arg(e->a, uintmax_t) : 0;
	e->c == 'z' ? nb = (size_t)va_arg(e->a, size_t) : 0;
	tmp = ft_uitoa_base(nb, 8);
	e->print = ft_strlen(tmp);
	if (e->m == 0)
		ft_is_o2(e, tmp, &nb);
	else
		ft_is_o4(e, tmp, &nb);
	free(tmp);
	*i = *i + 1;
}

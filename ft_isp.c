#include "ft_printf.h"

static void	ft_is_p3(t_en *e, char *tmp)
{
	e->r += write(1, "0x", 2);
	e->pr < e->print ? e->print += 2 : 0;
	if (e->pr > e->print)
	{
		while (e->pr > e->print)
		{
			e->r += write(1, "0", 1);
			e->pr--;
		}
	}
	e->w > e->pr && e->w > e->print && e->pr > 0 ? e->print++ : 0;
	e->pr >= 0 ? e->r += ft_putstr(tmp) : 0;
	while (e->w > e->print || e->z > 0)
	{
		e->z > 0 ? write(1, "0", 1) : 0;
		e->z == 0 ? write(1, " ", 1) : 0;
		--e->w;
		e->r = e->r + 1;
	}
}

static void	ft_is_p2(t_en *e, int *test)
{
	e->z != 0 && e->w > (e->print - e->pr) && e->pr > 0 ? e->z = 0 : 0;
	if (e->w <= e->print || e->w <= e->pr || e->z != 0)
	{
		e->r += write(1, "0x", 2);
		e->pr < e->print ? e->print += 2 : 0;
	}
	else if (e->w > e->print || e->w > e->pr)
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

void	ft_is_p(int *i, t_en *e)
{
	long long int	v;
	char			*tmp;
	int				test;

	v = va_arg(e->a, long long int);
	test = 0;
	tmp = ft_uitoa_base(v, 16);
	e->print = ft_strlen(tmp);
	if (e->m == 0)
	{
		if (e->w >= 0 || e->pr > e->print)
		{
			e->s != 0 && e->z != 0 ? e->print += 1 : 0;
			ft_is_p2(e, &test);
		}
		e->pr++;
		while (--e->pr > e->print)
			e->r += write(1, "0", 1);
		e->pr >= 0 ? e->r += ft_putstr(tmp) : 0;
	}
	else
		ft_is_p3(e, tmp);
	free(tmp);
	*i += 1;
}

#include "ft_printf.h"

void	ft_print_w(t_en *e, long long int n)
{
	int tmp;

	if ((e->w > e->pr) && (e->pr < e->print) && (e->pr != 0))
		e->print = e->pr;
	else if ((e->pr > e->print))
		e->pr = e->print;
	tmp = e->pr;
	e->s != 0 && e->z != 0 ? e->print += 1 : 0;
	e->z != 0 && e->w > (e->print - e->pr) && e->pr > 0 ? e->z = 0 : 0;
	if (e->w > e->pr)
	{
		n < 0 && (e->pr > e->print) ? e->w-- : 0;
		e->pr < 0 ? e->print = 0 : 0;
		while ((e->w > e->pr) && (e->w > e->print))
		{
			if (e->z > 0)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			--e->w;
			e->r = e->r + 1;
		}
	}
}

void	ft_nprint_w(t_en *e)
{
	int tmp;

	if ((e->w > e->pr) && (e->pr < e->print) && (e->pr != 0))
		e->print = e->pr;
	else if ((e->pr > e->print) && (e->f == 's' || e->f == 'S'))
		e->pr = e->print;
	tmp = e->pr;
	while (e->w > e->print || e->z > 0)
	{
		e->z > 0 ? write(1, "0", 1) : 0;
		e->z == 0 ? write(1, " ", 1) : 0;
		--e->w;
		e->r = e->r + 1;
	}
}

int		ft_putstr_capitalizer(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] > 96 && str[i] < 123)
			ft_putchar(str[i] - 32);
		else
			ft_putchar(str[i]);
	}
	return (i);
}

int		ft_putstr_minimizer(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] > 64 && str[i] < 91)
			ft_putchar(str[i] + 32);
		else
			ft_putchar(str[i]);
	}
	return (i);
}

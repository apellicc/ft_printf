#include "ft_printf.h"

void	ft_print_w(t_en *e, long long int n)
{
	int tmp;

	if ((e->w > e->pr) && (e->pr < e->print) && (e->f == 's' || e->f == 'S') && (e->pr != 0))
		e->print = e->pr;
	else if ((e->pr > e->print) && (e->f == 's' || e->f == 'S'))
			e->pr = e->print;
	tmp = e->pr;
	e->s != 0 && e->z != 0 ? e->print += 1 : 0;
	e->z != 0 && e->w > (e->print - e->pr) && e->pr > 0 ? e->z = 0 : 0;

	if ((e->d > 0 && (ft_strchr("oO", e->f))) || e->p > 0 || e->s > 0 )
	{
		e->p > 0 && n > -1 ? write(1, "+", 1) : 0;
		e->p > 0 && n < 0 ? write(1, "-", 1) : 0;
		e->s > 0 ? write(1, " ", 1) : 0;
		e->d > 0 && (e->f == 'o' || e->f == 'O') ? write(1, "0", 1) : 0;
		e->r = e->r + 1;
	}
	 if (e->d > 0 && (ft_strchr("xX", e->f)) && e->w <= e->pr && e->z != 0)
	 {
		 e->d > 0 && e->f == 'x' ? write(1, "0x", 2) : 0;
		 e->d > 0 && e->f == 'X' ? write(1, "0X", 2) : 0;
		 e->r = e->r + 2;
	 }
	if (e->p > 0 || (e->s > 0 && n < 0) || (e->d > 0 && ft_strchr("oOxXp", e->f)))
	{
		if(e->f == 'x' || e->f == 'X')
			e->print = e->print + 2;
		else
			e->print = e->print + 1;
	}
	if (e->w > e->pr)
	{
		n < 0 && (e->pr > e->print) ? e->w-- : 0;
		//e->pr <= 0 && e->f == 'p' ? e->print -= 1 : 0;
		e->pr < 0 && (e->f == 's' || e->f == 'c' || e->f == 'S' || e->f == 'C' || e->f == 'p') ? e->print = 0 : 0;
		while ((e->w > e->pr) && (e->w > e->print))
		{
			//ft_nbrendl(e->w);
			//ft_nbrendl(e->print);
			if (e->z > 0)
				write(1, "0", 1);
			else
				write(1, " ", 1);
			--e->w;
			e->r = e->r + 1;
		}
	}
	if (e->pr > e->print && (ft_strchr("diDuUoOxXp", e->f)))
	{
		if (n < 0)
		{
			e->r += ft_putchar('-');
			tmp++;
		}
		while(tmp > e->print || (e->pr > e->w && e->f == 'p'))
		{
			e->r += write(1, "0", 1);
			tmp--;
			(e->pr > e->w && e->f == 'p') ? e->pr-- : 0;
		}
	}
}
void	ft_nprint_w(t_en *e, long long int n)
{
	int tmp;

	if ((e->w > e->pr) && (e->pr < e->print) && (e->f == 's' || e->f == 'S') && (e->pr != 0))
		e->print = e->pr;
	else if ((e->pr > e->print) && (e->f == 's' || e->f == 'S'))
			e->pr = e->print;
	tmp = e->pr;
	if (e->p > 0 || (e->s > 0 && n < 0) || (e->d > 0 && (ft_strchr("oO", e->f))))
	{
		e->p > 0 && n > -1 ? write(1, "+", 1) : 0;
		e->p > 0 && n < 0 ? write(1, "-", 1) : 0;
		e->s > 0 ? write(1, " ", 1) : 0;
		e->d > 0 && (e->f == 'o' || e->f == 'O') ? write(1, "0", 1) : 0;
		e->r = e->r + 1;
	}
	if (e->d > 0 && ft_strchr("xX", e->f) && e->w <= e->pr && e->z != 0)
	 {
		 e->d > 0 && e->f == 'x' ? write(1, "0x", 2) : 0;
		 e->d > 0 && e->f == 'X' ? write(1, "0X", 2) : 0;
		 e->r = e->r + 2;
	}
	if (e->p > 0 || (e->s > 0 && n < 0) || (e->d > 0 && ft_strchr("oOxXp", e->f)))
	{
		if(e->f == 'x' || e->f == 'X')
			e->print = e->print + 2;
		else
			e->print = e->print + 1;
	}
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

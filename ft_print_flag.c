#include "ft_printf.h"
void	ft_print_w(t_en *e, long long int n)
{
	//ft_putendl("nqiqiq");
	if (e->p > 0 || (e->s > 0 && n < 0) || (e->d > 0 && ft_strchr("oOxXp", e->f)))
	{
		if(e->f == 'x' || e->f == 'X')
			e->print = e->print + 2;
		else
			e->print = e->print + 1;
	}
	while (e->w > e->print)
	{
		e->z > 0 ? write(1, "0", 1) : 0;
		e->z == 0 ? write(1, " ", 1) : 0;
		--e->w;
		e->r = e->r + 1;
	}
	if (e->p > 0 || (e->s > 0 && n < 0) || (e->d > 0 && (ft_strchr("oO", e->f))))
	{
		//ft_putendl("nqiqiq");
		e->p > 0 && n > -1 ? write(1, "+", 1) : 0;
		e->p > 0 && n < 0 ? write(1, "-", 1) : 0;
		e->s > 0 ? write(1, " ", 1) : 0;
		e->d > 0 && (e->f == 'o' || e->f == 'O') ? write(1, "0", 1) : 0;
		e->r = e->r + 1;
	}
	 if (e->d > 0 && (ft_strchr("xX", e->f)))
	 {
		 e->d > 0 && e->f == 'x' ? write(1, "0x", 2) : 0;
		 e->d > 0 && e->f == 'X' ? write(1, "0X", 2) : 0;
		 e->r = e->r + 2;
	 }
}
void	ft_nprint_w(t_en *e, long long int n)
{
	if (e->p > 0 || (e->s > 0 && n < 0) || (e->d > 0 && (ft_strchr("oO", e->f))))
	{
		//ft_putendl("nqiqiq");
		e->p > 0 && n > -1 ? write(1, "+", 1) : 0;
		e->p > 0 && n < 0 ? write(1, "-", 1) : 0;
		e->s > 0 ? write(1, " ", 1) : 0;
		e->d > 0 && (e->f == 'o' || e->f == 'O') ? write(1, "0", 1) : 0;
		e->r = e->r + 1;
	}
	if (e->d > 0 && ft_strchr("xX", e->f))
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

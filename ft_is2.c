#include "ft_printf.h"

void	ft_is_o(int *i, t_en *e)
{
	unsigned long long int nb;

	e->c == 0 ? nb = va_arg(e->a, unsigned int) : 0;
	e->c == 'H' ? nb = (unsigned char)va_arg(e->a, unsigned int) : 0;
	e->c == 'h' ? nb = (unsigned short int)va_arg(e->a, unsigned int) : 0;
	e->c == 'l' ? nb = (unsigned long int)va_arg(e->a, unsigned long long int) : 0;
	e->c == 'L' ? nb = (unsigned long long int)va_arg(e->a, unsigned long long int) : 0;
	e->c == 'j' ? nb = (uintmax_t)va_arg(e->a, uintmax_t) : 0;
	e->c == 'z' ? nb = (size_t)va_arg(e->a, size_t) : 0;
	e->print = ft_strlen(ft_uitoa_base(nb, 8));
	if (e->m == 0)
	{
		(e->w != 0 || e->d != 0 || e->pr > e->print) && nb != 0 ? ft_print_w(e, 1) : 0;
		e->r += ft_putstr(ft_uitoa_base(nb, 8));
		*i = *i + 1;
	}
	ft_ini(e);
}

void	ft_is_p(int *i, t_en *e)
{
	long long int	v;
	char *tmp;

	v = va_arg(e->a, long long int);
	tmp = ft_uitoa_base(v, 16);
	e->print = ft_strlen(tmp) + 2;
	if (e->m == 0)
	{
		if (e->pr > e->w || (e->z != 0))
		{
			e->z != 0 ? e->print -= 1 : 0;
			e->r += ft_putstr("0x");
			//e->print -= 2;
			e->w != 0 || e->pr > e->print ? ft_print_w(e, 1) : 0;
			*tmp != '0' ? e->r += ft_putstr(tmp) : 0;

		}
		else
		{
			e->w != 0 || e->pr > e->print ? ft_print_w(e, 1) : 0;
			e->r += ft_putstr("0x");
			e->r += ft_putstr(tmp);
		}
		*i = *i + 1;
	}
	else
	{
		e->r += ft_putstr("0x");
		e->r += ft_putstr(tmp);
		e->w != 0 ? ft_nprint_w(e, 1) : 0;
		*i = *i + 1;
	}
	ft_ini(e);
}

void	ft_is_x(int *i, t_en *e)
{
	long long int		nb;
	char *tmp;

	e->c == 0 ? nb = va_arg(e->a, int) : 0;
	e->c == 'H' ? nb = (unsigned char)va_arg(e->a, int) : 0;
	e->c == 'h' ? nb = (unsigned short int)va_arg(e->a, int) : 0;
	e->c == 'l' ? nb = (unsigned long long int)va_arg(e->a, unsigned long long int) : 0;
	e->c == 'L' ? nb = (unsigned long long int)va_arg(e->a, unsigned long long int) : 0;
	e->c == 'j' ? nb = (uintmax_t)va_arg(e->a, uintmax_t) : 0;
	e->c == 'z' ? nb = (size_t)va_arg(e->a, size_t) : 0;
	if (e->c == 'L' || e->c == 'l' || e->c == 'z' || e->c == 'j')
		tmp = ft_uitoa_base(nb, 16);
	else
		tmp = ft_itoa_base(nb, 16);
	e->print = ft_strlen(tmp);
	if (e->m == 0)
	{
		(e->w != 0 || e->d != 0 || e->pr > e->print) && nb != 0 ? ft_print_w(e, 1) : 0;
		e->r += ft_putstr_minimizer(tmp);
		*i = *i + 1;
	}
	ft_ini(e);
}

void	ft_is_X(int *i, t_en *e)
{
	long long int		nb;
	char	*tmp;

	e->c == 0 ? nb = va_arg(e->a, int) : 0;
	e->c == 'H' ? nb = (unsigned char)va_arg(e->a, int) : 0;
	e->c == 'h' ? nb = (unsigned short int)va_arg(e->a, int) : 0;
	e->c == 'l' ? nb = (unsigned long long int)va_arg(e->a, unsigned long long int) : 0;
	e->c == 'L' ? nb = (unsigned long long int)va_arg(e->a, unsigned long long int) : 0;
	e->c == 'j' ? nb = (uintmax_t)va_arg(e->a, uintmax_t) : 0;
	e->c == 'z' ? nb = (size_t)va_arg(e->a, size_t) : 0;
	if (e->c == 'L' || e->c == 'l' || e->c == 'z' || e->c == 'j')
		tmp = ft_uitoa_base(nb, 16);
	else
		tmp = ft_itoa_base(nb, 16);
	e->print = ft_strlen(tmp);
	if (e->m == 0)
	{
		(e->w != 0 || e->d != 0 || e->pr > e->print) && nb != 0? ft_print_w(e, 1) : 0;
		e->r += ft_putstr_capitalizer(tmp);
		*i = *i + 1;
	}
	ft_ini(e);
}
void	ft_is_invalid(char *f, int *i, t_en *e)
{
	int i1;
	(void)f;

	if (e->m == 0)
	{
		i1 = *i;
		e->r += (e->w > 0 ? e->w - 1 : e->w);
		while (--e->w > 0)
			e->z > 0 ? write(1, "0", 1) : write(1, " ", 1);
		e->r += ft_putchar(f[*i]);
		*i = *i + 1;
	}
	else
	{
		e->r += ft_putchar(f[*i]);
		e->r += (e->w > 0 ? e->w - 1 : e->w);
		while (--e->w > 0)
			e->z > 0 ? write(1, "0", 1) : write(1, " ", 1);
		*i = *i + 1;
	}
}

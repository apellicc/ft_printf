#include "ft_printf.h"

//e->f == 'O' ? ft_is_O(i, e) : 0;


void	ft_is_o(int *i, t_en *e)
{
	int nb;

	e->c == 0 ? nb = va_arg(e->a, int) : 0;
	e->c == 'H' ? nb = (unsigned char)va_arg(e->a, int) : 0;
	e->c == 'h' ? nb = (unsigned short int)va_arg(e->a, int) : 0;
	e->c == 'l' ? nb = (unsigned long int)va_arg(e->a, unsigned long long int) : 0;
	e->c == 'L' ? nb = (unsigned long long int)va_arg(e->a, unsigned long long int) : 0;
	e->c == 'j' ? nb = (uintmax_t)va_arg(e->a, uintmax_t) : 0;
	e->c == 'z' ? nb = (size_t)va_arg(e->a, size_t) : 0;
	e->print = ft_strlen(ft_uitoa_base(nb, 8));
	if (e->m == 0)
	{
		e->w != 0 ? ft_print_w(e, 1) : 0;
		e->w == 0 && e->d != 0 ? e->r += write(1, "0", 1) : 0;
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
		e->w != 0 ? ft_print_w(e, 1) : 0;
		e->r += ft_putstr("0x");
		e->r += ft_putstr(tmp);
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
	int		nb;
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
		e->w != 0 ? ft_print_w(e, 1) : 0;
		e->r += ft_putstr_minimizer(tmp);
		*i = *i + 1;
	}
	ft_ini(e);


}

void	ft_is_X(int *i, t_en *e)
{
	int		nb;
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
		e->w != 0 ? ft_print_w(e, 1) : 0;
		e->r += ft_putstr_capitalizer(tmp);
		*i = *i + 1;
	}
	ft_ini(e);
}

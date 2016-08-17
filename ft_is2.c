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
	e->c == 'j' ? nb = (int)va_arg(e->a, int) : 0;
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
	// if (v != 0)
	// {
	// 	e->r += ft_putstr("0x7fff");
	// 	e->r += ft_putstr(tmp);
	// }
	// else
	e->r += ft_putstr("0x");
	 e->r += ft_putstr(tmp);

	//printf("\n%s\n", ft_itoa_base(v, 16));
	*i = *i + 1;
}

void	ft_is_x(int *i, t_en *e)
{
	int		nb;

	e->c == 0 ? nb = va_arg(e->a, int) : 0;
	e->c == 'H' ? nb = (unsigned char)va_arg(e->a, int) : 0;
	e->c == 'h' ? nb = (unsigned short int)va_arg(e->a, int) : 0;
	e->c == 'l' ? nb = (unsigned long int)va_arg(e->a, int) : 0;
	e->c == 'L' ? nb = (unsigned long long int)va_arg(e->a, int) : 0;
	e->c == 'j' ? nb = (int)va_arg(e->a, int) : 0;
	e->c == 'z' ? nb = (size_t)va_arg(e->a, int) : 0;
	e->print = ft_strlen(ft_uitoa_base(nb, 16));
	if (e->m == 0)
	{
		e->w != 0 ? ft_print_w(e, 1) : 0;
		e->r += ft_putstr_minimizer(ft_uitoa_base(nb, 16));
		*i = *i + 1;
	}
	ft_ini(e);


}

void	ft_is_X(int *i, t_en *e)
{
	int		nb;

	e->c == 0 ? nb = va_arg(e->a, int) : 0;
	e->c == 'H' ? nb = (unsigned char)va_arg(e->a, int) : 0;
	e->c == 'h' ? nb = (unsigned short int)va_arg(e->a, int) : 0;
	e->c == 'l' ? nb = (unsigned long int)va_arg(e->a, int) : 0;
	e->c == 'L' ? nb = (unsigned long long int)va_arg(e->a, int) : 0;
	e->c == 'j' ? nb = (int)va_arg(e->a, int) : 0;
	e->c == 'z' ? nb = (size_t)va_arg(e->a, int) : 0;

	e->print = ft_strlen(ft_uitoa_base(nb, 16));
	if (e->m == 0)
	{
		e->w != 0 ? ft_print_w(e, 1) : 0;
		e->r += ft_putstr_capitalizer(ft_uitoa_base(nb, 16));
		*i = *i + 1;
	}
	ft_ini(e);
}

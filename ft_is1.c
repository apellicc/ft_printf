#include "ft_printf.h"


void	ft_is_d(int *i, t_en *e)
{

	long long int		nb;
	//ft_putendl("debut is d");
	e->c == 0 ? nb = va_arg(e->a, int) : 0;
	e->c == 'H' ? nb = (char)va_arg(e->a, int) : 0;
	e->c == 'h' ? nb = (short int)va_arg(e->a, int) : 0;
	e->c == 'l' ? nb = (long long int)va_arg(e->a, long long int) : 0;
	e->c == 'L' ? nb = (long long int)va_arg(e->a, long long int) : 0;
	e->c == 'j' ? nb = (int)va_arg(e->a, int) : 0;
	e->c == 'z' ? nb = (size_t)va_arg(e->a, size_t) : 0;
	e->print = ft_intlen(nb);
	if (e->m == 0)
	{
		//printf("%ld valeur ")
		e->w != 0 ? ft_print_w(e, e->print) : 0;
		ft_putlongnbr(nb);
		e->r += ft_intlen(nb);
		*i = *i + 1;
	}
	ft_ini(e);
}

void	ft_is_D(int *i, t_en *e)
{

	 long long		nb;

	nb = (long long)va_arg(e->a, long long);
	// e->c == 'H' ? nb = (char)va_arg(e->a, int) : 0;
	// e->c == 'h' ? nb = (short int)va_arg(e->a, int) : 0;
	// e->c == 'l' ? nb = (long int)va_arg(e->a, int) : 0;
	// e->c == 'L' ? nb = (long long int)va_arg(e->a, int) : 0;
	// e->c == 'j' ? nb = (int)va_arg(e->a, int) : 0;
	// e->c == 'z' ? nb = (size_t)va_arg(e->a, int) : 0;
	e->print = ft_intlen(nb);
	if (e->m == 0)
	{
		e->w != 0 ? ft_print_w(e, e->print) : 0;
		ft_putlongnbr(nb);
		e->r += ft_intlen(nb);
		*i = *i + 1;
	}
	ft_ini(e);
}

void	ft_is_O(int *i, t_en *e)
{
	unsigned long long int nb;

	nb = (unsigned long long int)va_arg(e->a, unsigned long long int);
	e->print = ft_strlen(ft_itoa_base(nb, 8));
	if (e->m == 0)
	{
		e->w != 0 ? ft_print_w(e, 1) : 0;
		e->r += ft_putstr(ft_itoa_base(nb, 8));
		*i = *i + 1;
	}
	ft_ini(e);
}

void	ft_is_u(int *i, t_en *e)
{

	unsigned long long int		nb;

	e->c == 0 ? nb = va_arg(e->a, unsigned int) : 0;
	e->c == 'H' ? nb = (unsigned char)va_arg(e->a, int) : 0;
	e->c == 'h' ? nb = (unsigned short int)va_arg(e->a, unsigned int) : 0;
	e->c == 'l' ? nb = (unsigned long int)va_arg(e->a, unsigned long long  int) : 0;
	e->c == 'L' ? nb = (unsigned long long int)va_arg(e->a, unsigned long long int) : 0;
	e->c == 'j' ? nb = (int)va_arg(e->a, int) : 0;
	e->c == 'z' ? nb = (size_t)va_arg(e->a, size_t) : 0;
	e->print = ft_uintlen(nb);
	if (e->m == 0)
	{
		e->w != 0 ? ft_print_w(e, 1) : 0;
		ft_putunsignedlongnbr(nb);
		e->r += ft_uintlen(nb);
		*i = *i + 1;
	}
	// else
	// {
	// 	ft_putnbr(nb);
	// 	e->w != 0 ? ft_nprint_w(i, e) : 0;
	// 	e->r += ft_intlen(nb);
	// 	*i = *i + 1;
	// }
	ft_ini(e);
}

void	ft_is_U(int *i, t_en *e)
{

	unsigned long long int		nb;

	nb = (unsigned long long int)va_arg(e->a, unsigned long long int);

	ft_putunsignedlongnbr(nb);
	e->r += ft_uintlen(nb);
	*i = *i + 1;
	ft_ini(e);
}

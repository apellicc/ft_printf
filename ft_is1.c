#include "ft_printf.h"

//e->f == 'D' ? ft_is_D(i, e) : 0;
//e->f == 'i' ? ft_is_i(i, e) : 0;
//e->f == 'u' ? ft_is_u(i, e) : 0;
//e->f == 'U' ? ft_is_U(i, e) : 0;

void	ft_is_d(int *i, t_en *e)
{

	int		nb;

	e->c == 0 ? nb = va_arg(e->a, int) : 0;
	e->c == 'H' ? nb = (char)va_arg(e->a, int) : 0;
	e->c == 'h' ? nb = (short int)va_arg(e->a, int) : 0;
	e->c == 'l' ? nb = (long int)va_arg(e->a, int) : 0;
	e->c == 'L' ? nb = (long long int)va_arg(e->a, int) : 0;
	e->c == 'j' ? nb = (int)va_arg(e->a, int) : 0;
	e->c == 'z' ? nb = (size_t)va_arg(e->a, int) : 0;
	
	ft_putnbr(nb);
	e->r += ft_intlen(nb);
	*i = *i + 1;
	ft_ini(e);
}

//
// void	ft_is_int(int *i, t_en *e)
// {
// 	int		nb;
//
// 	nb = va_arg(e->a, int);
// 	ft_putnbr(nb);
// 	e->r += ft_intlen(nb);
// 	*i = *i + 1;
//
// }
//
// void	ft_is_octal(int *i, t_en *e)
// {
//
// }
//
// void	ft_is_hex(int *i, t_en *e)
// {
//
// }
//
// void	ft_is_char(int *i, t_en *e)
// {
//
// }

#include "ft_printf.h"

//e->f == 'D' ? ft_is_D(i, e) : 0;
//e->f == 'i' ? ft_is_i(i, e) : 0;
//e->f == 'u' ? ft_is_u(i, e) : 0;
//e->f == 'U' ? ft_is_U(i, e) : 0;

void	ft_is_d(int *i, t_en *e)
{

	int		nb;

	nb = va_arg(e->a, int);
	ft_putnbr(nb);
	e->r += ft_intlen(nb);
	*i = *i + 1;
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

e->c == 'h' ? ft_conv_h(i, e) : 0;
e->c == 'l' ? ft_conv_l(i, e) : 0;
e->c == 'y' ? ft_conv_y(i, e) : 0;
e->c == 'z' ? ft_conv_z(i, e) : 0;
e->c == 'H' ? ft_conv_H(i, e) : 0;
#include "ft_printf.h"

void	ft_conv_H(int *i, t_en *e)
{
	e->s == 'd' || e->s == 'i' || e->s == 'D' ? ft_is_sc(i, e) : 0;
	e->s == 'u' || e->s == 'U' || e->s == 'o' || e->s == 'O' || e->s == 'x' || e->s == 'X' ? ft_is_uc(i, e) : 0; 
}

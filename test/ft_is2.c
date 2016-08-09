#include "ft_printf.h"

//e->f == 'O' ? ft_is_O(i, e) : 0;


void	ft_is_o(int *i, t_en *e)
{
	int		nb;

	nb = va_arg(e->a, int);
	e->r += ft_putstr(ft_itoa_base(nb, 8));
	*i = *i + 1;
}

void	ft_is_p(int *i, t_en *e)
{
	void *v;

	v = va_arg(e->a, void *);
	e->r += ft_putstr(v);
	*i = *i + 1;
}

void	ft_is_x(int *i, t_en *e)
{
	int		nb;

	nb = va_arg(e->a, int);
	e->r += ft_putstr_minimizer(ft_itoa_base(nb, 16));
	*i = *i + 1;
}

void	ft_is_X(int *i, t_en *e)
{
	int		nb;

	nb = va_arg(e->a, int);
	e->r += ft_putstr_capitalizer(ft_itoa_base(nb, 16));
	*i = *i + 1;
}

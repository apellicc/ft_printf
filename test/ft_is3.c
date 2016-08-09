#include "ft_printf.h"

//e->f == 'S' ? ft_is_S(i, e) : 0;
//e->f == 'C' ? ft_is_C(i, e) : 0;

void	ft_is_s(int *i, t_en *e)
{
	char *str;

	str = va_arg(e->a, char *);
	if (e->s != 0)
	{
		e->r += ft_putchar(' ');
		*i = *i + 1;
	} 
	if (!str)
		e->r += ft_putstr("(null)");
	else
		e->r += ft_putstr(str);
	*i = *i + 1;
}

void	ft_is_c(int *i, t_en *e)
{
	char c;

	c = va_arg(e->a, int);
	e->r += ft_putchar(c);
	*i = *i + 1;
}

void	ft_is_percent(int *i, t_en *e)
{
	e->r += ft_putchar('%');
	*i = *i + 1;
}

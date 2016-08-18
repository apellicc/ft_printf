#include "ft_printf.h"

//e->f == 'S' ? ft_is_S(i, e) : 0;
//e->f == 'C' ? ft_is_C(i, e) : 0;

void	ft_is_s(int *i, t_en *e)
{
	char *str;

	if (e->c == 0)
	{
		//ft_putendl("je suis ici");
		str = va_arg(e->a, char *);
		//e->print = ft_strlen(str);
		e->s = 0;
		if (e->m == 0)
		{
			//!str || str[0] == '\0' ? e->s = 0 : 0;
			if (e->s != 0)
			{
				e->print++;
				e->r += ft_putchar(' ');
				*i = *i + 1;
			}
			if (!str)
			{
				//		ft_putendl("je suis ici");
				e->print += 6;
				e->w != 0 ? ft_print_w(e, 1) : 0;

				e->r += ft_putstr("(null)");
			}
			else
			{
				e->print += ft_strlen(str);
				e->w != 0 ? ft_print_w(e, 1) : 0;
				e->r += ft_putstr(str);

			}
			*i = *i + 1;
			ft_ini(e);
		}
	}
	//e->c == 'l' ? ft_is_S(i, e) : 0;
}

void	ft_is_c(int *i, t_en *e)
{
	char c;

	if (e->c == 0)
	{
		c = va_arg(e->a, int);
		e->print = 1;
		if (e->m == 0)
		{
			e->w != 0 ? ft_print_w(e, 1) : 0;
			e->r += ft_putchar(c);
			*i = *i + 1;
		}
		ft_ini(e);
	}
//	e->c == 'l' ? ft_is_C(i, e) : 0;
}

void	ft_is_percent(int *i, t_en *e)
{
	e->r += ft_putchar('%');
	*i = *i + 1;
}

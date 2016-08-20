#include "ft_printf.h"

//e->f == 'S' ? ft_is_S(i, e) : 0;
//e->f == 'C' ? ft_is_C(i, e) : 0;

void	ft_is_s(int *i, t_en *e)
{
	char *str;
	int tmp;

	//ft_putendl("dans s");
	if (e->c != 'l')
	{
		// ft_putendl("je suis ici");
		str = va_arg(e->a, char *);
		//e->print = ft_strlen(str);
		//e->s = 0;
		//e->print = ft_strlen(str);
		//e->r += e->print;
		if (e->m == 0)
		{
			!str || str[0] == '\0' || (ft_strcmp(str, "(null)") == 0) ? e->s = 0 : 0;
			if (e->s != 0)
			{
				e->print++;
				e->r += ft_putchar(' ');
				*i = *i + 1;
			}
			if (!str)
			{
				e->s = 0;
				//		ft_putendl("je suis ici");
				e->print += 6;
				e->w != 0 || e->pr > e->print ? ft_print_w(e, 1) : 0;

				e->r += ft_putstr("(null)");
			}
			else
			{
				tmp = ft_strlen(str);
				e->print += tmp;
				//e->r += e->print;
				e->w != 0 || (e->pr > e->print)? ft_print_w(e, 1) : 0;
				// ft_nbrendl(e->w);
				// ft_nbrendl(e->pr);
				// ft_nbrendl(e->print);
				//ft_putendl("ici");
				e->pr < tmp && e->pr != 0 ? e->r += write(1, str, e->pr) : 0;
				e->pr >= tmp || e->pr == 0 ? e->r += ft_putstr(str) : 0;
				//ft_putendl("ici");
			}
			e->pr >= 0 ? *i = *i + 1 : e->r++;
			ft_ini(e);
		}
	}
	e->c == 'l' ? ft_is_S(i, e) : 0;
}

void	ft_is_c(int *i, t_en *e)
{
	char c;
	//  ft_putendl("icoi");
	if (e->c != 'l')
	{
		c = va_arg(e->a, int);
		// ft_putendl("ic");
		c == 0 && e->pr < 0 ? e->r++ : 0;
		e->print = 1;
		if (e->m == 0)
		{
			e->w != 0 || e->pr > e->print ? ft_print_w(e, 1) : 0;
			e->r += ft_putchar(c);
			//ft_nbrendl(e->r);
			*i = *i + 1;
		}
		ft_ini(e);
	}
	//ft_nbrendl(e->r);
	e->c == 'l' ? ft_is_C(i, e) : 0;
//	ft_putendl("ekek");
//		ft_nbrendl(e->r);
}

void	ft_is_percent(int *i, t_en *e)
{
	e->r += ft_putchar('%');
	*i = *i + 1;
}

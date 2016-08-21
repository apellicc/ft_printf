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

				e->pr >= 0 ? e->r += ft_putstr("(null)") : 0;
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
	e->p != 0 ? e->p = 0 : 0;
	e->d != 0 ? e->d = 0 : 0;
	e->s != 0 ? e->s = 0 : 0;
	if (e->c != 'l')
	{
		c = va_arg(e->a, int);
		c == 0 && e->pr < 0 ? e->r++ : 0;
		e->print = 1;
		if (e->m == 0)
		{
			if (e->w != 0 || c != 0)
			{
				if (e->w > e->pr)
				{
					while ((e->w > e->pr) && (e->w > e->print))
					{
						if (e->z > 0)
							write(1, "0", 1);
						else
							write(1, " ", 1);
						--e->w;
						e->r = e->r + 1;
					}
				}
			}
			e->pr >= 0 ? e->r += ft_putchar(c) : 0;
		}
		else
		{
			e->pr >= 0 ? e->r += ft_putchar(c) : 0;
			if (e->w != 0 || c != 0)
			{
				if (e->w > e->pr)
				{
					e->w--;
					while ((e->w > e->pr) && (e->w > e->print))
					{
						if (e->z > 0)
							write(1, "0", 1);
						else
							write(1, " ", 1);
						--e->w;
						e->r = e->r + 1;
					}
				}
			}
		}
		*i = *i + 1;

	}
	e->c == 'l' ? ft_is_C(i, e) : 0;
}

void	ft_is_percent(int *i, t_en *e)
{
	if (e->m == 0)
	{
		e->r += (e->w > 0 ? e->w - 1 : e->w);
		while (--e->w > 0)
			e->z > 0 ? write(1, "0", 1) : write(1, " ", 1);
		e->r += ft_putchar('%');
		*i = *i + 1;
	}
	else
	{
		e->r += ft_putchar('%');
		e->r += (e->w > 0 ? e->w - 1 : e->w);
		while (--e->w > 0)
			e->z > 0 ? write(1, "0", 1) : write(1, " ", 1);
		*i = *i + 1;
	}
	// e->r += ft_putchar('%');
	// *i = *i + 1;
}

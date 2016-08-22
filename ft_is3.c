#include "ft_printf.h"

void	ft_is_s(int *i, t_en *e)
{
	char	*str;
	int		tmp;

	if (e->c != 'l')
	{
		str = va_arg(e->a, char *);
		str ? tmp = ft_strlen(str) : 0;
		e->pr == 0 && tmp != 0 ? e->pr = tmp + e->w : 0;
		if (e->m == 0)
		{
			!str || str[0] == '\0' || (ft_strcmp(str, "(null)") == 0)
			? e->s = 0 : 0;
			if (e->s != 0)
			{
				e->print++;
				e->r += ft_putchar(' ');
				e->pr++;
			}
			if (!str)
			{
				e->print += 6;
				if (e->w != 0 || e->pr > e->print)
				{
					if ((e->w > e->pr) && (e->pr < e->print) && (e->pr != 0))
						e->print = e->pr;
					else if ((e->pr > e->print))
						e->pr = e->print;
					tmp = e->pr;
					e->s != 0 && e->z != 0 ? e->print += 1 : 0;
					e->z != 0 && e->w > (e->print - e->pr) && e->pr > 0
					? e->z = 0 : 0;
					if (e->w > e->pr)
					{
						(e->pr > e->print) ? e->w-- : 0;
						e->pr < 0 ? e->print = 0 : 0;
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
				e->pr >= 0 ? e->r += ft_putstr("(null)") : 0;
			}
			else
			{
				e->print += tmp;
				tmp = e->pr;
				if (e->w != 0 || e->pr > e->print)
				{
					if ((e->w > e->pr) && (e->pr < e->print) && (e->pr != 0))
						e->print = e->pr;
					else if (e->pr > e->print && e->w < e->pr)
						e->pr = e->print;
					e->s != 0 && e->z != 0 ? e->print += 1 : 0;
					tmp = e->pr;
					if (e->w > e->pr)
					{
						e->pr < 0 ? e->print = 0 : 0;
						while ((e->w > tmp) && (e->w > e->print))
						{
							if (e->z > 0)
								write(1, "0", 1);
							else
								write(1, " ", 1);
							--e->w;
							tmp--;
							e->r = e->r + 1;
						}
					}
				}
				if (e->pr >= 0 && e->pr <= e->print)
					e->r += write(1, str, e->pr);
				else if (e->pr >= 0 && e->pr > e->print)
					e->r += ft_putstr(str);
			}
		}
		else
		{
			if (e->pr < tmp && e->pr >= 0)
			{
				e->r += write(1, str, e->pr);
				e->w -= e->pr;
			}
			else if (e->pr >= tmp && e->pr >= 0)
			{
				e->r += ft_putstr(str);
				e->w -= ft_strlen(str);
			}
			if ((e->w > e->pr) && (e->pr < e->print) && (e->pr != 0))
				e->print = e->pr;
			else if (e->pr > e->print)
				e->pr = e->print;
			while (e->w > e->print && e->w > e->pr)
			{
				e->z > 0 ? write(1, "0", 1) : 0;
				e->z == 0 ? write(1, " ", 1) : 0;
				--e->w;
				e->r = e->r + 1;
			}
		}
		*i = *i + 1;
		ft_ini(e);
	}
	e->c == 'l' ? ft_is_ws(i, e) : 0;
}

void	ft_is_c(int *i, t_en *e)
{
	char	c;

	e->p != 0 ? e->p = 0 : 0;
	e->d != 0 ? e->d = 0 : 0;
	e->s != 0 ? e->s = 0 : 0;
	e->print = 1;
	if (e->c != 'l')
	{
		c = va_arg(e->a, int);
		c == 0 && e->pr < 0 ? e->r++ : 0;
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
			e->pr >= 0 ? e->r += ft_putchar(c) : ft_putchar(c);
		}
		else
		{
			e->pr >= 0 ? e->r += ft_putchar(c) : 0;
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
		}
		*i = *i + 1;
	}
	e->c == 'l' ? ft_is_wc(i, e) : 0;
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
}

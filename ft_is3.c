#include "ft_printf.h"

//e->f == 'S' ? ft_is_S(i, e) : 0;
//e->f == 'C' ? ft_is_C(i, e) : 0;

void	ft_is_s(int *i, t_en *e)
{
	char *str;
	int tmp;


	if (e->c != 'l')
	{
		str = va_arg(e->a, char *);
		// ft_putendl("ici3");

		str ? tmp = ft_strlen(str) : 0;
		//ft_printf("%d valeur e->pr\n", e->pr);
		e->pr == 0 && tmp != 0 ? e->pr = tmp + e->w : 0;
		//ft_printf("%d valeur e->pr\n", e->pr);

		if (e->m == 0)
		{
			// ft_putendl("ici4");

			!str || str[0] == '\0' || (ft_strcmp(str, "(null)") == 0) ? e->s = 0 : 0;
			if (e->s != 0)
			{
				e->print++;
				e->r += ft_putchar(' ');
				e->pr++;
				//*i = *i + 1;
			}
			if (!str)
			{
				//e->s = 0;
				e->print += 6;
				if (e->w != 0 || e->pr > e->print)
				{
					if ((e->w > e->pr) && (e->pr < e->print) && (e->pr != 0))
						e->print = e->pr;
					else if ((e->pr > e->print))
							e->pr = e->print;
					tmp = e->pr;
					e->s != 0 && e->z != 0 ? e->print += 1 : 0;
					e->z != 0 && e->w > (e->print - e->pr) && e->pr > 0 ? e->z = 0 : 0;
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
				// ft_putendl("ici");

				//  ft_putendl("ici5");

				e->print += tmp;
				tmp = e->pr;
			//	ft_printf("%d valeur e->pr\n", e->pr);
				if (e->w != 0 || e->pr > e->print)
				{
					// ft_putendl("ici");

				//	tmp = e->pr;
				// ft_nbrendl(e->pr);
				// ft_nbrendl(e->print);

					if ((e->w > e->pr) && (e->pr < e->print) && (e->pr != 0))
						e->print = e->pr;
					else if (e->pr > e->print && e->w < e->pr)
							e->pr = e->print;
					e->s != 0 && e->z != 0 ? e->print += 1 : 0;
					//e->z != 0 && e->w > (e->print - e->pr) && e->pr > 0 ? e->z = 0 : 0;
					//(tmp < e->pr) ? (tmp = e->pr) : 0;
					tmp = e->pr;

					if (e->w > e->pr)
					{
						// ft_printf("%d valeur e->pr\n", e->pr);
						// ft_printf("%d valeur tmp\n", tmp);
						// ft_printf("%d valeur e->w\n", e->w);
						// ft_putendl("ici");

						//(e->pr > e->print) ? e->w-- : 0;
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
					//ft_putendl("ici6");

					// e->pr < tmp && e->pr != 0 ? e->r += write(1, str, e->pr) : 0;
					// e->pr >= tmp || e->pr != 0 ? e->r += ft_putstr(str) : 0;
				}
			//	 ft_nbrendl(e->pr);
				 //ft_nbrendl(test);
			//	 ft_nbrendl(tmp);
			//	 ft_nbrendl(e->print);
			// ft_printf("%d valeur e->pr\n", e->pr);
			// ft_printf("%d valeur tmp\n", tmp);
			// ft_printf("%d valeur e->w\n", e->w);
			// ft_printf("%d valeur e->print\n", e->print);
			// ft_printf("%d valeur e->r\n", e->r);

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
			// ? e->r += write(1, str, e->pr) : 0;
			// e->pr >= tmp && e->pr >= 0 ? e->r += ft_putstr(str) : 0;

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
	e->c == 'l' ? ft_is_S(i, e) : 0;
}

void	ft_is_c(int *i, t_en *e)
{
	char c;
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
					//e->w--;
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

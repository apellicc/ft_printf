#include "ft_printf.h"

void	ft_is_o(int *i, t_en *e)
{
	unsigned long long int nb;
	int test = 0;
	char *tmp;
	e->c == 0 ? nb = va_arg(e->a, unsigned int) : 0;
	e->c == 'H' ? nb = (unsigned char)va_arg(e->a, unsigned int) : 0;
	e->c == 'h' ? nb = (unsigned short int)va_arg(e->a, unsigned int) : 0;
	e->c == 'l' ? nb = (unsigned long int)va_arg(e->a, unsigned long long int) : 0;
	e->c == 'L' ? nb = (unsigned long long int)va_arg(e->a, unsigned long long int) : 0;
	e->c == 'j' ? nb = (uintmax_t)va_arg(e->a, uintmax_t) : 0;
	e->c == 'z' ? nb = (size_t)va_arg(e->a, size_t) : 0;
	tmp = ft_uitoa_base(nb, 8);
	e->print = ft_strlen(tmp);
	if (e->m == 0)
	{
		if (e->w != 0 || e->d != 0 || e->pr > e->print)
		{
			e->s != 0 && e->z != 0 ? e->print += 1 : 0;
			e->z != 0 && e->w > (e->print - e->pr) && e->pr > 0 ? e->z = 0 : 0;
			if (e->d != 0 && (e->w <= e->print || e->w <= e->pr || e->z != 0) && nb != 0)
			{
				e->r += write(1, "0", 1);
				e->print += 1;
			}
			else if (e->d != 0 && (e->w > e->print || e->w > e->pr ) && nb != 0)
			{
				test = 2;
				e->w -= 1;
			}
			while ((e->w > e->pr) && (e->w > e->print))
			{
			//ft_nbrendl(e->w);
			//ft_nbrendl(e->print);
				if (e->z > 0)
					write(1, "0", 1);
				else
					write(1, " ", 1);
				--e->w;
				e->r = e->r + 1;
			}
			if (test == 2)
			{
				e->r += write(1, "0", 1);
				e->print += 1;
			}
		}
		while(e->pr > e->print)
		{
			e->r += write(1, "0", 1);
			e->pr--;
		}

	//}
	//e->d > 0 && e->z != 0 ? e->r += write(1, "0x", 2) : 0;


		e->r += ft_putstr(tmp);
	}
	else
	{
		e->d > 0 && e->z == 0 ? e->r += write(1, "0", 1) : 0;
		e->d > 0 && e->z == 0 ? e->print += 1 : 0;
		if (e->pr > e->print)
		{
			while(e->pr > e->print)
			{
				e->r += write(1, "0", 1);
				e->pr--;
			}
		}
		e->w > e->pr && e->w > e->print && e->pr > 0 ? e->print++ : 0;
		e->r += ft_putstr(tmp);
		while (e->w > e->print || e->z > 0)
		{
			e->z > 0 ? write(1, "0", 1) : 0;
			e->z == 0 ? write(1, " ", 1) : 0;
			--e->w;
			e->r = e->r + 1;
		}
	}
	*i = *i + 1;

}

void	ft_is_p(int *i, t_en *e)
{
	long long int	v;
	char *tmp;

	v = va_arg(e->a, long long int);
	tmp = ft_uitoa_base(v, 16);
	e->print = ft_strlen(tmp) + 2;
	if (e->m == 0)
	{
		if (e->pr > e->w || (e->z != 0))
		{
			e->z != 0 ? e->print -= 1 : 0;
			e->r += ft_putstr("0x");
			//e->print -= 2;
			e->w != 0 || e->pr > e->print ? ft_print_w(e, 1) : 0;
			*tmp != '0' ? e->r += ft_putstr(tmp) : 0;

		}
		else
		{
			e->w != 0 || e->pr > e->print ? ft_print_w(e, 1) : 0;
			e->r += ft_putstr("0x");
			e->r += ft_putstr(tmp);
		}
		*i = *i + 1;
	}
	else
	{
		e->r += ft_putstr("0x");
		e->r += ft_putstr(tmp);
		e->w != 0 ? ft_nprint_w(e, 1) : 0;
		*i = *i + 1;
	}
	ft_ini(e);
}

void	ft_is_x(int *i, t_en *e)
{
	long long int		nb;
	char 	*tmp;
	int test = 0;

	e->c == 0 ? nb = va_arg(e->a, int) : 0;
	e->c == 'H' ? nb = (unsigned char)va_arg(e->a, int) : 0;
	e->c == 'h' ? nb = (unsigned short int)va_arg(e->a, int) : 0;
	e->c == 'l' ? nb = (unsigned long long int)va_arg(e->a, unsigned long long int) : 0;
	e->c == 'L' ? nb = (unsigned long long int)va_arg(e->a, unsigned long long int) : 0;
	e->c == 'j' ? nb = (uintmax_t)va_arg(e->a, uintmax_t) : 0;
	e->c == 'z' ? nb = (size_t)va_arg(e->a, size_t) : 0;
	if (e->c == 'L' || e->c == 'l' || e->c == 'z' || e->c == 'j')
		tmp = ft_uitoa_base(nb, 16);
	else
		tmp = ft_itoa_base(nb, 16);
	e->print = ft_strlen(tmp);
	//ft_nbrendl(e->print);
	if (e->m == 0)
	{
		// if (e->w > e->pr)
		// {
			if (e->w != 0 || e->d != 0 || e->pr > e->print)
			{
				e->s != 0 && e->z != 0 ? e->print += 1 : 0;
				e->z != 0 && e->w > (e->print - e->pr) && e->pr > 0 ? e->z = 0 : 0;
				if (e->d != 0 && (e->w <= e->print || e->w <= e->pr || e->z != 0) && nb != 0)
				{
					e->r += write(1, "0x", 2);
					e->print += 2;
				}
				else if (e->d != 0 && (e->w > e->print || e->w > e->pr ) && nb != 0)
				{
					test = 2;
					e->w -= 2;
				}
				while ((e->w > e->pr) && (e->w > e->print))
				{
				//ft_nbrendl(e->w);
				//ft_nbrendl(e->print);
					if (e->z > 0)
						write(1, "0", 1);
					else
						write(1, " ", 1);
					--e->w;
					e->r = e->r + 1;
				}
				if (test == 2)
				{
					e->r += write(1, "0x", 2);
					e->print += 2;
				}
			}
			if (e->d != 0 && e->w <= 0 && e->pr > e->print)
				e->print -= 2;
			while(e->pr > e->print)
			{
				e->r += write(1, "0", 1);
				e->pr--;
			}

		//}
		//e->d > 0 && e->z != 0 ? e->r += write(1, "0x", 2) : 0;

		e->r += ft_putstr_minimizer(tmp);
	}
	else
	{
		e->d > 0 && e->z == 0 ? e->r += write(1, "0x", 2) : 0;
		e->d > 0 && e->z == 0 ? e->print += 2 : 0;
		if (e->pr > e->print)
		{
			while(e->pr > e->print)
			{
				e->r += write(1, "0", 1);
				e->pr--;
			}
		}
		e->w > e->pr && e->w > e->print && e->pr > 0 ? e->print++ : 0;
		e->r += ft_putstr_minimizer(tmp);
		while (e->w > e->print || e->z > 0)
		{
			e->z > 0 ? write(1, "0", 1) : 0;
			e->z == 0 ? write(1, " ", 1) : 0;
			--e->w;
			e->r = e->r + 1;
		}
	}
	*i += 1;
}

void	ft_is_X(int *i, t_en *e)
{
	long long int		nb;
	char 	*tmp;

	e->c == 0 ? nb = va_arg(e->a, int) : 0;
	e->c == 'H' ? nb = (unsigned char)va_arg(e->a, int) : 0;
	e->c == 'h' ? nb = (unsigned short int)va_arg(e->a, int) : 0;
	e->c == 'l' ? nb = (unsigned long long int)va_arg(e->a, unsigned long long int) : 0;
	e->c == 'L' ? nb = (unsigned long long int)va_arg(e->a, unsigned long long int) : 0;
	e->c == 'j' ? nb = (uintmax_t)va_arg(e->a, uintmax_t) : 0;
	e->c == 'z' ? nb = (size_t)va_arg(e->a, size_t) : 0;
	if (e->c == 'L' || e->c == 'l' || e->c == 'z' || e->c == 'j')
		tmp = ft_uitoa_base(nb, 16);
	else
		tmp = ft_itoa_base(nb, 16);
	e->print = ft_strlen(tmp);
	if (e->m == 0)
	{
		if (e->w != 0 || e->d != 0 || e->pr > e->print)
		{
			e->s != 0 && e->z != 0 ? e->print += 1 : 0;
			e->z != 0 && e->w > (e->print - e->pr) && e->pr > 0 ? e->z = 0 : 0;
			if (e->d > 0 && nb != 0)
				e->r += write(1, "0X", 2);
			e->d > 0 && nb != 0 ? e->print += 2 : 0;
			while ((e->w > e->pr) && (e->w > e->print))
			{
			//ft_nbrendl(e->w);
			//ft_nbrendl(e->print);
				if (e->z > 0)
					write(1, "0", 1);
				else
					write(1, " ", 1);
				--e->w;
				e->r = e->r + 1;
			}
			if (e->d != 0 && e->w <= 0 && e->pr > e->print)
				e->print -= 2;
			while(e->pr > e->print)
			{
				e->r += write(1, "0", 1);
				e->pr--;
			}

		}
		//e->d > 0 && e->z != 0 ? e->r += write(1, "0x", 2) : 0;

		e->r += ft_putstr_capitalizer(tmp);
	}
	else
	{
		e->d > 0 && e->z == 0 ? e->r += write(1, "0X", 2) : 0;
		e->d > 0 && e->z == 0 ? e->print += 2 : 0;
		if (e->pr > e->print)
		{
			while(e->pr > e->print)
			{
				e->r += write(1, "0", 1);
				e->pr--;
			}
		}
		e->w > e->pr && e->w > e->print && e->pr > 0 ? e->print++ : 0;
		e->r += ft_putstr_capitalizer(tmp);
		while (e->w > e->print || e->z > 0)
		{
			e->z > 0 ? write(1, "0", 1) : 0;
			e->z == 0 ? write(1, " ", 1) : 0;
			--e->w;
			e->r = e->r + 1;
		}
	}
	*i = *i + 1;
}
void	ft_is_invalid(char *f, int *i, t_en *e)
{
	int i1;

	if (e->m == 0)
	{
		i1 = *i;
		//*i -= 1;
		e->r += (e->w > 0 ? e->w - 1 : e->w);
		while (--e->w > 0)
			e->z > 0 ? write(1, "0", 1) : write(1, " ", 1);
		// ft_nbrendl(*i);
		// ft_putendl(f);
		// ft_putchar(f[*i]);
		// ft_putendl("lele");
		e->r += ft_putchar(f[*i]);
		*i = *i + 1;
	}
	else
	{
		e->r += ft_putchar(f[*i]);
		e->r += (e->w > 0 ? e->w - 1 : e->w);
		while (--e->w > 0)
			e->z > 0 ? write(1, "0", 1) : write(1, " ", 1);
		*i = *i + 1;
	}
}

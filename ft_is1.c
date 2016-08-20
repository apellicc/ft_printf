#include "ft_printf.h"


void	ft_is_d(int *i, t_en *e)
{
	long long int		nb;
	long long int		tmp;
	e->c == 0 ? nb = va_arg(e->a, int) : 0;
	e->c == 'H' ? nb = (char)va_arg(e->a, int) : 0;
	e->c == 'h' ? nb = (short int)va_arg(e->a, int) : 0;
	e->c == 'l' ? nb = (long long int)va_arg(e->a, long long int) : 0;
	e->c == 'L' ? nb = (long long int)va_arg(e->a, long long int) : 0;
	e->c == 'j' ? nb = (intmax_t)va_arg(e->a, intmax_t) : 0;
	e->c == 'z' ? nb = (size_t)va_arg(e->a, size_t) : 0;
	e->print = ft_intlen(nb);
	e->r += e->print;
	e->p != 0 && nb < 0 ? e->p = 0 : 0;
	e->s != 0 && (nb < 0 || e->p != 0) ? e->s = 0 : 0;
	tmp = nb;
	e->p != 0 || e->s != 0 ? e->w-- : 0;
	e->s != 0 ? e->r += ft_putchar(' ') : 0;
	e->pr > e->print && nb < 0 ? e->print-- : 0;
	if (e->m == 0)
	{
		//ft_nbrendl(e->w);
		e->p != 0 && (e->w <= 0 || e->pr <= 0)? e->r += ft_putchar('+') : 0;
		if (nb < 0 && ((e->w <= e->pr) || e->z != 0))
		{
			ft_putchar('-');
			nb *= -1;
			e->w > 0 && e->z == 0 ? e->w-- : 0;
		}
		if (e->w > e->pr)
		{
			(e->w > e->pr && e->pr > e->print) && nb < 0 ? e->w-- : 0;
			while ((e->w > e->pr) && (e->w > e->print))
			{
				//ft_nbrendl(e->w);
				//ft_putchar('a');
				if (e->z > 0 && (e->w > e->pr && e->pr > 0) && tmp >= 0)
				{
				//	ft_putchar('b');
					write(1, " ", 1);
				}
				else if (e->z > 0)
					write(1, "0", 1);
				else
					write(1, " ", 1);
				--e->w;
				e->p != 0 && (e->w == e->pr) ? e->r += ft_putchar('+') : 0;

				e->r = e->r + 1;
			}
			if (nb < 0 && e->z == 0)
			{
				ft_putchar('-');
				nb *= -1;
				e->w > 0 ? e->w-- : 0;
			}
		}
		if (e->pr > e->print)
		{
			while(e->pr > e->print)
			{
				e->r += write(1, "0", 1);
				e->pr--;
			}
		}
		ft_putunsignedlongnbr(nb);
	}
	else
	{
		e->p != 0 ? e->r += ft_putchar('+') : 0;
		if (nb < 0)
   		{
   			ft_putchar('-');
   			nb =  nb * -1;
   		}
		if (e->pr > e->print)
		{
			while(e->pr > e->print)
			{
				e->r += write(1, "0", 1);
				e->pr--;
			}
		}
		e->w > e->pr && e->w > e->print && e->pr > 0 ? e->print++ : 0;
		ft_putunsignedlongnbr(nb);
		while (e->w > e->print || e->z > 0)
		{
			e->z > 0 ? write(1, "0", 1) : 0;
			e->z == 0 ? write(1, " ", 1) : 0;
			--e->w;
			e->r = e->r + 1;
		}
	}
	//ft_nbrendl(e->r);
	*i += 1;
}


void	ft_is_u(int *i, t_en *e)
{

	unsigned long long int		nb;

	e->c == 0 ? nb = va_arg(e->a, unsigned int) : 0;
	e->c == 'H' ? nb = (unsigned char)va_arg(e->a, int) : 0;
	e->c == 'h' ? nb = (unsigned short int)va_arg(e->a, unsigned int) : 0;
	e->c == 'l' ? nb = (unsigned long int)va_arg(e->a, unsigned long long  int) : 0;
	e->c == 'L' ? nb = (unsigned long long int)va_arg(e->a, unsigned long long int) : 0;
	e->c == 'j' ? nb = (uintmax_t)va_arg(e->a, uintmax_t) : 0;
	e->c == 'z' ? nb = (size_t)va_arg(e->a, size_t) : 0;
	e->print = ft_uintlen(nb);
	e->r += e->print;
	e->s != 0 ? e->s = 0 : 0;
	e->p != 0 ? e->p = 0 : 0;
	if (e->m == 0)
	{
		e->p != 0 && (e->w <= 0 || e->pr <= 0)? e->r += ft_putchar('+') : 0;
		if (e->w > e->pr)
		{
			while ((e->w > e->pr) && (e->w > e->print))
			{
				if (e->z > 0 && (e->w > e->pr && e->pr > 0))
					write(1, " ", 1);
				else if (e->z > 0)
					write(1, "0", 1);
				else
					write(1, " ", 1);
				--e->w;
				e->r = e->r + 1;
			}
		}
		if (e->pr > e->print)
		{
			while(e->pr > e->print)
			{
				e->r += write(1, "0", 1);
				e->pr--;
			}
		}
		ft_putunsignedlongnbr(nb);
	}
	else
	{
		e->p != 0 && e? e->r += ft_putchar('+') : 0;
		if (e->pr > e->print)
		{
			while(e->pr > e->print)
			{
				e->r += write(1, "0", 1);
				e->pr--;
			}
		}
		e->w > e->pr && e->w > e->print && e->pr > 0? e->print++ : 0;
		ft_putunsignedlongnbr(nb);
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


void	ft_is_O(int *i, t_en *e)
{
	unsigned long long int nb;

	nb = (unsigned long long int)va_arg(e->a, unsigned long long int);
	e->print = ft_strlen(ft_uitoa_base(nb, 8));
	if (e->m == 0)
	{
		(e->w != 0 || e->d != 0 || e->pr > e->print || e->d != 0) && nb != 0 ? ft_print_w(e, 1) : 0;
		e->r += ft_putstr(ft_uitoa_base(nb, 8));
		*i = *i + 1;
	}
	ft_ini(e);
}

void	ft_is_U(int *i, t_en *e)
{

	unsigned long long int		nb;

	nb = (unsigned long long int)va_arg(e->a, unsigned long long int);
	e->print = ft_uintlen(nb);
	if (e->m == 0)
	{
		e->w != 0 ? ft_print_w(e, 1) : 0;
		ft_putunsignedlongnbr(nb);
		e->r += ft_uintlen(nb);
		*i = *i + 1;
	}
	else
	{
		ft_putunsignedlongnbr(nb);
		e->r += e->print;
		e->w > e->print ? ft_nprint_w(e, e->print) : 0;
		*i = *i + 1;
	}
	ft_ini(e);
}

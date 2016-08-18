#include "ft_printf.h"


void	ft_is_d(int *i, t_en *e)
{

	long long int		nb;
		//ft_putendl("debut is d");
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
	e->s != 0 && nb < 0 ? e->s = 0 : 0;
	if (e->m == 0)
	{
		//printf("%ld valeur ")
		if ((nb < 0 && e->z != 0) )
		{
			(nb < 0 && e->z != 0) ? e->r -= 1 : 0;
			e->r += ft_putchar('-');
		//	ft_putendl("ici 2");
			nb =  nb * -1;
		}
		ft_print_w(e, nb);
		e->pr > e->print && nb < 0 ? e->r-- : 0;
		e->pr > e->print && nb < 0 ? nb *= -1 : 0;
		(e->z != 0 ) ? ft_putunsignedlongnbr(nb) : ft_putlongnbr(nb);
	//	e->r += w;
		*i = *i + 1;
	}
	else
	{
		if (nb < 0)
		{
			e->r += ft_putchar('-');
			nb =  nb * -1;
			//e->r -= 1;
			//e->print -= 1;
		}
		//printf("%ld valeur ")
		ft_putunsignedlongnbr(nb);
		//e->r += e->print;
		ft_nprint_w(e, e->print);
		*i = *i + 1;
	}
	ft_ini(e);
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
	if (e->m == 0)
	{
		e->w != 0 || e->pr > e->print ? ft_print_w(e, 1) : 0;
		ft_putunsignedlongnbr(nb);
		e->r += ft_uintlen(nb);
		*i = *i + 1;
	}
	else
	{
		//printf("%ld valeur ")
		ft_putunsignedlongnbr(nb);
		e->r += e->print;
		e->w > e->print ? ft_nprint_w(e, e->print) : 0;
		*i = *i + 1;
	}
	ft_ini(e);
}

void	ft_is_D(int *i, t_en *e)
{

	 long long		nb;

	nb = (long long)va_arg(e->a, long long);
	// e->c == 'H' ? nb = (char)va_arg(e->a, int) : 0;
	// e->c == 'h' ? nb = (short int)va_arg(e->a, int) : 0;
	// e->c == 'l' ? nb = (long int)va_arg(e->a, int) : 0;
	// e->c == 'L' ? nb = (long long int)va_arg(e->a, int) : 0;
	// e->c == 'j' ? nb = (int)va_arg(e->a, int) : 0;
	// e->c == 'z' ? nb = (size_t)va_arg(e->a, int) : 0;
	e->print = ft_intlen(nb);
	if (e->m == 0)
	{
		e->w != 0 ? ft_print_w(e, e->print) : 0;
		ft_putlongnbr(nb);
		e->r += ft_intlen(nb);
		*i = *i + 1;
	}
	else
	{
		//printf("%ld valeur ")
		ft_putlongnbr(nb);
		e->r += e->print;
		e->w > e->print ? ft_nprint_w(e, e->print) : 0;
		*i = *i + 1;
	}
	ft_ini(e);
}

void	ft_is_O(int *i, t_en *e)
{
	unsigned long long int nb;
	//ft_putendl("nique ta mere");
	nb = (unsigned long long int)va_arg(e->a, unsigned long long int);
	e->print = ft_strlen(ft_itoa_base(nb, 8));
	if (e->m == 0)
	{
		(e->w != 0 || e->d != 0 || e->pr > e->print) && nb != 0 ? ft_print_w(e, 1) : 0;
		e->r += ft_putstr(ft_itoa_base(nb, 8));
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
		//printf("%ld valeur ")
		ft_putunsignedlongnbr(nb);
		e->r += e->print;
		e->w > e->print ? ft_nprint_w(e, e->print) : 0;
		*i = *i + 1;
	}
	ft_ini(e);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 00:54:59 by apellicc          #+#    #+#             */
/*   Updated: 2016/08/09 02:24:23 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void 	ft_ini(t_en *e)
{
	e->c = 0;
	e->f = 0;
	e->w = 0;
	e->pr = 0;
	e->p = 0;
	e->d = 0;
	e->z = 0;
	e->m = 0;
	e->s = 0;
	e->print = 0;
}
void	ft_select_print(char *f, int *i, t_en *e)
{
	// ft_putendl("jejkek");
	// 	ft_putchar(e->c);
		//ft_putendl("ici select");
		e->f == 'D' || e->f == 'U' || e->f == 'O' ? e->c = 'L' : 0;
		e->f == 'D' ? e->f = 'd' : 0;
		e->f == 'U' ? e->f = 'u' : 0;
		e->f == 'O' ? e->f = 'o' : 0;
		// if (e->f == 'p')
		// {
		// 	//ft_nbrendl(e->z);
		// 	//ft_ini(e);
		// 	e->z = 0;
		// 	e->c = 'l';
		// 	//e->w > 0 ? e->z = 0 : 0;
		// 	//e->print -= 2;
		// 	//e->z != 0 ? e->print += 2 : 0;
		// 	e->f = 'x';
		// 	e->d = 1;
		// }

		e->f == 'v' ? ft_is_invalid(f, i, e) : 0;
		e->f == 'd' || e->f == 'i' ? ft_is_d(i, e) : 0;
	 	//e->f == 'D' ? ft_is_D(i, e) : 0;
	 	e->f == 'u' ? ft_is_u(i, e) : 0;
	 	e->f == 'o' ? ft_is_o(i, e) : 0;
		// 	e->f == 'O' ? ft_is_O(i, e) : 0;
	 	e->f == 'p' ? ft_is_p(i, e) : 0;
	 	e->f == 'x' ? ft_is_x(i, e) : 0;
	 	e->f == 'X' ? ft_is_X(i, e) : 0;
	 	e->f == 's' ? ft_is_s(i, e) : 0;
	 	e->f == 'c' ? ft_is_c(i, e) : 0;
		e->f == 'C' ? ft_is_C(i, e) : 0;
		e->f == 'S' ? ft_is_S(i, e) : 0;
	 	e->f == '%' ? ft_is_percent(i, e) : 0;
		//ft_putendl("ici select 2");
}

void	ft_check(char *f, int *i, t_en *e)
{
	(ft_strchr(" +-0#",f[*i])) ? ft_check_flag(f, i, e) : 0;
	ft_isdigit(f[*i]) == 1 ? ft_check_width(f, i, e) : 0;
	f[*i] == '.' ? ft_check_precision(f, i, e) : 0;
	(ft_strchr("hljz", f[*i])) ? ft_check_modify_type(f, i, e) : 0;

	ft_check_specifier(f, i, e);
	// (e->f == 's' || e->f == 'S' || e->f == 'p' || e->f == 'c' || e->f == 'C') ?
	// e->c = 0 : 0;
	e->f == 'p' ? e->c = 0 : 0;
	((e->f == 'o' || e->f == 'O') && e->d > 0 && e->pr < 0) ? e->pr = 0 : 0;
	e->pr < 0 && e->f != '%' ? *i += 1 : 0;
	//ft_putendl("ici");
	(e->pr >= 0) || (e->w > 0) || (e->f =='%') ? ft_select_print(f, i, e) : 0;
	//ft_putendl("ici2");
	((e->pr < 0) || (e->w <= 0)) && (e->f == 'c' && e->c != 'l') ? e->r++ : 0;
	//ft_putendl("ici3");
	ft_ini(e);
}

void	ft_parse(char *f, t_en *e)
{
	int		i;

	i = 0;
	while (f[i] != '\0')
	{
		if (f[i] != '%')
		{
			ft_putchar(f[i]);
			++e->r;
			i++;
		}
		else
		{
			++i;
			ft_check(f, &i, e);
		}
	}
}


int		ft_printf(const char *format, ...)
{
	t_en	*e;
	int		ret;
	char *tmp;


	tmp = (char *)format;
	e = (t_en *)malloc(sizeof(t_en));
	e->r = 0;
	ft_ini(e);
	va_start(e->a, format);
	ft_parse(tmp, e);
	va_end(e->a);
	ret = e->r;
	free(e);
	return (ret);
}

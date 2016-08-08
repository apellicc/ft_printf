/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/08 00:54:59 by apellicc          #+#    #+#             */
/*   Updated: 2016/08/08 14:54:01 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_check_flag(char *f, int *i, t_en *e)
{
	while ((f[*i] == '+' || f[*i] == '-' || f[*i] == ' ' || f[*i] == '0' ||
			f[*i] == '#') && f[*i] != '\0')
	{
		f[*i] == '+' ? e->p++ : NULL;
		f[*i] == '-' ? e->m++ : NULL;
		f[*i] == ' ' ? e->s++ : NULL;
		f[*i] == '0' ? e->z++ : NULL;
		f[*i] == '#' ? e->d++ : NULL;
		*i++;
	}
	e->m != 0 && e->z != 0 ? e->z = 0 : NULL;
	e->p != 0 && e->s != 0 ? e->s = 0 : NULL;
}
void	ft_check_width(char *f, int *i, t_en *e)
{
	f[*i] > -1 && f[*i] < 10 ? e->w = ft_atoi(&f[*i]) : NULL;
	e->w != 0 ? *i += ft_intlen(e->w) : NULL;
}
void	ft_check_precision(char *f, int *i, t_en *e)
{
	f[*i] == . && f[++*i] > -1 f[*i] < 10 ? e->pr = ft_atoi(&f[*i]) : NULL;
	*i += ft_intlen(e->pr);
}

void	ft_check_modify_type(char *f, int *i, t_en *e)
{
	f[*i] == 'j' ? e->c = 'j' : NULL;
	f[*i] == 'z' ? e->c = 'z' : NULL;
	f[*i] == 'l' ? e->c = 'l' : NULL;
	f[*i] == 'h' ? e->c = 'h' : NULL;
	f[*i] == 'h' && f[*i + 1]  == 'h' ? e->c = 'H' : NULL;
	f[*i] == 'l' && f[*i + 1]  == 'l' ? e->c = 'L' : NULL;
	e->c == 'H' || e->c == 'L' ? *i += 2 : NULL;
	e->c == 'j' || e->c == 'z' || e->c == 'l' || e->c == 'h' ? ++*i : NULL;
}

void	ft_check_specifier(char *f, int *i, t_en *e)
{
	e->f = ft_strchr("sSpdDioOuUxXcC", f[*i]);
	e->f != 0 ? ++*i : NULL;
}
void	ft_check(char *f, int *i, t_en *e)
{
	ft_check_flag(f, i, e);
	ft_check_width(f, i, e);
	ft_check_precision(f, i, e);
	ft_check_modify_type(f, i, e);
	ft_check_specifier(f, i, e);
	ft_check_priority(f, i, e);
	ft_print(f, i, e);
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
			++i;
		}
		else
			ft_check(f, &i, e);
	}
}

void	ft_ini(t_en *e)
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
}

int		ft_printf(const char *format, ...)
{
	t_en	*e;
	int		ret;
	
	e = (t_en *)malloc(sizeof(t_en));
	e->r = 0;
	ft_ini(e);
	va_start(e->a, format)
	ft_parse(format, e);
	va_end(e->a);
	ret = e->r;
	ft_free(e);
	return (ret);
}

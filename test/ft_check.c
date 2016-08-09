#include "ft_printf.h"

void	ft_check_flag(char *f, int *i, t_en *e)
{
	while ((f[*i] == '+' || f[*i] == '-' || f[*i] == ' ' || f[*i] == '0' ||
			f[*i] == '#') && f[*i] != '\0')
	{
		f[*i] == '+' ? e->p++ : 0;
		f[*i] == '-' ? e->m++ : 0;
		f[*i] == ' ' ? e->s++ : 0;
		f[*i] == '0' ? e->z++ : 0;
		f[*i] == '#' ? e->d++ : 0;
		*i = *i + 1;
	}
	e->m != 0 && e->z != 0 ? e->z = 0 : 0;
	e->p != 0 && e->s != 0 ? e->s = 0 : 0;
}

void	ft_check_width(char *f, int *i, t_en *e)
{
	f[*i] > -1 && f[*i] < 10 ? e->w = ft_atoi(&f[*i]) : 0;
	e->w != 0 ? *i += ft_intlen(e->w) : 0;
}

void	ft_check_precision(char *f, int *i, t_en *e)
{
	f[*i] == '.' && f[++*i] > -1 && f[*i] < 10 ? e->pr = ft_atoi(&f[*i]) : 0;
	*i += ft_intlen(e->pr);
}

void	ft_check_modify_type(char *f, int *i, t_en *e)
{
	f[*i] == 'j' ? e->c = 'j' : 0;
	f[*i] == 'z' ? e->c = 'z' : 0;
	f[*i] == 'l' ? e->c = 'l' : 0;
	f[*i] == 'h' ? e->c = 'h' : 0;
	f[*i] == 'h' && f[*i + 1]  == 'h' ? e->c = 'H' : 0;
	f[*i] == 'l' && f[*i + 1]  == 'l' ? e->c = 'L' : 0;
	e->c == 'H' || e->c == 'L' ? *i += 2 : 0;
	e->c == 'j' || e->c == 'z' || e->c == 'l' || e->c == 'h' ? ++*i : 0;
}

void	ft_check_specifier(char *f, int *i, t_en *e)
{
	e->f = *ft_strchr("sSpdDioOuUxXcC%", f[*i]);
}

#include "ft_printf.h"

void	ft_is_wc(int *i, t_en *e)
{
	wchar_t	value;

	value = va_arg(e->a, wchar_t);
	e->r += ft_putwchar(value);
	*i += 1;
}

static void	ft_is_ws2(int *tmp, wchar_t *value, t_en *e)
{
	int		t;
	int		test;

	test = 0;
	t = 0;
	if (e->pr < *tmp && e->pr > 0)
	{
		*tmp = ft_wcharlen(value[t]);
		while (e->pr >= *tmp)
		{
			value[t + 1] ? test = ft_wcharlen(value[t + 1]) : 0;
			if (test < e->pr && (e->w >= e->pr))
			{
				e->pr++;
				while ((--e->pr - test) != 0)
					e->r += ft_putchar(' ');
			}
			e->r += ft_putwchar(value[t]);
			((e->pr - *tmp) >= 0) ? e->pr -= *tmp : 0;
			t++;
			*tmp = ft_wcharlen(value[t]);
		}
	}
	else
		e->pr >= 0 ? e->r += ft_putswchar(value) : 0;
}

void	ft_is_ws(int *i, t_en *e)
{
	wchar_t	*value;
	int		tmp;

	value = va_arg(e->a, wchar_t *);
	if (e->m == 0)
	{
		if (!value)
			e->r += ft_putstr("(null)");
		else
		{
			tmp = ft_swcharlen(value);
			e->print += tmp;
			e->w != 0 || (e->pr > e->print) ? ft_print_w(e, 1) : 0;
			ft_is_ws2(&tmp, value, e);
		}
	}
	else
	{
		tmp = ft_swcharlen(value);
		ft_putswchar(value);
		e->print = tmp;
		e->r += tmp;
		e->w > tmp ? ft_nprint_w(e) : 0;
	}
	*i = *i + 1;
}

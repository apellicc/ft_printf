#include "ft_printf.h"

int		ft_wcharlen(wchar_t value)
{
	int i;
	unsigned int	mask1 = 49280;
	unsigned int	mask2 = 14712960;
	unsigned int	mask3 = 4034953344;
	unsigned int	v = value;
	int size = ft_strlen(ft_uitoa_base(value, 2));
	unsigned char octet;

	i = 0;
	if (size <= 7)
	{
		octet = value;
		i++;
	}
	else if (size <= 11)
	{
		unsigned char o2 = (v << 26) >> 26;
		unsigned char o1 = ((v >> 6) << 27) >> 27;

		octet = (mask1 >> 8) | o1;
		octet = ((mask1 << 24) >> 24) | o2;
		i += 2;
	}
	else if (size <= 16)
	{
		unsigned char o3 = (v << 26) >> 26;
		unsigned char o2 = ((v >> 6) << 26) >> 26;
		unsigned char o1 = ((v >> 12) << 28) >> 28;

		octet = (mask2 >> 16) | o1;
		octet = ((mask2 << 16) >> 24) | o2;
		octet = ((mask2 << 24) >> 24) | o3;
		i += 3;
	}
	else
	{
		unsigned char o4 = (v << 26) >> 26;
		unsigned char o3 = ((v >> 6) << 26) >> 26;
		unsigned char o2 = ((v >> 12) << 26) >> 26;
		unsigned char o1 = ((v >> 18) << 29) >> 29;

		octet = (mask3 >> 24) | o1;
		octet = ((mask3 << 8) >> 24) | o2;
		octet = ((mask3 << 16) >> 24) | o3;
		octet = ((mask3 << 24) >> 24) | o4;
		i += 4;
	}
	return (i);
}

int		ft_swcharlen(wchar_t *value)
{
	int		ret;
	int		t;

	t = 0;
	ret = 0;
	while (value[t])
	{
		ret += ft_wcharlen(value[t]);
		t++;
	}
	return (ret);
}

int		ft_putswchar(wchar_t *value)
{
	int		t;
	int		ret;

	ret = 0;
	t = 0;
	while (value[t])
	{
		ret += ft_putwchar(value[t]);
		t++;
	}
	return (ret);
}

int		ft_putwchar(wchar_t value)
{
	int i;
	i = 0;
	unsigned int mask1 = 49280;
	unsigned int mask2= 14712960;
	unsigned int mask3= 4034953344;
	unsigned int v = value;

	int size = ft_strlen(ft_uitoa_base(value, 2));
	unsigned char octet;

	if (size <= 7)
	{
		octet = value;
		i += write(1, &octet, 1);
	}
	else if (size <= 11)
	{
		unsigned char o2 = (v << 26) >> 26;
		unsigned char o1 = ((v >> 6) << 27) >> 27;

		octet = (mask1 >> 8) | o1;
		i += write(1, &octet, 1);
		octet = ((mask1 << 24) >> 24) | o2;
		i += write(1, &octet, 1);
	}
	else if (size <= 16)
	{
		unsigned char o3 = (v << 26) >> 26;
		unsigned char o2 = ((v >> 6) << 26) >> 26;
		unsigned char o1 = ((v >> 12) << 28) >> 28;

		octet = (mask2 >> 16) | o1;
		i += write(1, &octet, 1);
		octet = ((mask2 << 16) >> 24) | o2;
		i += write(1, &octet, 1);
		octet = ((mask2 << 24) >> 24) | o3;
		i += write(1, &octet, 1);
	}
	else
	{
		unsigned char o4 = (v << 26) >> 26;
		unsigned char o3 = ((v >> 6) << 26) >> 26;
		unsigned char o2 = ((v >> 12) << 26) >> 26;
		unsigned char o1 = ((v >> 18) << 29) >> 29;

		octet = (mask3 >> 24) | o1;
		i += write(1, &octet, 1);
		octet = ((mask3 << 8) >> 24) | o2;
		i += write(1, &octet, 1);
		octet = ((mask3 << 16) >> 24) | o3;
		i += write(1, &octet, 1);
		octet = ((mask3 << 24) >> 24) | o4;
		i += write(1, &octet, 1);
	}
	return (i);
}

void	ft_is_c2(int *i, t_en *e)
{
	wchar_t	value;

	value = va_arg(e->a, wchar_t);
	e->r += ft_putwchar(value);
	*i += 1;
}

void	ft_is_s2(int *i, t_en *e)
{
	wchar_t	*value;
	int		test;
	int		tmp;
	int		t;

	test = 0;
	t = 0;
	value = va_arg(e->a, wchar_t *);
	if (e->m == 0)
	{
		if (!value)
		{
			e->s = 0;
			e->r += ft_putstr("(null)");
		}
		else
		{
			tmp = ft_swcharlen(value);
			e->print += tmp;
			e->w != 0 || (e->pr > e->print) ? ft_print_w(e, 1) : 0;
			if (e->pr < tmp && e->pr > 0)
			{
				tmp = ft_wcharlen(value[t]);
				while (e->pr >= tmp)
				{
					value[t + 1] ? test = ft_wcharlen(value[t + 1]) : 0;
					if (test < e->pr && (e->w >= e->pr))
					{
						while ((e->pr - test) != 0)
						{
							e->r += ft_putchar(' ');
							e->pr--;
						}
					}
					e->r += ft_putwchar(value[t]);
					((e->pr - tmp) >= 0) ? e->pr -= tmp : 0;
					t++;
					tmp = ft_wcharlen(value[t]);
				}
			}
			else
				e->pr >= 0 ? e->r += ft_putswchar(value) : 0;
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

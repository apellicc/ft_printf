#include "ft_printf.h"

int		ft_putstr_capitalizer(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] > 96 && str[i] < 123)
			ft_putchar(str[i] - 32);
		else
			ft_putchar(str[i]);
	}
	return (i);
}

int		ft_putstr_minimizer(char *str)
{
	int i;

	i = -1;
	while (str[++i])
	{
		if (str[i] > 64 && str[i] < 91)
			ft_putchar(str[i] + 32);
		else
			ft_putchar(str[i]);
	}
	return (i);
}

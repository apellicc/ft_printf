#include "ft_printf.h"

char	*ft_convert(long int n, int base, char *str, int i)
{
	long int	div;
	char		temp;

	div = 1;
	if (n < 0)
	{
		n = -n;
		str[i] = '-';
		i++;
	}
	while (n / div >= base)
		div *= base;
	while (div > 0)
	{
		temp = '0' + n / div;
		if (temp > '9')
			str[i] = (temp + 39);
		else
			str[i] = temp;
		n %= div;
		div /= base;
		i++;
	}
	return (str);
}

char	*ft_itoa_base(long int n, int base)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(*str) * 12);
	i = 0;
	while (i < 12)
	{
		str[i] = '\0';
		i++;
	}
	i = 0;
	if (base != 10)
		return (ft_convert((unsigned int)n, base, str, i));
	else
		return (ft_convert(n, base, str, i));
}

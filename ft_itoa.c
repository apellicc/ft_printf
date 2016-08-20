#include "ft_printf.h"

char		*ft_uitoa_base(unsigned long long nb, int base)
{
	char	*str;
	int		size;
	unsigned long long		save;

	size = 1;
	save = nb;
	while (nb > (unsigned long long int)base - 1)
	{
		nb = nb / base;
		size++;
	}
	if (!(str = (char *)malloc(sizeof(*str) * (size + 1))))
		return (NULL);
	str[size] = '\0';
	while (size--)
	{
		str[size] = (save % base < 10) ? (save % base) + '0' : (save % base) - 10 + 'a';
		save = save / base;
	}
	return (str);
}
char	*ft_convert(long long int n, int base, char *str, int i)
{
	long long int	div;
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

char	*ft_itoa_base(long long int n, int base)
{
	char	*str;
	int		i;

	str = (char *)malloc(sizeof(*str) * 21);
	i = 0;
	while (i < 21)
	{
		str[i] = '\0';
		i++;
	}
	i = 0;
	if (base == 16)
		return (ft_convert((unsigned int)n, base, str, i));
	else if (base == 8)
		return (ft_convert((unsigned long long int)n, base, str, i));
	else
		return (ft_convert(n, base, str, i));
}

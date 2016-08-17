#include "libft.h"

int		ft_uintlen(unsigned long long int n)
{
	int	size;

	size = 0;
	while (n > 9)
	{
		n = n / 10;
		size++;
	}
	size++;
	return (size);
}

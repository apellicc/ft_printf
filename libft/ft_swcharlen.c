#include "libft.h"

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

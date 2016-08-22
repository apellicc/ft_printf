#include "libft.h"

static void	ft_wcharlen3(unsigned int v, int *i)
{
	unsigned char	o4;
	unsigned char	o3;
	unsigned char	o2;
	unsigned char	o1;
	unsigned char	octet;

	o4 = (v << 26) >> 26;
	o3 = ((v >> 6) << 26) >> 26;
	o2 = ((v >> 12) << 26) >> 26;
	o1 = ((v >> 18) << 29) >> 29;
	octet = ((unsigned int)MASK3 >> 24) | o1;
	*i += 1;
	octet = (((unsigned int)MASK3 << 8) >> 24) | o2;
	*i += 1;
	octet = (((unsigned int)MASK3 << 16) >> 24) | o3;
	*i += 1;
	octet = (((unsigned int)MASK3 << 24) >> 24) | o4;
	*i += 1;
}

static void	ft_wcharlen2(unsigned int v, int *i)
{
	unsigned char	o3;
	unsigned char	o2;
	unsigned char	o1;
	unsigned char	octet;

	o3 = (v << 26) >> 26;
	o2 = ((v >> 6) << 26) >> 26;
	o1 = ((v >> 12) << 28) >> 28;
	octet = ((unsigned int)MASK2 >> 16) | o1;
	*i += 1;
	octet = (((unsigned int)MASK2 << 16) >> 24) | o2;
	*i += 1;
	octet = (((unsigned int)MASK2 << 24) >> 24) | o3;
	*i += 1;
}

static void	ft_wcharlen1(unsigned int v, int *i)
{
	unsigned char	o2;
	unsigned char	o1;
	unsigned char	octet;

	o2 = (v << 26) >> 26;
	o1 = ((v >> 6) << 27) >> 27;
	octet = ((unsigned int)MASK1 >> 8) | o1;
	*i += 1;
	octet = (((unsigned int)MASK1 << 24) >> 24) | o2;
	*i += 1;
}

int		ft_wcharlen(wchar_t value)
{
	int				i;
	unsigned int	v;
	unsigned char	octet;
	int				size;
	char			*tmp;

	v = value;
	tmp = ft_uitoa_base(value, 2);
	i = 0;
	size = ft_strlen(tmp);
	free(tmp);
	if (size <= 7)
	{
		octet = value;
		i += 1;
	}
	else if (size <= 11)
		ft_wcharlen1(v, &i);
	else if (size <= 16)
		ft_wcharlen2(v, &i);
	else
		ft_wcharlen3(v, &i);
	return (i);
}

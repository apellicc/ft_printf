#include "ft_printf.h"

void	ft_is_invalid(char *f, int *i, t_en *e)
{
	int	i1;

	if (e->m == 0)
	{
		i1 = *i;
		e->r += (e->w > 0 ? e->w - 1 : e->w);
		while (--e->w > 0)
			e->z > 0 ? write(1, "0", 1) : write(1, " ", 1);
		e->r += ft_putchar(f[*i]);
		*i = *i + 1;
	}
	else
	{
		e->pr >= 0 ? e->r += ft_putchar(f[*i]) : 0;
		e->r += (e->w > 0 ? e->w - 1 : e->w);
		while (--e->w > 0)
			e->z > 0 ? write(1, "0", 1) : write(1, " ", 1);
		*i = *i + 1;
	}
}

#include "ft_printf.h"

void	ft_check2(t_en *e)
{
	e->c == 'h' && (e->s == 's' || e->s == 'S')
}

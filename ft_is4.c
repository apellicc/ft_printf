#include "ft_printf.h"
int		ft_putwchar(wchar_t value)
{

//	ft_putendl("kil");
	int i;
	i = 0;
//	unsigned int mask0 = 0;
 	unsigned int mask1 = 49280;
 	unsigned int mask2= 14712960;
 	unsigned int mask3= 4034953344;
 	unsigned int v = value;

 	int size = ft_strlen(ft_uitoa_base(value, 2));
	//ft_nbrendl(size);
 	unsigned char octet;

 	if (size <= 7)
 	{
 			octet = value;
 			i += write(1, &octet, 1);
 	}
 	else  if (size <= 11)
 	{
 			unsigned char o2 = (v << 26) >> 26; // recuperation des 6 premiers bits 110xxxxx 10(xxxxxx)
 			unsigned char o1 = ((v >> 6) << 27) >> 27; // recuperation des 5 derniers bits 110(xxxxx) 10xxxxxx

 			octet = (mask1 >> 8) | o1; // application des bits du premier octet sur le premier octet mask
 			i += write(1, &octet, 1);
 			octet = ((mask1 << 24) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
 			i += write(1, &octet, 1);
 	}
 	else  if (size <= 16)
 	{
 			unsigned char o3 = (v << 26) >> 26; // recuperation des 6 premiers bits 1110xxxx 10xxxxxx 10(xxxxxx)
 			unsigned char o2 = ((v >> 6) << 26) >> 26; // recuperation des 6 seconds bits 1110xxxx 10(xxxxxx) 10xxxxxx
 			unsigned char o1 = ((v >> 12) << 28) >> 28; // recuperation des 4 derniers bits 1110(xxxx) 10xxxxxx 10xxxxxx

 			octet = (mask2 >> 16) | o1; // application des bits du premier octet sur le premier octet mask
 			i += write(1, &octet, 1);
 			octet = ((mask2 << 16) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
 			i += write(1, &octet, 1);
 			octet = ((mask2 << 24) >> 24) | o3; // application des bits du troisieme octet sur le troisieme octet du mask
 			i += write(1, &octet, 1);
 	}
 	else
 	{
 			unsigned char o4 = (v << 26) >> 26; // recuperation des 6 premiers bits 11110xxx 10xxxxxx 10xxxxxx 10(xxxxxx)
 			unsigned char o3 = ((v >> 6) << 26) >> 26; // recuperation des 6 seconds bits 11110xxx 10xxxxxx 10(xxxxxx) 10xxxxxx
 			unsigned char o2 = ((v >> 12) << 26) >> 26;  // recuperation des 6 seconds bits 11110xxx 10(xxxxxx) 10xxxxxx 10xxxxxx
 			unsigned char o1 = ((v >> 18) << 29) >> 29; // recuperation des 3 seconds bits 11110(xxx) 10xxxxxx 10xxxxxx 10xxxxxx

 			octet = (mask3 >> 24) | o1; // application des bits du premier octet sur le premier octet mask
 			i += write(1, &octet, 1);
 			octet = ((mask3 << 8) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
 			i += write(1, &octet, 1);
 			octet = ((mask3 << 16) >> 24) | o3; // application des bits du troisieme octet sur le troisieme octet du mask
 			i += write(1, &octet, 1);
 			octet = ((mask3 << 24) >> 24) | o4; // application des bits du quatrieme octet sur le quatrieme octet du mask
 			i += write(1, &octet, 1);
	}
	return (i);
}
void	ft_is_C(int *i, t_en *e)
{
	wchar_t value;

	value = va_arg(e->a, wchar_t);
	e->r += ft_putwchar(value);
	//ft_nbrendl(e->r);
	*i += 1;
}
void  ft_is_S(int *i, t_en *e)
{
	wchar_t *value;

	value = NULL;
	int  t = 0;
	if (!(value = va_arg(e->a, wchar_t *)))
	{
		e->s = 0;
		//		ft_putendl("je suis ici");
	//	e->w != 0 || e->pr > e->print ? ft_print_w(e, 1) : 0;

		e->r += ft_putstr("(null)");
	}
	//ft_putendl("lol");
	while (value != NULL && value[t])
	{
		//ft_putendl("uxux");
		e->r += ft_putwchar(value[t]);
		t++;
	}
// 	ft_putendl("ici");
	*i += 1;
}

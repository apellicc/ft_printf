#include "ft_printf.h"
int		ft_wcharlen(wchar_t value)
{
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
			i++;
 	}
 	else  if (size <= 11)
 	{
 			unsigned char o2 = (v << 26) >> 26; // recuperation des 6 premiers bits 110xxxxx 10(xxxxxx)
 			unsigned char o1 = ((v >> 6) << 27) >> 27; // recuperation des 5 derniers bits 110(xxxxx) 10xxxxxx

 			octet = (mask1 >> 8) | o1; // application des bits du premier octet sur le premier octet mask
			octet = ((mask1 << 24) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
			i += 2;
	}
 	else  if (size <= 16)
 	{
 			unsigned char o3 = (v << 26) >> 26; // recuperation des 6 premiers bits 1110xxxx 10xxxxxx 10(xxxxxx)
 			unsigned char o2 = ((v >> 6) << 26) >> 26; // recuperation des 6 seconds bits 1110xxxx 10(xxxxxx) 10xxxxxx
 			unsigned char o1 = ((v >> 12) << 28) >> 28; // recuperation des 4 derniers bits 1110(xxxx) 10xxxxxx 10xxxxxx

 			octet = (mask2 >> 16) | o1; // application des bits du premier octet sur le premier octet mask
			octet = ((mask2 << 16) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
			octet = ((mask2 << 24) >> 24) | o3; // application des bits du troisieme octet sur le troisieme octet du mask
			i += 3;
	}
 	else
 	{
 			unsigned char o4 = (v << 26) >> 26; // recuperation des 6 premiers bits 11110xxx 10xxxxxx 10xxxxxx 10(xxxxxx)
 			unsigned char o3 = ((v >> 6) << 26) >> 26; // recuperation des 6 seconds bits 11110xxx 10xxxxxx 10(xxxxxx) 10xxxxxx
 			unsigned char o2 = ((v >> 12) << 26) >> 26;  // recuperation des 6 seconds bits 11110xxx 10(xxxxxx) 10xxxxxx 10xxxxxx
 			unsigned char o1 = ((v >> 18) << 29) >> 29; // recuperation des 3 seconds bits 11110(xxx) 10xxxxxx 10xxxxxx 10xxxxxx

 			octet = (mask3 >> 24) | o1; // application des bits du premier octet sur le premier octet mask
 			octet = ((mask3 << 8) >> 24) | o2; // application des bits du seond octet sur le second octet du mask
 			octet = ((mask3 << 16) >> 24) | o3; // application des bits du troisieme octet sur le troisieme octet du mask
 			octet = ((mask3 << 24) >> 24) | o4; // application des bits du quatrieme octet sur le quatrieme octet du mask
			i += 4;
	}
	return (i);
}
int		ft_swcharlen(wchar_t *value)
{
	int ret = 0;
	int t = 0;
	//ft_putendl("ici l 1");
	while (value[t])
	{
		//ft_putendl("ici l ");
	//	ft_nbrendl(t);
		//ft_putendl("uxux");
		ret += ft_wcharlen(value[t]);
		t++;
	}
	return (ret);
}
int		ft_putswchar(wchar_t *value)
{
	int t;
	int ret = 0;
	t = 0;
	while (value[t])
	{
		//ft_putendl("uxux");
		ret += ft_putwchar(value[t]);
		t++;
	}
	return (ret);
}
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
	int tmp;
	int  t = 0;
//ft_putendl("ici s");
value = va_arg(e->a, wchar_t *);
	if (e->m == 0)
	{
		if (!value)
		{
			e->s = 0;
			//		ft_putendl("je suis ici");
		//	e->w != 0 || e->pr > e->print ? ft_print_w(e, 1) : 0;

			e->r += ft_putstr("(null)");
		}
		// else
		// 	e->r += ft_putswchar(value);
		else
		{
			tmp = ft_swcharlen(value);
			e->print += tmp;
			//e->r += e->print;
			e->w != 0 || (e->pr > e->print)? ft_print_w(e, 1) : 0;
			// ft_nbrendl(e->w);
			// ft_nbrendl(e->pr);
				// ft_nbrendl(e->print);
				//ft_putendl("ici");
			if (e->pr < tmp && e->pr > 0)
			{
				tmp = ft_wcharlen(value[t]);
				while (e->pr >= tmp)
				{
					 e->r += ft_putwchar(value[t]);
					 e->pr -= tmp;
					 t++;
					 tmp = ft_wcharlen(value[t]);

				}
			//e->r += ft_putswchar(value);

				//ft_putendl("ici");
		}
		else
			e->pr >= tmp || e->pr == 0 ? e->r += ft_putswchar(value) : 0;

	}
	e->pr >= 0 ? *i = *i + 1 : 0;
}
	else
	{
		//ft_putendl("ici s2 ");
		tmp = ft_swcharlen(value);
		//ft_putendl("ici s3");
		ft_putswchar(value);
		e->print = tmp;
		e->r += tmp;
		e->w > tmp ? ft_nprint_w(e, tmp) : 0;
		*i = *i + 1;
	}
		//ft_putendl("lol");
		// while (value != NULL && value[t])
		// {
		// 	//ft_putendl("uxux");
		// 	e->r += ft_putwchar(value[t]);
		// 	t++;

}
// 	ft_putendl("ici");
	// *i += 1;

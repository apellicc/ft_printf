/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apellicc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/01 23:35:50 by apellicc          #+#    #+#             */
/*   Updated: 2015/12/01 23:37:42 by apellicc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strchr(char const *s, int c)
{
	int		i;
	char	*s1;

	i = 0;
	s1 = (char *)s;
	//ft_putendl("dans strchr");
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return (s1 + i);
		i++;
	}
	if (c == '\0')
		return (s1 + i);
//	ft_putendl("apres strchr");
	return (NULL);
}

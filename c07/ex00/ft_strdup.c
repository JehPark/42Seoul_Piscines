/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 12:19:53 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/06 13:05:44 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (*str)
	{
		str++;
		len++;
	}
	return (len);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;
	char	*dest_cp;

	len = ft_strlen(src);
	dest = (char *)malloc(len + 1);
	if (dest == 0)
		return ((char *)0);
	dest_cp = dest;
	while (*src)
		*dest_cp++ = *src++;
	*dest_cp = 0;
	return (dest);
}

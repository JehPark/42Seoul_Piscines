/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 11:48:27 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/12 22:55:24 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

char	*ft_strcat(char *dest, char *src)
{
	char *dest_cp;

	dest_cp = dest;
	while (*dest_cp)
		dest_cp++;
	while (*src)
		*dest_cp++ = *src++;
	*dest_cp = '\0';
	return (dest);
}

char	*ft_strncat(char *dest, char *src, int n)
{
	char	*dest_cp;
	int		i;

	i = 0;
	dest_cp = dest;
	while (*dest_cp)
		dest_cp++;
	while (*src && i < n)
	{
		*dest_cp++ = src[i];
		i++;
	}
	*dest_cp = '\0';
	return (0);
}

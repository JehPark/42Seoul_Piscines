/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:32:20 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/01 10:20:00 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

char	*ft_strcat(char *dest, char *src)
{
	char *dest_cp;

	dest_cp = dest;
	while (*dest_cp)
		dest_cp++;
	while (*src)
		*dest_cp++ = *src++;
	*dest_cp = 0;
	return (dest);
}

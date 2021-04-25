/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 14:36:19 by jehpark           #+#    #+#             */
/*   Updated: 2021/03/31 13:19:23 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	char *dest_copy;

	dest_copy = dest;
	while (*src)
	{
		*dest_copy++ = *src++;
	}
	*dest_copy = '\0';
	return (dest);
}

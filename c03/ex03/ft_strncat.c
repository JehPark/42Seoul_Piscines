/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 13:32:20 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/01 10:21:07 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	char			*dest_copy;
	unsigned int	i;

	i = 0;
	dest_copy = dest;
	while (*dest_copy)
		dest_copy++;
	while (i < nb && *src)
	{
		*dest_copy = *src;
		dest_copy++;
		src++;
		i++;
	}
	*dest_copy = '\0';
	return (dest);
}

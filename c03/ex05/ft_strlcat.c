/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 20:27:04 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/05 12:10:35 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	count;

	count = 0;
	while (*dest && count < size)
	{
		dest++;
		count++;
	}
	while (count + 1 < size && *src)
	{
		*dest++ = *src++;
		count++;
	}
	if (count < size)
		*dest = 0;
	while (*src)
	{
		src++;
		count++;
	}
	return (count);
}

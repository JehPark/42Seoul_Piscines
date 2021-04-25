/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:35:56 by jehpark           #+#    #+#             */
/*   Updated: 2021/03/31 17:43:37 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int idx;

	idx = 0;
	if (size == 0)
	{
		while (src[idx])
			idx++;
		return (idx);
	}
	while (src[idx] && idx < size - 1)
	{
		dest[idx] = src[idx];
		idx++;
	}
	if (idx < size)
		dest[idx] = '\0';
	while (src[idx])
		idx++;
	return (idx);
}

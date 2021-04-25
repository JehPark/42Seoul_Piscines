/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 17:03:26 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/04 17:22:25 by jehpark          ###   ########.fr       */
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

char	*ft_strcpy(char *dest, char *src)
{
	char *temp;

	temp = dest;
	while (*src)
		*temp++ = *src++;
	*temp = 0;
	return (dest);
}

char	*ft_strcat(char *dest, char *src)
{
	char *temp;

	temp = dest;
	while (*temp)
		temp++;
	while (*src)
		*temp++ = *src++;
	*temp = 0;
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		len;
	int		seplen;
	int		idx;
	char	*ans;

	if (size == 0)
		return ((char *)malloc(size * sizeof(char)));
	idx = 0;
	len = 0;
	while (idx < size)
		len += ft_strlen(strs[idx++]);
	seplen = ft_strlen(sep);
	ans = (char *)malloc((size - 1) * seplen + len + 1);
	ft_strcpy(ans, strs[0]);
	idx = 1;
	while (idx < size)
	{
		ft_strcat(ans, sep);
		ft_strcat(ans, strs[idx++]);
	}
	return (ans);
}

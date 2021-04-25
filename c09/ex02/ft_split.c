/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 19:23:28 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/10 13:50:28 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int g_sep[256];

void	ft_mksep(char *sep)
{
	int idx;

	idx = 0;
	while (idx < 256)
		g_sep[idx++] = 0;
	while (*sep)
		g_sep[(int)(unsigned char)*sep++] = 1;
}

int		ft_issep(char ch)
{
	if (g_sep[(int)(unsigned char)ch] == 1)
		return (1);
	return (0);
}

int		ft_wordcnt(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		if (!ft_issep(*str))
		{
			count++;
			while (*str && !ft_issep(*str))
				str++;
		}
		else
			str++;
	}
	return (count);
}

char	*ft_strcpy(char *dest, char *start, char *end)
{
	char	*dest_cp;

	dest_cp = dest;
	while (start != end)
		*dest_cp++ = *start++;
	*dest_cp = 0;
	return (dest);
}

char	**ft_split(char *str, char *charset)
{
	char	*start;
	char	*word;
	int		idx;
	char	**ans;

	idx = 0;
	ft_mksep(charset);
	ans = (char **)malloc(sizeof(char *) * (ft_wordcnt(str) + 1));
	while (*str)
	{
		if (!ft_issep(*str))
		{
			start = str;
			while (*str && !ft_issep(*str))
				str++;
			word = (char *)malloc(str - start + 1);
			ans[idx++] = ft_strcpy(word, start, str);
		}
		else
			str++;
	}
	ans[idx] = 0;
	return (ans);
}

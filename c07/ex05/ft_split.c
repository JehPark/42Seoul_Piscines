/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 21:04:48 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/07 17:53:57 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	g_sep[256];

void	ft_sepmk(char *charset)
{
	int				idx;
	unsigned char	*temp;

	idx = 0;
	temp = (unsigned char *)charset;
	while (idx < 256)
		g_sep[idx++] = 0;
	while (*temp)
		g_sep[(int)*temp++] = 1;
}

int		ft_issep(char ch)
{
	int				idx;
	unsigned char	tmp;

	idx = 0;
	tmp = (unsigned char)ch;
	if (g_sep[(int)tmp] == 1)
		return (1);
	return (0);
}

int		ft_wordcount(char *str)
{
	int	count;

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

void	ft_strcpy(char *dest, char *start, char *end)
{
	while (start != end)
		*dest++ = *start++;
	*dest = '\0';
}

char	**ft_split(char *str, char *charset)
{
	char	*start;
	int		n_word;
	char	**ans;
	int		idx;

	ft_sepmk(charset);
	n_word = ft_wordcount(str);
	ans = (char **)malloc((n_word + 1) * sizeof(char *));
	idx = 0;
	while (*str)
	{
		if (!ft_issep(*str))
		{
			n_word = 0;
			start = str;
			while (*str && !ft_issep(*str))
				str++;
			ans[idx] = (char *)malloc(str - start + 1);
			ft_strcpy(ans[idx++], start, str);
		}
		else
			str++;
	}
	ans[idx] = (char *)(0);
	return (ans);
}

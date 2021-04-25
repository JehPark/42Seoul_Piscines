/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/29 14:28:35 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/01 10:30:58 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(char *str, char *to_find)
{
	char	*finder;
	char	*ans;
	char	*word;

	if (!*to_find)
		return (str);
	finder = str;
	word = to_find;
	while (*finder)
	{
		ans = finder;
		while (*word && *finder == *word)
		{
			finder++;
			word++;
		}
		if (*word == 0)
			return (ans);
		word = to_find;
		if (!*finder)
			break ;
		finder++;
	}
	return (0);
}

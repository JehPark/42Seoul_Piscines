/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 18:10:11 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/03 13:45:57 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_lower(char c)
{
	if (c >= 'a' && c <= 'z')
	{
		return (1);
	}
	return (0);
}

int		ft_is_upper(char c)
{
	if (c >= 'A' && c <= 'Z')
	{
		return (1);
	}
	return (0);
}

int		ft_is_number(char c)
{
	if ('0' <= c && '9' >= c)
	{
		return (1);
	}
	return (0);
}

int		ft_is_char(char c)
{
	if (ft_is_upper(c) || ft_is_lower(c) || ft_is_number(c))
	{
		return (1);
	}
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int idx;

	idx = 0;
	if (idx == 0 && ft_is_lower(str[idx]))
		str[idx] -= 32;
	idx++;
	while (str[idx])
	{
		if (ft_is_lower(str[idx]) && !ft_is_char(str[idx - 1]))
			str[idx] -= 32;
		else if (ft_is_upper(str[idx]) && ft_is_char(str[idx - 1]))
			str[idx] += 32;
		idx++;
	}
	return (str);
}

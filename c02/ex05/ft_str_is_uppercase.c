/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:03:27 by jehpark           #+#    #+#             */
/*   Updated: 2021/03/28 16:17:56 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_uppercase_checker(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] > 'Z' || str[idx] < 'A')
		{
			return (0);
		}
		idx++;
	}
	return (1);
}

int		ft_str_is_uppercase(char *str)
{
	if (ft_uppercase_checker(str))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

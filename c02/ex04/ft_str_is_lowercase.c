/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:03:27 by jehpark           #+#    #+#             */
/*   Updated: 2021/03/28 16:13:50 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_lowercase_checker(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] > 'z' || str[idx] < 'a')
		{
			return (0);
		}
		idx++;
	}
	return (1);
}

int		ft_str_is_lowercase(char *str)
{
	if (ft_lowercase_checker(str))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

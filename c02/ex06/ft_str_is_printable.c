/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 16:23:10 by jehpark           #+#    #+#             */
/*   Updated: 2021/03/28 16:36:07 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_printable_checker(char *str)
{
	int idx;

	idx = 0;
	while (str[idx] != '\0')
	{
		if (str[idx] < ' ' || str[idx] > 127)
		{
			return (0);
		}
		idx++;
	}
	return (1);
}

int		ft_str_is_printable(char *str)
{
	if (ft_str_printable_checker(str))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

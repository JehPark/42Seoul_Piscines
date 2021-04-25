/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 15:31:50 by jehpark           #+#    #+#             */
/*   Updated: 2021/03/28 16:01:19 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_checker(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if ((str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z'))
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int		ft_str_is_alpha(char *str)
{
	if (ft_str_checker(str))
	{
		return (1);
	}
	else
	{
		return (0);
	}
}

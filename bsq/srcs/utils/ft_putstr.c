/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 16:58:41 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/11 16:59:28 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

void	ft_putstr(char *str)
{
	while (*str)
	{
		write(1, str++, 1);
	}
}

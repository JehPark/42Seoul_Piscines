/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_msg.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/11 12:28:52 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/11 14:36:23 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "func.h"

void	ft_error_msg(void)
{
	write(1, "map error\n", 10);
}

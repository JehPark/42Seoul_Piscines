/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:26:50 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/01 14:30:50 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_factorial(int nb)
{
	int	ans;

	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	ans = 1;
	while (nb - 1)
		ans *= nb--;
	return (ans);
}

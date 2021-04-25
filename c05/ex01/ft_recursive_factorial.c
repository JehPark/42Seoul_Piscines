/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/01 14:31:35 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/01 14:58:06 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int ans;

	if (nb == 0)
		return (1);
	if (nb < 0)
		return (0);
	ans = ft_recursive_factorial(nb - 1) * nb;
	return (ans);
}

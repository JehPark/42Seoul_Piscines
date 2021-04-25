/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/28 12:44:54 by jehpark           #+#    #+#             */
/*   Updated: 2021/03/28 13:48:04 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *tab, int i, int j)
{
	int temp;

	temp = tab[i];
	tab[i] = tab[j];
	tab[j] = temp;
}

int		ft_partition(int *tab, int low, int high)
{
	int pivot;
	int i;
	int j;

	pivot = tab[high];
	j = low;
	i = low - 1;
	while (j <= high - 1)
	{
		if (tab[j] < pivot)
		{
			i++;
			ft_swap(tab, i, j);
		}
		j++;
	}
	ft_swap(tab, i + 1, high);
	return (i + 1);
}

void	ft_quicksort(int *tab, int low, int high)
{
	int divisor;

	if (low < high)
	{
		divisor = ft_partition(tab, low, high);
		ft_quicksort(tab, low, divisor - 1);
		ft_quicksort(tab, divisor + 1, high);
	}
}

void	ft_sort_int_tab(int *tab, int size)
{
	int high;
	int low;

	high = size - 1;
	low = 0;
	ft_quicksort(tab, low, high);
}

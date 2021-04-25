/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jehpark <jehpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/04 09:56:27 by jehpark           #+#    #+#             */
/*   Updated: 2021/04/05 12:33:54 by jehpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	g_minuscount;

int					ft_isspace(unsigned char c)
{
	if (c == '\f' || c == '\v' || c == ' ')
		return (1);
	else if (c == '\n' || c == '\r' || c == '\t')
		return (1);
	return (0);
}

int					ft_basechecker(unsigned char *ubase)
{
	int				len;
	int				checker[256];
	int				i;

	i = 0;
	while (i < 256)
		checker[i++] = 0;
	len = 0;
	while (*ubase)
	{
		if (checker[(int)*ubase] == 1)
			return (0);
		if (ft_isspace(*ubase) || *ubase == '+' || *ubase == '-')
			return (0);
		checker[(int)*ubase] = 1;
		ubase++;
		len++;
	}
	return (len);
}

unsigned char		*ft_strchecker(unsigned char *ustr, unsigned char *ubase)
{
	int	checker[256];
	int	i;

	g_minuscount = 0;
	while (ft_isspace(*ustr))
		ustr++;
	i = 0;
	while (i < 256)
		checker[i++] = 0;
	while (*ubase)
		checker[(int)*ubase++] = 1;
	while (!checker[(int)*ustr])
	{
		if (*ustr == '-' || *ustr == '+')
		{
			if (*ustr == '-')
				g_minuscount++;
		}
		else
			return (0);
		ustr++;
	}
	return (ustr);
}

long				ft_atoi(unsigned char *ustr, unsigned char *ubase, int len)
{
	int		checker[256];
	int		i;
	long	ans;

	i = 0;
	while (i < 256)
		checker[i++] = -1;
	i = 0;
	while (*ubase)
	{
		checker[(int)*ubase] = i;
		ubase++;
		i++;
	}
	ans = 0;
	while (checker[(int)*ustr] != -1)
	{
		ans *= len;
		ans += checker[(int)*ustr];
		ustr++;
	}
	return (ans);
}

int					ft_atoi_base(char *str, char *base)
{
	int				base_len;
	unsigned char	*num;
	int				flag;
	long			ans;

	base_len = ft_basechecker((unsigned char*)base);
	if (base_len == 0 || base_len == 1)
		return (0);
	num = ft_strchecker((unsigned char*)str, (unsigned char*)base);
	if (!num)
		return (0);
	flag = g_minuscount % 2 == 1 ? -1 : 1;
	ans = (ft_atoi(num, (unsigned char*)base, base_len) * flag);
	return ((int)ans);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgokce <bgokce@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:18:28 by bgokce            #+#    #+#             */
/*   Updated: 2022/02/23 20:10:01 by bgokce           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(char *str)
{
	int	i;
	int	pozitive;
	int	result;

	result = 0;
	pozitive = 1;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\r' && str[i] != '\n' && str[i] != '\t' && str[i] != '+')
		{
			if (str[i] == '-')
				pozitive *= -1;
			else if (str[i] >= '0' && str[i] <= '9')
				result = (str[i] - '0') + (result * 10);
			if (str[i] >= '0' && str[i] <= '9'
				&& !(str[i + 1] <= '9' && str[i + 1] >= '0'))
				break ;
		}
		i++;
	}
	return (result * pozitive);
}

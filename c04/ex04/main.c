/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgokce <bgokce@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/14 11:04:27 by bgokce            #+#    #+#             */
/*   Updated: 2022/02/17 16:09:08 by bgokce           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */
#include<stdio.h>

void	ft_putnbr_base(int nbr, char *base);

int	main(void)
{
	ft_putnbr_base(23457, "0123456789abcdef");
	return (0);
}

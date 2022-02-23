/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bgokce <bgokce@student.42kocaeli.com.tr>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 10:41:22 by bgokce            #+#    #+#             */
/*   Updated: 2022/02/23 11:39:23 by bgokce           ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = -1;
	while (
		str[++len]);
	return (len);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int	counter;
	unsigned int	dest_len;

	counter = 0;
	dest_len = ft_strlen(dest);
	while (src[counter] && counter < nb)
	{
		dest[dest_len] = src[counter];
		dest_len++;
		counter++;
	}
	dest[dest_len] = '\0';
	return (dest);
}

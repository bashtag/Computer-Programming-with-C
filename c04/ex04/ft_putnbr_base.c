#include <unistd.h>
#include <stdio.h>

int	ft_strlen(char *str)
{
	int	len;

	len = -1;
	while (
			str[++len]);
	return len;
}
void	ft_is_base_true(char *base, int *is_valid)
{
	int	i;
	int	j;

	if (*base == '\0' || *(base+1) == '\0')
		*is_valid = 0;
	i = 0;
	j = 0;
	while (base[i] != '\0')
	{
		if (base[i] == '+' && base[i] == '-')
			*is_valid = 0;
		while(base[j] != '\0')
		{
			if (i != j && base[j] == base[i])
				*is_valid = 0;
			j++;
		}
		i++;
	}
}

void	ft_nbr_base(int number, char *base)
{
	int	len;

	len = ft_strlen(base);
	if (nb == -2147483648)
	{
		write(1, "-", 1);
		write(1, "2", 1);
		nb = 147483648;
	}
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb > len - 1)
		ft_nbr_base(nb / len);
	write(1, &base[nb % len], 1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	is_valid;

	is_valid = 1;
	ft_is_base_true(base, &is_valid);
	if (!is_valid)
		return;
	ft_nbr_base();
}

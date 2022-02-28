int	ft_is_prime(int nb)
{
	int	flag;
	int	i;

	if (nb <= 1)
		return (0);
	flag = 1;
	i = 2;
	while (i < nb)
	{
		if (nb % i == 0)
			flag = 0;
		i++;
	}
	return (flag);
}

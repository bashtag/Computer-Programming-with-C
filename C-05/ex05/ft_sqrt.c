int	ft_sqrt(int nb)
{
	int	number;

	if (nb < 0)
		return (0);
	number = 0;
	while (number * number != nb)
	{
		number++;
		if (number * number > nb)
			return (0);
	}
	return (number);
}

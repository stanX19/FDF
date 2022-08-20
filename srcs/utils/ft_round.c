int ft_round(long double nbr)
{
	if (((int)(nbr * 10)) % 10 > 4)
		return ((int)(nbr + 1));
	return ((int)nbr);
}
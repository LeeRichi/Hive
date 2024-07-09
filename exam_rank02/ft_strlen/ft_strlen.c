int	ft_strlen(char *str)
{
	int i;

	while(str[i])
		i++;

	return (i);
}

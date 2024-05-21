char	*ft_strchar(char *content, char c)
{
	size_t	i;

	while (*content)
	{
		if (*content == 'c')
			return (*content);
		*content++;
	}
	

}
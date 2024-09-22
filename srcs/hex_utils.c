#include "../include/fdf.h"

int	is_hex(char *str)
{
	int		i;
	int		k;
	int		valid;
	char	*base;

	if (ft_strlen(str) <= 2 || (str[0] != '0' \
	&& (str[1] != 'x' || str[1] != 'X')))
		return (0);
	base = "0123456789abcdef";
	i = 1;
	while (str[++i])
	{
		valid = 0;
		k = -1;
		while (base[++k])
		{
			if (ft_tolower(str[i]) == base[k])
				valid = 1;
		}
		if (!valid)
			return (0);
	}
	return (1);
}

static int	dec_val(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == ft_tolower(c))
			return (i);
		i++;
	}
	return (-1);
}

int	hex_to_dec(char *hex)
{
	char			*base;
	unsigned int	dec;
	int				num;

	base = "0123456789abcdef";
	dec = 0;
	num = -1;
	while (hex[++num])
	{
		dec *= 16;
		dec += dec_val(hex[num], base);
	}
	return (dec);
}

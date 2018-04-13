#include "header.h"

int	parseparen(char **str)
{
	int		result;
	char	*s;

	s = *str;
	result = 0;
	if (*s == '(')
	{
		s++;
		result = parsesumsub(&s);
		s++;
	}
	else
	{
		while (*s >= '0' && *s <= '9')
		{
			result = result * 10 + (*s - '0');
			s++;
		}
	}
	*str = s;
	return (result);
}

int	parsemuldivmod(char **str)
{
	int		num1;
	char	*s;

	s = *str;
	num1 = parseparen(&s);
	while (*s == '*' || *s == '/' || *s == '%')
	{
		if (*s == '*')
		{
			s++;
			num1 = num1 * parseparen(&s);
		}
		else if (*s == '/')
		{
			s++;
			num1 = num1 / parseparen(&s);
		}
		else
		{
			s++;
			num1 = num1 % parseparen(&s);
		}
	}
	*str = s;
	return (num1);
}

int	parsesumsub(char **str)
{
	int		num1;
	char	*s;

	s = *str;
	num1 = parsemuldivmod(&s);
	while (*s == '+' || *s == '-')
	{
		if (*s == '+')
		{
			s++;
			num1 = num1 + parsemuldivmod(&s);
		}
		else
		{
			s++;
			num1 = num1 - parsemuldivmod(&s);
		}
	}
	*str = s;
	return (num1);
}

int	eval_expr(char *str)
{
	char *newstring;

	newstring = removespaces(str);
	return (parsesumsub(&newstring));
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		ft_putnbr(eval_expr(av[1]));
		ft_putchar('\n');
	}
	return (0);
}

#ifndef HEADER_H
# define HEADER_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putnbr(int nb);
char	*removespaces(char *str);

int		parsemuldivmod(char **str);
int		parseparen(char **str);
int		parsesumsub(char **str);

#endif

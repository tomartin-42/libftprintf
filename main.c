# include "libftprintf.h"

void ft_arg(char *c, ...)
{
	va_list arg;
	char	*w;

	va_start (arg, c);
	while (*c)
	{
		if (*c == '%')
			{
				w = va_arg (arg, char *);
				write (1, w, ft_strlen(w));
			}	
		else
			write (1, c, 1);
		c++;
	}
	va_end (arg);
}

int main (void)
{
	// -------------- %c --------------- 
	char	 cr = 'o';
 	printf ("AAA%-10cAAAAAA\n", cr);

	 // ------------- %s ---------------
	 char	*s = "WWWWWWWWWWWWW";
	 printf("----%s-----\n", s);

	 printf("[%s]\n", ft_change_base (999999, "1234567890abcdef", 16));
 
 return (1);
}
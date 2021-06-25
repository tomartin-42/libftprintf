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
	t_flags	flags;

	// -------------- %c --------------- 
	char	 cr = 'o';
 	printf ("AAA%-10cAAAAAA\n", cr);

	 // ------------- %s ---------------
	 char	*s = "WWWWWWWWWWWWW";
	 printf("----%s-----\n", s);

	 ft_init_flags (&flags);

	 printf ("%d %d %d %d %d %d %d\n ", flags.alig, flags.zero, flags.point, flags.pad, flags.space, flags.plus, flags.width);
	 flags.zero = true;
	 printf ("%d %d %d %d %d %d %d\n", flags.alig, flags.zero, flags.point, flags.pad, flags.space, flags.plus, flags.width);
	
 
 return (1);
}

# include "ft_printf.h"

int main (void)
{
	// -------------- %c --------------- 
	char	 cr = 'o';
 	printf ("AAA%-10cAAAAAA\n", cr);

	 // ------------- %s ---------------
	 char	*s = "WWWWWWWW";
	 printf("--%-10.3s--\n", s);

	 // ------------- %f ---------------
	 float	f = 123.45678;
	 int	n1 = -9;
	 int	n2 = -3;
	 printf("--%*.*f--\n", n1, n2, f);

	// printf ("%d %d %d %d %d %d %d\n ", flags.alig, flags.zero, flags.point, flags.pad, flags.space, flags.plus, flags.width);
	//flags.zero = true;
	//printf ("%d %d %d %d %d %d %d\n", flags.alig, flags.zero, flags.point, flags.pad, flags.space, flags.plus, flags.width);
	 char	c = 'O';
	// printf ("XX%-04*cXX%3.*c%03c\n", n1, c, n1, c, c);
	// ft_printf("XX%-04*cXX%3.*c%03c\n", n1, c, n1, c, c);
	char *str = "ABCDEF";
	//printf ("XX%10.2sXX%04.0cXX\n", str, c);
	//ft_printf ("XX%10.2sXX%04.0cXX\n", str, c);
	char *j;
	j = &c;
	printf ("XX%-23.12sXX\n", str);
	ft_printf ("XX%-23.12sXX\n", str);

 return (1);
}

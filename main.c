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
	 int	n2 = 2;
	 printf("--%*.*f--\n", n1, n2, f);

	// printf ("%d %d %d %d %d %d %d\n ", flags.alig, flags.zero, flags.point, flags.pad, flags.space, flags.plus, flags.width);
	//flags.zero = true;
	//printf ("%d %d %d %d %d %d %d\n", flags.alig, flags.zero, flags.point, flags.pad, flags.space, flags.plus, flags.width);
	 char	c = 'O';
	// printf ("XX%-04*cXX%3.*c%03c\n", n1, c, n1, c, c);
	// ft_printf("XX%-04*cXX%3.*c%03c\n", n1, c, n1, c, c);
	char *str = "ABCDEF" ;
	//printf ("XX%10.2sXX%04.0cXX\n", str, c);
	//ft_printf ("XX%10.2sXX%04.0cXX\n", str, c);
	char *j;
	j = &c;
	//printf ("XX%-0-0-0-0-0-0-0-0-0-0-0-0-0* kk\n", str);
	//printf ("XX%020pXX\n", j);
	//ft_printf ("XX%020pXX\n", j);
	int	d1 =-18;
	int d2 = -26;
	int x, y;
	x = printf ("XX%.15pXX\n",&n1);
	printf ("123456789012345678901234567890\n");
	y = ft_printf ("XX%.15pXX\n",&n1);
	printf ("***%d - %d***\n", x, y);
 return (1);
}

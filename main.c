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
	 int	n1 = 9;
	 int	n2 = 3;
	 printf("--%*.*f--\n", n1, n2, f);

	// printf ("%d %d %d %d %d %d %d\n ", flags.alig, flags.zero, flags.point, flags.pad, flags.space, flags.plus, flags.width);
	 //flags.zero = true;
	 //printf ("%d %d %d %d %d %d %d\n", flags.alig, flags.zero, flags.point, flags.pad, flags.space, flags.plus, flags.width);
	ft_printf("HOLA %06066eec 1234");
 
 return (1);
}

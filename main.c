# include "ft_printf.h"

int main (void)
{
	// -------------- %c --------------- 
	char	 cr = 'o';
 	printf ("AAA%-10cAAAAAA\n", cr);

	 // ------------- %s ---------------
	 char	*s = "WWWWWWWW";
	 printf("--%-10.3s--\n", s);


	// printf ("%d %d %d %d %d %d %d\n ", flags.alig, flags.zero, flags.point, flags.pad, flags.space, flags.plus, flags.width);
	 //flags.zero = true;
	 //printf ("%d %d %d %d %d %d %d\n", flags.alig, flags.zero, flags.point, flags.pad, flags.space, flags.plus, flags.width);
	ft_printf("HOLA %06066eec 1234");
 
 return (1);
}

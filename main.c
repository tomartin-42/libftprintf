# include "libftprintf.h"

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

	// printf ("%d %d %d %d %d %d %d\n ", flags.alig, flags.zero, flags.point, flags.pad, flags.space, flags.plus, flags.width);
	 //flags.zero = true;
	 //printf ("%d %d %d %d %d %d %d\n", flags.alig, flags.zero, flags.point, flags.pad, flags.space, flags.plus, flags.width);
	ft_printf("HOLA % ");
 
 return (1);
}

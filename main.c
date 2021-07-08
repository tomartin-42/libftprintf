# include "ft_printf.h"

int main (void)
{
	// -------------- %c --------------- 
	char	 cr = 'o';
 	//printf ("AAA%-10cAAAAAA\n", cr);

	 // ------------- %s ---------------
	 char	*s = "ABCDEFGHIJ";
	 //printf("--%-10.3s--\n", s);

	 // ------------- %f ---------------
	 float	f = 123.45678;
	 int	n1 = -9;
	 int	n2 = 2;
	 //printf("--%*.*f--\n", n1, n2, f);

	// printf ("%p %p %p %p %p %p %p\n ", flags.alig, flags.zero, flags.point, flags.pad, flags.space, flags.plus, flags.width);
	//flags.zero = true;
	//printf ("%p %p %p %p %p %p %p\n", flags.alig, flags.zero, flags.point, flags.pad, flags.space, flags.plus, flags.width);
	//char	str[]="ABCDEFG";
	char	c = 'O';
	//printf ("XX%cXX%3.*c%03c\n", c, n2, c, c);
	//ft_printf("XX%cXX%3.*c%03c\n", c, n2, c, c);
	//printf ("XX%10.2sXX%04.0cXX\n", str, c);
	//ft_printf ("XX%10.2sXX%04.0cXX\n", str, c);
	char *j;
	j = &c;
	//j = NULL;
	//printf ("XX%-0-0-0-0-0-0-0-0-0-0-0-0-0* kk\n", str);
	//printf ("%020.18pX\n", j);
	//ft_printf ("%020.18pX\n", j);
	int	d1 = 0;
	int d2 = -26;
	int *p = 0;
	int x, y;
	int h[11] = {-12,-23,-43,-5,-45,-54,-23,-12,-34, -8, -0};
	//printf ("%p\n", 7);
	//ft_printf ("%p\n", 7);
	//x = printf ("XX%pXX%-18.16pXX  %pXX  %20pXX%10pXX%2pXX%2pXX%2pXX%2pXX%pXX%pXX\n",&h[1],&h[2],&h[3],&h[4],&h[5],&h[6],&h[7],&h[8],&h[9],&h[10],&h[0]);
	
	//y = ft_printf ("XX%pXX%-18.16pXX  %pXX  %20pXX%10pXX%2pXX%2pXX%2pXX%2pXX%pXX%pXX\n",&h[1],&h[2],&h[3],&h[4],&h[5],&h[6],&h[7],&h[8],&h[9],&h[10],&h[0]);

	//x = printf ("%30.15x\n", d2);
	//printf ("123456789012345678901234567890\n");
	//y = ft_printf ("%30.15x\n", d2);
	//printf ("***%d - %d***\n", x, y);
	//x = printf("%-020.3sX\n", s);
	//y = ft_printf ("%-020.3sX\n", s);
	printf ("123456789012345678901234567890\n");
	x = printf("%-010.20%X\n");
	y = ft_printf ("%-010.20%X\n");
	printf ("123456789012345678901234567890\n");
	printf ("[[%d - %d]]\n", x, y);
 return (1);
}

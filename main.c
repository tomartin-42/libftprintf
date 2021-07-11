# include "ft_printf.h"

int main (void)
{/*
	// -------------- %c --------------- 
	char	 cr = 'o';
 	//printf ("AAA%-10cAAAAAA\n", cr);

	 // ------------- %s ---------------
	 char	*s = "hi low\0don't print me lol\0";
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
static char	a01;
static unsigned char a02;
static short a03;
static unsigned short a04;
static int a05;
static unsigned int a06;
static long a07;
static unsigned long a08;
static long long a09;
static unsigned long long a10;
static char *a11;
static void *a12;
int x, y;
//x = printf ("%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p\n",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);
//x = printf ("%010.5d\n", -216);
printf ("123456789012345678901234567890\n");
//y = ft_printf ("%010.5d\n", -216);
//y = ft_printf ("%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70p%70\np",&a01,&a02,&a03,&a04,&a05,&a06,&a07,&a08,&a09,&a10,&a11,&a12);

	int	d1 = 0;
	int d2 = -26;
	int *p = 0;
	int h[11] = {-12,-23,-43,-5,-45,-54,-23,-12,-34, -8, -0};
	//x = printf ("%p\n", 0);
	//y = ft_printf ("%p\n", 0);
	//x = printf ("XX%pXX%-18.16pXX  %pXX  %20pXX%10pXX%2pXX%2pXX%2pXX%2pXX%pXX%pXX\n",&h[1],&h[2],&h[3],&h[4],&h[5],&h[6],&h[7],&h[8],&h[9],&h[10],&h[0]);
	
	//y = ft_printf ("XX%pXX%-18.16pXX  %pXX  %20pXX%10pXX%2pXX%2pXX%2pXX%2pXX%pXX%pXX\n",&h[1],&h[2],&h[3],&h[4],&h[5],&h[6],&h[7],&h[8],&h[9],&h[10],&h[0]);

	//x = printf ("%30.15x\n", d2);
	//printf ("123456789012345678901234567890\n");
	//y = ft_printf ("%30.15x\n", d2);
	//printf ("***%d - %d***\n", x, y);
	//s = NULL;
	//y = printf("%-4k\n", 9648627);
	//y = ft_printf ("%.09s\n", s);
	//x = ft_printf("%-4k\n", 9648627);
	//y = ft_printf ("%-010.20%X\n");
	
	x = printf (" --0*%0*.0x-- \n", -21, LONG_MAX);
	y = ft_printf (" --0*%0*.0x-- \n", -21, LONG_MAX);
	
	//printf ("123456789012345678901234567890\n");
	printf ("[[%d - %d]]\n", x, y);
 return (1);*/

 	int		a = -4;
	int		b = 0;
	char	c = 'a';
	int		d = 2147483647;
	int		e = -2147483648;
	int		f = 42;
	int		g = 25;
	int		h = 4200;
	int		i = 8;
	int		j = -12;
	int		k = 123456789;
	int		l = 0;
	int		m = -12345678;
	char	*n = "abcdefghijklmnop";
	char	*o = "-a";
	char	*p = "-12";
	char	*q = "0";
	char	*r = "%%";
	char	*s = "-2147483648";
	char	*t = "0x12345678";
	char	*u = "-0";

	printf("Simple input test\n");
	ft_printf("Simple input test\n");
	printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j); //T2
	ft_printf("%i, %d, %d, %d, %d, %s, %c, %d, %u, %x, %X\n", i, j, k, l, m, n, c, c, j, j, j); //T2
	printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d); //T3
	ft_printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d\n", i, j, k, l, m, c, e, d); //T3
}

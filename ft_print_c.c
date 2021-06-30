#include "ft_printf.h"

void	ft_print_c (t_flags *flg, va_list *pf_arg)
{
	char	c;

	c = va_arg (*pf_arg, int);
	if (flg->width < 1 || flg->alig == true || flg->point == false)
		write (1, &c, 1);
	if (flg->alig == false && flg->width > 0 && flg->zero == false)
			ft_make_string_space (flg->width);
	else if (flg->zero == true && flg->alig == false && flg->width > 0)
	{
		ft_make_string_zero (flg->width);
		write (1, &c, 1);
	}
	else if (flg->alig == true && flg->width > 0)
		ft_make_string_space (flg->width);
}

// void	ft_print_c (t_flags *flg, va_list *pf_arg)
// {
// 	char	c;

// 	c = va_arg (*pf_arg, int);
// 	if (flg->width < 1 || flg->alig == true || flg->point == false)
// 		write (1, &c, 1);
// 	if (flg->alig == false && flg->width > 0 && flg->zero == false)
// 	{
// 		//if (flg->point == false)
// 		//{	
// 			//write (1, &c, 1);
// 			ft_make_string_space (flg->width);
// 		//}
// 		//else
// 		//{
// 		//	ft_make_string_space (flg->width);
// 		//	write (1, &c, 1);
// 		//}
// 	}
// 	else if (flg->zero == true && flg->alig == false && flg->width > 0)
// 	{
// 		ft_make_string_zero (flg->width);
// 		write (1, &c, 1);
// 	}
// 	else if (flg->alig == true && flg->width > 0)
// 	{
// 		//write (1, &c, 1);
// 		ft_make_string_space (flg->width);
// 	}
// }
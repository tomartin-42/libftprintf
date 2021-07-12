NAME = libftprintf.a

CFLAGS := -Wall -Wextra -Werror

CC := gcc

SRC = ft_init_flag.c \
				ft_itoa.c \
				ft_print_c.c \
				ft_print_d.c \
				ft_print_p.c \
				ft_print_por.c \
				ft_print_s.c \
				ft_print_u.c \
				ft_print_x.c \
				ft_print_xu.c \
				ft_printf.c \
				ft_procesing.c \
				ft_writes.c \
				utils.c \
				utils2.c \

BSRC = ./bonus/ft_init_flag_bonus.c \
				./bonus/ft_itoa_bonus.c \
				./bonus/ft_print_c_bonus.c \
				./bonus/ft_print_d_bonus.c \
				./bonus/ft_print_p_bonus.c \
				./bonus/ft_print_por_bonus.c \
				./bonus/ft_print_s_bonus.c \
				./bonus/ft_print_u_bonus.c \
				./bonus/ft_print_x_bonus.c \
				./bonus/ft_print_xu_bonus.c \
				./bonus/ft_printf_bonus.c \
				./bonus/ft_procesing_bonus.c \
				./bonus/ft_writes_bonus.c \
				./bonus/utils_bonus.c \
				./bonus/utils2_bonus.c \

OBJ = $(SRC:.c=.o)

BOBJ = $(BSRC:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	ar rc $(NAME) $?

bonus: $(BOBJ)
	ar rc $(NAME) $?

clean:
	rm -f $(OBJ) $(BOBJ)

fclean: clean
	rm -f $(NAME)

re: fclean clean all

.PHONY: all clean fclean re
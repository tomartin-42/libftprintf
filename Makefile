NAME = libftprintf.a

CFLAGS := -Wall -Wextra -Werror

CC := cc

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

OBJ = $(SRC:.c=.o)

all: $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJ)
	ar rc $(NAME) $?

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean clean all

.PHONY: all clean fclean re
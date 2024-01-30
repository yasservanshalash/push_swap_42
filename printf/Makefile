NAME = libftprintf.a

SRC = ft_printf.c ft_putchar.c ft_putdowncase_hex.c ft_putnbr.c ft_putpercentsign.c ft_putptr.c ft_putstr.c ft_putunsignedint.c ft_putupcase_hex.c

OBJS = $(SRC:.c=.o)

CC = cc

CFLAGS = -Wall -Wextra -Werror

RM = rm -rf

AR = ar crs

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

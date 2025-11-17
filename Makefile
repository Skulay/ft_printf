CC      = cc
CFLAGS  = -Wall -Wextra -Werror
NAME    = libftprintf.a
HEADER  = ft_printf.h
AR      = ar rcs
RM      = rm -f

SRCS = ft_printf.c \
		ft_printf_utils.c \
		ft_printf_utils_two.c

OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

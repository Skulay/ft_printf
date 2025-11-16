CC = cc
HEADER = ft_printf.h
CFLAGS = -Wall -Wextra -Werror
NAME = ft_printf.a
AR = ar rcs
RM = rm -f

SRCS = ft_printf.c \

OBJS = $(SRCS:.c=.o)
AR = ar rcs
RM = rm -f
.PHONY: all clean fclean re
all: $(NAME)
$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)
clean:
	$(RM) $(OBJS)
fclean: clean
	$(RM) $(NAME)
re: fclean all

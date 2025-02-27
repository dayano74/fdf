CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f
LIBFTDIR := libft/

SRCS := main.c \
		ft_draw.c \
		ft_readfile.c \
		ft_fdf_utils.c \

OBJS := $(SRCS:.c=.o)

INCLUDE := -L ./libft -lft

NAME := fdf

all : $(NAME)

$(NAME): $(OBJS)
		@make -C $(LIBFTDIR)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(INCLUDE)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		$(RM) $(OBJS)
		@make -C $(LIBFTDIR) clean

fclean : clean
		$(RM) $(OBJS) $(NAME)
		@make -C $(LIBFTDIR) fclean


re : fclean all

.PHONY : all clean fclean re

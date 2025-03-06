CC := cc
CFLAGS := -Wall -Wextra -Werror
RM := rm -f
LIBFTDIR := libft/
MINILIBXDIR := minilibx-linux/

SRCS := main.c \
		ft_deal_key.c \
		ft_draw.c \
		ft_draw_2.c \
		ft_fdf_utils.c \
		ft_free.c \
		ft_read_file.c \
		ft_calc_bounding_box.c \


OBJS := $(SRCS:.c=.o)

LDFLAGS := -L./libft -lft -L./minilibx-linux -lmlx_Linux -lXext -lX11 -lm

NAME := fdf

all : $(NAME)

$(NAME): $(OBJS)
		@make -C $(LIBFTDIR)
		@make -C $(MINILIBXDIR)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDFLAGS)

%.o: %.c
		$(CC) $(CFLAGS) -c $< -o $@

clean :
		$(RM) $(OBJS)
		@make -C $(LIBFTDIR) clean
		@make -C $(MINILIBXDIR) clean

fclean : clean
		$(RM) $(OBJS) $(NAME)
		@make -C $(LIBFTDIR) fclean
		@make -C $(MINILIBXDIR) clean



re : fclean all

.PHONY : all clean fclean re

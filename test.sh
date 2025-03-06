### error cases

./fdf test_maps/10-2.fdf
#double free or corruption (out)
#zsh: IOT instruction (core dumped)  ./fdf test_maps/10-2.fdf

./fdf test_maps/basictest.fdf
#munmap_chunk(): invalid pointer
#zsh: IOT instruction (core dumped)  ./fdf test_maps/basictest.fdf

# ============================

### for compile

ccw *.c -g -O0 -o fdf libft/libft.a minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm -ldl


ccw *.c -g -O0 -o fdf libft/libft.a minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm -ldl
ccw ft_deal_key.c  ft_fdf_utils.c  ft_readfile.c  main.c -g -O0 -o fdf libft/libft.a minilibx-linux/libmlx_Linux.a -lX11 -lXext -lm -ldl


valgrind --leak-check=full --track-origins=yes --show-leak-kinds=all ./fdf test_maps/20-60.fdf


mlx_put_image_to_window();

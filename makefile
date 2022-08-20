SRCDIR	= srcs/
FUNC	= functions/
UTILS	= utils/
MLXUTILS	= mlx_utils/
SHARED	= shared/
MAP		= map/
SRCS	=	$(addsuffix .c, \
		$(addprefix $(SRCDIR)ft_, \
			) \
		$(addprefix $(SRCDIR)$(FUNC)ft_, \
			)\
		$(addprefix $(SRCDIR)$(SHARED)ft_, \
			)\
		$(addprefix $(SRCDIR)$(UTILS)ft_, \
			round)\
		$(addprefix $(SRCDIR)$(MAP)ft_, \
			)\
		$(addprefix $(SRCDIR)$(MLXUTILS)ft_, \
			mlx_new_img mlx_pixel_put draw_line put_polygon))

OBJS	=	$(subst .c,.o,$(SRCS))

CC			= 	gcc
CFLAGS		=	-Wall -Wextra -Werror#-fsanitize=address
RM			=	rm -rf
TESTDIR		= so_long_tester
TESTGIT		= https://github.com/augustobecker/so_long_tester.git
MLX_LINUX	= -Lmlx_linux -lmlx_Linux -L/usr/lib -Imlx_linux -lXext -lX11 -lm -lz
MLX_MACOS	= -lmlx -I. -framework OpenGL -framework AppKit
NAME		= fdf

run: re
	./$(NAME) data/map1
all: $(NAME)

$(NAME): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) main.c -I. $(MLX_MACOS) -o $(NAME)
	
%.o: %.c
	$(CC) $(CFLAGS) -Imlx -I. -c $< -o $@
	@echo "\033[1A\033[2K\033[1A"
clean:
	@$(RM) $(OBJS)
	
fclean:	clean
	$(RM) $(NAME)
	$(RM) $(TESTDIR)
	$(RM) ./a.out
re:	fclean $(NAME)

test: $(TESTDIR)
	cd $(TESTDIR) && make && make fclean
$(TESTDIR):
	git clone $(TESTGIT)
.PHONY:			all clean fclean re .c.o
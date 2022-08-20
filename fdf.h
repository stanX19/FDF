#ifndef SO_LONG_HEADER_H
# define SO_LONG_HEADER_H
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <math.h>
# include <stdlib.h>
typedef struct	s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct	s_window
{

	t_img* img;
}				t_window;

typedef struct	s_cord
{
	int x;
	int y;
}				t_cord;

typedef struct	s_line
{
	t_cord c1;
	t_cord c2;
	double m;
	int c;
}				t_line;

void	ft_mlx_pixel_put(t_img *img, int x, int y, int color);
t_img*	ft_mlx_new_image(void* mlx, int x_size, int y_size);
void	ft_draw_line(t_img *img, t_cord c1, t_cord c2, int color);
int		ft_round(long double nbr);

#endif
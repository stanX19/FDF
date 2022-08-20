#include "fdf.h"
#include "stdio.h"
static void iter_x(t_img *img, t_cord c1, t_cord c2, int color)
{
	double	m;
	int		x;
	int		c;
	int		max_x;

	m = (double)(c2.y - c1.y) / (c2.x - c1.x);
	x = c1.x < c2.x? c1.x: c2.x;
	max_x = c1.x < c2.x? c2.x: c1.x;
	
	c = c1.x < c2.x? c1.y - m * x: c2.y - m * x;

	while (x <= max_x)
	{
		ft_mlx_pixel_put(img, x, ft_round(m * x + c), color);
		x++;
	}
}

static void iter_x2(t_img *img, t_cord c1, t_cord c2, int color)
{
	double	m;
	int		x;
	double	y;
	int		max_x;

	m = (double)(c2.y - c1.y) / (c2.x - c1.x);
	x = c1.x < c2.x? c1.x: c2.x;
	max_x = c1.x < c2.x? c2.x: c1.x;
	y = c1.x < c2.x? c1.y: c2.y;
	while (x <= max_x)
	{
		ft_mlx_pixel_put(img, x, ft_round(y), color);
		y += m;
		x++;
	}
	printf("\n%i | ", c2.y);
	printf("%d\n", ft_round(y));
}

static void iter_y(t_img *img, t_cord c1, t_cord c2, int color)
{
	double	m;
	int		y;
	int		c;
	int		max_y;

	m = (double)(c2.x - c1.x) / (c2.y - c1.y);
	y = c1.y < c2.y? c1.y: c2.y;
	max_y = c1.y < c2.y? c2.y: c1.y;
	
	c = c1.y < c2.y? c1.x - m * y: c2.x - m * y;

	while (y <= max_y)
	{
		ft_mlx_pixel_put(img, ft_round(m * y + c), y, color);
		y++;
	}
}

void ft_draw_line(t_img *img, t_cord c1, t_cord c2, int color)
{
	double m;

	m = (double)(c2.y - c1.y) / (c2.x - c1.x);
	if (m < 1.0 && m > -1.0)
		iter_x(img, c1, c2, color);
	else
		iter_y(img, c1, c2, color);
	iter_x2(img, c1, c2, 0x00FF00FF);
}
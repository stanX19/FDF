#include "fdf.h"

void ft_put_polygon(t_img *img, t_cord *cords, int length, int color)
{
	int i;

	i = 0;
	while (i < length - 1)
	{
		ft_draw_line(img, cords[i], cords[i + 1], color);
		i++;
	}
	ft_draw_line(img, cords[0], cords[i], color);
}
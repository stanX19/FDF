#include "fdf.h"

t_img* ft_mlx_new_image(void* mlx, int x_size, int y_size)
{
	t_img* img;

	img = malloc(sizeof(t_img));
	img->img = mlx_new_image(mlx, x_size, y_size);
	img->addr = mlx_get_data_addr(img->img, &(img->bits_per_pixel), &(img->line_length),
								&(img->endian));
	return (img);
}
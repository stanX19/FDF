
#include "stdio.h"
#include "fdf.h"

int	main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_img	*img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	img = ft_mlx_new_image(mlx, 1920, 1080);


	ft_draw_line(img, (t_cord){100,200}, (t_cord){1000, 100}, 0x00FFFFFF);

	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	
	
	mlx_loop(mlx);
}

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

	ft_put_polygon(img, (t_cord[11]){
		{10,10},
		{100,10},
		{100,100},
		{103,100},
		{10,130},
		{1000,10},
		{1020,100},
		{110,100},
		{110,10},
		{1010,10},
		{10,100}
		}, 11, 0xFFFFFF);

	mlx_put_image_to_window(mlx, mlx_win, img->img, 0, 0);
	
	
	mlx_loop(mlx);
}
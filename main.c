
#include "stdio.h"
#include "fdf.h"

int	main(void)
{
	void* mlx;
	void* mlx_win;

	mlx = mlx_init();
	if (!mlx)
	{
		printf("failed to mlx_init\n");
		return 0;
	}
	mlx_win = mlx_new_window(mlx, 1920, 1080, "Hello world!");
	mlx_loop(mlx);
	(void)mlx_win;
}
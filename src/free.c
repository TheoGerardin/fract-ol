#include "../include/fractol.h"

void	clean_up(t_fractol *fractol)
{
	mlx_destroy_image(fractol->mlx, fractol->image);
	mlx_destroy_window(fractol->mlx, fractol->win);
	mlx_loop_end(fractol->mlx);
	mlx_destroy_display(fractol->mlx);
	free(fractol->mlx);
}

int	close_hook(t_fractol *fractol)
{
	clean_up(fractol);
	exit(0);
	return (0);
}

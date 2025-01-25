#include "../include/fractol.h"

void	init_fractol(t_fractol *fractol, int width, int height)
{
	fractol->mlx = mlx_init();
	fractol->win = mlx_new_window(fractol->mlx, width, height, "Fractol");
	fractol->image = mlx_new_image(fractol->mlx, width, height);
	fractol->image_data = mlx_get_data_addr(fractol->image,
			&fractol->bits_per_pixel, &fractol->size_line, &fractol->endian);
	fractol->width = width;
	fractol->height = height;
	fractol->zoom = 1.0;
	fractol->x_offset = 0.0;
	fractol->y_offset = 0.0;
	fractol->max_iter = 100;
	fractol->julia_real = -0.7;
	fractol->julia_imag = 0.27015;
	fractol->fractal_type = 0;
}

void	fractal_type_init(t_fractol *fractol, char *a, char *b)
{
	if (fractol->fractal_type == 1)
	{
		fractol->julia_real = ft_atod(a);
		fractol->julia_imag = ft_atod(b);
	}
}

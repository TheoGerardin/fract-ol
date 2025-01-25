#include "../include/fractol.h"

void	draw_fractal(t_fractol *fractol)
{
	if (fractol->fractal_type == 0)
	{
		draw_mandelbrot(fractol);
	}
	else if (fractol->fractal_type == 1)
	{
		draw_julia(fractol);
	}
	else if (fractol->fractal_type == 2)
	{
		draw_tricorn(fractol);
	}
}

void	display_image(t_fractol *fractol)
{
	mlx_put_image_to_window(fractol->mlx, fractol->win, fractol->image, 0, 0);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
		i++;
	return (s1[i] - s2[i]);
}

void	print_usage(void)
{
	printf("Usage:\n./fractol (mandelbrot)\n\n OR\n\n");
	printf("./fractol julia (-2.0 >= n <= 2.0) (-2.0 >= n <= 2.0)\n\n OR\n\n");
	printf("./fractol tricorn\n");
}

#include "../include/fractol.h"

void	draw_mandelbrot(t_fractol *fractol)
{
	t_fractal_var	var;

	var.y = 0;
	while (var.y < fractol->height)
	{
		var.x = 0;
		while (var.x < fractol->width)
		{
			init_var(&var, fractol, var.x, var.y);
			calculate_iterations_mandelbrot(&var, fractol);
			put_color(fractol, var.x, var.y, var.color);
			var.x++;
		}
		var.y++;
	}
}

void	draw_julia(t_fractol *fractol)
{
	t_fractal_var	var;

	var.y = 0;
	while (var.y < fractol->height)
	{
		var.x = 0;
		while (var.x < fractol->width)
		{
			var.zx = (var.x - fractol->width / 2.0) * 4.0 / fractol->width
				/ fractol->zoom + fractol->x_offset;
			var.zy = (var.y - fractol->height / 2.0) * 4.0 / fractol->height
				/ fractol->zoom + fractol->y_offset;
			var.iter = 0;
			calculate_iterations_julia(&var, fractol);
			put_color(fractol, var.x, var.y, var.color);
			var.x++;
		}
		var.y++;
	}
}

void	draw_tricorn(t_fractol *fractol)
{
	t_fractal_var	var;

	var.y = 0;
	while (var.y < fractol->height)
	{
		var.x = 0;
		while (var.x < fractol->width)
		{
			init_var(&var, fractol, var.x, var.y);
			calculate_iterations_tricorn(&var, fractol);
			put_color(fractol, var.x, var.y, var.color);
			var.x++;
		}
		var.y++;
	}
}

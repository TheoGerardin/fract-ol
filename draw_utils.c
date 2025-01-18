#include "fractol.h"

void	init_var(t_fractal_var *var, t_fractol *fractol, int x, int y)
{
	var->zx = 0;
	var->zy = 0;
	var->cx = (x - fractol->width / 2.0) * 4.0 / fractol->width / fractol->zoom
		+ fractol->x_offset;
	var->cy = (y - fractol->height / 2.0) * 4.0 / fractol->height
		/ fractol->zoom + fractol->y_offset;
	var->iter = 0;
}

void	calculate_iterations_mandelbrot(t_fractal_var *var, t_fractol *fractol)
{
	while ((var->zx * var->zx + var->zy * var->zy < 4)
		&& (var->iter < fractol->max_iter))
	{
		var->tmp = var->zx * var->zx - var->zy * var->zy + var->cx;
		var->zy = 2 * var->zx * var->zy + var->cy;
		var->zx = var->tmp;
		var->iter++;
	}
	var->color = get_color(var->iter, fractol->max_iter);
}

void	calculate_iterations_julia(t_fractal_var *var, t_fractol *fractol)
{
	while ((var->zx * var->zx + var->zy * var->zy < 4)
		&& (var->iter < fractol->max_iter))
	{
		var->tmp = var->zx * var->zx - var->zy * var->zy + fractol->julia_real;
		var->zy = 2 * var->zx * var->zy + fractol->julia_imag;
		var->zx = var->tmp;
		var->iter++;
	}
	var->color = get_color(var->iter, fractol->max_iter);
}

void	calculate_iterations_tricorn(t_fractal_var *var, t_fractol *fractol)
{
	while ((var->zx * var->zx + var->zy * var->zy < 4)
		&& (var->iter < fractol->max_iter))
	{
		var->tmp = var->zx * var->zx - var->zy * var->zy + var->cx;
		var->zy = -2 * var->zx * var->zy + var->cy;
		var->zx = var->tmp;
		var->iter++;
	}
	var->color = get_color(var->iter, fractol->max_iter);
}

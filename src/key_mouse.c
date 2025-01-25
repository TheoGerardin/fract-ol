#include "../include/fractol.h"

void	zoom(t_fractol *fractol, double zoom_factor)
{
	fractol->zoom *= zoom_factor;
	draw_fractal(fractol);
	display_image(fractol);
}

void	move_view(t_fractol *fractol, double x_offset, double y_offset)
{
	fractol->x_offset += x_offset / fractol->zoom;
	fractol->y_offset += y_offset / fractol->zoom;
	draw_fractal(fractol);
	display_image(fractol);
}

int	key_hook(int keycode, t_fractol *fractol)
{
	if (keycode == 65307)
	{
		clean_up(fractol);
		exit(0);
	}
	else if (keycode == 97 || keycode == 65361)
	{
		move_view(fractol, -0.1, 0);
	}
	else if (keycode == 100 || keycode == 65363)
	{
		move_view(fractol, 0.1, 0);
	}
	else if (keycode == 115 || keycode == 65364)
	{
		move_view(fractol, 0, 0.1);
	}
	else if (keycode == 119 || keycode == 65362)
	{
		move_view(fractol, 0, -0.1);
	}
	return (0);
}

int	mouse_hook(int button, int x, int y, t_fractol *fractol)
{
	double	mouse_re;
	double	mouse_im;
	double	zoom_factor;

	mouse_re = (x - fractol->width / 2.0) * 4.0 / fractol->width / fractol->zoom
		+ fractol->x_offset;
	mouse_im = (y - fractol->height / 2.0) * 4.0 / fractol->height
		/ fractol->zoom + fractol->y_offset;
	if (button == 4)
		zoom_factor = 1.1;
	else if (button == 5)
		zoom_factor = 0.9;
	else
		return (0);
	fractol->zoom *= zoom_factor;
	fractol->x_offset = mouse_re - (x - fractol->width / 2.0) * 4.0
		/ fractol->width / fractol->zoom;
	fractol->y_offset = mouse_im - (y - fractol->height / 2.0) * 4.0
		/ fractol->height / fractol->zoom;
	draw_fractal(fractol);
	display_image(fractol);
	return (0);
}

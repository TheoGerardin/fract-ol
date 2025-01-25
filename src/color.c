#include "../include/fractol.h"

void	put_color(t_fractol *fractol, int x, int y, int color)
{
	if (x >= 0 && x < fractol->width && y >= 0 && y < fractol->height)
	{
		*(unsigned int *)(fractol->image_data + (y * fractol->size_line + x
					* (fractol->bits_per_pixel / 8))) = color;
	}
}

int	get_color(int iter, int max_iter)
{
	double	t;
	int		r;
	int		g;
	int		b;

	if (iter == max_iter)
		return (0);
	t = (double)iter / max_iter;
	r = (int)(9 * (1 - t) * t * t * t * 255);
	g = (int)(15 * (1 - t) * (1 - t) * t * t * 255);
	b = (int)(8.5 * (1 - t) * (1 - t) * (1 - t) * t * 255);
	return ((r << 16) | (g << 8) | b);
}

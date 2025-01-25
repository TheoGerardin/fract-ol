#include "../include/fractol.h"

int	ft_verif(char *a, char *b)
{
	if ((ft_atod(a) >= -2.0 && ft_atod(a) <= 2.0)
		&& (ft_atod(b) >= -2.0 && ft_atod(b) <= 2.0))
	{
		return (0);
	}
	else
	{
		return (1);
	}
}

int	main(int argc, char **argv)
{
	t_fractol	fractol;

	init_fractol(&fractol, 800, 800);
	if ((ft_strcmp(argv[1], "mandelbrot") == 0) && argc == 2)
		fractol.fractal_type = 0;
	else if ((ft_strcmp(argv[1], "julia") == 0) && argc == 4
		&& (ft_verif(argv[2], argv[3]) == 0))
		fractol.fractal_type = 1;
	else if ((ft_strcmp(argv[1], "tricorn") == 0) && argc == 2)
		fractol.fractal_type = 2;
	else
	{
		print_usage();
		clean_up(&fractol);
		return (1);
	}
	fractal_type_init(&fractol, argv[2], argv[3]);
	draw_fractal(&fractol);
	display_image(&fractol);
	mlx_key_hook(fractol.win, key_hook, &fractol);
	mlx_mouse_hook(fractol.win, mouse_hook, &fractol);
	mlx_hook(fractol.win, 17, 0, close_hook, &fractol);
	mlx_loop(fractol.mlx);
	clean_up(&fractol);
	return (0);
}

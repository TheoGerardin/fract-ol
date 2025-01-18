#ifndef FRACTOL_H
# define FRACTOL_H

# include <math.h>
# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

typedef struct s_fractol
{
	double	x_offset;
	double	y_offset;
	void	*mlx;
	void	*win;
	void	*image;
	char	*image_data;
	int		bits_per_pixel;
	int		size_line;
	int		endian;
	int		width;
	int		height;
	double	zoom;
	int		max_iter;
	double	julia_real;
	double	julia_imag;
	int		fractal_type;
}			t_fractol;

typedef struct s_fractal_var
{
	int		color;
	int		x;
	int		y;
	int		iter;
	double	zx;
	double	zy;
	double	cx;
	double	cy;
	double	tmp;
}			t_fractal_var;

void		put_color(t_fractol *fractol, int x, int y, int color);
int			get_color(int iter, int max_iter);

void		draw_mandelbrot(t_fractol *fractol);
void		draw_julia(t_fractol *fractol);
void		draw_tricorn(t_fractol *fractol);

void		init_var(t_fractal_var *var, t_fractol *fractol, int x, int y);
void		calculate_iterations_mandelbrot(t_fractal_var *var,
				t_fractol *fractol);
void		calculate_iterations_julia(t_fractal_var *var, t_fractol *fractol);
void		calculate_iterations_tricorn(t_fractal_var *var,
				t_fractol *fractol);

void		clean_up(t_fractol *fractol);
int			close_hook(t_fractol *fractol);

void		init_fractol(t_fractol *fractol, int width, int height);
void		fractal_type_init(t_fractol *fractol, char *a, char *b);

void		zoom(t_fractol *fractol, double zoom_factor);
void		move_view(t_fractol *fractol, double x_offset, double y_offset);
int			key_hook(int keycode, t_fractol *fractol);
int			mouse_hook(int button, int x, int y, t_fractol *fractol);

void		draw_fractal(t_fractol *fractol);
void		display_image(t_fractol *fractol);
int			ft_strcmp(char *s1, char *s2);
void		print_usage(void);

double		ft_atod(char *nbr);

#endif
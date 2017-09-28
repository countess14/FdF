#include "libft.h"
#include "mlx.h"
#include <stdio.h>

int ft_abs(int x)
{
	if (x < 0)
		return (-x);
	else
		return (x);
}

void seg(int xi,int yi,int xf,int yf)
{
  void *mlx;
	void *win;
	int dx;
	int dy;
	int i;
	int xinc;
	int yinc;
	int cumul;
	int x;
	int y;

  x = xi;
  y = yi;
  dx = xf - xi;
  dy = yf - yi;
  xinc = ( dx > 0 ) ? 1 : -1;
  yinc = ( dy > 0 ) ? 1 : -1;
  dx = ft_abs(dx);
  dy = ft_abs(dy);
	mlx = mlx_init();
	win = mlx_new_window(mlx, 500, 500, "ligne2");
	mlx_pixel_put(mlx, win, x, y, 0X00FF0000);
  if ( dx > dy )
	{
    cumul = (dx / 2);
		i = 1;
		while (i <= dx)
		{
      x += xinc;
      cumul += dy;
			i++;
      	if (cumul >= dx)
				{
        	cumul -= dx;
        	y += yinc;

				}
      mlx_pixel_put(mlx, win, x, y, 0X00FF0000);
		}
	}
  else
		{
    cumul = dy / 2;
		i = 1;
		while (i <= dy)
		{
      y += yinc ;
      cumul += dx;
      	if ( cumul >= dy)
					{
        		cumul -= dy;
        		x += xinc;
					}
      mlx_pixel_put(mlx, win, x, y, 0X00FF0000);
			i++;
		}
	}
	mlx_loop(mlx);
}





int main ()
{
	void *mlx;
	void *win;

	int xi;
	int yi;
	int xf;
	int yf;

	xi = 50;
	yi = 50;
	xf = 500;
	yf = 500;

	seg(xi, yi, xf, yf);
}

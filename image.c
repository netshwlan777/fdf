/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: poatmeal <poatmeal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 17:13:36 by rstarfir          #+#    #+#             */
/*   Updated: 2020/02/18 18:45:30 by poatmeal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		ft_close(void)
{
	exit(0);
	return (0);
}

int		key_press(int keycode, void *param)
{
	(void)param;
	if (keycode == 53)
		exit(0);
	return (0);
}

/*int		new_(t_map *map)
{
	
}*/

void	draw_matrix(t_map *map, t_mlx *tmp)
{
	t_point ps;
	t_point pf;
	int		n;
	int		i;
	int		j;

	i = 0;
	j = 0;
	n = 20;
	ps.y = 270;
	pf.y = ps.y;
	while (((pf.y - 270) < (map->y * n)) && (i < map->y))
	{
		j = 0;
		ps.x = 480;
		pf.x = ps.x + n;
		while (((pf.x - 480) <= (map->x * n)) && (j < map->x))
		{
			printf("1 = %x\n", tmp->img.clr);
			printf("2 = %x\n", map->map[i][j].color);
			//pf.z = map->map[i][j].height;
			if (map->map[i][j].color != -1)
				tmp->img.clr = map->map[i][j].color;
			else
				tmp->img.clr = 0xF07800;
			printf("3 = %x\n", tmp->img.clr);
			if ((pf.x - 480) < (map->x * n))
				drawline(tmp, &ps, &pf);
				//drawline(tmp, trans(&ps), trans(&pf));
			pf.x = ps.x;
			pf.y = ps.y + n;
			if ((pf.y - 270) < (map->y * n))
				drawline(tmp, &ps, &pf);
				//drawline(tmp, trans(&ps), trans(&pf));
			ps.x = ps.x + n;
			pf.x = pf.x + 2 * n;
			pf.y = pf.y - n;
			j++;
		}
		i++;
		ps.y = ps.y + n;
		pf.y = pf.y + n;
	}
}

/*void	draw_circle(t_mlx *tmp)
{
	t_point	ps;
	t_point pf;
	int		sectors = 60;
	int		radius = 270;
	double	alpha = 0, beta = 360;
	double	step = 360 / sectors;

	printf("enter starting angle: ");
	scanf("%lf", &alpha);
	printf("enter ending angle: ");
	scanf("%lf", &beta);

	ps.x = 960;
	ps.y = 540; //10
	pf.x = 960 + cos(alpha) * radius;
	pf.y = 540 + sin(alpha) * radius; // 200
	printf("%d	%d\n", pf.x, pf.y);
	drawline(tmp, &ps, &pf);
	while (alpha < beta)
	{
		alpha += step;
		pf.x = 960 + (cos(PI / 180 * alpha) * radius);
		pf.y = 540 - (sin(PI / 180 * alpha) * radius); // 200
		drawline(tmp, &ps, &pf);
	}
}
*/
int image_init(t_map *map)
{
	t_mlx	tmp;
	int		x;

	x = 1;
	tmp.img.clr = 0xF07800;
	tmp.mlx = mlx_init();
	tmp.wndw = mlx_new_window(tmp.mlx, WIDTH, HEIGHT, "FDF");
	tmp.img.img_ptr = mlx_new_image(tmp.mlx, WIDTH, HEIGHT);
	tmp.img.data = (int *)mlx_get_data_addr(tmp.img.img_ptr, &tmp.img.bpp, &tmp.img.size_l, &tmp.img.endian);
//	draw_circle(&tmp);
	draw_matrix(map, &tmp);
	mlx_put_image_to_window(tmp.mlx, tmp.wndw, tmp.img.img_ptr, 0, 0);
	//mlx_key_hook(tmp.wndw, key_press, &tmp);
	mlx_hook(tmp.wndw, 2, 0L, key_press, &tmp);
	mlx_hook(tmp.wndw, 17, 0L, ft_close, &tmp);
	mlx_loop(tmp.mlx);
	return (0);
}

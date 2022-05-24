/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mtoia <mtoia@student.42roma.it>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 11:21:32 by mtoia             #+#    #+#             */
/*   Updated: 2022/05/24 17:29:25 by mtoia            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef SO_H
# define SO_H
# include "mlx.h"
# include "mlx/mlx.h"
# include <stdlib.h>
# include <unistd.h>
# define MAXCOUNT 30
typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bit_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct	s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

enum {
	ESC = 53,
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

int fractaly(float left, float top, float xside, float yside);
int fractalx(float left, float top, float xside, float yside);
int	main();

#endif
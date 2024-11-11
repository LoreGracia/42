/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <lgracia-@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 11:20:09 by lgracia-          #+#    #+#             */
/*   Updated: 2024/11/11 20:01:23 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	fractol(char **argv)
{
	if (argv[1][0] == 'm')
	{
		if (mandelbrot(argv, PX_SIZE) == -1)
			return (-1);
	}
	else if (argv[1][0] == 'j')
	{
		//if (julia_t(img, 0, ft_atoi(argv[2])) == -1);
			return (-1);
	}
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	if (argv[1][0] == 'm' || argv[1][0] == 'j')
	{
		if (!argv[2] && argv[1][0] == 'm')
			return (write(2, "Try './fractol m 2'", 20), 0);
		else if (!argv[2] && argv[1][0] == 'p')
			return (write(2, "Try './fractol j 2'", 20), 0);
		if (argc > 2)
		{
			if (argv[3] || argv[1][1] || fractol(argv) == -1)
				return (ft_printf("%s\n", "EXIT_FAILURE"));
			else
				return (ft_printf("%s\n", "EXIT_SUCCESS"));
		}
	}
	if (argv[1][0] == 'p')
		panda();
	else if (argv[1][0] == 'l')
		line();
}

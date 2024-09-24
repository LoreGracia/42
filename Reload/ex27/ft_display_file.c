/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgracia- <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 16:37:22 by lgracia-          #+#    #+#             */
/*   Updated: 2024/06/16 19:45:48 by lgracia-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <fcntl.h>

void	print_file(const char *file)
{
	char	i;
	int		op;

	op = open(file, O_RDONLY);
	if (op == -1)
	{
		write (2, "Cannot read file.\n", 18);
		return ;
	}
	while (read(op, &i, sizeof(i)) != 0)
		write (1, &i, 1);
	close(op);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_file(argv[1]);
	else if (argc < 2)
		write(2, "File name missing.\n", 19);
	else if (argc > 2)
		write(2, "Too many arguments.\n", 20);
	return (0);
}

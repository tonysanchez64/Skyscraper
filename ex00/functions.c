/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-tole <ede-tole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:02:51 by ede-tole          #+#    #+#             */
/*   Updated: 2023/06/11 16:13:35 by ede-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void	write_char(char c)
{
	write(1, &c, 1);
}

void	write_num(int num)
{
	char	c;

	c = '0' + num;
	write_char(c);
}

void	write_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write_char(str[i]);
		i++;
	}
}

void	display(int grid[][4])
{
	int	row;
	int	column;

	row = 0;
	while (row < 4)
	{
		column = 0;
		while (column < 4)
		{
			write_num(grid[row][column]);
			if (column < 3)
				write_char(' ');
			column++;
		}
		row++;
		write_char('\n');
	}
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-tole <ede-tole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:01:09 by ede-tole          #+#    #+#             */
/*   Updated: 2023/06/11 19:16:14 by ede-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	write_str(char *str);
void	display(int grid[4][4]);
void	write_num(int num);
int	check_repeated(int grid[4][4], int num, int pos);
int	check_hints(int grid[4][4], int *hints, int pos);
void	initialize_matrix(int matrix[4][4])
{
	int	index_c;
	int	index_r;

	index_r = 0;
	index_c = 0;
	while (index_r < 4)
	{
		while (index_c < 4)
		{
			matrix[index_r][index_c] = 0;
			index_c++;
		}
		index_c = 0;
		index_r++;
	}
}
int rush01(int grid[4][4], int pos, int *hints)
{
	int	counter;

    counter = 1;
	if (pos > 15)
		return (1);
    while (counter <= 4)
    {
		printf("\n %d %d",pos,counter);
		if (check_repeated(grid, counter, pos) == 0)
		{
			grid[pos/4][pos % 4] = counter;
			display(grid);
			printf("\n valor check hints %d",check_hints(grid, hints, pos));
			if (check_hints(grid, hints, pos) == 0)
			{
				printf("\n cumple con hints");
				if (rush01(grid, pos + 1, hints) == 1)
					return 1;
			}
			else
				grid[pos/4][pos % 4] = 0;
		} 
		counter++;
    }
	return (0);
}

void convert_hints(char *input, int *hints)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (input[i] != '\0')
	{
		if (input[i] != 32)
		{
			hints[j] = input[i] - '0';
			j++;
		}
		i++;
	}
}
int	main(int argc, char **argv)
{
	int	grid[4][4];
	int hints[16];

	if (argc != 2)
	{
		write_str("\n Error: Wrong number of arguments. \n");
		return (0);
		//conttol de errores: lonngitud, caracteres, formato espacios, que los numeros entre 1 y 4
	}
	else
	{
		initialize_matrix(grid);
		convert_hints(argv[1], hints);
		if(rush01(grid, 0, hints)==1)
			argc++;
			//display(grid);
		else
			 write_str("No solution found.\n");
	}
	//display(grid);
	return (0);
}

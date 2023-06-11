/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-tole <ede-tole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 12:01:09 by ede-tole          #+#    #+#             */
/*   Updated: 2023/06/11 21:31:20 by ede-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	write_str(char *str);
int		check_input(char *str);
void	display(int grid[4][4]);
void	write_num(int num);
int		check_repeated(int grid[4][4], int num, int pos);
int		check_hints(int grid[4][4], int *hints, int pos);

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

int	rush01(int grid[4][4], int pos, int *hints)
{
	int	counter;

	counter = 1;
	if (pos > 15)
		return (1);
	while (counter <= 4)
	{
		if (check_repeated(grid, counter, pos) == 0)
		{
			grid[pos / 4][pos % 4] = counter;
			if (check_hints(grid, hints, pos) == 0)
			{
				if (rush01(grid, pos + 1, hints) == 1)
				{
					return (1);
				}
			}
			else
			{
				grid[pos / 4][pos % 4] = 0;
			}
		}
		counter++;
	}
	return (0);
}

void	convert_hints(char *input, int *hints)
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
	int	hints[16];

	if (argc != 2)
	{
		write_str("Error: Wrong number of arguments. \n");
		return (0);
	}
	else
	{
		if (check_input(argv[1]) == -1)
		{
			write_str("Error. Format requirement not met. \n");
			return (0);
		}
		initialize_matrix(grid);
		convert_hints(argv[1], hints);
		if (rush01(grid, 0, hints) == 1)
			display(grid);
		else
			write_str("No solution found.\n");
	}
	return (0);
}

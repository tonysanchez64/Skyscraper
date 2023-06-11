/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-tole <ede-tole@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:43:13 by ede-tole          #+#    #+#             */
/*   Updated: 2023/06/11 19:12:57 by ede-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
int	check_repeated(int grid[4][4], int num, int pos)
{
	int	index;

	index = 0;
	while (index < pos / 4)
	{
		printf("\n Entra en rep 2");
		if (num == grid[index][pos % 4])
			printf("\n Error rep 2");
			return (1);
		index++;	
	}
	index = 0;
	while (index < pos % 4)
	{
		printf("\n Entra en rep");
		if (num == grid[pos/4][index])
			printf("\n Error rep 1");
			return (1);
		index++;
	}
	printf("\n Sale de rep");
	return (0);
}

int	check_up(int grid[4][4], int *hints, int pos)
{
	int	views;
	int	prev;
	int	counter;

	views = 0;
	prev = 0;
	counter = 0;
	if (pos / 4 == 3)
	{
		while (counter < 4)
		{
			if (grid[counter][pos % 4] < prev)
			{
				views++;
			}
			prev = grid[counter][pos % 4];
			counter++;
		}
	if (views == hints[pos % 4])
		return (views);
	else
		return (-1);
	}
	return (0);
}

int	check_down(int grid[4][4], int *hints, int pos)
{
	int	views;
	int	prev;
	int	counter;

	views = 0;
	prev = 0;
	counter = 3;
	if (pos / 4 == 3)
	{
		while (counter >= 0)
		{
			if (grid[counter][pos % 4] < prev)
			{
				views++;
			}
			prev = grid[counter][pos % 4];
			counter--;
		}
	if (views == hints[(pos % 4) + 4])
		return (views);
	else
		return (-1);
	}
	return (0);
}
int	check_left(int grid[4][4], int *hints, int pos)
{
	int	views;
	int	prev;
	int	counter;
	int	max;

	max = hints[(pos / 4) + 8];
	views = 0;
	prev = 0;
	counter = 0;
	if (pos % 4 == 3)
	{
		while (counter < 4)
		{
			if (grid[pos / 4][counter] < prev)
			{
				views++;
			}
			prev = grid[pos / 4][counter];
			counter++;
		}
	if (views == max)
		return (views);
	else
		return (-1);
	}
	return (0);
}
int	check_right(int grid[4][4], int *hints, int pos)
{
	int	views;
	int	prev;
	int	counter;
	int	max;

	max = hints[(pos / 4) + 12];
	views = 0;
	prev = 0;
	counter = 3;
	if (pos % 4 == 3)
	{
		while (counter >= 0)
		{
			if (grid[pos / 4][counter] < prev)
			{
				views++;
			}
			prev = grid[pos / 4][counter];
			counter--;
		}
	if (views == max)
		return (views);
	else
		return (-1);
	}
	return (0);
}

int	check_hints(int grid[4][4], int *hints, int pos)
{
	printf("\n esntro en check hints");
	if (check_up(grid, hints, pos) == -1)
	{
		printf("\n FALLO 1");
		fflush(stdout);
		return -1;
	}
	if (check_down(grid, hints, pos) == -1)
	{
		printf("\n FALLO 2");
		fflush(stdout);
		return -1;
	}
	if (check_left(grid, hints, pos) == -1)
	{
		printf("\n FALLO 3");
		fflush(stdout);
		return -1;
	}
	if (check_right(grid, hints, pos) == -1)
	{
		printf("\n FALLO 4");
		fflush(stdout);
		return -1;
	}
	return(0);
}

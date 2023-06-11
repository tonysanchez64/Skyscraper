/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antosanc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 21:47:01 by antosanc          #+#    #+#             */
/*   Updated: 2023/06/11 21:47:07 by antosanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
			if (grid[counter][pos % 4] > prev)
			{
				prev = grid[counter][pos % 4];
				views++;
			}
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
			if (grid[counter][pos % 4] > prev)
			{
				views++;
				prev = grid[counter][pos % 4];
			}
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

	views = 0;
	prev = 0;
	counter = 0;
	if (pos % 4 == 3)
	{
		while (counter < 4)
		{
			if (grid[pos / 4][counter] > prev)
			{
				views++;
				prev = grid[pos / 4][counter];
			}
			counter++;
		}
		if (views == hints[(pos / 4) + 8])
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

	views = 0;
	prev = 0;
	counter = 3;
	if (pos % 4 == 3)
	{
		while (counter >= 0)
		{
			if (grid[pos / 4][counter] > prev)
			{
				views++;
				prev = grid[pos / 4][counter];
			}
			counter--;
		}
		if (views == hints[(pos / 4) + 12])
			return (views);
		else
			return (-1);
	}
	return (0);
}

int	check_hints(int grid[4][4], int *hints, int pos)
{
	if (check_left(grid, hints, pos) == -1)
	{
		return (-1);
	}
	if (check_right(grid, hints, pos) == -1)
	{
		return (-1);
	}
	if (check_down(grid, hints, pos) == -1)
	{
		return (-1);
	}
	if (check_up(grid, hints, pos) == -1)
	{
		return (-1);
	}
	return (0);
}

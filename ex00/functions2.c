/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ede-tole <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 21:28:51 by ede-tole          #+#    #+#             */
/*   Updated: 2023/06/11 21:31:08 by ede-tole         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_input(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != 32 && (str[i] < 49 || str[i] > 52))
			return (-1);
		i++;
	}
	if (i != 31)
		return (-1);
	return (0);
}

int	check_repeated(int grid[4][4], int num, int pos)
{
	int	index;

	index = 0;
	while (index < pos / 4)
	{
		if (num == grid[index][pos % 4])
		{
			return (1);
		}
		index++;
	}
	index = 0;
	while (index < pos % 4)
	{
		if (num == grid[pos / 4][index])
		{
			return (1);
		}
		index++;
	}
	return (0);
}

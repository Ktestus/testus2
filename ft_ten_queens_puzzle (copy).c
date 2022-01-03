/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrey <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/23 15:57:10 by andrey            #+#    #+#             */
/*   Updated: 2021/12/24 16:27:05 by andrey           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<unistd.h>

#define N 10

int		ft_ten_queens_puzzle(void);
void	ft_n_queens(int *pos, int n, int *solutions);
int		ft_is_d(int *pos);
void	ft_print(int *pos);
int		assignment(int *pos, int n, int *i);

int	ft_ten_queens_puzzle(void)
{
	int	k;
	int	pos[N];
	int	solutions;

	k = 0;
	solutions = 0;
	while (k < N)
		pos[k++] = -1;
	ft_n_queens(pos, N, &solutions);
	return (solutions);
}

void	ft_n_queens(int *pos, int n, int *solutions)
{
	int	i;
	int	j;
	int	go;

	i = 0;
	while (i < N)
	{
		go = assignment(pos, n, &i);
		if (go == -1)
			continue ;
		if (n > 1 && go == 1)
			ft_n_queens(pos, n - 1, solutions);
		if (n == 1 && go == 1)
			ft_print(pos);
		if (n == 1 && go == 1)
			*solutions += 1;
		j = 0;
		while (j < N)
		{
			if (pos[j] >= N - n)
				pos[j] = -1;
			j++;
		}
			i++;
	}
}

int	assignment(int *pos, int n, int *i)
{
	if (pos[*i] < 0)
	{
		pos[*i] = N - n;
		if (ft_is_d(pos))
		{
			pos[*i] = -1;
			*i += 1;
			return (-1);
		}
		return (1);
	}
	return (0);
}

void	ft_print(int *pos)
{
	int		i;
	char	c;

	i = 0;
	while (i < N)
	{
		c = pos[i] + '0';
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	ft_is_d(int *pos)
{
	int	i;
	int	j;

	i = 0;
	while (i < N - 1)
	{
		j = i + 1;
		while (j < N)
		{
			if (pos[i] + (j - i) == pos[j] && pos[j] >= 0 && pos[i] >= 0)
				return (1);
			if (pos[N - 1 - i] + j - i == pos[N - 1 - j]
				&& pos[N - 1 - j] >= 0 && pos[N - 1 - i] >= 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

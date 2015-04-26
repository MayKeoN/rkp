/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rkp_2_rate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 09:55:35 by ymonfray          #+#    #+#             */
/*   Updated: 2015/04/20 09:55:35 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rkp.h"

// void				combinations(int v[5], int start, int k, int w[21][5])
// {
// 	int     i;

// 	if (k > 4)
// 	{
// 		for (i=0; i < 5; i++)
// 		{
// 			printf ("%d ", v[i]);
// 			// *(w[0][i]) = v[i];
// 		}
// 		printf("\n");
// 		return;
// 	}

// 	i = start;
// 	while (i < 7)
// 	{
// 		v[k] = i;
// 		// printf("FUCK\n");
// 		combinations(v, i+1, k+1, w);
// 		// idx += (k > 3);
// 		i++;
// 	}
// 	// return (NULL);
// }

int					rate_count(t_set *hand)
{
	int				i;
	int				j;
	int				count;


	i = 0;
	j = 0;
	count = 0;
	while (i < 5)
	{
		while (j < 5)
		{
			if (j != i && !!(hand->s[i] & NO_COL & hand->s[j] & NO_COL))
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

int					rate_straight(t_set *hand)
{
	int				i;
	int				count;

	i = 1;
	count = (hand->s[0] | hand->s[1] | hand->s[2] | hand->s[3] | hand->s[4]) & NO_COL;
	if (count == 31)
		return (5);
	else if (!!(count & 1))
		count += (1 << 13) - 1;
	while (i < 10)
		if (count == (31 << i++))
			return (4 + i);
	return (0);
}

int					rate_flush(t_set *hand)
{
	int 			i;
	int 			flush;

	i = 0;
	flush = 1;
	while (++i < 5)
		flush += !!(hand->s[i - 1] & NO_VAL & hand->s[i]);
	return (flush);
}

t_set				*rate_pair(t_set *hand, int n)
{
	// int				i;
	// int				j;
	// int				pair;
	// int				count;
	int				counthigh;
	// int				flush;
	int				flushigh;
	int				straighigh;


	// count = 0;
	// flush = 0;
	flushigh = 0;
	counthigh = 0;
	straighigh = 0;
	// i = 0;
	// j = 1;
	// pair = 0;
	// printf("======================\n");
	// printf("Player %s\n", ft_itoa(++n));
	// while (i < 5)
	// {
	// 	while (j < 5)
	// 	{
	// 		// if (j == i && j < 5)
	// 		// 	j++;
	// 		// printf("L: %x\tR: %x\n", (hand->s[i] & NO_COL), (hand->s[j] & NO_COL));
	// 		if ((hand->s[i] & NO_COL) & (hand->s[j] & NO_COL) && j != i)
	// 		{
	// 			count++;
	// 		}
	// 		j++;
	// 		// printf("FLUSH: %d\n", flush);
	// 	}
	// 	// if (flush == 4)
	// 	// 	break;
	// 	// flushigh = (flush > flushigh) ? flush : flushigh;
	// 	// flush = 0;
	// 	counthigh = (count > counthigh) ? count : counthigh;
	// 	// count = 0;
	// 	j = 0;
	// 	i++;
	// }

	flushigh = rate_flush(hand);
	counthigh = rate_count(hand);
	straighigh = rate_straight(hand);

	// count 2	0000 0001
	// count 4 0000 0010
	// count 6 0000 0100


		// printf("StraightHigh: %d\n", straighigh);
	if (flushigh == 5 || counthigh == 12 || straighigh > 13)
	{
		printf("==========================\n");
		printf("CardCount: %d\n", counthigh);
		printf("FlushCount: %d\n", flushigh);
		printf("StraightHigh: %d\n", straighigh);
		printf("==========================\n");
		if (counthigh == 4)
			printf("DOUBLE!\n");
		else if (counthigh == 6)
			printf("TOAK!\n");
		else if (counthigh == 8)
			printf("FULL HOUSE!\n");
		else if (counthigh == 12)
			printf("SQUARED!\n");
		else if (flushigh == 5)
			printf("FLUSH!\n");
		else if (straighigh > 4)
			printf("STRAIGHT!\n");

		printf("Player %s WINS!\n", ft_itoa(++n));
		printf("==========================\n");
		// printf("ROYAL FLUSHHHHH!\n");
		SDL_Delay(88);
		// SDL_Quit();
		// exit(0);
		hand->n = 9;
		// combinations(v, 0, 0, 0);
		// printf("%d\n", hand->n);
	} 
	return (hand);
}
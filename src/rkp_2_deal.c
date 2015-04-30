/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rkp_2_deal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 02:52:44 by ymonfray          #+#    #+#             */
/*   Updated: 2015/04/20 02:52:44 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rkp.h"

t_set				*shuffle_deck(t_set *deck)
{
	int	 			card;
	int 			tmp;	
	int 			i;
	int				swap;

	i = 0;
	srand(time(NULL));
	while (i < 52)
	{
		card = deck->s[i];
		swap = (rand() % 520000) / 10000;
		// printf("card 1: %d\tcard 2: %d\n", i, swap);
		tmp = deck->s[swap];
		deck->s[swap] = card;
		deck->s[i] = tmp;
		i++;
	}
	return (deck);
}

t_game				*serve_card(t_game *g)
{
	int				i;
	int				count;

	i = 0;
	count = 0;
	while (i < g->npl)
	{
		g->pl[i]->hand->s[0] = g->deck->s[count];
		g->deck->s[count] = init_card(0,0);
		count++;
		g->pl[i]->hand->s[1] = g->deck->s[count];
		g->deck->s[count] = init_card(0,0);
		count++;
		i++;
	}
	return (g);
}

t_game				*serve_round(t_game *g, int itr, int idx)
{
	int				i;
	int				j;
	int				d;

	i = 0;
	j = 0;
	d = 0;
	g->deck->s[0] = init_card(0,0);
	while (j < itr)
	{
		while (g->deck->s[d + 1 + j] == 0)
			d++;
		while (i < g->npl)
		{
			g->pl[i]->hand->s[idx + j] = g->deck->s[d + 1 + j];
			i++;
		}
		g->deck->s[d + 1 + j] = init_card(0, 0);
		i = 0;
		j++;	
	}
	return (g);
}

t_game				*serve_flop(t_game *g)
{
	return (serve_round(g, 3, 2));
}

t_game				*serve_turn(t_game *g)
{
	return (serve_round(g, 1, 5));
}

t_game				*serve_river(t_game *g)
{
	return (serve_round(g, 1, 6));
}





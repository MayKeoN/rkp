/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rkp_deal.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/19 03:54:24 by ymonfray          #+#    #+#             */
/*   Updated: 2015/04/19 03:54:24 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rkp.h"

t_deck				*shuffle_deck(t_deck *deck)
{
	t_card 			card;
	t_card 			tmp;	
	int 			i;
	int				swap;

	i = 0;
	srand(time(NULL));
	while (i < 52)
	{
		card = deck->d[i];
		swap = rand() % 52;
		tmp = deck->d[swap];
		deck->d[swap] = card;
		deck->d[i] = tmp;
		i++;
	}
	return (deck);
}

t_game				*serve_card(t_game *game)
{
	int				i;
	int				al;


	i = 0;
	srand(time(NULL));
	al = rand() % 52;
	while (i < game->np)
	{
		while (game->deck.d[al].c == 0)
				al = rand() % 52;
		game->players[i].h[0] = game->deck.d[al];
		game->deck.d[al] = *init_card(0,0);
		while (game->deck.d[al].c == 0)
				al = rand() % 52;
		game->players[i].h[1] = game->deck.d[al];
		game->deck.d[al] = *init_card(0,0);
		i++;
	}
	return (game);
}

t_game				*serve_flop(t_game *game)
{
	int				i;
	int				j;
	int				count;
	
	i = 0;
	j = 0;
	count = 0;
	while (count < 3)
	{
		while (game->deck.d[j].c == 0)
			j++;
		while (i < game->np)
			game->players[i++].h[count + 2] = game->deck.d[j];
		game->deck.d[j] = *init_card(0, 0);
		i = 0;
		count++;
	}
	return (game);
}

t_game				*serve_turn(t_game *game)
{
	int				i;
	int				j;
	
	i = 0;
	j = 0;
	while (game->deck.d[j].c == 0)
		j++;
	while (i < game->np)
		game->players[i++].h[5] = game->deck.d[j];
	game->deck.d[j] = *init_card(0, 0);
	return (game);
}

t_game				*serve_river(t_game *game)
{
	int				i;
	int				j;
	
	i = 0;
	j = 0;
	while (game->deck.d[j].c == 0)
		j++;
	while (i < game->np)
		game->players[i++].h[6] = game->deck.d[j];
	game->deck.d[j] = *init_card(0, 0);
	return (game);
}













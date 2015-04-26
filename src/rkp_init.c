/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rkp_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 00:48:00 by ymonfray          #+#    #+#             */
/*   Updated: 2015/04/18 00:48:01 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rkp.h"

t_card				*init_card(int color, int value)
{
	t_card			*card;

	card = NULL;
	card = malloc(sizeof(t_card));
	if (card)
	{
		card->c = color;
		card->v = value;		
	}
	return (card);
};

t_deck				*init_deck(void)
{
	t_deck			*deck;
	int				i;

	i = 0;
	deck = NULL;
	deck = malloc(sizeof(t_deck));
	if (deck)
	{
		while (i < 52)
		{
			deck->d[i] = *init_card((i / 13) + 1, (i % 13) + 1);
			// printf("i: %d Card: Color= %d Value= %d \n", i, deck->d[i].c, deck->d[i].v);
			i++;
		}
	}
	return (deck);
}

t_player			*init_player(int n)
{
	t_player		*player;
	int				i;

	i = 0;
	player = NULL;
	player = malloc(sizeof(t_player));
	if (player)
	{
		while (i < 7)
		{
			if (i < 5)
				player->nuts[i] = *init_card(0, 0);
			player->h[i] = *init_card(0, 0);
			i++;
		}
		player->n = n;
	}
	return (player);
};

t_game				*init_game(int nb)
{
	t_game			*game;

	game = NULL;
	game = malloc(sizeof(t_game));
	if (game)
	{
		game->deck = *init_deck();
		game->np = nb;
		game->players = malloc(sizeof(t_player) * nb);
		while (nb--)
			game->players[nb] = *init_player(nb);
	}
	return (game);
}










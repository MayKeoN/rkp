/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rkp_2_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 01:39:53 by ymonfray          #+#    #+#             */
/*   Updated: 2015/04/20 01:39:53 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rkp.h"

int						init_card(int color, int value)
{
	int					card;

	card = 0;
	card += (color > 0 && color < 5) ? (1 << (15 + color)) : 0;
	card += (value > 0 && value < 16) ? (1 << (value - 1)) : 0;
	return (card);
}

t_set					*init_set(int n)
{
	int					i;
	t_set				*set;

	i = 0;
	set = (t_set *)malloc(sizeof(t_set));
	set->s = (int *)malloc(sizeof(int) * n);
	while (i < n)
		set->s[i++] = init_card(0, 0);
	set->n = n;
	return (set);
}

t_set					*init_deck(t_set *deck)
{
	int					i;
	// t_set				*deck;

	i = 0;
	// if (deck)
	// 	free(deck);
	deck = (t_set *)malloc(sizeof(t_set) * 52);
	deck = init_set(52);
	while (i < 52)
	{
		deck->s[i] = init_card((i / 13) + 1, (i % 13) + 1);
		i++;
	}
	return (deck);
}

t_player				*init_player(int n)
{
	t_player			*pl;

	pl = (t_player *)malloc(sizeof(t_player));
	pl->n = n;
	pl->hand = init_set(7);
	pl->nuts = init_set(5);
	return (pl);
}

t_display				*init_display(void)
{
	t_display			*display;
	SDL_Window			*screen;
	SDL_Renderer		*render;
	SDL_Rect			cardpos;

	display = (t_display *)malloc(sizeof(t_display));
    screen = SDL_CreateWindow("RKP",
                          SDL_WINDOWPOS_UNDEFINED,
                          SDL_WINDOWPOS_UNDEFINED,
                          1280, 768, 0);
	if (screen)
	{	
		render = SDL_CreateRenderer(screen, -1, 0);
		SDL_SetRenderDrawColor(render, 0x35, 0x5e, 0x3b, 255);
		SDL_RenderClear(render);
		SDL_RenderPresent(render);
	}
	else 
	{
		screen = NULL;
		render = NULL;
	}
	display->screen = screen;
	display->render = render;
	return (display);
}


void					combinations(int v[5], int start, int k, int w[21][5], int *index)
{
	int					i;

	if (k > 4)
	{	
		i = -1;
		while (++i < 5)
			w[(*index)][i] = v[i];
		*index += 1;
		return;
	}
	i = start;
	while (i < 7)
	{
		v[k] = i;
		combinations(v, i+1, k+1, w, index);
		i++;
	}
}

void					init_combo(t_game *g)
{
	int 				v[5];
	int					w[21][5];
	int					index;
	int					i;
	int					j;

	index = 0;
	combinations(v, 0, 0, w, &index);
	i = -1;
	j = -1;
	while (++j < 21)
	{
		while (++i < 5)
			g->w[j][i] = w[j][i];
		i = -1;
	}
}

t_game					*init_regame(t_game *game)
{
	int					i;

	i = 0;
	game->deck = init_deck(game->deck);
	while (i < game->npl)
	{
		game->pl[i] = init_player(i);
		i++;
	}
	shuffle_deck(game->deck);
	return (game);
}

t_game					*init_game(int n)
{
	t_game				*game;
	int					i;

	i = 0;
	game = (t_game *)malloc(sizeof(t_game));
	// game->deck = init_deck();
	game->pl = (t_player **)malloc(sizeof(t_player *) * n);
	while (i < n)
	{
		game->pl[i] = init_player(i);
		i++;
	}
	game->npl = n;
	i = 0;
	while (i < 10)
		game->stat[i++] = 0;
	// game->stat = (int *)malloc(sizeof(int) * 10);
	// for (int i=0; i < 10; i++)
	// 	game->stat[i] = 0;
	init_combo(game);
	// game->w = (int **)malloc(sizeof(int) * 105);
	return (game);
}




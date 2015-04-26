/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rkp_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 00:46:56 by ymonfray          #+#    #+#             */
/*   Updated: 2015/04/18 00:46:56 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rkp.h"

int			main(int ac, char **av)
{
	int  	i;

	i = 0;
	printf("Hello\n");
	if (ac == 1)
	{	
		t_game *game;

		game = init_game(22);
		display_deck(&game->deck);

		printf("=================================================================\n");
		// printf("Name: %s\n", av[0]);
		while (i < 1)
		{
			game->deck = *shuffle_deck(&game->deck);
			display_deck(&game->deck);
		printf("=================================================================\n");
			i++;
		}

		game = serve_card(game);
		// display_deck(&game->deck);
		printf("=================================================================\n");
		i = 0;
		while (i < game->np)
		{
			display_player(&game->players[i]);
			i++;
		}


		game = serve_flop(game);
		// display_deck(&game->deck);
		printf("=================================================================\n");
		i = 0;
		while (i < game->np)
		{
			display_player(&game->players[i]);
			i++;
		}
		printf("=================================================================\n");

		game = serve_turn(game);
		// display_deck(&game->deck);
		printf("=================================================================\n");
		i = 0;
		while (i < game->np)
		{
			display_player(&game->players[i]);
			i++;
		}
		printf("=================================================================\n");

		game = serve_river(game);
		// display_deck(&game->deck);
		printf("=================================================================\n");
		i = 0;
		while (i < game->np)
		{
			display_player(&game->players[i]);
			i++;
		}
		printf("=================================================================\n");

		printf("Name: %s\n", av[0]);
	}
	return (0);
}
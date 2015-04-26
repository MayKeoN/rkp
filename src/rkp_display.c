/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rkp_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 00:47:35 by ymonfray          #+#    #+#             */
/*   Updated: 2015/04/18 00:47:35 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rkp.h"

void			display_deck(t_deck *deck)
{
	int			i;
	char		*color[5];
	char		*value[14];

	color[0] = "NULL";
	color[1] = "H";
	color[2] = "D";
	color[3] = "C";
	color[4] = "S";
	value[0] = "NULL";
	value[1] = "Ace";
	value[2] = "Two";
	value[3] = "Tre";
	value[4] = "For";
	value[5] = "Fiv";
	value[6] = "Six";
	value[7] = "Sev";
	value[8] = "Hui";
	value[9] = "Nin";
	value[10] = "Ten";
	value[11] = "Jak";
	value[12] = "LoU";
	value[13] = "KeL";
	i = 0;
	while (i < 52)
	{	
		printf(" %s %s\n", color[deck->d[i].c], value[deck->d[i].v]);
		i++;
	}
}

void			display_player(t_player *player)
{
	int			i;
	char		*color[5];
	char		*value[14];

	color[0] = "NULL";
	color[1] = "H";
	color[2] = "D";
	color[3] = "C";
	color[4] = "S";
	value[0] = "NULL";
	value[1] = "Ace";
	value[2] = "Two";
	value[3] = "Tre";
	value[4] = "For";
	value[5] = "Fiv";
	value[6] = "Six";
	value[7] = "Sev";
	value[8] = "Hui";
	value[9] = "Nin";
	value[10] = "Ten";
	value[11] = "Jak";
	value[12] = "LoU";
	value[13] = "KeL";
	i = 0;
	printf("______________\n");
	printf("Player Number: %d\nPlayer Hand: \n", player->n);
	while (i < 7)
	{	
		printf(" %s %s \n", color[player->h[i].c], value[player->h[i].v]);
		if (i == 1)
			printf("Community: \n");
		i++;
	}
}
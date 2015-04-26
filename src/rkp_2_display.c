/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rkp_2_display.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 01:49:18 by ymonfray          #+#    #+#             */
/*   Updated: 2015/04/20 01:49:19 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rkp.h"

void					display_card_img(t_game *g, int card)
{
	int 				value;
	int 				color;
	int					i;

	i = 0;
	while (i < 20)
	{
		if (card & (1 << i) && i < 16)
			value = i;
		else if (card & (1 << i))
			color = i - 16;
		i++;	
	}
	if (card)
	{
		// printf("E L E V E N\n");
		// printf("rectX: %d\trectY: %d\tCard: %x\n", g->display->cardpos.x, g->display->cardpos.y, card);
		render_card(g, g->display->cardpos, value, color);
		// SDL_RenderPresent(g->display->render);
		// SDL_RenderClear(g->display->render);
		display_card(card);
		// printf("\n");
	}
}

////////CONVERT TO PRINT////////////////
void					display_card(int card)
{
	char				*cards;
	int					i;

	i = 0;
	cards = "123456789TJQKA--HDCS";
	// printf("card: %x\n", card);
	printf("\\");
	while (i < 20)
	{
		if (card & (1 << i))
			printf("| %c |", cards[i]);
		i++;	
	}
	if (!card)
		printf(" NULL ");
	printf("/ \t");
	// rate_pair(g->pl[n]->hand);
}

void					display_set(t_game *g, int n)
{
	int					i;
	float				ppos[2];
	SDL_Rect			savepos;
	// int					x1;
	// int					y1;

	i = 0;
	ppos[0] = (n == 2 || n == 3) ? 8 : 0;
	ppos[1] = (!n || n == 3) ? 0 : 3;
	if (n > 3)
	{
		ppos[0] = (n == 5 || n == 7 ) ? 4 : ((n == 6) ? 8 : 0);
		ppos[1] = (n == 4 || n == 6) ? 1.5 : ((n == 5) ? 3 : 0);
	}
	// x1 = g->display->cardpos.x;
	// y1 = g->display->cardpos.y;
	while (i < g->pl[n]->hand->n)
	{
		// set->s[1] = 0;
		if (g->pl[n]->hand->s[i])
		{
			// printf("i: %d\tplayer#: %d\n", i, n);
			// printf("ppos[0]: %d\tppos[1]#: %d\n", ppos[0], ppos[1]);

			savepos = create_card_rect((i > 1) ? (i + 0.5) : ppos[0] + i, (i > 1) ? 1.5 : ppos[1]);
			// printf("!@ !@ !@\n");
			// printf("X: %dY: %dW: %dH: %d\n", savepos.x, savepos.y, savepos.w, savepos.h);


			g->display->cardpos = savepos;
			// g->display->cardpos.x = x1;
			// g->display->cardpos.y = y1;
			// printf("!!!!!!!!!!!!\n");
			display_card_img(g, g->pl[n]->hand->s[i]);
			if (!i)
				display_player_text(g, n);
			g->display->cardpos = savepos;
			display_card_text(g, g->pl[n]->hand->s[i]);
		}
		i++;
	}
	// rate_pair(g->pl[n]->hand, n);
	// SDL_RenderPresent(g->display->render);
}

void					display_player(t_game *g, int n)
{
	// printf("Player #%d\n", n + 1);
	// printf("Hand:\n");
	// g->display->cardpos = create_card_rect(0, pl->n);
	display_set(g, n);
	printf("\n");
	// printf("Nuts:\n");
	// display_set(pl->nuts);	
}

t_set					*shift_set(t_set *set, int start, int offset)
{
	int					i;

	i = 0;
	while (i < 5)
	{
		set->s[i] = set->s[i + offset];
		i++;
	}
	// set->s[i]
	return (set);
}

// t_set				*combo(t_set *hand, int c, int w[21][5])
// {
// 	hand->s[0] = 
// 	return (hand);
// }

t_set					*combo_hand(t_set *hand, int w[21][5], int index)
{
	t_set				*tmp;
	int					i;

	i = 0;
	tmp = init_set(5);
	while (i < 5)
	{
		tmp->s[i] = hand->s[w[index][i]];
		i++;
	}
	return (tmp);
}
int					rate_hands(t_game *g)
{
	int					i;
	int					j;
	// t_set				*savehand;
	

	i = 0;
	j = 0;
	// savehand = init_set(5);
	while (i < g->npl)
	{
		// printf("CHECK\n");
		while (j < 21)
		{
			// savehand = combo_hand(g->pl[i]->hand, g->w, j);
			// set = g->pl[i]->hand;
			if (rate_pair(combo_hand(g->pl[i]->hand, g->w, j), i)->n == 9)
			{
				// printf("N I N E\n");
				g->pl[i]->hand->n = 7;
				// printf("HAND in G: %d\n", g->pl[i]->hand->n);
				return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}


void					display_players(t_game *g)
{
	int					i;
	// t_set				*set;

	i = 0;
	// set = init_set(5);
	if (rate_hands(g))
	{
		SDL_RenderClear(g->display->render);
		while (i < g->npl)
		{
			printf("Player %d\n", i + 1);
			display_player(g, i);
			i++;
		}
		SDL_RenderPresent(g->display->render);
		SDL_Delay(5555);
		input_loop();
	}
	// rate_hands(g);
}


void					display_card_text(t_game *g, int card)
{
	int 				i;
	int					j;
	char				*cards;
	char				text[4];
	SDL_Texture			*img;

	i = 0;
	cards = "123456789TJQKA--HDCS";
	text[0] = ((card & NO_COL) == 1 ) ? 'A' : ' ';
	text[1] = 32;
	text[2] = 32;
	text[3] = '\0';
	while (i++ < 20)
		if (card & (1 << i))
			text[(i > 14) ? 2 : 0] = cards[i];
	img = display_text(text, "rsrc/LiberationSans-Regular.ttf", (SDL_Color){255, 127, 255, 255}, 32, g->display->render);
	if (!img)
		return;
	SDL_QueryTexture(img, NULL, NULL, &i, &j);
	g->display->cardpos.x += 53 - (i / 2);
	g->display->cardpos.y += -32;//(iH / 2) + 85;
	g->display->cardpos.w = i;
	g->display->cardpos.h = j;	
	SDL_Rect textureRect = create_rect(0, 0, i, j);
	SDL_RenderCopy(g->display->render, img, &textureRect, &g->display->cardpos);
}

void					display_player_text(t_game *g, int n)
{
	int 				iW;
	int 				iH;
	SDL_Texture			*img;

	img = display_text(ft_strjoin("Player ", ft_itoa(n + 1)), "rsrc/LiberationSans-Regular.ttf", (SDL_Color){255, 255, 0, 255}, 20, g->display->render);
	if (img == NULL)
		return;
	SDL_QueryTexture(img, NULL, NULL, &iW, &iH);
	g->display->cardpos.x += (224 / 2) -  (iW / 2);
	g->display->cardpos.y += 170;
	g->display->cardpos.w = iW;
	g->display->cardpos.h = iH;	
	SDL_Rect textureRect = create_rect(0, 0, iW, iH);
	SDL_RenderCopy(g->display->render, img, &textureRect, &g->display->cardpos);
}

Uint16					*display_unicodify(char *msg)
{
	Uint16				*uni;	
	Uint16				u;
	int					i;

	i = 0;
	uni = (Uint16 *)malloc(sizeof(Uint16) * (1 + strlen(msg)));
	while (*msg)
	{
		u = *msg;
		u = (*msg == 'H') ? 0x2665 : u;
		u = (*msg == 'D') ? 0x2666 : u;
		u = (*msg == 'C') ? 0x2663 : u;
		u = (*msg == 'S') ? 0x2660 : u;
		*uni = u;
		uni++;
		msg++;
		i++;
	}
	*uni = '\0';
	return (uni - i);
}


SDL_Texture* 			display_text(char *message, char *fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer)
{
	Uint16				*msg;

	TTF_Font *font = TTF_OpenFont(fontFile, fontSize);
	if (font == NULL){
		printf("TTF_OpenFont Error!\n");
		return (NULL);
	}	
	msg = display_unicodify(message);
	SDL_Surface *surf = TTF_RenderUNICODE_Blended(font, msg, color);
	if (surf == NULL){
		TTF_CloseFont(font);
		printf("TTF_RenderText Error!\n");
		return (NULL);
	}
	SDL_Texture *texture = SDL_CreateTextureFromSurface(renderer, surf);
	if (texture == NULL){
		printf("CreateTexture Error!\n");
	}
	SDL_FreeSurface(surf);
	TTF_CloseFont(font);
	return (texture);
}




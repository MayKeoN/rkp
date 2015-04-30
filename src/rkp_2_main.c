/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rkp_2_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 02:52:54 by ymonfray          #+#    #+#             */
/*   Updated: 2015/04/20 02:52:54 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rkp.h"



SDL_Rect				create_rect(int x, int y, int width, int height)
{
	SDL_Rect			rect;

	rect.x = x;
	rect.y = y;
	rect.w = width;
	rect.h = height;
	return (rect);
}

SDL_Rect				create_card_rect(float xpos, float ypos)
{
	return (create_rect(56 + 118 * xpos, 28 + 181 * ypos, 106, 169));
}

SDL_Surface				*load_card(int value, int color)
{
	SDL_Surface			*card;
	char				*path;
	char				*suit;
	char				*rank;

	suit = "";
	suit = (!color) ? "h" : suit;
	suit = (color == 1) ? "d" : suit;
	suit = (color == 2) ? "c" : suit;
	suit = (color == 3) ? "s" : suit;	
	value++;
	rank = (value > 9) ? ft_itoa(value) : ft_strjoin("0", ft_itoa(value));
	path = ft_strjoin("rsrc/deck/0", rank);
	path = ft_strjoin(path, suit);
	path = ft_strjoin(path, ".gif");
	// printf("%s\n", path);
	card = SDL_CreateRGBSurface(0, 106, 169, 32, 0, 0, 0, 0);
	card = IMG_Load(path);
	return (card);
}

void					render_card(t_game *g, SDL_Rect renderRect, int value, int color)
{
	SDL_Texture 		*texture;
	SDL_Surface			*card;
	SDL_Rect			textureRect;

	// SDL_RenderClear(g->display->render);
    card = load_card(value, color);
    texture = SDL_CreateTexture(g->display->render,
                               SDL_PIXELFORMAT_ARGB8888,
                               0,
                               106, 169);
    // texture = SDL_CreateTextureFromSurface(g->render, card);
    SDL_UpdateTexture(texture, NULL, card->pixels, card->pitch);
	// printf("--------UPDATED-------\n");
	// SDL_Delay(20);

	textureRect.x = 0;
	textureRect.y = 0;
	textureRect.w = 106;
	textureRect.h = 169;
	SDL_RenderCopy(g->display->render, texture, &textureRect, &renderRect);
	// printf("--------RENDER COPY-------\n");
	// SDL_Delay(30);
	// SDL_RenderPresent(g->display->render);
	// g->display->render = SDL_CreateRenderer(g->display->screen, -1, 0);
	// printf("-------SURRENDER PRESENT\n");
	SDL_Delay(1);
	// SDL_RenderClear(g->display->render);
}

int					loop_game(t_game *g)
{
	// int 			*v;
	// int				**w;
	// int				i;

	g = init_regame(g);
	// g->display = d;
	// shuffle_deck(g->deck);
	serve_card(g);
	// g->display->screen = screen;
	// g->display->render = render;
	/* Enable Unicode translation */
    // SDL_EnableUNICODE(1);
	// printf("START! \n");
	// display_players(g);
    // SDL_Delay(6000);
    // input_loop();
	serve_flop(g);
	// display_players(g);
    // SDL_Delay(4500);
    // input_loop();
	serve_turn(g);
	// display_players(g);
    // SDL_Delay(2500);
    // input_loop();    
	serve_river(g);
	// combinations(v, 0, 0, &w);
	// for (i=0; i < 5; i++) printf ("%d ", v[0][i]);
	display_players(g);
    // input_loop();
    // SDL_Delay(10);
    // SDL_DestroyWindow(g->display->screen);
    // SDL_DestroyRenderer(g->display->render);
    // SDL_Quit();
    return (1);
}


// void				combinations(int v[5], int start, int k, int w[21][5], int *index)
// {
// 	int     i;

// 	if (k > 4)
// 	{	
// 		// printf("FUCK\n");
// 		// printf("Index: %d\n", *index);
// 		for (i=0; i < 5; i++)
// 		{
// 			// printf ("%d ", v[i]);
// 			w[(*index)][i] = v[i];
// 		}
// 			// w++;
// 		*index += 1;
// 		// printf("\n");
// 		return;
// 	}

// 	i = start;
// 	while (i < 7)
// 	{
// 		// printf("FUCK\n");
// 		v[k] = i;
// 		combinations(v, i+1, k+1, w, index);
// 		// index += (k > 3);
// 		// idx += (k > 3);
// 		i++;
// 	}
// 	// return (NULL);
// }


int 					main(int ac, char **av)
{
	int 				i;
	int 				j;

   	t_game				*g;
   	t_display			*d;

    if(SDL_Init(SDL_INIT_VIDEO) == -1 )
    {
        printf( "Can't init SDL:  %s\n", SDL_GetError( ) );
        return (1);
    }
    TTF_Init();
    atexit(SDL_Quit);

    g = init_game(2);
    d = init_display();
    g->display = d;


	i = 0;
   	SDL_Delay(100);
    while(loop_game(g) && i < 2392)
    {
    	printf("Game #%d\n", i++);
    }
    printf(">>>>>>>>>>>>RESULTS<<<<<<<<<<<<\n");
    printf("HIGH	: %d\n", g->stat[0]);
    printf("PAIR	: %d\n", g->stat[1]);
    printf("DOUBLE	: %d\n", g->stat[2]);
    printf("THREE	: %d\n", g->stat[3]);
    printf("STR8	: %d\n", g->stat[4]);
    printf("FLUSH	: %d\n", g->stat[5]);
    printf("FULL	: %d\n", g->stat[6]);
    printf("FOUR	: %d\n", g->stat[7]);
    printf("ROYAL--	: %d\n", g->stat[8]);
    printf("ROYAL	: %d\n", g->stat[9]);
    printf(">>>>>>>>>>>>STLUSER<<<<<<<<<<<<\n");
    return (0);
}
/*
int						main(int ac, char **av)
{
	t_game				*g;

	if (ac == 1)
	{
		g = init_game(2);
		shuffle_deck(g->deck);
		serve_card(g);
		// display_set(g->deck);
		display_players(g);
		serve_flop(g);
		// display_set(g->deck);
		display_players(g);
		// serve_turn(g);
		// display_players(g);
		// serve_river(g);
		// display_players(g);
		rate_pair(g->pl[0]->hand);
		rate_pair(g->pl[1]->hand);
		display_players(g);
		serve_turn(g);
		display_players(g);
		rate_pair(g->pl[0]->hand);
		rate_pair(g->pl[1]->hand);
		display_players(g);
		serve_river(g);
		display_players(g);
		rate_pair(g->pl[0]->hand);
		rate_pair(g->pl[1]->hand);
		display_players(g);
		printf("Name: %s\n", av[0]);
	}
	return (0);
}
*/
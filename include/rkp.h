/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rkp.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 00:41:18 by ymonfray          #+#    #+#             */
/*   Updated: 2015/04/18 00:41:18 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RKP_H_
# define _RKP_H_

# define _2_

# ifndef _2_
#  include "rkp_def.h"
//INIT

t_card				*init_card(int color, int value);
t_deck				*init_deck(void);
t_player			*init_player(int n);
t_game				*init_game(int nb);


//DEAL
t_deck				*shuffle_deck(t_deck *deck);
t_game				*serve_card(t_game *game);
t_game				*serve_flop(t_game *game);
t_game				*serve_turn(t_game *game);
t_game				*serve_river(t_game *game);

//DISPLAY
void				display_deck(t_deck *deck);
void				display_player(t_player *player);

# else

#  include "rkp_2_def.h"

//INIT

int					init_card(int color, int value);
t_set				*init_set(int n);
t_set				*init_deck(t_set *deck);
t_player			*init_player(int n);
t_display			*init_display(void);
t_game				*init_game(int n);
t_game				*init_regame(t_game *game);
void				init_combo(t_game *g);


//DEAL

t_set				*shuffle_deck(t_set *deck);
t_game				*serve_card(t_game *g);
t_game				*serve_round(t_game *g, int itr, int idx);
t_game				*serve_flop(t_game *g);
t_game				*serve_turn(t_game *g);
t_game				*serve_river(t_game *g);


//DISPLAY

void				display_card(int card);
void				display_card_img(t_game *g, int card);
void				display_card_text(t_game *g, int card);
void				display_player_text(t_game *g, int n);
void				display_set(t_game *g, int n);
void				display_player(t_game *g, int n);
int					display_players(t_game *g);
void				display_win(int npl, int note);
Uint16				*display_unicodify(char *msg);
SDL_Texture			*display_text(char *message, char *fontFile, SDL_Color color, int fontSize, SDL_Renderer *renderer);


//SORT

//RATE

int					rate_count(t_set *hand);
int					rate_straight(t_set *hand);
int					rate_flush(t_set *hand);
int					rate_hands(t_game *g);
int					rate_pair(t_set *hand, int n);
void				combinations(int v[5], int start, int k, int w[21][5], int *index);
t_set				*combo_hand(t_set *hand, int w[21][5], int index);


//////
SDL_Rect				create_card_rect(float xpos, float ypos);
SDL_Surface				*load_card(int value, int color);
SDL_Rect				create_rect(int x, int y, int width, int height);
void					render_card(t_game *g, SDL_Rect	renderRect, int value, int color);

//KEY

int			key_input(void);
void	    input_loop();

char 					*int2bin(int i);





# endif

#endif
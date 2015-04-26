/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rkp_2_def.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 05:17:45 by ymonfray          #+#    #+#             */
/*   Updated: 2015/04/20 05:17:45 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RKP_2_DEF_H_
# define _RKP_2_DEF_H_

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <SDL.h>
# include <time.h>
# include "SDL_image.h"
# include "SDL_ttf.h"
# include "libft.h"

# define NO_COL			0x0000FFFF
# define NO_VAL			0x000F0000
# define NO_SRT			0x000FFFFF
# define NO_RNK			0x0FF00000

# define PAIR			0x00100000
# define TUPR			0x00200000
# define TOAK			0x00400000
# define STR8			0x00800000
# define FLSH			0x01000000
# define FULL			0x02000000
# define FOUR			0x04000000
# define STFL			0x08000000

typedef struct 			s_display
{
	SDL_Window			*screen;
	SDL_Renderer		*render;
	SDL_Rect			cardpos;
}						t_display;

typedef struct			s_set
{
	int					n;
	int					*s;
}						t_set;

typedef struct 			s_player
{
	int					n;
	t_set				*hand;
	t_set				*nuts;
}						t_player;

typedef struct 			s_game
{
	int					npl;
	t_player			**pl;
	t_set				*deck;
	t_display			*display;
	int					w[21][5];
}						t_game;

#endif
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rkp_def.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/18 00:46:34 by ymonfray          #+#    #+#             */
/*   Updated: 2015/04/18 00:46:35 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RKP_DEF_H_
# define _RKP_DEF_H_

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <SDL.h>
# include <time.h>

# define	ZRO	0x0000
# define	ONE			0x0001
# define	TWO			0x0002
# define	THR			0x0004
# define	QAD			0x0008
# define	FIV			0x0010
# define	SIX			0x0020
# define	SEV			0x0040
# define	HUI			0x0080
# define	NIN			0x0100
# define	TEN			0x0200
# define	JCK			0x0400
# define	LOU			0x0800
# define	KNG			0x1000
# define	ACE			0x2001

typedef enum 				e_card_value
{
	zero = ZRO,
	one = ONE,
	two = TWO,
	three =THR,
	four = QAD,
	five = FIV,
	six = SIX,
	seven = SEV,
	huit = HUI,
	nine = NIN,
	dix = TEN,
	jack = JCK,
	queen = LOU,
	king = KNG,
	ace = ACE
}							t_card_value;

// struct 					s_card_value
// {
// 	enum e_card_value	v;
// }						t_card_value;

// enum 					e_card_value
// {
// 	ZRO,
// 	ONE,
// 	TWO,
// 	THR,
// 	QAD,
// 	FIV,
// 	SIX,
// 	SEV,
// 	HUI,
// 	NIN,
// 	TEN,
// 	JCK,
// 	LOU,
// 	KNG,
// 	ACE
// };

typedef enum 	e_card_color
{
	Z,
	H, //Hearts
	T, //Diamonds
	K, //Clubs
	S //Spades
} 				t_card_color;

// struct 					s_card_color
// {
// 	enum e_card_color	c;
// }						t_card_color;


typedef	struct 			s_card
{
	t_card_color		c;
	t_card_value		v;
}						t_card;

typedef struct			s_deck
{
	t_card				d[52];
}						t_deck;

typedef struct			s_player
{
	int					n;
	t_card				h[7];
	t_card				nuts[5];
}						t_player;

typedef struct			s_game
{
	t_deck				deck;
	int					np;
	t_player			*players;
}						t_game;


#endif














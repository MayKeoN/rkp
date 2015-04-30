/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rkp_2_rate.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/20 09:55:35 by ymonfray          #+#    #+#             */
/*   Updated: 2015/04/20 09:55:35 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rkp.h"

//////////////////////////////////////////
//RETURNS CARD PAIRING COUNT
//////////////////////////////////////////	
int					rate_count(t_set *hand)
{
	int				i;
	int				j;
	int				count;

	i = 0;
	j = 0;
	count = 0;
	//////////////////////////////////////////
	//ITERATE EACH CARD WITH ALL OTHERS
	while (i < 5)
	{
		while (j < 5)
		{
			//////////////////////////////////////////
			//INCREASE COUNT WHEN SAME VALUE
			if (j != i && !!(hand->s[i] & NO_COL & hand->s[j] & NO_COL))
				count++;
			j++;
		}
		j = 0;
		i++;
	}
	return (count);
}

//////////////////////////////////////////
//RETURNS STRAIGHT HIGH POSITION
//////////////////////////////////////////	
int					rate_straight(t_set *hand)
{
	int				i;
	int				count;

	i = 1;
	//////////////////////////////////////////
	//ADD CARDS IN HAND
	count = (hand->s[0] | hand->s[1] | hand->s[2] | hand->s[3] | hand->s[4]) & NO_COL;
	//////////////////////////////////////////
	//ACE HIGH LOW EXCEPTION
	if (count == 31)
		return (5);
	else if (!!(count & 1))
		count += (1 << 13) - 1;
	//////////////////////////////////////////
	//LOOP-COMB OVER REMAINING STRAIGHTS
	while (i < 10)
		if (count == (31 << i++))
			return (4 + i);
	return (0);
}

//////////////////////////////////////////
//RETURNS NB MATCHING SUITS
//////////////////////////////////////////
int					rate_flush(t_set *hand)
{
	//////////////////////////////////////////
	//SUMS UP ALL CARD SUITS IN HAND
	return ((hand->s[0] & NO_VAL) & hand->s[1] & hand->s[2] & hand->s[3] & hand->s[4]);
}

int					rate_pair(t_set *hand, int n)
{
	int				chi;
	int				fhi;
	int				shi;
	int 			note;

	note = 0;
	//////////////////////////////////////////
	//COUNT FLUSH STRAIGHT GRADING
	fhi = rate_flush(hand);
	chi = rate_count(hand);
	shi = rate_straight(hand);
	note += (!!chi) * ((chi < 7) ? chi : (8 << (chi / 4)));
	note += (shi > 4) ? 8 : 0;
	note += (fhi) ? 16 : 0;
	note += (fhi && (shi > 4)) ? (128 << (shi == 14)) : 0;
	//////////////////////////////////////////
	////////////HAND RATING SYSTEM////////////
	//////////////////////////////////////////
	// chi	==	2		PAIR	2	00000 0010
	// chi	==	4 		TWO		4	00000 0100
	// chi	==  6 		THREE	6	00000 0110
	// shi	>	4		STR8	8	00000 1000
	// fhi	==	1		FLUSH	16	00001 0000
	// chi	==	8		FULL	32	00010 0000
	// chi	==	12		FOUR	64	00100 0000
	// (fhi == 1) & (shi > 4)	128	01000 0000
	// (fhi == 1) & (shi == 14)	256	10000 0000
	//////////////////////////////////////////
	note = note << 20;
	note |= hand->s[0] | hand->s[1] | hand->s[2] | hand->s[3] | hand->s[4];
	// hand->n = note;

	return (note);
}

t_set					*combo_hand(t_set *hand, int w[21][5], int index)
{
	int					i;
	t_set				*tmp;

	i = 0;
	tmp = init_set(5);
	while (i < 5)
	{
		tmp->s[i] = hand->s[w[index][i]];
		i++;
	}
	return (tmp);
}

void					rate_scores(t_game *g, int note)
{
	// int					add;

	// add = 1;
	// printf("---------------------NOTE BINARY\n");
	// printf("%s\n", int2bin(note));
	// printf("---|-4-FS42|HDCS-AKQJT9876543210\n");
	// printf("--------------------------------\n");

	note &= NO_RNK;
	if ((note & PAIR) == PAIR)
	{	
		if ((note & TUPR) == TUPR)
			g->stat[3] += 1;
		else
			g->stat[1] += 1;
	}
	else if ((note & TUPR) == TUPR)
		g->stat[2] += 1;
	else if ((note & STR8) == STR8)
		g->stat[4] += 1;
	else if ((note & FLSH) == FLSH)
		g->stat[5] += 1;
	else if ((note & FULL) == FULL)
		g->stat[6] += 1;
	else if ((note & FOUR) == FOUR)
		g->stat[7] += 1;
	else if ((note & STFL) == STFL)
		g->stat[8] += 1;
	else if ((note & RYAL) == RYAL)
		g->stat[9] += 1;
	else
		g->stat[0] += 1;



	// if ((note & TOAK) == TOAK)
	// 	g->stat[3] += 1;
	// else if (((note & TUPR) == TUPR) && (add > 0))
	// 	g->stat[2] += add--;
	// else
	// 	g->stat[0] += 1;
	// else if (((note & PAIR) == PAIR) && (add > 0))
	// 	g->stat[1] += add--;
	// else if (((note & STR8) == STR8) && (add > 0))
	// 	g->stat[4] += add--;
	// else if (((note & FLSH) == FLSH) && (add > 0))
	// 	g->stat[5] += add--;
	// else if (((note & FULL) == FULL) && (add > 0))
	// 	g->stat[6] += add--;
	// else if (((note & FOUR) == FOUR) && (add > 0))
	// 	g->stat[7] += add--;
	// else if (((note & STFL) == STFL) && (add > 0))
	// 	g->stat[8] += add--;
	// else if (((note & RYAL) == RYAL) && (add > 0))
	// 	g->stat[9] += add--;

	printf(">>>>>>>>>>>>RESULTS<<<<<<<<<<<<\n");
	// printf("ADD ---- %d\n", add);
    printf("HIGH	: %d\n", g->stat[0]);
    printf("PAIR	: %d\n", g->stat[1]);
    printf("DOUBLE	: %d\n", g->stat[2]);
    printf("THREE	: %d\n", g->stat[3]);
    printf("STR8	: %d\n", g->stat[4]);
    printf("FLUSH	: %d\n", g->stat[5]);
    printf("FULL	: %d\n", g->stat[6]);
    printf("FOUR	: %d\n", g->stat[7]);
    printf("ROYAL--	: %d\n", g->stat[8]);
    printf("ROYAL++	: %d\n", g->stat[9]);
    printf(">>>>>>>>>>>>STLUSER<<<<<<<<<<<<\n");
	// SDL_Delay(1000);
}

int					rate_hands(t_game *g)
{
	int					i;
	int					j;
	int					n;
	int					nmax;
	int					imax;
	
	i = 0;
	j = 0;
	n = 0;
	nmax = 0;
	imax = 0;
	while (i < g->npl)
	{
		while (j < 21)
		{
			if ((n = rate_pair(combo_hand(g->pl[i]->hand, g->w, j), i)))
			{
				imax = ((n & ON_RNK) > (nmax & ON_RNK)) ? i : imax;
				nmax = ((n & ON_RNK) > (nmax & ON_RNK)) ? n : nmax;
				// return (1);
			}
			j++;
		}
		j = 0;
		i++;
	}
	printf("---------------------NOTE BINARY\n%s\n", int2bin(nmax));
	printf("---R{4HFS42|HDCS-AKQJT9876543210\n");
	printf("--------------------------------\n");
	rate_scores(g, nmax);
	// if (nmax > 15 << 20)
	{
		// display_win(imax, nmax);
		// input_loop();
		// SDL_Delay(2225);
		// return (1);
	}
	// display_win(imax, nmax);
	// input_loop();
	// SDL_Delay(25);
	return (1);
}


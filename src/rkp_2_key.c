/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rkp_2_key.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymonfray <yukel.monfray@mac.com>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/04/22 04:15:14 by ymonfray          #+#    #+#             */
/*   Updated: 2015/04/22 04:15:14 by ymonfray         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rkp.h"


/* Print all information about a key event */
void 		PrintKeyInfo( SDL_KeyboardEvent *key ){
    /* Is it a release or a press? */
    if( key->type == SDL_KEYUP )
        printf( "Release:- " );
    else
        printf( "Press:- " );

    /* Print the hardware scancode first */
    printf( "Scancode: 0x%02X", key->keysym.scancode );
    /* Print the name of the key */
    printf( ", Name: %s", SDL_GetKeyName( key->keysym.sym ) );
    /* We want to print the unicode info, but we need to make */
    /* sure its a press event first (remember, release events */
    /* don't have unicode info                                */
    if( key->type == SDL_KEYDOWN ){
        /* If the Unicode value is less than 0x80 then the    */
        /* unicode value can be used to get a printable       */
        /* representation of the key, using (char)unicode.    */
        // printf(", Unicode: " );
        // if( key->keysym.unicode < 0x80 && key->keysym.unicode > 0 ){
        //     printf( "%c (0x%04X)", (char)key->keysym.unicode,
        //             key->keysym.unicode );
        // }
        // else{
        //     printf( "? (0x%04X)", key->keysym.unicode );
        // }
    }
    printf( "\n" );
    /* Print modifier info */
    // PrintModifiers( key->keysym.mod );
}


int			key_input(void)
{
  SDL_Event event;



  /* Poll for events. SDL_PollEvent() returns 0 when there are no  */
  /* more events on the event queue, our while loop will exit when */
  /* that occurs.                                                  */
  while (SDL_PollEvent(&event))
  {
	// SDL_EnableUNICODE(1);
    /* We are only worried about SDL_KEYDOWN and SDL_KEYUP events */
    switch (event.type)
    {
      case SDL_KEYDOWN:
        printf( "Key press detected\n" );
        PrintKeyInfo( &event.key );
     	if (event.key.keysym.sym == SDLK_SPACE)
	        return (1);
	    else if (event.key.keysym.sym == SDLK_ESCAPE)
	    {
	    	SDL_Quit();
	    	exit(0);
	    }

      case SDL_KEYUP:
        // printf( "Key release detected\n" );
        // PrintKeyInfo( &event.key );
        break;

      case SDL_QUIT:
    	  // PrintKeyInfo( &event.key );
	      SDL_Quit();
	      exit(0);
	  break;

      default:
        break;
    }

  }
  return (0);
}

void			input_loop(void)
{
  printf(".  ");
	// printf("Press ANY KEY!...\n");
	while (!key_input());
		// printf("scanning...\n");
}

// static void		set_keyboard(t_pong_data *data, int key_code, int key_down)
// {
// 	if (key_code == SDLK_ESCAPE)
// 		data->input.need_exit = true;
// 	else if (key_code == SDLK_w)
// 		data->input.in[P1_UP] = key_down;
// 	else if (key_code == SDLK_s)
// 		data->input.in[P1_DOWN] = key_down;
// 	else if (key_code == SDLK_UP)
// 		data->input.in[P2_UP] = key_down;
// 	else if (key_code == SDLK_DOWN)
// 		data->input.in[P2_DOWN] = key_down;
// }

// void			get_input(t_game *g)
// {
// 	SDL_Event	event;

// 	while (SDL_PollEvent(&event))
// 	{
// 		if (event.type == SDL_KEYDOWN)
// 			set_keyboard(data, event.key.keysym.sym, 1);
// 		else if (event.type == SDL_QUIT)
// 			data->input.need_exit = true;
// 	}
// }

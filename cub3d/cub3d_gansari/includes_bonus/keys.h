/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gansari <gansari@student.42berlin.de>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/04 15:34:19 by gansari           #+#    #+#             */
/*   Updated: 2025/08/11 13:12:55 by gansari          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYS_H
# define KEYS_H

# ifdef __linux__

/* =============================== KEY CODES =============================== */
typedef enum keys
{
	KEY_ESC = 65307,
	KEY_UP = 65362,
	KEY_DOWN = 65364,
	KEY_RIGHT = 65363,
	KEY_LEFT = 65361,
	KEY_ZERO = 48,
	KEY_ONE = 49,
	KEY_TWO = 50,
	KEY_THREE = 51,
	KEY_FOUR = 52,
	KEY_FIVE = 53,
	KEY_SIX = 54,
	KEY_SEVEN = 55,
	KEY_EIGHT = 56,
	KEY_NINE = 57,
	KEY_PLUS = 43,
	KEY_MINUS = 45,
	KEY_A = 97,
	KEY_B = 98,
	KEY_C = 99,
	KEY_D = 100,
	KEY_E = 101,
	KEY_F = 102,
	KEY_G = 103,
	KEY_H = 104,
	KEY_I = 105,
	KEY_J = 106,
	KEY_K = 107,
	KEY_L = 108,
	KEY_M = 109,
	KEY_N = 110,
	KEY_O = 111,
	KEY_P = 112,
	KEY_Q = 113,
	KEY_R = 114,
	KEY_S = 115,
	KEY_T = 116,
	KEY_U = 117,
	KEY_V = 118,
	KEY_W = 119,
	KEY_X = 120,
	KEY_Y = 121,
	KEY_Z = 122,
	MOUSE_LEFT_CLK = 1,
	MOUSE_SCRL_CLK = 2,
	MOUSE_RIGHT_CLK = 3,
	MOUSE_SCRL_UP = 4,
	MOUSE_SCRL_DOWN = 5,
}	t_keys;

# else

typedef enum keys
{
	KEY_ESC = 53,
	KEY_UP = 126,
	KEY_DOWN = 125,
	KEY_LEFT = 123,
	KEY_RIGHT = 124,
	KEY_ZERO = 29,
	KEY_ONE = 18,
	KEY_TWO = 19,
	KEY_THREE = 20,
	KEY_FOUR = 21,
	KEY_FIVE = 23,
	KEY_SIX = 22,
	KEY_SEVEN = 26,
	KEY_EIGHT = 28,
	KEY_NINE = 25,
	KEY_PLUS = 24,
	KEY_MINUS = 27,
	KEY_A = 0,
	KEY_B = 11,
	KEY_C = 8,
	KEY_D = 2,
	KEY_E = 14,
	KEY_F = 3,
	KEY_G = 5,
	KEY_H = 4,
	KEY_I = 34,
	KEY_J = 38,
	KEY_K = 40,
	KEY_L = 37,
	KEY_M = 46,
	KEY_N = 45,
	KEY_O = 31,
	KEY_P = 35,
	KEY_Q = 12,
	KEY_R = 15,
	KEY_S = 1,
	KEY_T = 17,
	KEY_U = 32,
	KEY_V = 9,
	KEY_W = 13,
	KEY_X = 7,
	KEY_Y = 16,
	KEY_Z = 6,
	MOUSE_LEFT_CLK = 1,
	MOUSE_RIGHT_CLK = 2,
	MOUSE_SCRL_CLK = 3,
	MOUSE_SCRL_DOWN = 4,
	MOUSE_SCRL_UP = 5,
}	t_keys;

# endif

#endif
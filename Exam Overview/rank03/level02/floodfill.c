/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floodfill.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hta-rezi1 <hta-rezi1@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/28 01:03:38 by hta-rezi1         #+#    #+#             */
/*   Updated: 2025/02/28 02:04:35 by hta-rezi1        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct  s_point
{
  int           x;
  int           y;
}  t_point;

void fill(char **tab, char target, int x, int y, t_point size){
    if (x < 0 || y < 0 || x >= size.x || y >= size.y)
        return ;
    if (tab[y][x] != target || tab[y][x] == 'F')
        return ;
    tab[y][x] = 'F';
    fill(tab, target, x, y - 1, size);
    fill(tab, target, x, y + 1, size);
    fill(tab, target, x - 1, y, size);
    fill(tab, target, x + 1, y, size);
}

void  flood_fill(char **tab, t_point size, t_point begin){
    char target = tab[begin.y][begin.x];
    if (size.x < 0 || size.y < 0)
        return ;
    fill(tab, target, begin.x, begin.y, size);
}

char **make_area(char **zone, t_point size){
    char **area = malloc(sizeof(char *) * size.y);
    for (int i = 0; i < size.y; i++){
        area[i] = malloc(sizeof(char) * (size.x + 1));
        for (int j = 0; j < size.x; j++){
            area[i][j] = zone[i][j];
        }
        area[i][size.x] = '\0';
    }
    return area;
}

int main(void){
    t_point begin = {2, 2};
    char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};
    t_point size = {16, 5};
    char **area = make_area(zone, size);
    for(int i = 0; i < size.y; i++){
        printf("%s\n", area[i]);
    }
    printf("=================================\n");

    flood_fill(area, size, begin);
    for(int i = 0; i < size.y; i++){
        printf("%s\n", area[i]);
    }
}
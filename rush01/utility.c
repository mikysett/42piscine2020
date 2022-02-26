/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msessa <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/06 09:45:02 by msessa            #+#    #+#             */
/*   Updated: 2020/12/06 09:45:05 by msessa           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdio.h>
#define N 4

extern int g_board[N][N];
extern int g_headers[N][N];

void	print_headers(void)
{
	printf("--- HEADERS ---\n");
	printf("    %d %d %d %d  \n", g_headers[0][0], g_headers[0][1], g_headers[0][2], g_headers[0][3]);
	printf("   %d_ _ _ _ %d\n", g_headers[2][0], g_headers[3][0]);
	printf("   %d_ _ _ _ %d\n", g_headers[2][1], g_headers[3][1]);
	printf("   %d_ _ _ _ %d\n", g_headers[2][2], g_headers[3][2]);
	printf("   %d_ _ _ _ %d\n", g_headers[2][3], g_headers[3][3]);
	printf("    %d %d %d %d  \n", g_headers[1][0], g_headers[1][1], g_headers[1][2], g_headers[1][3]);
}

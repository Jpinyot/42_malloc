/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:28:10 by jpinyot           #+#    #+#             */
/*   Updated: 2020/09/30 11:29:10 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmalloc.h"

void	free(void *ptr)
{
	t_mem_block*	block;
	t_mem_zone*	zone;

	if (ptr != NULL && k_zones != NULL)
	{
		block = (t_mem_block*)(ptr - sizeof(t_mem_block));
		/* if () { */
			if (block->free == BLOCK_FREE) {
				return ;
			}
			/* zone = getzone; */
			/* free_block(block); */
		/* } */
	}
}

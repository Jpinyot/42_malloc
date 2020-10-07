/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:28:10 by jpinyot           #+#    #+#             */
/*   Updated: 2020/10/07 10:56:54 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmalloc.h"
#include "utils.h"

void	ft_free(void *ptr)
{
	t_mem_block*	block;
	t_mem_zone*	zone;

	if (ptr != NULL && k_zones != NULL)
	{
		block = (t_mem_block*)(ptr - sizeof(t_mem_block));
		if (block->free == BLOCK_FREE) {
			return ;
		}
		zone = block->zone;
		zone->blocks_used -= 1;
		if (zone->blocks_created == ALLOCATION_PER_ZONE) {
			set_current_as_free_block(zone);
		}
		block->free = BLOCK_FREE;

	}
}

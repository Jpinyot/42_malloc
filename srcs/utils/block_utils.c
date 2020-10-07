/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 12:23:33 by jpinyot           #+#    #+#             */
/*   Updated: 2020/10/07 09:51:20 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_mem_block	*new_block(void* block, const size_t size, const enum e_zones_type zone_type)
{
	/* t_mem_block* block = (t_mem_block *)mem; */

	((t_mem_block *)block)->addr = block + sizeof(t_mem_block);
	/* printf("%p---%p\n", block, block->addr); */
	((t_mem_block *)block)->free = BLOCK_FREE;
	((t_mem_block *)block)->next = NULL;
	((t_mem_block *)block)->size = size;
	((t_mem_block *)block)->block_type = zone_type;

	return (block);
}

void		free_block(void* mem, const enum e_zones_type zone_type)
{
	t_mem_block* block = (t_mem_block *)mem;

	block->addr = NULL;
	block->free = BLOCK_FREE;
	block->next = NULL;
	block->size = 0;
	block->block_type = zone_type;
}

t_mem_block	*add_block_to_zone(t_mem_zone* zone, const size_t size, const enum e_zones_type zone_type)
{ /* TODO: when zone->blocks_created == ALLOCATION_PER_ZONE */ 
	t_mem_block	*block;
	t_mem_block	*next_block;
	void*		new_block_mem;

	/* t_mem_zone* zone = *mem; */


	if ((block = zone->current_block) == NULL) { /* TODO: Need to set block with new varables */
		return (NULL);
	}
	if (zone->blocks_created < ALLOCATION_PER_ZONE)
	{
		if (zone_type == e_tiny)
			new_block_mem = block + sizeof(t_mem_block) + TINY_SIZE;
		else if (zone_type == e_small)
			new_block_mem = block + sizeof(t_mem_block) + SMALL_SIZE;
		next_block = new_block(new_block_mem, size, zone_type);
		block->next = next_block;
		zone->current_block = next_block;
		zone->blocks_created += 1;
	}
	if (zone->blocks_created == ALLOCATION_PER_ZONE && zone->blocks_used < ALLOCATION_PER_ZONE)
		set_current_as_free_block(zone);
	return (block);
	/* return (curr_zone->current_block); */
}

t_mem_block	*get_freed_block(t_mem_zone* zone, const size_t size, const enum e_zones_type zone_type)
{ /* TODO: when zone is full, use current as beguinning of freed objects */
	t_mem_block	*block;

	block = zone->current_block;
	if (block)
	{
		zone->blocks_free -= 1;
		/* zone->blocks_created += 1; */ /* TODO: how to set??? */
		if (zone->blocks_free > 0) {
			zone->current_block = zone->first_block;
			while (zone->current_block && ((t_mem_block*)zone->current_block)->free == BLOCK_FREE)
				zone->current_block = ((t_mem_block*)zone->current_block)->next;
		}
		else
			zone->current_block = NULL;
	}
	return (block);
}

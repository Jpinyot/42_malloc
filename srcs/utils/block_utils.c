/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 12:23:33 by jpinyot           #+#    #+#             */
/*   Updated: 2020/10/07 11:13:58 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_mem_block	*new_block(void* block, void* zone, const size_t size, const enum e_zones_type zone_type)
{
	/* t_mem_block* block = (t_mem_block *)mem; */

	((t_mem_block *)block)->addr = block + sizeof(t_mem_block);
	((t_mem_block *)block)->zone = zone;
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
	if (block->free == BLOCK_USED) {
		/* write(1, "$", 1); */
	}
	if (zone->blocks_created < ALLOCATION_PER_ZONE)
	{
		if (zone_type == e_tiny)
			new_block_mem = block + sizeof(t_mem_block) + TINY_SIZE;
		else if (zone_type == e_small)
			new_block_mem = block + sizeof(t_mem_block) + SMALL_SIZE;
		next_block = new_block(new_block_mem, zone, size, zone_type);
		block->next = next_block;
		/* zone->current_block = next_block; */
		zone->current_block = block->next;
		zone->blocks_created += 1;
		/* write(1, "$", 1); */
	}
	else if (zone->blocks_created == ALLOCATION_PER_ZONE && zone->blocks_used < ALLOCATION_PER_ZONE)
	{
		block->free = BLOCK_USED; /* TODO: NEED TO BETTER THING WHEN MARK BLOCK AS FREE!!! */
		set_current_as_free_block(zone);
	}
	return (block);
	/* return (curr_zone->current_block); */
}

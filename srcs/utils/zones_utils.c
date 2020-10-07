/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zones_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:31:35 by jpinyot           #+#    #+#             */
/*   Updated: 2020/10/07 10:57:22 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	get_zone_size_by_zone_type(const enum e_zones_type zone_type)
{
	if (zone_type == e_tiny)
		return sizeof(t_mem_zone) + (TINY_SIZE * ALLOCATION_PER_ZONE * sizeof(t_mem_block));
	else if (zone_type == e_small)
		return sizeof(t_mem_zone) + (SMALL_SIZE * ALLOCATION_PER_ZONE * sizeof(t_mem_block));
	else
		return 0;
}

void	set_current_as_free_block(t_mem_zone* zone)
{
	t_mem_block* block;

	zone->current_block = NULL;
	if (zone->blocks_used < ALLOCATION_PER_ZONE)
	{
		block = zone->first_block;
		while (block)
		{
		       if (block->free == BLOCK_FREE)
		       {
				write(1, "#", 1);
			       zone->current_block = block;
			       break ;
		       }
		       block = block->next;
		}
	}
}
void	new_zone(t_mem_zone* zone, const enum e_zones_type zone_type)
{ /* TODO: need better implementation of block creation */
	void* block_mem = zone + sizeof(t_mem_zone);
	size_t size = TINY_SIZE;
	zone->first_block = new_block(block_mem, zone, size, zone_type);
	zone->current_block = zone->first_block;
	zone->blocks_created = 1;
	zone->blocks_used = 0;
	zone->zone_type = zone_type;
}

void		init_zone_from_size_type(t_mem_zone** zone, const enum e_zones_type zone_type)
{
	int zone_size = get_zone_size_by_zone_type(zone_type);
	*zone = mmap(0, zone_size , PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1,  0);
	new_zone(*zone, zone_type);
}

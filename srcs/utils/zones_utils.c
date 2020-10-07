/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zones_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:31:35 by jpinyot           #+#    #+#             */
/*   Updated: 2020/10/07 16:41:51 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

int	get_zone_size_from_zone_type(const enum e_zones_type zone_type)
{
	if (zone_type == e_tiny)
		return sizeof(t_mem_zone) + (TINY_SIZE * ALLOCATION_PER_ZONE * sizeof(t_mem_block));
	else if (zone_type == e_small)
		return sizeof(t_mem_zone) + (SMALL_SIZE * ALLOCATION_PER_ZONE * sizeof(t_mem_block));
	else if (zone_type == e_large)
		return sizeof(t_mem_zone);
	else
		return 0;
}

static int	get_size_from_zone_type(const enum e_zones_type zone_type)
{
	if (zone_type == e_tiny)
		return TINY_SIZE;
	else if (zone_type == e_small)
		return SMALL_SIZE;
	else if (zone_type == e_large)
		return 0;
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
			       zone->current_block = block;
			       break ;
		       }
		       block = block->next;
		}
	}
}
void	new_zone(t_mem_zone* zone, const enum e_zones_type zone_type)
{ /* TODO: need better implementation of block creation */
	zone->first_block = NULL;
	zone->current_block = NULL;
	zone->blocks_created = 0;
	zone->blocks_used = 0;
	zone->zone_type = zone_type;
	zone->next = NULL;
	if (zone_type != e_large)
	{
		void* block_mem = zone + sizeof(t_mem_zone);
		size_t size = get_size_from_zone_type(zone_type);
		zone->first_block = new_block(block_mem, zone, size, zone_type);
		zone->current_block = zone->first_block;
		zone->blocks_created = 1;
	}
}

void		init_zone_from_size_type(t_mem_zone** zone, const enum e_zones_type zone_type)
{
		/* printf("---------------------------\n"); */
	int zone_size = get_zone_size_from_zone_type(zone_type);
	*zone = mmap(0, zone_size , PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1,  0);
	new_zone(*zone, zone_type);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:28:10 by jpinyot           #+#    #+#             */
/*   Updated: 2020/10/07 17:01:28 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmalloc.h"
#include "utils.h"


static void	delete_zone(t_mem_zone* zone)
{
	t_mem_zone* tmp_zone;

	if (zone == NULL)
		return ;
	tmp_zone = k_zones;
	while(tmp_zone && tmp_zone->next && tmp_zone != zone)
	{
		if (tmp_zone->next == zone)
			break ;
	}
	if (tmp_zone->next == zone)
	{
		tmp_zone->next = zone->next;
	}
	else if (k_zones == zone)
	{
		k_zones = zone->next;
	}
		munmap(zone, get_zone_size_from_zone_type(zone->zone_type));
		zone = NULL;
}

static void	delete_block(t_mem_zone* zone, t_mem_block* block)
{
	t_mem_block* tmp_block;

	if (zone == NULL)
		return ;
	tmp_block = zone->first_block;
	while (tmp_block && tmp_block->next && tmp_block != block)
	{
		if (tmp_block->next == block)
			break ;
	}
	if (tmp_block->next == block)
	{
		tmp_block->next = block->next;
	}
	else if (zone->first_block == block)
	{
		zone->first_block = block->next;
	}
	munmap (block, sizeof(t_mem_block) + block->size);
	block = NULL;
}

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
		if (zone->zone_type == e_large)
		{
			write(1, "#", 1);
			delete_block(zone, block);
		}
		else {
			block->free = BLOCK_FREE;
			if (zone->blocks_created == ALLOCATION_PER_ZONE)
		       	{
				set_current_as_free_block(zone);
			}
		}
		if (zone->blocks_used == 0)
		{
			write(1, "%", 1);
			delete_zone(zone);
		}
	}
}

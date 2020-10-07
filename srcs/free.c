/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:28:10 by jpinyot           #+#    #+#             */
/*   Updated: 2020/10/07 16:44:01 by jpinyot          ###   ########.fr       */
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
		k_zones->next = zone->next;
	}
		munmap(zone, get_zone_size_from_zone_type(zone->zone_type));
		zone = NULL;
}

static void	delete_block(t_mem_zone* zone, t_mem_block* block)
{
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
		if (zone->blocks_used == 0)
		{
			delete_zone(zone);
		}
		else if (zone->zone_type == e_large)
		{
			delete_block(zone, block);
		}
		else if (zone->blocks_created == ALLOCATION_PER_ZONE) { /* ERROR: When last block is not used before free */
			/* write(1, "@", 1); */
			block->free = BLOCK_FREE;
			set_current_as_free_block(zone);
		}
	}
}

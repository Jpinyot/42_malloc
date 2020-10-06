/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:28:31 by jpinyot           #+#    #+#             */
/*   Updated: 2020/10/06 12:33:38 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmalloc.h"
#include "utils.h"


/* TODO: delete block struct?? what it comprts */

static enum e_zones_type	get_zone_type_from_size(const size_t size)
{
	if (size < TINY_MAX_SIZE)
		return e_tiny;
	else if (size < SMALL_MAX_SIZE)
		return e_small;
	else
		return e_large;
}

static t_mem_zone 	*get_zone_from_size(const size_t size)
{
	t_mem_zone		*zone;
	enum e_zones_type	zone_type;

	zone = k_zones;
	zone_type = get_zone_type_from_size(size);
	/* while (zone != NULL && zone->next != NULL) { */
	while (zone != NULL) {
		if (zone->zone_type == zone_type &&
			(zone->blocks_used < MIN_ALLOCATION_PER_ZONE ||
			 zone->blocks_free != 0)) {
			break ;
		}
		zone = zone->next;
	}
	if ( zone == NULL) {
		init_zone_from_size_type(&zone, &zone_type);
		if (zone == NULL) 
			return (NULL);
		else if (k_zones == NULL)
			k_zones = zone;
		else {
			zone->next = k_zones;
			k_zones = zone;
		}
	}
	return (zone);
}

static t_mem_block	*get_block(t_mem_zone* zone, const size_t* size)
{
	t_mem_block	*block;

	block = NULL;
	if (zone->blocks_used < MIN_ALLOCATION_PER_ZONE)
	{
		/* write(1, "#", 1); */
		block = add_block_to_zone(zone, size, &zone->zone_type);
	}
	else if (zone->blocks_free)
	{ /* TODO: use freed bloks when zone is full */
		/* write(1, "$", 1); */
		block = get_freed_block(zone, size, &zone->zone_type);
	}
	return(block);
}

void	*malloc(size_t size)
{
	t_mem_zone*	zone;
	t_mem_block*	block;

	if ((zone = get_zone_from_size(size)) == NULL) /* TODO: pass zone as argument and delete return */ 
		return (NULL);
	if ((block = get_block(zone, &size)) == NULL) /* TODO: pass block asargument and delete return */
		return (NULL);

	/* write(1, "#", 1); */
	/* update_block(&block, &size); */
	/* update_zone(&zone); */
	return (block->addr);
}

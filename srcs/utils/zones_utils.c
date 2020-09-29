/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zones_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:31:35 by jpinyot           #+#    #+#             */
/*   Updated: 2020/09/29 17:58:16 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

static int	get_zone_size_by_zone_type(const enum e_zones_type* zone_type)
{
	int zone_size;

	if (*zone_type == e_tiny)
		return sizeof(t_mem_zone *) + (TINY_SIZE * MIN_ALLOCATION_PER_ZONE * sizeof(t_mem_block *));
	else if (*zone_type == e_small)
		return sizeof(t_mem_zone *) + (SMALL_SIZE * MIN_ALLOCATION_PER_ZONE * sizeof(t_mem_block *));
	else
		return 0;
}

void	new_zone(t_mem_zone** zone, const enum e_zones_type* zone_type)
{
	t_mem_zone*	curr_zone = *zone;

	/* curr_zone->first_block = NULL; */
	/* curr_zone->current_block = NULL; */
	curr_zone->blocks_used = 0;
	curr_zone->zone_type = *zone_type;

	curr_zone->first_block = curr_zone + sizeof(t_mem_zone);
	curr_zone->current_block = curr_zone->first_block;
}

void		init_zone_from_size_type(t_mem_zone** zone, const enum e_zones_type* zone_type)
{
	int zone_size = get_zone_size_by_zone_type(zone_type);
	*zone = mmap(0, zone_size , PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1,  0);
	new_zone(zone, zone_type);
}

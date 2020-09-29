/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:28:31 by jpinyot           #+#    #+#             */
/*   Updated: 2020/09/29 16:51:50 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmalloc.h"
#include "utils.h"

static enum e_zones_type	get_zone_type_from_size(const size_t* size)
{
	if (*size < TINY_MAX_SIZE)
		return e_tiny;
	else if (*size < SMALL_MAX_SIZE)
		return e_small;
	else
		return e_large;
}

static t_mem_zone 	*get_zone_from_size(const size_t* size)
{
	t_mem_zone		*zone;
	enum e_zones_type	zone_type;

	zone_type = get_zone_type_from_size(size);
	zone = (t_mem_zone*)k_zones;
	while (zone != NULL && zone->zone_type != zone_type) { /* TODO: check for zone->next */
		zone = (t_mem_zone*)zone->next;
	}
	if ( zone == NULL) {
		init_zone_from_size_type(&zone, &zone_type);
		if (zone == NULL) 
			return (NULL);
	}
	return (zone);
}

static t_mem_block	*get_block(t_mem_zone** zone, const size_t* size)
{
	t_mem_block	*block;

	block = NULL;
	while (block == NULL)
	{
		/* ` */
	}
	return(block);
}

/* t_block	*get_block(t_block *block, t_zone *first_zone, size_t size) */
/* { */
/* 	t_zone	*current_zone; */

/* 	current_zone = first_zone; */
/* 	while (block == NULL) */
/* 	{ */
/* 		current_zone = get_right_zone(current_zone, size); */
/* 		if (current_zone == NULL) */
/* 		{ */
/* 			current_zone = add_new_zone(first_zone, size); */
/* 			if (current_zone == NULL) */
/* 				return (NULL); */
/* 			init_one_block(current_zone, current_zone->first_block, size); */
/* 		} */
/* 		block = get_reusable_block(current_zone->first_block, size); */
/* 		if (block == NULL) */
/* 		{ */
/* 			if (is_space_available_zone(current_zone, size) == TRUE) */
/* 				block = add_block_to_zone(current_zone, size); */
/* 			else */
/* 				current_zone = current_zone->next_zone; */
/* 		} */
/* 	} */
/* 	return (block); */
/* } */

void	*malloc(size_t size)
{
	t_mem_zone*	zone;
	t_mem_block*	block;

	if ((zone = get_zone_from_size(&size)) == NULL) /* TODO: pass zone as argument and delete return */ 
		return (NULL);
	if ((block = get_block(&zone, &size)) == NULL) /* TODO: pass block asargument and delete return */
		return (NULL);
	update_block(&block, &size);
	/* update_zone(&zone); */
	return (block->addr);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:14:24 by jpinyot           #+#    #+#             */
/*   Updated: 2020/10/07 09:49:34 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "stdio.h" /* printf, TODO: delete include */
#include "libmalloc.h"

t_mem_block	*new_block(void* mem, const size_t size, const enum e_zones_type zone_type);
void		free_block(void* mem, const enum e_zones_type zone_type);
t_mem_block	*add_block_to_zone(t_mem_zone* zone, const size_t size, const enum e_zones_type zone_type);
t_mem_block	*get_freed_block(t_mem_zone* zone, const size_t size, const enum e_zones_type zone_type);
/* void		update_block(t_mem_block* block, const size_t* size); */

void		set_current_as_free_block(t_mem_zone* zone);
void		new_zone(t_mem_zone* zone, const enum e_zones_type zone_type);
void		init_zone_from_size_type(t_mem_zone** zone, const enum e_zones_type zone_type);
/* void		update_zone(t_mem_zone** zone); */

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:14:24 by jpinyot           #+#    #+#             */
/*   Updated: 2020/09/29 16:18:58 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

#include "libmalloc.h"

t_mem_block	*new_block(void** mem, const size_t* size, const enum e_zones_type* zone_type);
void		free_block(void** mem, const enum e_zones_type* zone_type);
void		update_block(t_mem_block** block, const size_t* size);

t_mem_zone	*new_zone(const enum e_zones_type* zone_type);
void		update_zone(t_mem_zone** zone);

#endif

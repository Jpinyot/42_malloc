/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 10:14:24 by jpinyot           #+#    #+#             */
/*   Updated: 2020/09/29 10:25:39 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmalloc.h"

t_mem_block	*new_block(void** mem, const size_t* size, const enum e_zones_type* zone_type);
void		free_block(void** mem, const enum e_zones_type* zone_type);

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zones_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 12:31:35 by jpinyot           #+#    #+#             */
/*   Updated: 2020/09/29 12:43:25 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_mem_zone	*new_zone(const enum e_zones_type* zone_type)
{
	t_mem_zone*	zone = NULL;

	zone->first_block = NULL;
	zone->current_block = NULL;
	zone->blocks_used = 0;
	zone->zone_type = *zone_type;

	return (zone);
}

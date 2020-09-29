/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 12:23:33 by jpinyot           #+#    #+#             */
/*   Updated: 2020/09/29 10:43:53 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_mem_block	*new_block(void** mem, const size_t* size, const enum e_zones_type* zone_type)
{
	t_mem_block* block = (t_mem_block *)*mem;

	block->addr = NULL;
	block->free = 0;
	block->next = NULL;
	block->size = *(size);
	block->zone_type = *(zone_type);

	return (block);
}

void		free_block(void** mem, const enum e_zones_type* zone_type)
{
	t_mem_block* block = (t_mem_block *)*mem;

	block->addr = NULL;
	block->free = 0;
	block->next = NULL;
	block->size = 0;
	block->zone_type = *(zone_type);
}

void		add_block(void*** mem, t_mem_block** block_mem) /* TODO: need to check if enough space?? */
{
	t_mem_block** block_arr = (t_mem_block**)*mem;
	t_mem_block* block = (t_mem_block*)*block_mem;
	int i = -1;

	while (block_arr[++i]->next != NULL) {
		if (block_arr[i]->next->size >= block->size) {
			/* block->next = block_arr[i]->next; */
			/* block_arr[i]->next = block; */
			break ;
		}
	}
	if (block_arr[i]->next == NULL) /* TODO: check if [++i] change i */
		block->next = block_arr[i]->next;
	block_arr[i]->next = block;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 12:23:33 by jpinyot           #+#    #+#             */
/*   Updated: 2020/09/29 18:29:07 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_mem_block	*new_block(void** mem, const size_t* size, const enum e_zones_type* zone_type)
{
	t_mem_block* block = (t_mem_block *)*mem;

	block->addr = NULL;
	block->free = BLOCK_USED;
	block->next = NULL;
	block->size = *(size);
	block->block_type = *(zone_type);

	return (block);
}

void		free_block(void** mem, const enum e_zones_type* zone_type)
{
	t_mem_block* block = (t_mem_block *)*mem;

	block->addr = NULL;
	block->free = BLOCK_FREE;
	block->next = NULL;
	block->size = 0;
	block->block_type = *(zone_type);
}

void		update_block(t_mem_block** block, const size_t* size)
{
	t_mem_block	*curr_bock;

	curr_bock = *block;
	curr_bock->size = *size;
	curr_bock->free = BLOCK_USED;
}

t_mem_block	*add_block_to_zone(t_mem_zone** zone, const size_t* size, const enum e_zones_type* zone_type)
{
	t_mem_block	*block;
	t_mem_block	*new_block;
	t_mem_zone	*curr_zone;

	block = curr_zone->current_block; /* TODO: Need to set block with new varables */
	/* block = new_block(&block, size, zone_type); */

	new_block = block + sizeof(t_mem_block) + block->size; /* TODO: setting incorrect size */
	/* TODO: Need something new_block?? */
	write(1,"$", 1);
	block->size = 10;
	write(1,"#", 1);
	block->next = new_block;
	curr_zone->current_block = new_block;
	curr_zone->blocks_used += 1;
	return (block);
}
/* void		add_block(void*** mem, t_mem_block** block_mem) /1* TODO: need to check if enough space?? *1/ */
/* { */
/* 	t_mem_block** block_arr = (t_mem_block**)*mem; */
/* 	t_mem_block* block = (t_mem_block*)*block_mem; */
/* 	int i = -1; */

/* 	while (block_arr[++i]->next != NULL) { */
/* 		if (block_arr[i]->next->size >= block->size) { */
/* 			/1* block->next = block_arr[i]->next; *1/ */
/* 			/1* block_arr[i]->next = block; *1/ */
/* 			break ; */
/* 		} */
/* 	} */
/* 	if (block_arr[i]->next == NULL) /1* TODO: check if [++i] change i *1/ */
/* 		block->next = block_arr[i]->next; */
/* 	block_arr[i]->next = block; */
/* } */

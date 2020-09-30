/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 12:23:33 by jpinyot           #+#    #+#             */
/*   Updated: 2020/09/30 10:15:58 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

t_mem_block	*new_block(void** mem, const size_t* size, const enum e_zones_type* zone_type)
{
	t_mem_block* block = (t_mem_block *)*mem;

	block->addr = &mem + sizeof(t_mem_block);
	/* block->addr = NULL; */
	block->free = BLOCK_USED;
	block->next = NULL;
	block->size = 10;
	/* block->size = *(size); */
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
	t_mem_block	*next_block;
	t_mem_zone	*curr_zone;
	void*		new_block_mem;


	curr_zone = *zone;
	block = curr_zone->current_block; /* TODO: Need to set block with new varables */
	/* block = next_block(&block, size, zone_type); */

	/* next_block = block + sizeof(t_mem_block) + block->size; /1* TODO: setting incorrect size *1/ */
	if (*zone_type == e_tiny)
		new_block_mem = block +sizeof(t_mem_block) + TINY_SIZE;
	else if (*zone_type == e_small)
		new_block_mem = block +sizeof(t_mem_block) + SMALL_SIZE;
	next_block = new_block(&new_block_mem, size, zone_type);
	/* TODO: Need something next_block?? */
	/* write(1,"$", 1); */
	block->size = 10;
	/* write(1,"#", 1); */
	block->next = next_block;
	curr_zone->current_block = next_block;
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

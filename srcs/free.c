/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:28:10 by jpinyot           #+#    #+#             */
/*   Updated: 2020/09/30 12:51:48 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libmalloc.h"


/* TODO: WAYS TO IMPLEMENT FREE: 
 * 		-first use non freed blocks and after use current_block for empty
 * 			-need *prev for correct maintannce of the linked list
 * 		-first use freed blocks or not, depend of implementation
 * 			-need to iterate zone, to set current the first freed block:
 * 				-when free
 * 				-when used a freed block
 * */


void	free(void *ptr)
{
	t_mem_block*	block;
	t_mem_zone*	zone;

	if (ptr != NULL && k_zones != NULL)
	{
		block = (t_mem_block*)(ptr - sizeof(t_mem_block));
		/* if () { */
			if (block->free == BLOCK_FREE) {
				return ;
			}
			/* zone = getzone; */
			/* free_block(block); */
		/* } */
	}
}

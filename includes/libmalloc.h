/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmalloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:27:58 by jpinyot           #+#    #+#             */
/*   Updated: 2020/09/23 11:52:08 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/mman.h>		//mmap, munmap
#include <sys/resource.h>	//getrlimit
#include <unistd.h>		//getpagesize

const size_t k_tiny_max_size = 16;	//n
const size_t k_small_max_size = 64;	//m
const size_t k_tiny_size = 16;		//N
const size_t k_small_size = 64;		//M

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);

void	show_alloc_mem();

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmalloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:27:58 by jpinyot           #+#    #+#             */
/*   Updated: 2020/09/23 12:51:10 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMALLOC_H
# define LIBMALLOC_H

# include <stdlib.h>
# include <sys/mman.h> /* mmap, munmap */
# include <sys/resource.h> /* getrlimit */
# include <unistd.h> /* getpagesize */

/* const size_t k_tiny_max_size = 16; /1* n *1/ */
/* const size_t k_small_max_size = 64; /1* m *1/ */
/* const size_t k_tiny_size = 16; /1* N *1/ */
/* const size_t k_small_size = 64; /1* M *1/ */

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);

void	show_alloc_mem();

#endif

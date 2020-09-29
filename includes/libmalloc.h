/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmalloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:27:58 by jpinyot           #+#    #+#             */
/*   Updated: 2020/09/29 16:18:11 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMALLOC_H
# define LIBMALLOC_H

# include <stdlib.h>
# include <sys/mman.h> /* mmap, munmap */
# include <sys/resource.h> /* getrlimit */
# include <unistd.h> /* getpagesize */
# include <pthread.h> /* bonus part */

/* #include "util.h" /1* header for utils .c files *1/ */

/* const size_t k_tiny_size = getpagesize(); /1* N *1/ */
/* const size_t k_small_size = getpagesize() * 4; /1* M *1/ */
/* const size_t k_tiny_max_size = k_tiny_size / 2; /1* n *1/ */
/* const size_t k_small_max_size = k_small_size / 2; /1* m *1/ */

#define MIN_ALLOCATION_PER_ZONE = 100;

#define BLOCK_FREE  0;
#define BLOCK_USED  1;

#define TINY_SIZE getpagesize() /* N */
#define SMALL_SIZE getpagesize() * 4 /* M */
#define TINY_MAX_SIZE  (TINY_SIZE / 2) /* n */
#define SMALL_MAX_SIZE  (SMALL_SIZE * 2) /* m */

/* #define TINY_SIZE 10 /1* N *1/ */
/* #define SMALL_SIZE 20 /1* M *1/ */
/* #define TINY_MAX_SIZE 10 / 2 /1* n *1/ */
/* #define SMALL_MAX_SIZE  20 / 2 /1* m *1/ */

/* const size_t k_allocation_count = 100; */

enum	e_zones_type
{
	e_tiny,
	e_small,
	e_large
};

typedef struct	s_mem_block
{
	void			*addr;
	size_t			size;
	enum e_zones_type	block_type;
	/* char			zone_id; */
	char			free;
	struct s_mem_block	*next;
	/* struct s_mem_block	*left; */
	/* struct s_mem_block	*right; */
}		t_mem_block;

typedef struct s_mem_zone		//sort by addr
{
	void			*first_block;
	void			*current_block;
	size_t			blocks_used;
	enum e_zones_type	zone_type;

	void			*next;
	/* struct t_mem_zone	*next; */
}		t_mem_zone;

/* typedef struct	s_zones_manager */
/* { */
/* 	void		*first_tiny_zone; */
/* 	void		*first_small_zone; */

/* 	void		*large_zone; */

/* 	void		*current_tiny_zone; */
/* 	void		*current_small_zone; */

/* 	/1* pthread_mutex_t	lock; *1/ */
/* 	/1* int			lock_init; *1/ */
/* }		t_zones_manager; */

void	*k_zone_manager;
void	*k_zones;

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);

void	show_alloc_mem();

/* UTILS */
t_mem_block	*new_block();
void		delete_block();
void		delete_next_block();

#endif

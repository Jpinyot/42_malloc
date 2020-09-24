/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libmalloc.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 10:27:58 by jpinyot           #+#    #+#             */
/*   Updated: 2020/09/24 12:51:49 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBMALLOC_H
# define LIBMALLOC_H

# include <stdlib.h>
# include <sys/mman.h> /* mmap, munmap */
# include <sys/resource.h> /* getrlimit */
# include <unistd.h> /* getpagesize */
# include <pthread.h> /* bonus part */

/* const size_t k_tiny_size = getpagesize(); /1* N *1/ */
/* const size_t k_small_size = getpagesize() * 4; /1* M *1/ */
/* const size_t k_tiny_max_size = k_tiny_size / 2; /1* n *1/ */
/* const size_t k_small_max_size = k_small_size / 2; /1* m *1/ */

#define TINY_SIZE = getpagesize(); /* N */
#define SMALL_SIZE = getpagesize() * 4; /* M */
#define TINY_MAX_SIZE = TINY_SIZE / 2; /* n */
#define SMALL_MAX_SIZE = SMALL_SIZE / 2; /* m */

const size_t k_allocation_count = 100;

enum	e_zones_type
{
	tiny,
	small,
	large
};

typedef struct	s_mem_block
{
	void			*addr;
	size_t			size;
	enum e_zones_type	zone_type;
	struct s_mem_block	*next;
	/* struct s_mem_block	*left; */
	/* struct s_mem_block	*right; */
}		t_mem_block;

/* ypedef struct		s_block { */
/* 	void			*addr; */
/* 	size_t			size; */
/* 	struct s_block	*next; */
/* 	short			zone_type; */
/* 	char			zone_id; */
/* 	char			free; */
/* }					t_block; */

typedef struct	s_env
{
	t_mem_block		*tiny;
	t_mem_block		*small;
	t_mem_block		*large;
	/* pthread_mutex_t	lock; */
	/* int			lock_init; */
}		t_env;

struct s_env	*k_env;

void	free(void *ptr);
void	*malloc(size_t size);
void	*realloc(void *ptr, size_t size);

void	show_alloc_mem();

/* UTILS */
t_mem_block	*new_block();
void		delete_block();
void		delete_next_block();

#endif

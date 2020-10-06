/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:04:12 by jpinyot           #+#    #+#             */
/*   Updated: 2020/10/06 12:32:04 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../include/libmalloc.h" */
#include "libmalloc.h"
#include "stdio.h"

int	main(void)
{
	/* int int_test = 10; */
	/* void* test = malloc(sizeof(int)); */
	/* write(1, "1", 1); */
	int* test = malloc(sizeof(int));
	/* write(1, "2", 1); */
	int* test2 = malloc(sizeof(int));
	/* write(1, "3", 1); */
	int* test3 = malloc(sizeof(int));
	int* test4 = malloc(sizeof(int));
	*test = 11;
	*test2 = 21;
	*test3 = 31;
	*test4 = 41;
	/* write(1, "<", 1); */
	printf("%i---%p\n %i---%p\n %i---%p\n %i---%p\n", *test, test, *test2, test2, *test3, test3, *test4, test4);
	/* write(1, ">", 1); */
	return (0);
}

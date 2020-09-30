/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:04:12 by jpinyot           #+#    #+#             */
/*   Updated: 2020/09/30 10:24:18 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../include/libmalloc.h" */
#include "libmalloc.h"
#include "stdio.h"

int	main(void)
{
	/* int int_test = 10; */
	/* void* test = malloc(sizeof(int)); */
	write(1, "1", 1);
	int* test = malloc(sizeof(int));
	write(1, "2", 1);
	int* test2 = malloc(sizeof(int));
	write(1, "3", 1);
	*test = 11;
	*test2 = 21;
	write(1, "<", 1);
	printf("%i---%i", *test, *test2);
	write(1, ">", 1);
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:04:12 by jpinyot           #+#    #+#             */
/*   Updated: 2020/10/07 10:58:35 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../include/libmalloc.h" */
#include "libmalloc.h"
#include "stdio.h"

int	main(void)
{
	int* test;
	for (int i = 0; i < 10; i++) {
		test = ft_malloc(sizeof(int));
		*test = i;
		printf("%-3i---%p\n", *test, test);
		ft_free(test);
	}
		printf("---------------------------\n");
	for (int i = 0; i < 10; i++) {
		test = ft_malloc(sizeof(int));
		printf("%-3i---%p\n", *test, test);
	}
	return (0);
}

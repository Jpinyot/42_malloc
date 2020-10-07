/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:04:12 by jpinyot           #+#    #+#             */
/*   Updated: 2020/10/07 16:45:52 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../include/libmalloc.h" */
#include "libmalloc.h"
#include "stdio.h"

const int k_test_large_size = 10000000;

int	main(void)
{
	char* test_large;

	test_large = ft_malloc(sizeof(char) * k_test_large_size);
	for (int i = 0; i < k_test_large_size; i++) {
		test_large[i] = 'a';
	}
	ft_free(test_large);
	test_large = ft_malloc(sizeof(char) * k_test_large_size);
	for (int i = 0; i < k_test_large_size; i++) {
		test_large[i] = 'a';
	}
	/* write(1, test_large, k_test_large_size); */
	ft_free(test_large);
		/* printf("%-3i---%p\n", *test, test); */


	/* int* test; */
	/* for (int i = 0; i < 10; i++) { */
	/* 	test = ft_malloc(sizeof(int)); */
	/* 	*test = i + 1; */
	/* 	printf("%-3i---%p\n", *test, test); */
	/* 	/1* if (i < 9) *1/ */
	/* 	ft_free(test); */
	/* } */
	/* printf("\n+++++++++++++++++\n"); */
	/* for (int i = 0; i < 10; i++) { */
	/* 	test = ft_malloc(sizeof(int)); */
	/* 	printf("%-3i---%p\n", *test, test); */
	/* } */
	return (0);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 10:04:12 by jpinyot           #+#    #+#             */
/*   Updated: 2020/09/30 10:19:09 by jpinyot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* #include "../include/libmalloc.h" */
#include "libmalloc.h"
#include "stdio.h"

int	main(void)
{
	int int_test = 10;
	/* void* test = malloc(sizeof(int)); */
	int* test = malloc(sizeof(int));
	int* test2 = malloc(sizeof(int));
	*test = int_test;
	*test2 = 21;
	printf("%i\n%i\n", *test, *test2);
	return (0);
}

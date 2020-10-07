# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    CMakeLists.txt                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jpinyot <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/23 10:17:31 by jpinyot           #+#    #+#              #
#    Updated: 2020/10/07 10:08:17 by jpinyot          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

cmake_minimum_required(VERSION 3.10)
# set (CMAKE_CXX_STANDARD 11)

# set the project name
project(malloc C)

# for YCM vim
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# set definitions
#add_definitions(-O2)

# add the executable
# DSLR
add_executable(		malloc
			srcs/test_main.c
			srcs/utils/block_utils.c
			srcs/utils/zones_utils.c
			srcs/malloc.c
			srcs/free.c
			)

target_include_directories(malloc PRIVATE 
			"${CMAKE_SOURCE_DIR}/includes"
			)

set(HEADER_FILES	
			includes/libmalloc.h
			includes/utils.h
			)

#find_package (Eigen3 3.3 REQUIRED NO_MODULE)
#target_link_libraries (DSLR Eigen3::Eigen)


# dependencies for Python.h, used for ploting
# find_package(Python2 COMPONENTS Development NumPy)
# target_include_directories(DSLR PRIVATE ${Python2_INCLUDE_DIRS} ${Python2_NumPy_INCLUDE_DIRS})
# target_link_libraries(DSLR Python2::Python Python2::NumPy)

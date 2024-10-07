/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:04:21 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/07 19:09:37 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

// Implement a function template iter that takes 3 parameters and returns nothing.
// • The first parameter is the address of an array.
// • The second one is the length of the array.
// • The third one is a function that will be call on every element of the array.
// Turn in a main.cpp file that contains your tests. Provide enough code to generate a test executable.
// Your iter function template must work with any type of array. The third parameter can be an instantiated function template.

template<typename T>
void multiply(T &x) {
	x *= 2;
}

template<typename T>
void	iter(T *arr, int n, void (*function)(T &obj)) {
	for (int i = 0; i < n; i++) {
		function(arr[i]);
	}
}


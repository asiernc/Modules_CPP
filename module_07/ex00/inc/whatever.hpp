/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:04:21 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/07 18:29:34 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>

template <typename T>
void swap(T &a, T &b) {
	T	tmp = a;

	a = b;
	b = tmp;
}

template <typename T>
T& min(T &x, T &y) {
	return ((x < y) ? x : y);
}

template <typename T>
T& max(T &x, T &y) {
	return ((x > y) ? x : y);
}

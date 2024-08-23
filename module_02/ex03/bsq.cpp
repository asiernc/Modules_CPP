/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 17:36:25 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/23 15:20:18 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include "Point.hpp"

// To conclude, implement the following function in the appropriate file:
//     bool bsp( Point const a, Point const b, Point const c, Point const point);
// • a, b, c: The vertices of our beloved triangle.
// • point: The point to check.
// • Returns: True if the point is inside the triangle. False otherwise. Thus, if the point is a vertex or on edge, it will return False.

static Fixed sign(Point a, Point b, Point c) {
	Fixed	result;
	
	result = (a.x() - c.x()) * (b.y() - c.y()) - (b.x() - c.x()) * (a.y() - c.y());
    return (result);
}

bool	bsp(const Point a, const Point b, const Point c, const Point point) {
	Fixed	d1, d2, d3;
	bool	hasNeg, hasPos;
	
	d1 = sign(point, a, b);
	d2 = sign(point, b, c);
	d3 = sign(point, c, a);

	hasNeg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	hasPos = (d1 > 0) || (d2 > 0) || (d3 > 0);
	if ((d1 == 0 || d2 == 0 || d3 == 0)
		|| (hasNeg && hasPos))
		return (false);
	return (true);
} 

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:04:21 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/08 21:43:35 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <exception>
# include <algorithm>
# include <vector>

class Span {
	private:
		std::vector<unsigned int>	_container;
		unsigned int		_maxSize;

	public:
		Span(void);
		Span(unsigned int size);
		Span(const Span &src);
		Span &operator=(const Span &src);
		~Span(void);

		class maxReached : public std::exception {
			public:
				virtual const char *what(void) const throw() {
					return ("Max of size vector is limit.");
				}
		};

		class emptyArray : public std::exception {
			public:
				virtual const char *what(void) const throw () {
					return ("The container is empty.");
				}
		};

		class onlyOne : public std::exception {
			public:
				virtual const char *what(void) const throw () {
					return ("Is impossible calculate the span with only one number stored.");
				}
		};

		class moreThanOne : public std::exception {
			public:
				virtual const char *what(void) const throw () {
					return ("You cannot fill the container with 0 numbers :\\");
				}
		};

		class sizeMax : public std::exception {
			public:
				virtual const char *what(void) const throw () {
					return ("You cannot fill the container with more than the size of this. :\\");
				}
		};

		void			addNumber(unsigned int num);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		void			fillRandom(unsigned int size);

		// Last but not least, it would be wonderful to fill your Span using a 
		// range of iterators. Making thousands calls to addNumber() is so
		// annoying. Implement a member function to add many numbers to your
		// Span in one call.

		

		void			showArray(void);

};


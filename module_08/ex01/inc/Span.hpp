/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:04:21 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/15 12:07:06 by anovio-c         ###   ########.fr       */
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
		unsigned int				_maxSize;

	public:
		Span(void);
		Span(unsigned int size);
		Span(const Span &src);
		Span &operator=(const Span &src);
		~Span(void);


		void			addNumber(unsigned int num);
		unsigned int	shortestSpan(void);
		unsigned int	longestSpan(void);
		void			fillRandom(unsigned int size);
		void			cleanVector(void);
		void			showArray(void);

		template<typename Iterator>
		void	addRange(Iterator begin, Iterator end) {
			if (std::distance(begin, end) + this->_container.size() > this->_maxSize)
				throw sizeMax();
			for (Iterator it = begin; it != end; it++)
				this->addNumber(*it);
		}
		
		class maxReached : public std::exception {
			public:
				virtual const char *what(void) const throw() {
					return ("Reached max of vector size.");
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
};


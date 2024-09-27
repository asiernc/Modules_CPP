/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:05:59 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/26 22:18:10 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <stdexcept>
# include <cstdlib>

enum specialLiteral {
	DEFAULT,
	NaN,
	MINUS_INF,
	MINUS_INFF,
	PLUS_INF,
	PLUS_INFF
};

class ScalarConverter {
	private:
		static char			_char;
		static int			_int;
		static float		_float;
		static double		_double;
		
		static bool			isChar(std::string &str);
		static bool			isInt(std::string &str);
		static bool			isFloat(std::string &str);
		static bool			isDouble(std::string &str);
		static bool			isSpecialLiteral(std::string &str);
		static void			showChar(std::string &str);
		static void			showInt(std::string &str);
		static void			showFloat(std::string &str);
		static void			showDouble(std::string &str);
		static void			showSpecialLiteral(std::string &str);
		static void			displayPrompt(void);
		ScalarConverter(void);
		ScalarConverter(const ScalarConverter &src);
		ScalarConverter	&operator=(const ScalarConverter &src);
		~ScalarConverter(void);
	public:
		class notValidChars : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Error: the string contains invalid characters.");
				}
		};
		static void	convert(std::string num);
};

// char, int, float, double o un valor especial como nan o
// inf antes de hacer las conversiones:

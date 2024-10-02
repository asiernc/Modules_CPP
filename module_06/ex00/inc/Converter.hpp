/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Converter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/26 20:05:59 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/01 16:12:58 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <stdexcept>
# include <string>
# include <cstdlib>
# include "ScalarConverter.hpp"

# define RESET   "\033[0m"
# define RED     "\033[31m"
# define YELLOW  "\033[33m"
# define LIGHT_BLUE "\033[36m"
# define GREEN   "\033[32m" 


enum specialLiteral {
	MINUS_INF = 1,
	PLUS_INF
};

enum type {
	CHAR = 1,
	INT,
	FLOAT,
	DOUBLE,
	SPECIAL,
	NaN,
	NON_DISPL
};

class Converter : public ScalarConverter {
	private:

		// Variable types
		char		_char;
		int			_int;
		float		_float;
		double		_double;

		// Utils variables
		std::string			_input;
		int					_inputType;
		int					_specialLiteral;
		
		// _ TO PRIVATE MEMBER FUNCTIONS
		void			checkInput(std::string &input);
		bool			isChar(std::string &str);
		bool			isInt(std::string &str);
		bool			isFloat(std::string &str);
		bool			isDouble(std::string &str);
		void			toChar(std::string &str);
		void			toInt(std::string &str);
		void			toFloat(std::string &str);
		void			toDouble(std::string &str);
		void			displayPromptEspecial(void);
		void			displayPrompt(void);
		
	public:
		// orthodoxical canonical form
		Converter(void);
		Converter(std::string &input);
		Converter(const Converter &src);
		Converter	&operator=(const Converter &src);
		~Converter(void);

		// Getters Setters
		std::string	getInput(void) const;
		int			getInputType(void) const;
		char		getChar(void) const;
		int			getInt(void) const;
		float		getFloat(void) const;
		double		getDouble(void) const;
		int			getSpecialLiteral(void) const;


		class notValidChars : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Error: the string contains invalid characters.");
				}
		};
		class notValidInput : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Error: not valid input.");
				}
		};
		virtual void	convert(void);
};


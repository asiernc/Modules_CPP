/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/15 20:00:25 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/15 20:53:44 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_HPP
# define HARL_HPP

# include <iostream>
# include <stdbool.h>

// Colores ANSI
#define RESET   "\033[0m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define BLUE    "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN    "\033[36m"
#define WHITE   "\033[37m"

// Fondo de colores ANSI
#define BACK_RED     "\033[41m"
#define BACK_GREEN   "\033[42m"
#define BACK_YELLOW  "\033[43m"
#define BACK_BLUE    "\033[44m"
#define BACK_MAGENTA "\033[45m"
#define BACK_CYAN    "\033[46m"
#define BACK_WHITE   "\033[47m"

class Harl
{
private:
	void _debug(void);
	void _info(void);
	void _warning(void);
	void _error(void);
public:
	Harl(/* args */);
	~Harl();
	void    complain(std::string level);
};


#endif

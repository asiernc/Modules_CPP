/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:54:38 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/28 21:36:01 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H

# define FRAGTRAP_H

# include "ClapTrap.hpp" 
# include <iostream>

class FragTrap : virtual public ClapTrap {
	private:
		
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &src);
		~FragTrap();
		FragTrap	&operator=(const FragTrap &src);

		void 		attack(const std::string& target);
		void		highFivesGuys(void);
};

#endif

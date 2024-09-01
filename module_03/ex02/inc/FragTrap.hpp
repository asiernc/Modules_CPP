/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/27 19:54:38 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/27 20:28:41 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAGTRAP_H

# define FRAGTRAP_H

# include "ClapTrap.hpp" 
# include <iostream>

class FragTrap : public ClapTrap {
	private:
		
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(const FragTrap &src);
		~FragTrap();
		FragTrap	&operator=(const FragTrap &src);

		void		highFivesGuys(void);
};

#endif

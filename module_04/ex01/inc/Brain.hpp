/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/01 19:50:22 by anovio-c          #+#    #+#             */
/*   Updated: 2024/09/02 10:01:59 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>

# define MAX_IDEAS 10

class Brain {
	protected:
		std::string _ideas[MAX_IDEAS];

	public:
		Brain(void);
		Brain(const Brain &src);
		Brain &operator=(const Brain &src);
		~Brain(void);

		void	setIdea(int index, std::string idea);
		std::string	getIdea(int index);
};

#endif

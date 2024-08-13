/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 20:37:10 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/05 20:37:11 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int ac, char **av)
{
    int i;
    int j;

    if (ac < 2)
        std::cout << "* LOUD AND UNBEREABLE FEEDBACK NOISE *";
    i = -1;
    if (ac > 1)
    {
        while (av && av[++i])
        {
            j = -1;
            while (i > 0 && av[i][++j])
                std::cout << (char)std::toupper(av[i][j]);
        }
    }
    std::cout << std::endl;
    return (0);
}

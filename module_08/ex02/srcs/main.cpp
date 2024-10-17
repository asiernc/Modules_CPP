/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/07 18:03:25 by anovio-c          #+#    #+#             */
/*   Updated: 2024/10/17 12:23:20 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MutantStack.hpp"

static void	ownTest(void) {
	{
        std::cout << "MutantStack - Alternative Test" << std::endl;
        MutantStack<int> mstack;

        mstack.push(42);
		std::cout << "Pushing 42" << std::endl;
        mstack.push(84);
		std::cout << "Pushing 84" << std::endl;
        mstack.push(21);
		std::cout << "Pushing 21" << std::endl;
        mstack.push(63);
		std::cout << "Pushing 63" << std::endl;

		MutantStack<int>::iterator it1 = mstack.begin();
        MutantStack<int>::iterator ite1 = mstack.end();

        std::cout << "Iterator throught MutantStack:" << std::endl;
        for (; it1 != ite1; ++it1) {
            std::cout << *it1 << " ";
        }
		std::cout << std::endl;
        
        std::cout << "Size of stack: " << mstack.size() << std::endl;
        std::cout << "Top element: " << mstack.top() << std::endl;

        mstack.pop();
        std::cout << "Delete element. New top: " << mstack.top() << std::endl;
        
        MutantStack<int>::iterator it = mstack.begin();
        MutantStack<int>::iterator ite = mstack.end();

        std::cout << "Iterator throught MutantStack:" << std::endl;
        for (; it != ite; ++it) {
            std::cout << *it << " ";
        }
        std::cout << std::endl;

        std::cout << "Copying MutantStack to another MutantStack..." << std::endl;
        MutantStack<int> mstack_copy(mstack);
        
        MutantStack<int>::iterator it_copy = mstack_copy.begin();
        MutantStack<int>::iterator ite_copy = mstack_copy.end();

        std::cout << "Iterator trought MutantStack Copy" << std::endl;
        for (; it_copy != ite_copy; ++it_copy) {
            std::cout << *it_copy << " ";
        }
        std::cout << std::endl;

        std::cout << "Copy size: " << mstack_copy.size() << std::endl;
    }
}

int main( void ) {
	{
		std::cout << "MutantStack" << std::endl;
		MutantStack<int>	mstack;

		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::const_iterator it = mstack.begin();
		MutantStack<int>::const_iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	{
		std::cout << "NotMutant Lists" << std::endl;
		std::list<int>	mstack;

		mstack.push_back(5);
		mstack.push_back(17);
		std::cout << mstack.back() << std::endl;
		mstack.pop_back();
		std::cout << mstack.size() << std::endl;
		mstack.push_back(3);
		mstack.push_back(5);
		mstack.push_back(737);
		//[...]
		mstack.push_back(0);
		std::list<int>::iterator it = mstack.begin();
		std::list<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
	}

	std::cout << "_______________________________________________\n\n";
	ownTest();
	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anovio-c <anovio-c@student.42barcelona.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/05 21:15:39 by anovio-c          #+#    #+#             */
/*   Updated: 2024/08/06 21:41:18 by anovio-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


int	Account::getNbAccounts(void) {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void) {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void) {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void) {
	return (Account::_totalNbWithdrawals);
}

void Account::_displayTimestamp(void) {
	std::time_t	now;
	std::tm* localTime;

	now = std::time(0);
	localTime = std::localtime(&now);
	std::cout << "[" << (localTime->tm_year + 1900) << (localTime->tm_mon + 1)
		<< localTime->tm_mday;
	std::cout << "_" << localTime->tm_hour << localTime->tm_min <<
		localTime->tm_sec << "] ";
}

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << Account::getNbAccounts()
		<< ";total:" << Account::getTotalAmount()
		<< ";deposits:" << Account::getNbAccounts()
		<< ";withdrawals" << Account::getNbWithdrawals()
		<< std::endl;
}

Account::Account() {
	Account::_accountIndex = 0;
	Account::_amount = 0;
	Account::_nbDeposits = 0;
	Account::_nbWithdrawals = 0;
}

Account::Account(int initial_deposit) {
	_accountIndex = _nbAccounts++;
	_amount = initial_deposit;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout <<
		"index:" << _accountIndex
		<< "amount:" << _amount
		<< ";created" << std::endl;
	
}

Account::~Account(void) { // ya estoy dentro de la instancia de account por lo
						// que no es necesario antes de llamar a la variable
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed" << std::endl;
}

void	Account::makeDeposit(int deposit) {
	
}

bool	Account::makeWithdrawal(int withdrawal) {
	
}

int	Account::checkAmount(void) const {
	
}

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits;" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals
		<< std::endl;
}
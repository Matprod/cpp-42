/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Matprod <matprod42@gmail.com>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 13:21:14 by Matprod           #+#    #+#             */
/*   Updated: 2025/03/03 23:32:51 by Matprod          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;


int	Account::getNbAccounts() {
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount() {
	return (Account::_totalAmount);
}

int	Account::getNbDeposits() {
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals() {
	return (Account::_totalNbWithdrawals);
}

int	Account::checkAmount() const {
	return (this->_amount);
}

void Account::_displayTimestamp(void) {
	time_t now = time(NULL);
	struct tm* timeinfo = localtime(&now);
	char buffer[20];
	std::cout << "\033[0m";
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S] ", timeinfo);
	std::cout << buffer;
}

void	Account::makeDeposit(int deposit) {
	this->_nbDeposits++;
	this->_amount += deposit;
	Account::_totalNbDeposits++;
	Account::_totalAmount += deposit;
	Account::_displayTimestamp();
	std::cout << "\033[0mindex:\033[34m" << this->_accountIndex;
	std::cout << "\033[0m;p_amount:\033[34m" << this->_amount - deposit;
	std::cout << "\033[0m;deposit:\033[34m" << deposit;
	std::cout << "\033[0m;amount:\033[34m" << this->_amount;
	std::cout << "\033[0m;nb_deposits:\033[34m" << this->_nbDeposits << std::endl;
}

bool	Account::makeWithdrawal(int withdrawal) {
	Account::_displayTimestamp();
	std::cout << "\033[0mindex:\033[34m" << this->_accountIndex;
	std::cout << "\033[0m;p_amount:\033[34m" << this->_amount;
	std::cout << "\033[0m;withdrawal:\033[34m";
	if (withdrawal > this->_amount) {
		std::cout << "\033[0mrefused\033[34m" << std::endl;
		return (false);
	}
	std::cout << withdrawal;
	this->_amount -= withdrawal;
	this->_nbWithdrawals ++;
	std::cout << "\033[0m;amount:\033[34m" << this->_amount;
	std::cout << "\033[0m;nb_withdrawals:\033[34m" << this->_nbWithdrawals << std::endl;
	Account::_totalNbWithdrawals++;
	Account::_totalAmount-=withdrawal;
	return (true);
}

void	Account::displayAccountsInfos() {
	Account::_displayTimestamp();
	std::cout << "\033[0maccounts:\033[34m" << getNbAccounts();
	std::cout << "\033[0m;total:\033[34m" << getTotalAmount();
	std::cout << "\033[0m;deposits:\033[34m" << getNbDeposits();
	std::cout << "\033[0m;withdrawals:\033[34m" << getNbWithdrawals() << std::endl;
}

void	Account::displayStatus() const{
	Account::_displayTimestamp();
	std::cout << "\033[0mindex:\033[34m" << this->_accountIndex;
	std::cout << "\033[0m;amount:\033[34m" << this->_amount;
	std::cout << "\033[0m;deposits:\033[34m" << this->_nbDeposits;
	std::cout << "\033[0m;withdrawals:\033[34m" << this->_nbWithdrawals << std::endl;
}

Account::Account(int deposit) {
	Account::_displayTimestamp();
	Account::_totalAmount += deposit;
	this->_accountIndex = Account::_nbAccounts;
	this->_amount = deposit;
	this->_nbDeposits = 0;
	this->_nbWithdrawals = 0;
	_nbAccounts++;
	std::cout << "\033[0mindex:\033[34m" << _accountIndex;
	std::cout << "\033[0m;amount:\033[34m" << deposit;
	std::cout << "\033[0m;created" << std::endl;
}

Account::Account()
{}

Account::~Account() {
	Account::_displayTimestamp();
	std::cout << "\033[0mindex:\033[34m" << this->_accountIndex;
	std::cout << "\033[0m;amount:\033[34m" << this->_amount;
	std::cout << "\033[0m;closed\033[0m" << std::endl;
}




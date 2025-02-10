/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:40:24 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/10 14:25:24 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

// static varianle init
int	Account::_totalAmount = 0;
int	Account::_nbAccounts = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// getters
int	Account::getNbAccounts(void){
	return _nbAccounts;
}

int	Account::getTotalAmount(void){
	return _totalAmount;
}

int	Account::getNbDeposits(void){
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void){
	return _totalNbWithdrawals;
}

// constructor
Account::Account(int initial_deposit)
	:_accountIndex(_nbAccounts++), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
		_totalAmount += _amount;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << "; created" << std::endl;
}

Account::Account(void){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << "; created" << std::endl;
}

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << "; closed" << std::endl;
}


void Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals() << std::endl;
}
// methods
void Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout <<
	"index:" << this->_accountIndex << ";" <<
	"p_amount:" << this->checkAmount() << ";" <<
	"deposit:" << deposit << ";";
	_amount += deposit;
	_totalAmount +=deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout <<
	"amount:" << this->checkAmount() << ";" <<
	"nb_deposits:" << this->_nbDeposits <<
	std::endl;
}

bool Account::makeWithdrawal(int withdrawal){
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << checkAmount() << ";";
	if (withdrawal > _amount)
		return (false);
	_amount -= withdrawal;
	_totalAmount -= withdrawal;
	_nbWithdrawals++, _totalNbWithdrawals++;
	return (true);
}

int	Account::checkAmount(void) const {
	return (_amount);
}

void Account::_displayTimestamp(void) {
	std::time_t now = std::time(NULL);
	std::tm* localTime = std::localtime(&now);
	std::cout << "[" << std::setfill('0')
			<< 1900 + localTime->tm_year
			<< std::setw(2) << std::setfill('0') << 1 + localTime->tm_mon
			<< std::setw(2) << std::setfill('0') << localTime->tm_mday
			<< "_"
			<< std::setw(2) << std::setfill('0') << localTime->tm_hour
			<< std::setw(2) << std::setfill('0') << localTime->tm_min
			<< std::setw(2) << std::setfill('0') << localTime->tm_sec
			<< "] ";
}

void Account::displayStatus(void) const{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals << std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mukibrok <mukibrok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 18:40:24 by mukibrok          #+#    #+#             */
/*   Updated: 2025/02/06 16:09:06 by mukibrok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"

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

void Account::displayAccountsInfos(void){
	_displayTimestamp();
	std::cout << "index:" << getNbAccounts << ";";
	std::cout << "amount:" << getTotalAmount << ";";

}

void Account::makeDeposit(int deposit) {
	_amount += deposit;
	_nbDeposits++;

}

void Account::_displayTimestamp(void) {
	std::time_t now = std::time(nullptr);
	std::tm* localTime = std::localtime(&now);
	std::cout << "["
			<< 1900 + localTime->tm_year
			<< std::setw(2) << std::setfill('0') << 1 + localTime->tm_mon
			<< std::setw(2) << std::setfill('0') << localTime->tm_mday
			<< "_"
			<< std::setw(2) << std::setfill('0') << localTime->tm_hour
			<< std::setw(2) << std::setfill('0') << localTime->tm_min
			<< std::setw(2) << std::setfill('0') << localTime->tm_sec
			<< "] ";
}

Account::Account(int inittial_deposit)
	:_accountIndex(_nbAccounts++), _amount(inittial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
		_totalAmount += _amount;
	}

int	Account::_totalAmount = 0;
int	Account::_nbAccounts = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;
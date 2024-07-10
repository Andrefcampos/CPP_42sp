/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: andrefil <andrefil@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/02 19:19:38 by andrefil          #+#    #+#             */
/*   Updated: 2024/07/04 15:46:40 by andrefil         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>
#include <iomanip>
#include <ostream>

int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit) :_accountIndex(_nbAccounts), \
	_amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "created";
	std::cout << std::endl;
};

int	Account::getNbAccounts(void) {return (_nbAccounts);};

int	Account::getTotalAmount(void) {return (_totalAmount);};

int	Account::getNbDeposits(void) {return (_totalNbDeposits);};

int	Account::getNbWithdrawals(void) {return (_totalNbWithdrawals);};

void	Account::displayAccountsInfos(void) {
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() << ";";
	std::cout << "total:" << getTotalAmount() << ";";
	std::cout << "deposits:" << getNbDeposits() << ";";
	std::cout << "withdrawals:" << getNbWithdrawals();
	std::cout << std::endl;
};

void	Account::makeDeposit(int deposit) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	_nbDeposits++;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
	std::cout << "deposit:" << deposit << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_deposits:" << _nbDeposits;
	std::cout << std::endl;
};

bool	Account::makeWithdrawal(int whithdrawal) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "p_amount:" << _amount << ";";
	if (_amount - whithdrawal < 0) {
		std::cout << "withdrawal:refused" << std::endl;
		return (false);
	}
	_amount -= whithdrawal;
	_totalAmount -= whithdrawal;
	_nbWithdrawals++;	
	_totalNbWithdrawals++;
	std::cout << "withdrawal:" << whithdrawal << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "nb_withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
	return (true);
};

int		Account::checkAmount(void) const {
	if (_amount >= 0)
		return (0);
	return (1);
};

void	Account::displayStatus(void) const {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "deposits:" << _nbDeposits << ";";
	std::cout << "withdrawals:" << _nbWithdrawals;
	std::cout << std::endl;
};

void	Account::_displayTimestamp(void) {
	std::time_t		time_stmp;
	struct tm	*t_stmp;
		
	std::time(&time_stmp);
	t_stmp = localtime(&time_stmp);
	std::cout << "[";
	std::cout << t_stmp->tm_year + 1900;
	std::cout << std::setw(2) << std::setfill('0') << t_stmp->tm_mon + 1;
	std::cout << std::setw(2) << std::setfill('0') << t_stmp->tm_mday << "_";
	std::cout << std::setw(2) << std::setfill('0') << t_stmp->tm_hour;
	std::cout << std::setw(2) << std::setfill('0') << t_stmp->tm_min;
	std::cout << std::setw(2) << std::setfill('0') << t_stmp->tm_sec;
	std::cout << "] ";
};

Account::~Account(void) {
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";";
	std::cout << "amount:" << _amount << ";";
	std::cout << "closed" << std::endl;
};

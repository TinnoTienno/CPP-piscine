/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eschussl <eschussl@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/25 12:22:56 by eschussl          #+#    #+#             */
/*   Updated: 2024/07/25 14:47:49 by eschussl         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void	Account::_displayTimestamp( void )
{
    std::time_t result = std::time(NULL);
	std::tm *time = std::localtime(&result);
	std::cout << "[" << time->tm_year + 1900;
	if (time->tm_mday < 10)
		std::cout << "0";
	std::cout<< time->tm_mday;
	if (time->tm_mon < 10) 
	std::cout <<"0";
	std::cout << time->tm_mon << "_" << time->tm_hour << time->tm_min << time->tm_sec << "] ";
}

void Account::displayAccountsInfos()
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount << ";deposits:" << _totalNbDeposits << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	_nbDeposits++;
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";deposit:" << deposit << ";amount:" << _amount + deposit << ";nb_deposits:" << _nbDeposits << std::endl;
	_totalNbDeposits++;
	_amount += deposit;
	_totalAmount += deposit;
}

void Account::displayStatus() const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";deposits:" << _nbDeposits << ";withdrawals:" << _nbWithdrawals << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	if (_amount < withdrawal)
	{
		_displayTimestamp();
		std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << "refused" <<std::endl;
		return (1);
	}
	_nbWithdrawals++;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:" << withdrawal << ";amount:" << _amount - withdrawal << ";nb_withdrawals:" << _nbWithdrawals <<std::endl;
	_totalNbWithdrawals++;
	_amount -= withdrawal;
	return (0);
}

Account::Account(int initial_deposit)
{
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = _nbAccounts;
	_nbAccounts++;
	_totalAmount += initial_deposit;
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account()
{
	_displayTimestamp();
	std::cout <<"index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}



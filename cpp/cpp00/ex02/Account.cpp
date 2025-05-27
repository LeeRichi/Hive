/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chlee2 <chlee2@student.hive.fi>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 15:58:16 by chlee2            #+#    #+#             */
/*   Updated: 2025/05/23 20:15:48 by chlee2           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ctime>
#include "Account.hpp"
#include <iostream>

// Initialize static members
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//from private
Account::Account( void )
{}

// public Constructor with params //these prints at the begining
Account::Account( int initial_deposit )
	: _accountIndex(_nbAccounts),
	  _amount(initial_deposit),
	  _nbDeposits(0),
	  _nbWithdrawals(0)
{
	_nbAccounts++;
	_totalAmount += initial_deposit;

	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";created" << std::endl;
}

// public destructor //this will print at the end
Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex
	          << ";amount:" << _amount
	          << ";closed" << std::endl;
}

//set of public static ints
int	Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int	Account::getTotalAmount( void )
{
	return _totalAmount;
}

int	Account::getNbDeposits( void )
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals( void )
{
	return _totalNbWithdrawals;
}

void	Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:"     << getNbAccounts()
	          << ";total:"       << getTotalAmount()
	          << ";deposits:"    << getNbDeposits()
	          << ";withdrawals:" << getNbWithdrawals()
	          << std::endl;
}

void	Account::makeDeposit( int deposit )
{
	_displayTimestamp();
	std::cout << "index:"       << _accountIndex
	          << ";p_amount:"   << _amount
	          << ";deposit:"    << deposit;

	_amount += deposit;
	_nbDeposits++;
	_totalAmount += deposit;
	_totalNbDeposits++;

	std::cout << ";amount:"        << _amount
	          << ";nb_deposits:"   << _nbDeposits
	          << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	std::cout << "index:"       << _accountIndex
	          << ";p_amount:"   << _amount;

	if (withdrawal > _amount)
	{
		std::cout << ";withdrawal:refused" << std::endl;
		return false;
	}

	_amount -= withdrawal;
	_nbWithdrawals++;
	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	std::cout << ";withdrawal:"     << withdrawal
	          << ";amount:"         << _amount
	          << ";nb_withdrawals:" << _nbWithdrawals
	          << std::endl;

	return true;
}

//this is never used but still in header
int	Account::checkAmount( void ) const
{
	return _amount;
}

void	Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:"       << _accountIndex
	          << ";amount:"     << _amount
	          << ";deposits:"   << _nbDeposits
	          << ";withdrawals:"<< _nbWithdrawals
	          << std::endl;
}

void	Account::_displayTimestamp( void )
{
	std::time_t now = std::time(NULL);
	std::tm*     ptm = std::localtime(&now);

	char buffer[20];
	//size_t strftime(char* buffer, size_t maxSize, const char* format, const std::tm* timeStruct);
	std::strftime(buffer, sizeof(buffer), "[%Y%m%d_%H%M%S]", ptm);
	std::cout << buffer << " ";
}

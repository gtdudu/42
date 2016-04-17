/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.class.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdurand <tdurand@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/04/04 18:02:40 by tdurand           #+#    #+#             */
/*   Updated: 2016/04/04 18:12:35 by tdurand          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.class.hpp"
#include <iostream>
#include <string>
#include <stdio.h>
#include <time.h>

//CONSTRUCTOR
Account::Account( int initial_deposit ) : _accountIndex( getNbAccounts())
, _amount( initial_deposit ), _nbDeposits( 0 ), _nbWithdrawals( 0 )  {

  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << initial_deposit << ";created" << std::endl;
  Account::_nbAccounts += 1;
  Account::_totalAmount += this->_amount;
  return;
}

//DESTRUCTOR
Account::~Account( void ) {

  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";closed" << std::endl;
  Account::_nbAccounts -= 1;
  return;
}


//PUBLIC MEMBER FUNCTIONS
void  Account::makeDeposit( int deposit ) {
  int prev = this->_amount;
  this->_nbDeposits += 1;
  this->_amount += deposit;
  Account::_totalAmount += deposit;
  Account::_totalNbDeposits += 1;
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex;
  std::cout << ";p_amount:" << prev;
  std::cout << ";deposit:" <<  deposit;
  std::cout << ";amount:" << this->_amount;
  std::cout << ";nb_deposits:" << this->_nbDeposits << std::endl;
  return;
}

bool  Account::makeWithdrawal( int withdrawal ) {
  Account::_displayTimestamp();
  if (withdrawal > this->_amount) {
    std::cout << "index:" << this->_accountIndex;
    std::cout << ";p_amount:" << this->_amount;
    std::cout << ";withdrawal:refused" << std::endl;
    return false;
  }
  int prev = this->_amount;
  this->_amount -= withdrawal;
  this->_nbWithdrawals += 1;
  Account::_totalAmount -= withdrawal;
  Account::_totalNbWithdrawals += 1;
  std::cout << "index:" << this->_accountIndex;
  std::cout << ";p_amount:" << prev;
  std::cout << ";withdrawal:" <<  withdrawal;
  std::cout << ";amount:" << this->_amount;
  std::cout << ";nb_withdrawals:" << this->_nbWithdrawals << std::endl;
  return true;
}

int   Account::checkAmount( void ) const {

  Account::_displayTimestamp();

  return 0;
}

void  Account::displayStatus( void ) const {
  Account::_displayTimestamp();
  std::cout << "index:" << this->_accountIndex;
  std::cout << ";amount:" << this->_amount;
  std::cout << ";deposits:" << this->_nbDeposits;
  std::cout << ";withdrawals:" << this->_nbWithdrawals << std::endl;

  return;
}

//PUBLIC NON MEMBER FUNCTIONS
int   Account::getNbAccounts( void ) {

  return Account::_nbAccounts;
}

int   Account::getTotalAmount( void ) {

  return Account::_totalAmount;
}

int   Account::getNbDeposits( void ) {

  return Account::_totalNbDeposits;
}

int   Account::getNbWithdrawals( void ) {

  return Account::_totalNbWithdrawals;
}

void  Account::displayAccountsInfos( void ) {

  Account::_displayTimestamp();
  std::cout << "accounts:" << Account::_nbAccounts;
  std::cout << ";total:" << Account::_totalAmount;
  std::cout << ";deposits:" << Account::_totalNbDeposits;
  std::cout << ";withdrawals:" << Account::_totalNbWithdrawals << std::endl;


  return;
}

//PRIVATE NON MEMBER ATTRIBUTES
int   Account::_nbAccounts = 0;
int   Account::_totalAmount = 0;
int   Account::_totalNbDeposits = 0;
int   Account::_totalNbWithdrawals = 0;

//PRIVATE NON MEMBER FUNCTIONS

void  Account::_displayTimestamp( void ) {

  time_t     now = time(0);
  struct tm  tstruct;
  char       buf[80];
  tstruct = *localtime(&now);
  strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S]", &tstruct);

  std::cout << buf << " ";
}

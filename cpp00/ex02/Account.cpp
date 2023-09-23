#include "Account.hpp"
#include <ctime>
#include <iomanip> // For std::setw


int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits;
int	Account::_totalNbWithdrawals;

Account::Account(int initial_deposit)
{
	int	na = getNbAccounts();
	int	ta = getTotalAmount();

	_nbDeposits = 0;
	_nbWithdrawals = 0;
	_accountIndex = na;
	_amount = initial_deposit;
	setTotalAmount(ta + initial_deposit);
	setNbAccounts(na + 1); 

	std::cout <<"[";
	_displayTimestamp();
	std::cout <<"] ";
	std::cout <<"index:"<<_accountIndex<<";amount:"<<initial_deposit<<";created"<<std::endl;
}

void	Account::_displayTimestamp()
{
	time_t currentTime;
	struct tm *timeInfo;
	char timestamp[16];

	time(&currentTime);
	timeInfo = localtime(&currentTime);

	// Format the timestamp as "YYYYMMDD_HHMMSS"
	strftime(timestamp, sizeof(timestamp), "%Y%m%d_%H%M%S", timeInfo);

	std::cout << timestamp ;
}

int	Account::getNbAccounts(void)
{
	return (_nbAccounts);
}
int	Account::getTotalAmount( void )
{
	return (_totalAmount);
}
int	Account::getNbDeposits( void )
{
	return (_totalNbDeposits);
}
int	Account::getNbWithdrawals( void )
{
	return (_totalNbWithdrawals);
}

void	Account::setNbAccounts(int value)
{
	_nbAccounts = value;
}
void	Account::setTotalAmount( int value )
{
	_totalAmount = value;
}
void	Account::setNbDeposits( int value )
{
	_totalNbDeposits = value;
}
void	Account::setNbWithdrawals( int value )
{
	_totalNbWithdrawals = value;
}

void	Account::displayAccountsInfos()
{
	int na = Account::getNbAccounts();
	
	std::cout <<"[";
	Account::_displayTimestamp();
	std::cout <<"] ";
	std::cout <<"accounts:"<<na<<";total:"<<_totalAmount;
	std::cout<< ";deposits:"<<_totalNbDeposits<<"withdrawals:"<<_totalNbWithdrawals;
	std::cout<<std::endl;
}

void	Account::displayStatus(void) const
{
	std::cout <<"[";
	_displayTimestamp();
	std::cout <<"] ";
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";deposits:"<<_nbDeposits;
	std::cout<<";withdrawals:"<<_nbWithdrawals<<std::endl;
}

void	Account::makeDeposit(int deposit)
{
	int	amount_bef;
	int	td = getNbDeposits();

	_nbDeposits++;
	setNbDeposits(td + 1);
	amount_bef = _amount;
	_amount += deposit;
	std::cout <<"[";
	_displayTimestamp();
	std::cout <<"] ";
	std::cout<<"index:"<<_accountIndex<<";p_amount:"<<amount_bef;
	std::cout<<";deposit:"<<deposit<<";amount:"<<_amount<<";nb_deposits:"<<_nbDeposits;
	std::cout<<std::endl;

	// [19920104_091532] index:0;p_amount:42;deposit:5;amount:47;nb_deposits:1
}

bool	Account::makeWithdrawal(int withdrawal)
{

	if (withdrawal > _amount)
	{
		std::cout <<"[";
		_displayTimestamp();
		std::cout <<"] ";
		std::cout<<"index:"<<_accountIndex<<";p_amount:"<<_amount<<";withdrawal:refused";
		std::cout<<std::endl;
		return (false);

		// [19920104_091532] index:0;p_amount:47;withdrawal:refused
	}
	else
	{
		int	amount_bef;
		int	tnw = getNbWithdrawals();

		setNbWithdrawals(tnw + 1);
		amount_bef = _amount;
		_nbWithdrawals++;
		_amount += withdrawal;
		std::cout <<"[";
		_displayTimestamp();
		std::cout <<"] ";
		std::cout<<"index:"<<_accountIndex<<";p_amount:"<<amount_bef<<";withdrawal:"<<_nbWithdrawals;
		std::cout<<";amount:"<<_amount<<";nb_withdrawals:"<<_nbWithdrawals;
		std::cout<<std::endl;
		return (true);

		// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
	}
}

Account::~Account ()
{
	std::cout <<"[";
	_displayTimestamp();
	std::cout <<"] ";
	std::cout<<"index:"<<_accountIndex<<";amount:"<<_amount<<";closed"<<std::endl;

	// [19920104_091532] index:0;amount:47;closed
}
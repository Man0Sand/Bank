#include <algorithm>

#include "accounts.h"

//----------------------------------------------------------------------------------------------------------------------------
// Ordinary account
//----------------------------------------------------------------------------------------------------------------------------
Account::Account(float initial_balance):
balance_(initial_balance)
{
}

float Account::GetBalance() const
{
    return balance_;
}

void Account::Deposit(float amount)
{
    balance_ += amount;
}

float Account::Withdraw(float amount)
{
    Deposit(-amount);
    return amount;
}

void Account::MonthlyActions()
{
}

//----------------------------------------------------------------------------------------------------------------------------
// Checking account
//----------------------------------------------------------------------------------------------------------------------------
CheckingAccount::CheckingAccount(float initial_balance, float transaction_fee, int number_of_free_transactions):
Account(initial_balance),
transaction_fee_(transaction_fee),
number_of_free_transactions_(number_of_free_transactions),
transaction_count_(0)
{
}

void CheckingAccount::Deposit(float amount)
{
    ++transaction_count_;
    Account::Deposit(amount);
}

void CheckingAccount::DeductFees()
{
    int charged_transaction_count = std::max(0, transaction_count_ - number_of_free_transactions_);
    balance_ -= charged_transaction_count * transaction_fee_;

    transaction_count_ = 0;
}

void CheckingAccount::MonthlyActions()
{
    DeductFees();
}

//----------------------------------------------------------------------------------------------------------------------------
// Savings account
//----------------------------------------------------------------------------------------------------------------------------
SavingsAccount::SavingsAccount(float initial_balance, float initial_interest_rate):
Account(initial_balance),
interest_rate_(initial_interest_rate)
{
}

void SavingsAccount::AddInterest()
{
    balance_ *= (1.0f + interest_rate_ / 100.0f);
}

void SavingsAccount::MonthlyActions()
{
    AddInterest();
}

//----------------------------------------------------------------------------------------------------------------------------
// Transfer money
//----------------------------------------------------------------------------------------------------------------------------
void Transfer(Account* source_account, Account* target_account, float amount)
{
    target_account->Deposit(source_account->Withdraw(amount));
}

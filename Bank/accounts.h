#ifndef ACCOUNTS_H
#define ACCOUNTS_H

class Account
{
public:
    Account(float initial_balance);
    virtual ~Account() = default;
    float GetBalance() const;
    virtual void Deposit(float amount);
    float Withdraw(float amount);
    virtual void MonthlyActions();

protected:
    float balance_;
};

class CheckingAccount : public Account
{
public:
    CheckingAccount(float initial_balance, float transaction_fee, int number_of_free_transactions);
    void Deposit(float amount);
    void MonthlyActions();

private:
    void DeductFees();
    float transaction_fee_;
    int number_of_free_transactions_;
    int transaction_count_;
};

class SavingsAccount : public Account
{
public:
    SavingsAccount(float initial_balance, float initial_interest_rate);
    void MonthlyActions();

private:
    void AddInterest();
    float interest_rate_;
};

void Transfer(Account* source_account, Account* target_account, float amount);

#endif // ACCOUNTS_H
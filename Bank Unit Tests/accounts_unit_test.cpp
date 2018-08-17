#include "gtest/gtest.h"
#include "accounts.h"

void DepositWithdrawal(Account& account)
{
    ASSERT_EQ(42.0, account.GetBalance());

    account.Deposit(12.5);
    ASSERT_EQ(54.5, account.GetBalance());

    ASSERT_EQ(14.5, account.Withdraw(14.5));
    ASSERT_EQ(40.0, account.GetBalance());
}

TEST(TestOrdinaryAccount, BasicDepositAndWithdrawal)
{
    Account account = Account(42.0);
    DepositWithdrawal(account);
}

TEST(TestSavingsAccount, BasicDepositAndWithdrawal)
{
    SavingsAccount account = SavingsAccount(42.0, 5.0);
    DepositWithdrawal(account);
}

TEST(TestSavingsAccount, Interest)
{
    SavingsAccount account = SavingsAccount(100.0, 10.0);
    ASSERT_EQ(100.0, account.GetBalance());

    account.MonthlyActions();
    ASSERT_EQ(110.0, account.GetBalance());
}

TEST(TestCheckingAccount, DepositFees_Object)
{
    CheckingAccount account = CheckingAccount(100.0, 1.0, 2);

    account.MonthlyActions();
    ASSERT_EQ(100.0, account.GetBalance());

    account.Deposit(10.0);
    ASSERT_EQ(110.0, account.GetBalance());
    account.MonthlyActions();
    ASSERT_EQ(110.0, account.GetBalance());

    account.Deposit(10.0);
    account.Deposit(10.0);
    ASSERT_EQ(130.0, account.GetBalance());
    account.MonthlyActions();
    ASSERT_EQ(130.0, account.GetBalance());

    account.Deposit(10.0);
    account.Deposit(10.0);
    account.Deposit(10.0);
    ASSERT_EQ(160.0, account.GetBalance());
    account.MonthlyActions();
    ASSERT_EQ(159.0, account.GetBalance());

    account.Deposit(10.0);
    account.Deposit(10.0);
    account.Deposit(10.0);
    account.Deposit(10.0);
    account.Deposit(10.0);
    account.Deposit(10.0);
    ASSERT_EQ(219.0, account.GetBalance());
    account.MonthlyActions();
    ASSERT_EQ(215.0, account.GetBalance());
}

TEST(TestCheckingAccount, DepositFees_BaseClassReference)
{
    Account& account = CheckingAccount(100.0, 1.0, 2);

    account.MonthlyActions();
    ASSERT_EQ(100.0, account.GetBalance());

    account.Deposit(10.0);
    ASSERT_EQ(110.0, account.GetBalance());
    account.MonthlyActions();
    ASSERT_EQ(110.0, account.GetBalance());

    account.Deposit(10.0);
    account.Deposit(10.0);
    ASSERT_EQ(130.0, account.GetBalance());
    account.MonthlyActions();
    ASSERT_EQ(130.0, account.GetBalance());

    account.Deposit(10.0);
    account.Deposit(10.0);
    account.Deposit(10.0);
    ASSERT_EQ(160.0, account.GetBalance());
    account.MonthlyActions();
    ASSERT_EQ(159.0, account.GetBalance());

    account.Deposit(10.0);
    account.Deposit(10.0);
    account.Deposit(10.0);
    account.Deposit(10.0);
    account.Deposit(10.0);
    account.Deposit(10.0);
    ASSERT_EQ(219.0, account.GetBalance());
    account.MonthlyActions();
    ASSERT_EQ(215.0, account.GetBalance());
}

TEST(TestCheckingAccount, DepositFees_BaseClassPointer)
{
    Account* account = new CheckingAccount(100.0, 1.0, 2);

    account->MonthlyActions();
    ASSERT_EQ(100.0, account->GetBalance());

    account->Deposit(10.0);
    ASSERT_EQ(110.0, account->GetBalance());
    account->MonthlyActions();
    ASSERT_EQ(110.0, account->GetBalance());

    account->Deposit(10.0);
    account->Deposit(10.0);
    ASSERT_EQ(130.0, account->GetBalance());
    account->MonthlyActions();
    ASSERT_EQ(130.0, account->GetBalance());

    account->Deposit(10.0);
    account->Deposit(10.0);
    account->Deposit(10.0);
    ASSERT_EQ(160.0, account->GetBalance());
    account->MonthlyActions();
    ASSERT_EQ(159.0, account->GetBalance());

    account->Deposit(10.0);
    account->Deposit(10.0);
    account->Deposit(10.0);
    account->Deposit(10.0);
    account->Deposit(10.0);
    account->Deposit(10.0);
    ASSERT_EQ(219.0, account->GetBalance());
    account->MonthlyActions();
    ASSERT_EQ(215.0, account->GetBalance());
}

TEST(TestCheckingAccount, WithdrawalFees_Object)
{
    CheckingAccount account = CheckingAccount(200.0, 1.0, 2);

    account.MonthlyActions();
    ASSERT_EQ(200.0, account.GetBalance());

    account.Withdraw(10.0);
    ASSERT_EQ(190.0, account.GetBalance());
    account.MonthlyActions();
    ASSERT_EQ(190.0, account.GetBalance());

    account.Withdraw(10.0);
    account.Withdraw(10.0);
    ASSERT_EQ(170.0, account.GetBalance());
    account.MonthlyActions();
    ASSERT_EQ(170.0, account.GetBalance());

    account.Withdraw(10.0);
    account.Withdraw(10.0);
    account.Withdraw(10.0);
    ASSERT_EQ(140.0, account.GetBalance());
    account.MonthlyActions();
    ASSERT_EQ(139.0, account.GetBalance());

    account.Withdraw(10.0);
    account.Withdraw(10.0);
    account.Withdraw(10.0);
    account.Withdraw(10.0);
    account.Withdraw(10.0);
    account.Withdraw(10.0);
    ASSERT_EQ(79.0, account.GetBalance());
    account.MonthlyActions();
    ASSERT_EQ(75.0, account.GetBalance());
}

TEST(TestCheckingAccount, WithdrawalFees_BaseClassReference)
{
    Account& account = CheckingAccount(200.0, 1.0, 2);

    account.MonthlyActions();
    ASSERT_EQ(200.0, account.GetBalance());

    account.Withdraw(10.0);
    ASSERT_EQ(190.0, account.GetBalance());
    account.MonthlyActions();
    ASSERT_EQ(190.0, account.GetBalance());

    account.Withdraw(10.0);
    account.Withdraw(10.0);
    ASSERT_EQ(170.0, account.GetBalance());
    account.MonthlyActions();
    ASSERT_EQ(170.0, account.GetBalance());

    account.Withdraw(10.0);
    account.Withdraw(10.0);
    account.Withdraw(10.0);
    ASSERT_EQ(140.0, account.GetBalance());
    account.MonthlyActions();
    ASSERT_EQ(139.0, account.GetBalance());

    account.Withdraw(10.0);
    account.Withdraw(10.0);
    account.Withdraw(10.0);
    account.Withdraw(10.0);
    account.Withdraw(10.0);
    account.Withdraw(10.0);
    ASSERT_EQ(79.0, account.GetBalance());
    account.MonthlyActions();
    ASSERT_EQ(75.0, account.GetBalance());
}

TEST(TestCheckingAccount, WithdrawalFees_BaseClassPointer)
{
    Account* account = new CheckingAccount(200.0, 1.0, 2);

    account->MonthlyActions();
    ASSERT_EQ(200.0, account->GetBalance());

    account->Withdraw(10.0);
    ASSERT_EQ(190.0, account->GetBalance());
    account->MonthlyActions();
    ASSERT_EQ(190.0, account->GetBalance());

    account->Withdraw(10.0);
    account->Withdraw(10.0);
    ASSERT_EQ(170.0, account->GetBalance());
    account->MonthlyActions();
    ASSERT_EQ(170.0, account->GetBalance());

    account->Withdraw(10.0);
    account->Withdraw(10.0);
    account->Withdraw(10.0);
    ASSERT_EQ(140.0, account->GetBalance());
    account->MonthlyActions();
    ASSERT_EQ(139.0, account->GetBalance());

    account->Withdraw(10.0);
    account->Withdraw(10.0);
    account->Withdraw(10.0);
    account->Withdraw(10.0);
    account->Withdraw(10.0);
    account->Withdraw(10.0);
    ASSERT_EQ(79.0, account->GetBalance());
    account->MonthlyActions();
    ASSERT_EQ(75.0, account->GetBalance());
}

TEST(TestCheckingAccount, WithdrawalFees_SubClassPointer)
{
    CheckingAccount* account = new CheckingAccount(200.0, 1.0, 2);

    account->MonthlyActions();
    ASSERT_EQ(200.0, account->GetBalance());

    account->Withdraw(10.0);
    ASSERT_EQ(190.0, account->GetBalance());
    account->MonthlyActions();
    ASSERT_EQ(190.0, account->GetBalance());

    account->Withdraw(10.0);
    account->Withdraw(10.0);
    ASSERT_EQ(170.0, account->GetBalance());
    account->MonthlyActions();
    ASSERT_EQ(170.0, account->GetBalance());

    account->Withdraw(10.0);
    account->Withdraw(10.0);
    account->Withdraw(10.0);
    ASSERT_EQ(140.0, account->GetBalance());
    account->MonthlyActions();
    ASSERT_EQ(139.0, account->GetBalance());

    account->Withdraw(10.0);
    account->Withdraw(10.0);
    account->Withdraw(10.0);
    account->Withdraw(10.0);
    account->Withdraw(10.0);
    account->Withdraw(10.0);
    ASSERT_EQ(79.0, account->GetBalance());
    account->MonthlyActions();
    ASSERT_EQ(75.0, account->GetBalance());
}

TEST(TestAccounts, Transfer)
{
    Account account = Account(40.0);
    Transfer(&account, &account, 666.0);
    ASSERT_EQ(40.0, account.GetBalance());

    Account account2 = Account(100.0);
    Transfer(&account, &account2, 20.0);
    ASSERT_EQ(20.0, account.GetBalance());
    ASSERT_EQ(120.0, account2.GetBalance());
}

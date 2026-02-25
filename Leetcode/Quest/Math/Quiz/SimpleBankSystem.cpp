// You have been tasked with writing a program for a popular bank that will automate all its incoming transactions (transfer, deposit, and withdraw). The bank has n accounts numbered from 1 to n. The initial balance of each account is stored in a 0-indexed integer array balance, with the (i + 1)th account having an initial balance of balance[i]. Execute all the valid transactions. A transaction is valid if:

//     1 - The given account number(s) are between 1 and n, and
//     2 - The amount of money withdrawn or transferred from is less than or equal to the balance of the account.

// Implement the Bank class: Bank(long[] balance) Initializes the object with the 0-indexed integer array balance.
// boolean transfer(int account1, int account2, long money) Transfers money dollars from the account numbered account1 to the account numbered account2. Return true if the transaction was successful, false otherwise.
// boolean deposit(int account, long money) Deposit money dollars into the account numbered account. Return true if the transaction was successful, false otherwise. boolean withdraw(int account, long money) Withdraw money dollars from the account numbered account. Return true if the transaction was successful, false otherwise.







#include <bits/stdc++.h>
using namespace std;

class Bank {
public:
    Bank(vector<long long>& balance) : balance(std::move(balance)) {}

    bool transfer(int account1, int account2, long long money) {
        if (!isValid(account2)) return false;
        return withdraw(account1, money) && deposit(account2, money);
    }

    bool deposit(int account, long long money) {
        if (!isValid(account)) return false;
        balance[account - 1] += money;
        return true;
    }

    bool withdraw(int account, long long money) {
        if (!isValid(account)) return false;
        if (balance[account - 1] < money) return false;
        balance[account - 1] -= money;
        return true;
    }

private:
    vector<long long> balance;

    bool isValid(int account) {
        return 1 <= account && account <= balance.size();
    }
};

int main() {
    vector<long long> balance = {10, 100, 20, 50, 30};
    Bank bank(balance);
    cout << bank.withdraw(3, 10) << endl; 
    cout << bank.transfer(5, 1, 20) << endl; 
    cout << bank.deposit(5, 20) << endl; 
    cout << bank.transfer(3, 4, 15) << endl;
    cout << bank.withdraw(10, 50) << endl; 
}
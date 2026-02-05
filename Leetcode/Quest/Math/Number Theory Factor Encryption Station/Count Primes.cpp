// Given an integer n, return the number of prime numbers that are strictly less than n.




#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPrimes(int n) {
        if(n == 0) return false;
        vector<bool>isPrime(n, true);
        isPrime[0] = false;
        isPrime[1] = false;
        int count = 0;
        for(int i = 0;i < n; i++){
            if(isPrime[i]){
                count++;
                int k = 2;
                int j = (i * k);
                while(j < n){
                    isPrime[j] = false;
                    j += i;
                }
            }
        }
        return count;
    }
};

int main(){
    Solution s;
    int n = 10;
    cout << "Number of primes less than " << n << " : " << s.countPrimes(n) << endl;

    n = 0;
    cout << "Number of primes less than " << n << " : " << s.countPrimes(n) << endl;
}
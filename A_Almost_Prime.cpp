/*
Problem: Almost Prime
Platform: Codeforces

Approach:
1. Use Sieve of Eratosthenes to find all prime numbers up to n
2. For each number, count distinct prime divisors
3. If exactly 2 → count as almost prime

Time Complexity: O(n^2)
*/

#include <iostream>
#include <vector>
using namespace std;
int main()
{
    //taking input
    int n;
    cin >> n;

    //precomputing of prime numbers using sieve of erathosis
    //and store them in vector 
    //prime[i]==true means i is a prime number
    //prime[i]==false means i is not a prime
    
    //assume all number to n ,are prime
    vector<bool> prime(n + 1, true);
    //0 ans 1 are not prime
    prime[0] = prime[1] = 0;
    // we will start our loop from 2,our first prime number,and go upto root(n),
    //making all the multiples of prime numbers false
    for (int i = 2; i * i <= n; i++)
    {
        if (prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = false;
            }
        }
    }
    // Count numbers having exactly 2 distinct prime divisors
    int No_of_almost_prime=0;
    for (int i = 1; i <= n; i++)
    {
        int no_of_prime_divisors=0;
      
        for (int j=2; j <= i; j++)
        {
            if(prime[j] and i%j==0) no_of_prime_divisors++; 
        }
        if(no_of_prime_divisors==2) No_of_almost_prime++; 
        
    }
    cout<<No_of_almost_prime;

    return 0;
}


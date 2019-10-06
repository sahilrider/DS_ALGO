// C++ program to print all primes smaller than or equal to
// n using Sieve of Eratosthenes
#include <bits/stdc++.h>

using namespace std;

void sieveOfEratosthenes(bool prime[], int n) {
    for (int i = 2; i * i <= n; i++) {
        // If prime[p] is true, then it is a prime
        if (prime[i]) {
            // Removing prime multipes by changing it to false
            for (int j = i * i; j <= n; j += i) prime[j] = false;
        }
    }
}

int main(){
    // For demo printing prime numbers upto 100
    int n = 100;
    bool prime[n + 1];
    memset(prime, true, sizeof(prime));
    sieveOfEratosthenes(prime, n);
    for(int i = 2; i<= n; i++){
        if(prime[i]){
            cout<<i<<" ";
        }
    }
    cout<<"\n";
}
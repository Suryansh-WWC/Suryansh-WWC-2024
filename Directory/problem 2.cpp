#include <iostream>
using namespace std;

// Function to check if a number is prime
bool isPrime(int n) {
    if (n <= 1) 
        return false; // Numbers less than or equal to 1 are not prime
    for (int i = 2; i * i <= n; i++) { // Check divisors up to sqrt(n)
        if (n % i == 0) 
            return false; // If divisible, it's not prime
    }
    return true; // If no divisors, it's prime
}

int main() {
    int num;
    cout << "Enter a natural number: ";
    cin >> num;

    if (num <= 0) {
        cout << "Please enter a natural number (greater than 0)." << endl;
    } else if (isPrime(num)) {
        cout << num << " is a prime number." << endl;
    } else {
        cout << num << " is not a prime number." << endl;
    }

    return 0;
}

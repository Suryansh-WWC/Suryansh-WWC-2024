#include <iostream>
using namespace std;

// Function to calculate the sum of natural numbers up to N
int sumOfNaturalNumbers(int n) {
    if (n < 1) 
        return 0; // Natural numbers start from 1
    return n * (n + 1) / 2; // Using the formula for the sum of the first N natural numbers
}

int main() {
    int N;
    cout << "Enter a positive integer: ";
    cin >> N;

    if (N < 1) {
        cout << "Please enter a positive integer greater than or equal to 1." << endl;
    } else {
        int result = sumOfNaturalNumbers(N);
        cout << "The sum of natural numbers up to " << N << " is " << result << "." << endl;
    }

    return 0;
}


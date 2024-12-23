#include <iostream>
#include <vector>
using namespace std;

int lastRemaining(int n) {
    bool leftToRight = true;  // Track the direction of elimination
    int remaining = n;        // Total numbers remaining
    int step = 1;             // Step size
    int head = 1;             // Starting head of the sequence

    while (remaining > 1) {
        if (leftToRight || remaining % 2 == 1) {
            head += step;  // Update head when moving left to right or odd-sized removal
        }
        step *= 2;           // Double the step size after each pass
        remaining /= 2;      // Halve the remaining numbers
        leftToRight = !leftToRight;  // Alternate direction
    }

    return head;
}

int main() {
    int n = 9;  // Example input
    cout << "Last remaining number: " << lastRemaining(n) << endl;

    return 0;
}

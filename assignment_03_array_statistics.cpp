// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 3
// =============================================================================
//
// TASK: Array Statistics Calculator
//
// Write a C++ program that reads a collection of numbers from the user
// and computes key statistical values using separate functions.
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT / OUTPUT EXAMPLE
// -----------------------------------------------------------------------------
//
//   How many numbers? 5
//   Enter number 1: 4
//   Enter number 2: 7
//   Enter number 3: 2
//   Enter number 4: 9
//   Enter number 5: 1
//
//   Results:
//   Sum:     23
//   Average: 4.6
//   Maximum: 9
//   Minimum: 1
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - You MUST implement each calculation in its own function (see scaffold).
// - You may NOT use any standard library functions like accumulate(), max(),
//   or min(). Implement the logic yourself using loops.
// - N must be a positive integer. If the user enters 0 or a negative number,
//   print an error message and stop.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std

// Function to calculate sum
int calculateSum(int numbers[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += numbers[i];
    }
    return sum;
}

// Function to calculate average
double calculateAverage(int sum, int n) {
    return (double)sum / n;
}

// Function to find maximum
int findMax(int numbers[], int n) {
    int maxVal = numbers[0];
    for (int i = 1; i < n; i++) {
        if (numbers[i] > maxVal) {
            maxVal = numbers[i];
        }
    }
    return maxVal;
}

// Function to find minimum
int findMin(int numbers[], int n) {
    int minVal = numbers[0];
    for (int i = 1; i < n; i++) {
        if (numbers[i] < minVal) {
            minVal = numbers[i];
        }
    }
    return minVal;
}

int main() {
    int n;
    cout << "How many numbers? ";
    cin >> n;
    
    // Check if N is positive
    if (n <= 0) {
        cout << "Error: Number must be positive!" << endl;
        return 0;
    }
    
    int numbers[100]; // store the numbers
    
    // Read each number
    for (int i = 0; i < n; i++) {
        cout << "Enter number " << (i + 1) << ": ";
        cin >> numbers[i];
    }
    
    // Calculate everything
    int sum = calculateSum(numbers, n);
    double avg = calculateAverage(sum, n);
    int maxVal = findMax(numbers, n);
    int minVal = findMin(numbers, n);
    
    // Print results
    cout << "\nResults:" << endl;
    cout << "Sum:     " << sum << endl;
    cout << "Average: " << avg << endl;
    cout << "Maximum: " << maxVal << endl;
    cout << "Minimum: " << minVal << endl;
    
    return 0;
}


// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

const int MAX = 10; // Fixed maximum size

// ===== PART A: TRANSPOSE =====
void transposeMatrix(int matrix[MAX][MAX], int rows, int cols) {
    int transposed[MAX][MAX];
    
    // Calculate transpose (rows ↔ columns)
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            transposed[j][i] = matrix[i][j];
        }
    }
    
    // Display original and transposed side by side
    cout << "\nOriginal Matrix:\tTransposed Matrix:\n";
    int maxLines = (rows > cols) ? rows : cols;
    for (int i = 0; i < maxLines; i++) {
        // Original side
        if (i < rows) {
            for (int j = 0; j < cols; j++) {
                cout << matrix[i][j] << " ";
            }
        }
        cout << "\t\t";
        // Transposed side
        if (i < cols) {
            for (int j = 0; j < rows; j++) {
                cout << transposed[i][j] << " ";
            }
        }
        cout << endl;
    }
}

// ===== PART B: ADD TWO MATRICES =====
void addMatrices(int a[MAX][MAX], int b[MAX][MAX], int rows, int cols) {
    int sum[MAX][MAX];
    
    // Element-wise addition
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            sum[i][j] = a[i][j] + b[i][j];
        }
    }
    
    // Display result
    cout << "\nSum of Matrices:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << sum[i][j] << " ";
        }
        cout << endl;
    }
}

// ===== PART C: MULTIPLY TWO MATRICES =====
void multiplyMatrices(int a[MAX][MAX], int b[MAX][MAX], int m, int n, int p) {
    int product[MAX][MAX] = {0}; // Initialize to zero
    
    // Check: columns of A must equal rows of B
    if (n != p) {
        cout << "\nError: Cannot multiply! Columns of A must equal rows of B.\n";
        return;
    }
    
    // Matrix multiplication
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            for (int k = 0; k < n; k++) {
                product[i][j] += a[i][k] * b[k][j];
            }
        }
    }
    
    // Display result
    cout << "\nProduct of Matrices:\n";
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < p; j++) {
            cout << product[i][j] << " ";
        }
        cout << endl;
    }
}

// ===== HELPER: READ A MATRIX =====
void readMatrix(int matrix[MAX][MAX], int rows, int cols) {
    cout << "Enter " << rows << "x" << cols << " matrix values:\n";
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Element [" << i+1 << "][" << j+1 << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// ===== MAIN =====
int main() {
    int choice;
    cout << "===== MATRIX OPERATIONS =====\n";
    cout << "1. Transpose a Matrix\n";
    cout << "2. Add Two Matrices\n";
    cout << "3. Multiply Two Matrices\n";
    cout << "Enter your choice (1-3): ";
    cin >> choice;
    
    if (choice == 1) {
        // PART A: TRANSPOSE
        int rows, cols;
        cout << "\n=== MATRIX TRANSPOSE ===\n";
        cout << "Enter rows and columns (M N): ";
        cin >> rows >> cols;
        if (rows > MAX || cols > MAX) {
            cout << "Error: Max size is " << MAX << "x" << MAX << endl;
            return 0;
        }
        int mat[MAX][MAX];
        readMatrix(mat, rows, cols);
        transposeMatrix(mat, rows, cols);
    }
    else if (choice == 2) {
        // PART B: ADD
        int rows, cols;
        cout << "\n=== MATRIX ADDITION ===\n";
        cout << "Enter rows and columns (M N): ";
        cin >> rows >> cols;
        if (rows > MAX || cols > MAX) {
            cout << "Error: Max size is " << MAX << "x" << MAX << endl;
            return 0;
        }
        int a[MAX][MAX], b[MAX][MAX];
        cout << "\nMatrix A:\n"; readMatrix(a, rows, cols);
        cout << "\nMatrix B:\n"; readMatrix(b, rows, cols);
        addMatrices(a, b, rows, cols);
    }
    else if (choice == 3) {
        // PART C: MULTIPLY
        int m, n, p;
        cout << "\n=== MATRIX MULTIPLICATION ===\n";
        cout << "Matrix A size (rows cols): ";
        cin >> m >> n;
        cout << "Matrix B size (rows cols): ";
        cin >> p;
        if (m > MAX || n > MAX || p > MAX) {
            cout << "Error: Max size is " << MAX << "x" << MAX << endl;
            return 0;
        }
        int a[MAX][MAX], b[MAX][MAX];
        cout << "\nMatrix A:\n"; readMatrix(a, m, n);
        cout << "\nMatrix B:\n"; readMatrix(b, n, p);
        multiplyMatrices(a, b, m, n, p);
    }
    else {
        cout << "Invalid choice!\n";
    }
    
    return 0;
}


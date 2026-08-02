// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 8
// =============================================================================
//
// TASK: Student Record Management System
//
// Build a console-based program that stores and manages student information.
// Use a struct to represent each student record containing:
//
//   - name   : the student's full name  (string)
//   - id     : a unique student ID number (int, e.g. 20240001)
//   - scores : a list of scores from multiple assessments (vector<double>)
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Student
//      - Ask the user to enter the student's name and ID.
//      - Ask how many scores to enter, then collect each score one by one.
//      - Save the student record and confirm it was added.
//
//   2. Display All Students
//      - Print a formatted table showing every student's:
//          Name, ID, individual scores, and their average score.
//      - If no students have been added yet, print a message saying so.
//
//   3. Calculate Average Score for a Specific Student
//      - Ask the user to enter a student ID.
//      - Find the student and print their average score.
//      - If the ID is not found, print an error message.
//
//   4. Quit
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ================================
//      STUDENT RECORD SYSTEM MENU
//   ================================
//   1. Add student
//   2. Display all students
//   3. Calculate average score
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Student name: Alice Mensah
//   Student ID: 20240001
//   How many scores? 3
//   Enter score 1: 78
//   Enter score 2: 85
//   Enter score 3: 90
//   Student "Alice Mensah" added successfully.
//
//   Enter your choice (1-4): 3
//   Enter student ID: 20240001
//   Alice Mensah's average score: 84.33
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Define a struct called Student (see scaffold below).
// - Store all records in a vector<Student>.
// - Average scores must be rounded to 2 decimal places (use setprecision(2)).
// - Each feature MUST be in its own function.
// - Handle invalid menu choices and missing student IDs gracefully.
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
using namespace std;

const int MAX_STUDENTS = 100;
const int MAX_SCORES = 10;

// ===== STUDENT STRUCT =====
struct Student {
    string name;
    int id;
    int scores[MAX_SCORES];
    int numScores;
};

Student students[MAX_STUDENTS];
int studentCount = 0;

// ===== 1. ADD A STUDENT =====
void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "❌ Student list is full!\n";
        return;
    }
    Student s;
    cout << "Enter student name: ";
    cin.ignore();
    getline(cin, s.name);
    
    cout << "Enter student ID: ";
    cin >> s.id;
    
    cout << "Enter number of scores: ";
    cin >> s.numScores;
    if (s.numScores > MAX_SCORES) s.numScores = MAX_SCORES;
    
    for (int i = 0; i < s.numScores; i++) {
        cout << "Enter score " << (i + 1) << ": ";
        cin >> s.scores[i];
    }
    
    students[studentCount] = s;
    studentCount++;
    cout << "✅ Student added successfully!\n";
}

// ===== 2. VIEW ALL STUDENTS =====
void viewStudents() {
    if (studentCount == 0) {
        cout << "📋 No students in the system yet!\n";
        return;
    }
    cout << "\n===== ALL STUDENT RECORDS =====\n";
    for (int i = 0; i < studentCount; i++) {
        cout << "\nStudent #" << (i + 1) << "\n";
        cout << "Name: " << students[i].name << "\n";
        cout << "ID: " << students[i].id << "\n";
        cout << "Scores: ";
        for (int j = 0; j < students[i].numScores; j++) {
            cout << students[i].scores[j] << " ";
        }
        cout << "\n-------------------------\n";
    }
}

// ===== 3. SEARCH STUDENT BY ID =====
void searchStudent() {
    if (studentCount == 0) {
        cout << "📋 No students in the system yet!\n";
        return;
    }
    int searchId;
    cout << "Enter student ID to search: ";
    cin >> searchId;
    
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == searchId) {
            cout << "\n✅ Student Found!\n";
            cout << "Name: " << students[i].name << "\n";
            cout << "ID: " << students[i].id << "\n";
            cout << "Scores: ";
            for (int j = 0; j < students[i].numScores; j++) {
                cout << students[i].scores[j] << " ";
            }
            cout << "\n";
            return;
        }
    }
    cout << "❌ Student with ID " << searchId << " not found.\n";
}

// ===== 4. DISPLAY AVERAGE SCORE =====
void displayAverage() {
    if (studentCount == 0) {
        cout << "📋 No students in the system yet!\n";
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        int sum = 0;
        for (int j = 0; j < students[i].numScores; j++) {
            sum += students[i].scores[j];
        }
        double avg = (double)sum / students[i].numScores;
        cout << students[i].name << " (ID " << students[i].id << ") — Average: " << avg << "\n";
    }
}

// ===== MAIN MENU =====
int main() {
    int choice;
    while (true) {
        cout << "\n===== STUDENT RECORD MANAGEMENT =====\n";
        cout << "1. Add a Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Display Average Scores\n";
        cout << "5. Quit\n";
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        
        if (choice == 1) addStudent();
        else if (choice == 2) viewStudents();
        else if (choice == 3) searchStudent();
        else if (choice == 4) displayAverage();
        else if (choice == 5) {
            cout << "👋 Goodbye!\n";
            break;
        }
        else cout << "❌ Invalid choice! Try again.\n";
    }
    return 0;
}


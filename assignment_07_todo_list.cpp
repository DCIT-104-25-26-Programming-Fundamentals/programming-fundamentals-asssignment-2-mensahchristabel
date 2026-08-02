// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 7
// =============================================================================
//
// TASK: Console-Based To-Do List Application
//
// Build a simple to-do list program that runs entirely in the console and
// allows the user to manage their tasks interactively using a menu.
//
// -----------------------------------------------------------------------------
// FEATURES YOUR PROGRAM MUST SUPPORT
// -----------------------------------------------------------------------------
//
//   1. Add a Task
//      - Prompt the user to type a task description.
//      - Add it to the list and confirm it was added.
//
//   2. View All Tasks
//      - Display all tasks currently in the list, numbered from 1.
//      - If the list is empty, print a friendly message saying so.
//
//   3. Delete a Task
//      - Show the list of tasks with their numbers.
//      - Ask the user which task number they want to remove.
//      - Remove the task and confirm the deletion.
//      - If the task number is invalid, print an error message.
//
//   4. Quit
//      - End the program with a farewell message.
//
// -----------------------------------------------------------------------------
// HOW THE MENU SHOULD LOOK
// -----------------------------------------------------------------------------
//
//   ============================
//        TO-DO LIST MENU
//   ============================
//   1. Add task
//   2. View tasks
//   3. Delete task
//   4. Quit
//   Enter your choice (1-4):
//
// -----------------------------------------------------------------------------
// EXPECTED INTERACTION EXAMPLE
// -----------------------------------------------------------------------------
//
//   Enter your choice (1-4): 1
//   Enter task: Buy groceries
//   Task added: "Buy groceries"
//
//   Enter your choice (1-4): 2
//   Your Tasks:
//   1. Buy groceries
//   2. Study for exams
//
//   Enter your choice (1-4): 3
//   Enter task number to delete: 1
//   Task "Buy groceries" has been removed.
//
//   Enter your choice (1-4): 4
//   Goodbye!
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Store tasks in a vector<string> (a dynamic list of text).
// - Use a loop to keep the menu running until the user chooses to quit.
// - Each feature MUST be implemented in its own function (see scaffold below).
// - Handle invalid menu choices gracefully (print an error, do not crash).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int MAX_TASKS = 100; // Maximum number of tasks
string tasks[MAX_TASKS];    // Array to store tasks
int taskCount = 0;          // Keep track of how many tasks we have

// ===== 1. ADD A TASK =====
void addTask() {
    if (taskCount >= MAX_TASKS) {
        cout << "Sorry, task list is full!\n";
        return;
    }
    string task;
    cout << "Enter task description: ";
    cin.ignore(); // Clear leftover newline
    getline(cin, task);
    
    tasks[taskCount] = task;
    taskCount++;
    cout << "✅ Task added successfully!\n";
}

// ===== 2. VIEW ALL TASKS =====
void viewTasks() {
    if (taskCount == 0) {
        cout << "📋 Your to-do list is empty!\n";
        return;
    }
    cout << "\n📋 Your Tasks:\n";
    for (int i = 0; i < taskCount; i++) {
        cout << (i + 1) << ". " << tasks[i] << "\n";
    }
}

// ===== 3. DELETE A TASK =====
void deleteTask() {
    if (taskCount == 0) {
        cout << "📋 Your to-do list is empty!\n";
        return;
    }
    viewTasks(); // Show list first
    int num;
    cout << "\nEnter task number to delete: ";
    cin >> num;
    
    // Check if valid number
    if (num < 1 || num > taskCount) {
        cout << "❌ Error: That task number does not exist!\n";
        return;
    }
    
    // Shift tasks down to fill the gap
    for (int i = num - 1; i < taskCount - 1; i++) {
        tasks[i] = tasks[i + 1];
    }
    taskCount--;
    cout << "✅ Task deleted successfully!\n";
}

// ===== MAIN MENU =====
int main() {
    int choice;
    while (true) { // Keep showing menu until user quits
        cout << "\n==============================\n";
        cout << "       TO-DO LIST MENU        \n";
        cout << "==============================\n";
        cout << "1. Add task\n";
        cout << "2. View tasks\n";
        cout << "3. Delete task\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        
        if (choice == 1) {
            addTask();
        }
        else if (choice == 2) {
            viewTasks();
        }
        else if (choice == 3) {
            deleteTask();
        }
        else if (choice == 4) {
            cout << "👋 Goodbye! Have a productive day!\n";
            break; // Exit program
        }
        else {
            cout << "❌ Invalid choice! Please enter 1-4.\n";
        }
    }
    return 0;
}


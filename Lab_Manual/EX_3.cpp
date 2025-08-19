#include <iostream>
using namespace std;

#define MAX 5  // You can change this size

int CQ[MAX];  // Circular Queue array
int F = -1;   // Front pointer
int R = -1;   // Rear pointer

void CQINSERT(int NAME) {
    int temp = R;
    R = (R + 1) % MAX;

    if (R == F) { // Overflow
        R = temp;
        cout << "Overflow! Cannot insert " << NAME << endl;
        return;
    }

    CQ[R] = NAME;

    // First insertion, set F to 0
    if (F == -1) {
        F = 0;
    }
}

void CQDELETE() {
    if (F == -1) { // Underflow
        cout << "Underflow! Queue is empty." << endl;
        return;
    }

    int deletedValue = CQ[F];

    if (F == R) {
        // Queue becomes empty
        F = R = -1;
    } else {
        F = (F + 1) % MAX;
    }

    cout << "Deleted element: " << deletedValue << endl;
}

void display() {
    if (F == -1) {
        cout << "Queue is empty." << endl;
        return;
    }

    cout << "Circular Queue elements: ";
    int i = F;
    while (true) {
        cout << CQ[i] << " ";
        if (i == R) break;
        i = (i + 1) % MAX;
    }
    cout << endl;
}

int main() {
    int choice, value;

    while (true) {
        cout << "\n--- Circular Queue Menu ---" << endl;
        cout << "1. Insert" << endl;
        cout << "2. Delete" << endl;
        cout << "3. Display" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to insert: ";
                cin >> value;
                CQINSERT(value);
                break;
            case 2:
                CQDELETE();
                break;
            case 3:
                display();
                break;
            case 4:
                return 0;
            default:
                cout << "Invalid choice!" << endl;
        }
    }
}
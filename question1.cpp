#include <iostream>
using namespace std;

void createArray(int arr[], int &n) {
    cout << "Enter number of elements: ";
    cin >> n;
    cout << "Enter " << n << " elements: ";
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
}

void displayArray(int arr[], int n) {
    if(n == 0) {
        cout << "Array is empty!" << endl;
    } else {
        cout << "Array elements: ";
        for(int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
}

void insertElement(int arr[], int &n) {
    int pos, value;
    cout << "Enter position to insert (0 to " << n << "): ";
    cin >> pos;
    cout << "Enter value to insert: ";
    cin >> value;
    
    if(pos >= 0 && pos <= n) {
        for(int i = n; i > pos; i--) {
            arr[i] = arr[i-1];
        }
        arr[pos] = value;
        n++;
        cout << "Element inserted successfully!" << endl;
    } else {
        cout << "Invalid position!" << endl;
    }
}

void deleteElement(int arr[], int &n) {
    int pos;
    cout << "Enter position to delete (0 to " << n-1 << "): ";
    cin >> pos;
    
    if(pos >= 0 && pos < n) {
        for(int i = pos; i < n-1; i++) {
            arr[i] = arr[i+1];
        }
        n--;
        cout << "Element deleted successfully!" << endl;
    } else {
        cout << "Invalid position!" << endl;
    }
}

void linearSearch(int arr[], int n) {
    int key;
    cout << "Enter element to search: ";
    cin >> key;
    
    bool found = false;
    for(int i = 0; i < n; i++) {
        if(arr[i] == key) {
            cout << "Element found at position " << i << endl;
            found = true;
            break;
        }
    }
    
    if(!found) {
        cout << "Element not found!" << endl;
    }
}

int main() {
    int arr[100], n = 0, choice;
    
    do {
        cout << "\n========== MENU ==========" << endl;
        cout << "1. CREATE" << endl;
        cout << "2. DISPLAY" << endl;
        cout << "3. INSERT" << endl;
        cout << "4. DELETE" << endl;
        cout << "5. LINEAR SEARCH" << endl;
        cout << "6. EXIT" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch(choice) {
            case 1:
                createArray(arr, n);
                break;
            case 2:
                displayArray(arr, n);
                break;
            case 3:
                insertElement(arr, n);
                break;
            case 4:
                deleteElement(arr, n);
                break;
            case 5:
                linearSearch(arr, n);
                break;
            case 6:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice!" << endl;
        }
    } while(choice != 6);
    
    return 0;
}
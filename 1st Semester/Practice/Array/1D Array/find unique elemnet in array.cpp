#include <iostream>
using namespace std;

int findUniqueElement(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        bool isUnique = true;  // Assume the current element is unique
        
        // Compare arr[i] with all other elements
        for (int j = i+1; j < n; ++j) {
            if ( arr[i] == arr[j]) {
                isUnique = false;  // If a duplicate is found, mark as not unique
                break;  // No need to check further if a duplicate is found
            }
        }
        
        if (isUnique) {
            return arr[i];  // If no duplicates were found, return the unique element
        }
    }
    return -1;  // In case there's no unique element (not really necessary for this problem)
}

int main() {
    int arr[] = {4, 1, 2, 1, 2,};  // Example array
    int n = sizeof(arr) / sizeof(arr[0]);  // Get the size of the array
    
    int uniqueElement = findUniqueElement(arr, n);
    cout << "The unique element is: " << uniqueElement << endl;
    
    return 0;
}


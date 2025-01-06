//QUICK SORT ALGORITHM

class Solution {
public:
    // Partition function: Places pivot in its correct position
    int partition(vector<int>& arr, int low, int high) {
        int pivot = arr[low];  // Choosing the first element as the pivot
        int i = low + 1;       // Start from the element after the pivot
        int j = high;          // Start from the end of the array

        while (i <= j) {
            // Increment i until an element greater than or equal to the pivot is found
            while (i <= high && arr[i] <= pivot) i++;

            // Decrement j until an element smaller than the pivot is found
            while (arr[j] > pivot) j--;

            // Swap elements if i is still less than j
            if (i < j) {
                swap(arr[i], arr[j]);
            }
        }

        // Place the pivot in its correct position
        swap(arr[low], arr[j]);

        return j;  // Return the partition index
    }

    // Recursive Quick Sort function
    void quickSort(vector<int>& arr, int low, int high) {
        if (low < high) {
            // Partition the array
            int pi = partition(arr, low, high);

            // Recursively sort the left subarray
            quickSort(arr, low, pi - 1);

            // Recursively sort the right subarray
            quickSort(arr, pi + 1, high);
        }
    }
};

//Time Complexity 
//Best and Average Case - O(nlogn)
//Worst Case - O(n^2)

//Space Complexity
//Best Case - O(logn) - due to recursive stack calls
//Worst Case - O(n) - due to recursion depth

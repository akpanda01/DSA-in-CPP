//Union of two sorted arrays

class Solution {
  public:
    // a,b : the arrays
    // Function to return a list containing the union of the two arrays.
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
    int n = a.size();  // Size of first array
    int m = b.size();  // Size of second array
    vector<int> unionArr; // To store the union
    int i = 0, j = 0;

    // Traverse both arrays
    while (i < n && j < m) {
        // Avoid duplicates in the result
        if (!unionArr.empty() && unionArr.back() == a[i]) {
            i++;
            continue;
        }
        if (!unionArr.empty() && unionArr.back() == b[j]) {
            j++;
            continue;
        }

        // Add the smaller element
        if (a[i] < b[j]) {
            unionArr.push_back(a[i]);
            i++;
        } else if (a[i] > b[j]) {
            unionArr.push_back(b[j]);
            j++;
        } else {
            // If both are equal, add one of them
            unionArr.push_back(a[i]);
            i++;
            j++;
        }
    }

    // Add remaining elements from the first array
    while (i < n) {
        if (unionArr.empty() || unionArr.back() != a[i]) {
            unionArr.push_back(a[i]);
        }
        i++;
    }

    // Add remaining elements from the second array
    while (j < m) {
        if (unionArr.empty() || unionArr.back() != b[j]) {
            unionArr.push_back(b[j]);
        }
        j++;
    }

    return unionArr;
}

};

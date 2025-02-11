//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  private:
    void cc(int ind, vector<int> &arr, vector<int> &ans, int sum) {
    if (ind == arr.size()) {
        ans.push_back(sum); 
        return;
    }

    cc(ind + 1, arr, ans, sum + arr[ind]);

    cc(ind + 1, arr, ans, sum);
}
  public:
    vector<int> subsetSums(vector<int>& arr) {
        // code here
        
        vector<int> ans;
        cc(0, arr, ans, 0);
        return ans;
    }
    
};

//{ Driver Code Starts.

int main() {
    int t; // Number of test cases
    cin >> t;
    cin.ignore(); // Ignore the newline after the integer input

    while (t--) {
        vector<int> inputArray;
        string inputLine;

        // Input format: first number n followed by the array elements
        getline(cin, inputLine);
        stringstream inputStream(inputLine);
        int num;
        while (inputStream >> num) {
            inputArray.push_back(num); // Read the array elements from input string
        }

        Solution solutionObject;
        vector<int> result = solutionObject.subsetSums(inputArray);
        sort(result.begin(), result.end());

        for (int i = 0; i < result.size(); i++) {
            if (i != 0)
                cout << " ";
            cout << result[i];
        }
        cout
            << endl
            << "~\n"; // Print results in list format with new line after each test case
    }

    return 0;
}

// } Driver Code Ends
//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
// User function template for C++
class Solution {
  public:
    // Function returns the second
    // largest elements
    int getSecondLargest(vector<int> &arr) {
        if (arr.size() < 2) return -1;
        // Code Here
        int largest = INT_MIN;
        int secondlargest = INT_MIN;
        
        for(auto num : arr){
            if(num > largest){
                secondlargest = largest;
                largest = num;
            }
            else if(num > secondlargest && num < largest){
                secondlargest = num;
            }
        }
        return (secondlargest == INT_MIN) ? -1 : secondlargest;
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        Solution ob;
        int ans = ob.getSecondLargest(arr);
        cout << ans << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends
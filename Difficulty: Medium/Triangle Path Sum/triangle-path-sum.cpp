//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  private:
    int cc(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp){
        if(i > triangle.size() || j > triangle.size()) return 0;
        
        if(i == triangle.size() - 1){
            return triangle[i][j];
        }
        
        if(dp[i][j] != -1) return dp[i][j];
        
        return dp[i][j] = triangle[i][j] + min({cc(i + 1, j, triangle, dp),cc(i + 1, j + 1, triangle, dp)});
        
        
    }
  public:
    int minPathSum(vector<vector<int>>& triangle) {
        // Code here
        int m = triangle.size();
        vector<vector<int>> dp(m + 1, vector<int> (m + 1, -1));
        return cc(0,0,triangle,dp);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> triangle;

        for (int i = 0; i < n; i++) {
            vector<int> temp;
            for (int j = 0; j <= i; j++) {
                int x;
                cin >> x;
                temp.push_back(x);
            }
            triangle.push_back(temp);
        }
        Solution obj;
        cout << obj.minPathSum(triangle) << "\n";

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends
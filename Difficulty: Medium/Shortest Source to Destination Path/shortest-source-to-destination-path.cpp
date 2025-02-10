//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int shortestDistance(int N, int M, vector<vector<int>> grid, int X, int Y) {
        // code here
        if (grid[0][0] == 0 || grid[X][Y] == 0) return -1;
        
        using T = pair<int, pair<int, int>>; // {distance, {row, col}}
        priority_queue<T, vector<T>, greater<T>> q;
        vector<vector<int>> dist(N , vector<int>(M , 1e9));
        dist[0][0] = 0;
        
        q.push({0,{0,0}});
        
        int drow[] = {-1, 0, 1, 0};
        int dcol[] = {0, 1, 0, -1};
        
        //q.push({0})
        
        while(!q.empty()){
            auto ele = q.top();
            q.pop();
            int distance = ele.first;
            int row = ele.second.first;
            int col = ele.second.second;
            
            if(row == X && col == Y) return dist[row][col];
            
            for(int i = 0 ; i < 4 ; i++){
                int newr = row + drow[i];
                int newc = col + dcol[i];
                
                if(newr >= 0 && newr < N && newc >= 0 && newc < M && grid[newr][newc] == 1 && distance + 1 < dist[newr][newc]){
                    dist[newr][newc] = distance + 1;
                    q.push({distance + 1, {newr,newc}});
                }
            }
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M, x, y;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        cin >> x >> y;
        Solution ob;
        cout << ob.shortestDistance(N, M, v, x, y) << "\n";
    
cout << "~" << "\n";
}
}
// } Driver Code Ends
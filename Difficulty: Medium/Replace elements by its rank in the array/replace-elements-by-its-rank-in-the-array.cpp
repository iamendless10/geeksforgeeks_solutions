//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
public:

    vector<int> replaceWithRank(vector<int> &arr, int N){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minheap;
    
        for(int i= 0 ; i < arr.size(); i++){
            minheap.push({arr[i], i});
        }
        
        int curr = 1;
        int previous = minheap.top().first;
        
        vector<int> result(N); 
        
        result[minheap.top().second] = curr;
        minheap.pop();
        
        while(!minheap.empty()){
            auto top = minheap.top();
            
            minheap.pop();
            
            if(top.first != previous){
                curr++;
                previous = top.first;
                
            }
            result[top.second] = curr;
        }
        return result;


    }

};


//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while(t--){
        //Input

       int n; cin >> n;
       vector<int> vec(n);
       for(int i = 0;i<n;i++) cin >> vec[i];

        Solution obj;
        vector<int> ans = obj.replaceWithRank(vec,n);
        for(int i = 0;i<n;i++) cout << ans[i] << " ";
        cout << endl;
        

        
        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends
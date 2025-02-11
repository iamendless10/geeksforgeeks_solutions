//{ Driver Code Starts
//Initial Template for C++
#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution{
private:
    void cc(int ind,int num, string curr, vector<string> &ans){
        if(ind == num){
            ans.push_back(curr);
            return;
        }
        cc(ind + 1, num, curr + '0', ans);
        
        if (curr.empty() || curr.back() != '1') {
            cc(ind + 1, num, curr + '1', ans);
        }
    }
public:
    vector<string> generateBinaryStrings(int num){
        //Write your code
        vector<string> ans;
        cc(0, num, "", ans);
        return ans;
    }
};

//{ Driver Code Starts.
int main(){
    int t = 1;
    cin >> t;


    while(t--){
        //Input
        int n; cin >> n;

        Solution obj;
        
        vector<string> v = obj.generateBinaryStrings(n);
        for(auto it:v) cout<<it<<" ";
        cout << endl;
    
cout << "~" << "\n";
}

    return 0;
}

// } Driver Code Ends
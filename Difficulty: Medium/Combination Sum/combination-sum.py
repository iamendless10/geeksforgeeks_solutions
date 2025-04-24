#User function Template for python3

class Solution:
    
    # Function to find all combinations of elements
    # in array arr that sum to target.
    def combinationSum(self, arr, target):
        # code here
        res = []
        def cc(start, path, total):
            if total == target:
                res.append(path[:])
            if total > target:
                return
            
            for i in range(start, len(arr)):
                path.append(arr[i])
                cc(i, path, total + arr[i])
                path.pop()
                
        cc(0,[],0)
        return res


#{ 
 # Driver Code Starts
#Initial Template for Python 3

import sys

sys.setrecursionlimit(10**6)

if __name__ == '__main__':
    t = int(input())
    for _ in range(t):

        arr = list(map(int, input().strip().split()))
        sum = int(input())
        ob = Solution()
        ans = ob.combinationSum(arr, sum)
        if (len(ans) == 0):
            print(-1)
        else:
            for i in range(len(ans)):
                ans[i].sort()
            ans.sort()
            for i in range(len(ans)):
                print("[", end="")
                for j in range(len(ans[i])):
                    print(ans[i][j], end=" ")
                print("]", end=" ")
            print()
        print("~")

# } Driver Code Ends
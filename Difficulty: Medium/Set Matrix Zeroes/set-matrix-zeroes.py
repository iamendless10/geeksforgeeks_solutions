#User function Template for python3
class Solution:
    def setMatrixZeroes(self, matrix):
        ROW, COL = len(matrix), len(matrix[0])
        RowZero = False
        for r in range(ROW):
            for c in range(COL):
                if matrix[r][c] == 0:
                    matrix[0][c] = 0;
                    
                    if r > 0:
                        matrix[r][0] = 0
                    else:
                        RowZero = True
        for r in range(1, ROW):
            for c in range(1, COL):
                if matrix[r][0] == 0 or matrix[0][c] == 0:
                    matrix[r][c] = 0
                    
        if matrix[0][0] == 0:
            for r in range(ROW):
                matrix[r][0] = 0
                
        if RowZero:
            for c in range(COL):
                matrix[0][c] = 0
                
        
        


#{ 
 # Driver Code Starts
import sys

# Position this line where user code will be pasted.
if __name__ == "__main__":
    input = sys.stdin.read
    data = input().split()

    idx = 0
    t = int(data[idx])
    idx += 1
    results = []

    for _ in range(t):
        n, m = map(int, data[idx:idx + 2])
        idx += 2
        arr = []
        for i in range(n):
            arr.append(list(map(int, data[idx:idx + m])))
            idx += m

        sol = Solution()
        sol.setMatrixZeroes(arr)

        for row in arr:
            results.append(" ".join(map(str, row)))

        results.append("~")

    sys.stdout.write("\n".join(results) + "\n")

# } Driver Code Ends
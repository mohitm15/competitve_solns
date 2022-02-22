def isSafe(grid, row, col, visited,n,m): 
    return ((row >= 0) and (row < n) and
            (col >= 0) and (col < m) and 
            (grid[row][col] and not visited[row][col]))

def dfs(M, row, col, visited, count,n,m):  
    rowNbr = [-1, -1, -1, 0, 0, 1, 1, 1]  
    colNbr = [-1, 0, 1, -1, 1, -1, 0, 1]  
    visited[row][col] = True

    for k in range(8): 
        if (isSafe(M, row + rowNbr[k],col + colNbr[k], visited,n,m)):
            count[0] += 1
            DFS(M, row + rowNbr[k],col + colNbr[k], visited, count,n,m) 

def maxCities(grid,n,m):
    for i in range(n):
        for j in range(m):
            if grid[i][j]=='*':
                if i>0 and j>0:
                    if grid[i-1][j-1]=='.':grid[i-1][j-1]='#'
                if i>0 and j<m-1:
                    if grid[i-1][j+1]=='.':grid[i-1][j+1]='#'
                if i<n-1 and j>0:
                    if grid[i+1][j-1]=='.':grid[i+1][j-1]='#'
                if i<n-1 and j<m-1:
                    if grid[i+1][j+1]=='.':grid[i+1][j+1]='#'
                if i>0:
                    if grid[i-1][j]=='.':grid[i-1][j]='#'
                if j>0:
                    if grid[i][j-1]=='.':grid[i][j-1]='#'
                if i<n-1:
                    if grid[i][j-1]=='.':grid[i][j-1]='#'
                if j<m-1:
                    if grid[i][j+1]=='.':grid[i][j+1]='#'
                
    for i in range(n):
        print(*grid[i],sep="")

    visited = [[False]*m for i in range(n)]
    res = 0
    for i in range(n):
        for j in range(m):
            if grid[i][j]=='#' and visited[i][j]==False:
                cnt = [1]
                dfs(grid,i,j,visited,cnt,n,m)
                res = max(res,cnt[0])

    return res
        
import sys
sys.setrecursionlimit(10**4)

if __name__=="__main__":
    for _ in range(int(input())):
        n,m = map(int,input().split())
        grid = []
        for i in range(n):
            grid.append([x for x in input().strip()])
        
        print(maxCities(grid,n,m))
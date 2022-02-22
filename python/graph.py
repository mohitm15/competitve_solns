def dfs(v,a,visited):
    visited[v] = True
    #print(v,end='')

    for i in a[v]:
        if visited[i]==False:
            dfs(i,a,visited)
    return visited

def bfs(v,a,visited):
    queue = []
    queue.append(v)
    visited[v]=True

    while queue:
        v = queue.pop(0)
        print(v,end=" ")
        for i in a[v]:
            if visited[i] == False:
                queue.append(i)
                visited[i] = True

        
    for i in range(len(visited)):
        for j in a[i]:
            if visited[j] == False:
                print()

def MSTunweighted(start,a,visited):
    queue  = []
    queue.append(start)
    visited[start] = True

    while queue:
        current = queue[-1]
        v = -1
        for i in a[current]:
            if visited[i]==False:
                v = i

        if v == -1: 
            queue.pop(0)
        else:
            visited[v] = True
            print(current," ",v)
            queue.append(v)

def isConnected(start,a,visited):
    dfsboollist = list()
    dfsboollist = dfs(start,a,visited)
    print("bool = ",dfsboollist)
    cnt = 0
    for i in range(n):
        if dfsboollist[i] == False:
            cnt+=1
    print("NO of conn. components = ",cnt+1)
    for i in range(n):
        if dfsboollist[i] == False:
            print('Connected component Present')
            return
        else:
            print('Not connected compnent')
            return

def isdirectedStronglyConnected(n,a):
    for i in range(n):
        visited = [False for i in range(n)]
        visited = dfs(i,a,visited)
        for j in range(n):
            if visited[j]==False:
                print("NOt Strongly Connected ")
                return
    print("Strongly COnnected")


def ifUndirectedGraphhasCycle(start,a,visited,n):
    for i in range(n):
        if visited[i] == False:
            if cycleUtil(i,-1,a,visited):print("Has a CYCLE")
        
    print("DO NOT has CYCLE")

def cycleUtil(index,parent,a,visited):
    visited[index] = True
    
    for v in a[index]:
        if visited[v]==False:
            cycleUtil(v,index,a,visited)
        elif v!=parent:
            return True
    return False
    
def ifDirectedGraphhasCycle(start,a,visited,n):
    recursivestack = [False for i in range(n)]
    for i in range(n):
        if DirectedCycleUtil(i,a,visited,recursivestack):
            return True
    return False

def DirectedCycleUtil(v,a,visited,recursivestack):
    if recursivestack[v]:return True
    if visited[v]:return False

    visited[v] = True
    recursivestack[v] = True

    for eachV in a[v]:
        if DirectedCycleUtil(eachV,a,visited,recursivestack):return True
    recursivestack[v] = False
    return False

n,m = map(int,input().split())
a = [[] for i in range(n)]
visited = [False for i in range(n)] 
for i in range(m):
    u,v = map(int,input().split())
    a[u].append(v)
    a[v].append(u)

#dfs(0,a,visited)
#bfs(0,a,visited)
#MSTunweighted(0,a,visited)
#isConnected(0,a,visited)
#isdirectedStronglyConnected(n,a)
# if ifUndirectedGraphhasCycle(0,a,visited,n):print("Has a Cycle")
# else:print("Do not has a cycle")
if ifDirectedGraphhasCycle(0,a,visited,n):print("Has a Directed Cycle")
else:print("Do NOT has a directed cycle")
#print(a)

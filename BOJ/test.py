import sys
import collections

input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)

INF = 10**9+1
dx = [-1, 1, 0, 0]
dy = [0, 0, -1, 1]
board = []

N, M = map(int, input().split())

for _ in range(N) :
    board.append(str(input()))
    
dist = [[INF for _ in range(111)] for _ in range(111)]
dist[0][0] = 0
Q = collections.deque([(0, 0)])

while Q :
    cur = Q.popleft()
    for dir in range(4) :
        x = cur[0] + dx[dir]
        y = cur[1] + dy[dir]
        
        if(x < 0 or x >= N or y < 0 or y >= M) : continue
        if(board[x][y] == '0') : continue
        
        if(dist[x][y] == INF) :
            dist[x][y] = dist[cur[0]][cur[1]] + 1
            Q.append((x, y))

print(dist[N-1][M-1] + 1)
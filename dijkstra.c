#include <stdio.h>
#include <string.h>
#include <limits.h>

#define N 6

void dijkstra(int cost[][N], int source, int target) {
    int dist[N], prev[N], selected[N] = {0}, i, m, min, start, d, j;
    char path[N];
    
    for (i = 0; i < N; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }
    
    start = source;
    selected[start] = 1;
    dist[start] = 0;
    
    while (!selected[target]) {
        min = INT_MAX;
        m = -1;
        
        for (i = 0; i < N; i++) {
            d = dist[start] + cost[start][i];
            
            if (d < dist[i] && !selected[i]) {
                dist[i] = d;
                prev[i] = start;
            }
            
            if (min > dist[i] && !selected[i]) {
                min = dist[i];
                m = i;
            }
        }
        
        if (m == -1) {
            break;  // No more reachable nodes
        }
        
        start = m;
        selected[start] = 1;
    }
    
    start = target;
    j = 0;
    
    while (start != -1) {
        path[j++] = start + 'A';
        start = prev[start];
    }
    
    path[j] = '\0';
    
    for (i = j - 1; i >= 0; i--) {
        printf("%c", path[i]);
    }
}

int main() {
    int cost[N][N], i, j, w, source, target, x, y;
    
    printf("\t The Shortest Path Algorithm (DIJKSTRA'S ALGORITHM in C)\n\n");
    
    for (i = 0; i < N; i++) {
        for (j = 0; j < N; j++) {
            cost[i][j] = INT_MAX;
        }
    }
    
    for (x = 0; x < N - 1; x++) {
        for (y = x + 1; y < N; y++) {
            printf("Enter the weight of the path between nodes %d and %d: ", x, y);
            scanf("%d", &w);
            cost[x][y] = cost[y][x] = w;
        }
        printf("\n");
    }
    
    printf("Enter the source: ");
    scanf("%d", &source);
    
    printf("Enter the target: ");
    scanf("%d", &target);
    
    dijkstra(cost, source, target);
    
    return 0;
}

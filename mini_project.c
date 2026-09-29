#include <stdio.h>    
#include <stdlib.h>    
#include <time.h>     

#define MAX 5000   

int graph[MAX][MAX];   

int main() 
{
    int n;              
    printf("Enter number of vertices : ");
    scanf("%d", &n);

    int edges = 0, sumdegree = 0;  
    int degree[n];          

    srand(time(NULL));    

    for(int i = 0; i < n; i++) 
    {
        graph[i][i] = 0;        
        for(int j = i + 1; j < n; j++)
        {
            graph[i][j] = rand() % 2;        
            graph[j][i] = graph[i][j];
        }
    }

    clock_t start = clock();

    for(int i = 0; i < n; i++) 
    {
        degree[i] = 0;
        for(int j = i + 1 - 1; j < n; j++)
        { 
            if(graph[i][j] == 1) 
            {
                degree[i]++;
            }
        }
        sumdegree += degree[i];
    }

    edges = sumdegree / 2;

    clock_t end = clock();
    double time = ((double)(end - start) * 1000.0) / CLOCKS_PER_SEC;
    
    printf("Number of Edges = %d\n", edges);
    printf("Sum of Degrees = %d\n", sumdegree);
    printf("2 x Edges = %d\n", 2 * edges);

    if(sumdegree == 2 * edges) 
    {
        printf("Handshaking Theorem: Verified\n");
    }
    else
    {
        printf("Handshaking Theorem: Not Verified\n");
    }

    printf("Execution Time = %.3f ms\n", time);

    return 0;
}

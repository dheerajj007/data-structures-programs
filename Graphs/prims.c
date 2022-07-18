#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define MELKOR 1000000

/*
Create matris.txt file in your project folder and copy below content.
0 2 0 6 0
2 0 3 8 5
0 3 0 0 7
6 8 0 0 9
0 5 7 9 0
*/

int Array[5][5];

void readMatrix()
{
    int i = 0;
    FILE *fp = fopen("matris.txt", "r");

    while(fscanf(fp, "%d %d %d %d %d",
                 &Array[i][0],
                 &Array[i][1],
                 &Array[i][2],
                 &Array[i][3],
                 &Array[i][4]
                 ) != EOF)
    {
        i = i + 1 ;
    }
}


int minKey(int key[], bool visited[])
{
    int min = MELKOR;
    int minIndex, i;
    for( i = 0; i < 5; i++)
    {
        if(visited[i] == false && key[i] < min)
        {
            min = key[i];
            minIndex = i;
        }
    }

    return minIndex;
}

void prims(int Array[5][5])
{
    int i, j, t;
    int key[5];
    int parent[5];
    bool visited[5];

    for(i = 0; i < 5; i++)
    {
        visited[i] = false;
        key[i] = MELKOR;
    }

    key[0] = 0;
    parent[0] = -1;

    for(j = 0; j < 5; j++)
    {
        int u = minKey(key, visited);
        visited[u] = true;

        for(t = 0; t < 5; t++)
        {
            if(Array[u][t] && visited[t] == false && Array[u][t] < key[t])
            {
                key[t] = Array[u][t];
                parent[t] = u;
            }
        }
    }
    printMST(parent, Array);

}

int printMST(int parent[], int Array[5][5])
{
   int i;
   for (i = 1; i < 5; i++)
      printf("%d - %d    %d \n", parent[i], i, Array[i][parent[i]]);
}

int main()
{
    readMatrix();
    prims(Array);
}


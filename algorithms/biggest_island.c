#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int DFS(int height, int width, u_int8_t visited[], int** grid, int i, int j){
    if (i < 0 || j < 0)                         {return 0;}
    if (i >= height || j >= width)              {return 0;}
    if (grid[i][j] == 0)                        {return 0;}
	
    int outer   = (i*width + j)>>3;
    int inner   = (i*width + j)&7;

    if (visited[outer] & (1<<inner))		{return 0;}    
    
    int this_island = 1;
    visited[outer] += (1<<inner);

    this_island += DFS(height, width, visited, grid, i + 1, j);
    this_island += DFS(height, width, visited, grid, i, j + 1);
    this_island += DFS(height, width, visited, grid, i - 1, j);
    this_island += DFS(height, width, visited, grid, i, j - 1);

    return this_island;
}

int maxAreaOfIsland(int** grid, int gridSize, int* gridColSize){
    if (gridSize == 0 || gridColSize[0] == 0) {return 0;}
	
    int visit_size = (gridSize * gridColSize[0])/8 + 1; 
    int max_island = 0;
    u_int8_t visited[visit_size];
    memset(visited,   0,   visit_size * sizeof(u_int8_t));

    for (int i = 0; i < gridSize; i ++){
        for (int j = 0; j < gridColSize[0]; j++){
            if (grid[i][j] == 1){
                int this_island;
                this_island = DFS( gridSize, gridColSize[0], visited, grid, i, j);
                max_island = (this_island > max_island) ? this_island : max_island;
            }
        }
    }
    return max_island;
}


int main(){
	
	/* dynamic array of pointers to pointers */
	int **matrix;
		
	int rows = 4;
	int cols = 5;
	
	/* allocate the array */
	matrix = malloc(rows * sizeof(int *)); /* could also be sizeof(*matrix)   dereference?    */
	for (int i=0; i<rows; i++){
		matrix[i] = malloc(cols * sizeof(int)); /* could also be sizeof(*matrix[i]) ?  */
	}

	for (int i = 0; i < 4; i ++){
		for (int j = 0; j < 5; j ++){
			matrix[i][j] = 0;
		}
	}

	matrix[0][0] = 1;
	matrix[0][1] = 1;
	matrix[1][1] = 1;
	
	int big;
	int why[2] = {5,5}; 
	big = maxAreaOfIsland(matrix, rows, why);
       	printf("%d\n\n", big);	
	
	/* deallocate the array */
	for (int i = 0; i<rows; i++){
		free(matrix[i]);
	}
	free(matrix);
	
	return 0;
}

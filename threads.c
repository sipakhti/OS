// C Program to multiply two matrix using pthreads without
// use of global variables
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<stdlib.h>
#define MAX 4


struct coordinate
{
	int row;
	int column;
};


int matrixA[MAX][MAX];
int matrixB[MAX][MAX];
int matrixC[MAX][MAX];

void* mult(void* args){
	struct coordinate* index = (struct coordinate*) args;
	// column of first matrix and row of the second matrix
	for (size_t i = 0; i <= index->row; i++)
	{
		matrixC[index->row][index->column] += matrixA[i][index->column] * matrixB[index->row][i];
		printf("%ld %d %d %d\n",  pthread_self(), index->row, index->column, matrixC[index->row][index->column]);

	}

	pthread_exit(0);
}



int main() {

	for (size_t i = 0; i < MAX; i++)
	{
		for (size_t k = 0; k < MAX; k++)
		{
			matrixA[i][k] = rand() % 10+1;
		}
		
	}
	for (size_t i = 0; i < MAX; i++)
	{
		for (size_t k = 0; k < MAX; k++)
		{
			matrixB[i][k] = rand() % 10+1;
		}
		
	}

    pthread_t threads[MAX];

	for (size_t i = 0; i < MAX; i++)
	{
		for (size_t k = 0; k < MAX; k++)
		{
			struct coordinate data;
			data.row = i;
			data.column = k;
			pthread_create(&threads[k],NULL,&mult,(void*) &data);
		}
		// wait for threads to join and calculate one row
		for (size_t k = 0; k < MAX; k++)
		{
			pthread_join(threads[k],NULL);
		}
		
	}


	printf("MATRIX A: \n");
	for (size_t i = 0; i < MAX; i++)
	{
		for (size_t k = 0; k < MAX; k++)
		{
			printf("%d ",matrixA[i][k]);
		}
		printf("\n");
		
	}
	printf("-----------------------\n");
	printf("MATRIX B: \n");
	for (size_t i = 0; i < MAX; i++)
	{
		for (size_t k = 0; k < MAX; k++)
		{
			printf("%d ",matrixB[i][k]);
		}
		printf("\n");
		
	}
	printf("-----------------------\n");
	printf("MATRIX C: \n");
	for (size_t i = 0; i < MAX; i++)
	{
		for (size_t k = 0; k < MAX; k++)
		{
			printf("%d ",matrixC[i][k]);
		}
		printf("\n");
		
	}

	return 0;
	
	
}


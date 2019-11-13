#include<stdio.h>
#include<stdlib.h>

/*		Arrays on the heap		




	level2		level1		level0
	int**		int*		int
	a		3		4
					4
					4

*/


int main(void)
{
/*		Allocate the memory		*/

	int **a; // a is a pointer to an array of 3 pointers to 3 arrays of 4 ints.

	a = (int**) malloc(3 * sizeof(int*)); // Allocate memory for 3 int pointers
	
	for(int i =0; i < 3; i++)
	{
		a[i]= (int*) malloc(4 * sizeof(int)); // Allocate memory for 3 * 4 ints
	}


/*		Populate the array		*/
	for(int row = 0; row < 3; row ++)
	{
		for(int col = 0; col < 4; col++)
		{
			a[row][col]=10*row+col;
		}
	}


/*		Print the array			*/
	for(int row = 0; row < 3; row ++)
	{
		for(int col = 0; col < 4; col++)
		{
			printf("%3i",a[row][col]);
		}
		printf("\n");
	}

/*		Clean up the heap		*/
	for(int row = 0; row < 3; row ++)
	{
		free(a[row]);
	}
	free(a);
	return 0;
}



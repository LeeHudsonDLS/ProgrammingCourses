
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MASK_LEN	16



int main() 
{
    
    double output;
    int noOfPolePairs = 7;
    int omegaCountsPerRev = 400000;
    output = 2048 * noOfPolePairs / (256 * omegaCountsPerRev);
    printf("%d\n",output);
	return 0;
}



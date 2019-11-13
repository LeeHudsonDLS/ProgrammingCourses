#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main(){

    double input =235.6987;
    double intpart,fractPart,fractPartShift;
    int counter, result, sign = 0,mantissa=0, exp = 0, integerPart,integerPartShift;

    //If input is negative set the sign bit and make input positive for the rest of the algorithm
    if(input < 0) {
        sign = 1;
        input = 0 - input;
    }

    //Extract the fraction and integer components of the input
    fractPart = modf(input,&intpart);
    integerPart = (int)intpart;


    integerPartShift = integerPart;
    fractPartShift = fractPart;
    printf("Raw int part = %d ($%06X), ",integerPart,integerPart);
    printf("Raw fract part = %f\n",fractPart);

    //If input is < 1 derive exp from fraction, else derive from integer
    if(input < 1) {
        printf("   Input is less than 1\n");
        while(fractPartShift < 1 and fractPartShift > 0 ) {
            fractPartShift = fractPartShift * 2;
            exp--;
            printf("      Shifting fraction left %f\n",fractPartShift);
        }
        printf("\n");
    //If we only have to worry about the fraction part
    }else{
        //Keep shifting the integer part right until < 1 to find exp
        printf("   Input is more than 1\n");
        while (integerPartShift > 1) {
            exp++;
            integerPartShift = integerPartShift >> 1;
            printf("      Shifting integer right $%06X\n",integerPartShift);
        }
        printf("      So exponent is %d\n\n",exp);
    }

    printf("Exponent is %d\n",exp);
    //Remove MSB of integer (part of formatting mantissa)
    if(integerPart > 0)
        integerPart = integerPart - pow(2,exp);
    printf("Removing MSB of int $%06X\n",integerPart);

    //Shift the integer left to the most significant bits of the mantissa
    integerPart = integerPart << (23-exp);
    printf("Shifting integer $%06X\n\n",integerPart);


    //Iterate through the fraction part to get the binary equivilent
    for(counter = 22; counter > -1; counter--){
        fractPart=fractPart*2;
        if(fractPart >= 1){
            mantissa = mantissa + pow(2,counter);
            printf("   Calculating fraction in binary $%06X\n",mantissa);
            fractPart = fractPart - 1.0;
        }

    }
    printf("\n");

    printf("Mantissa Before shift = $%06X\n",mantissa);

    //Shift mantissa left of right depending on sign of exponent
    if(exp > 0) {
        mantissa = mantissa >> exp;
        printf("   Mantissa shifted right by %d = $%06X\n",exp,mantissa);

    }
    else {
        mantissa = mantissa << abs(exp);
        printf("   Mantissa shifted left by %d = $%06X\n",abs(exp),mantissa);
    }
    printf("\n");

    //Truncate mantissa to 23 bits
    mantissa = mantissa & int(pow(2,23)-1);
    printf("Truncating mantissa to 23 bits = $%06X\n",mantissa);


    printf("Adding the shifted integer ($%06X) to mantissa ($%06X)\n",integerPart,mantissa);
    mantissa = mantissa + integerPart;
    printf("Mantissa is now = $%06X\n",mantissa);
    printf("\n");

    sign = sign << 31;

    if(exp !=0) {
        printf("Adding 127 to exp(%d) and shifting to 23 bits ", exp);
        exp = 127 + exp;
        exp = exp << 23;
        printf("$%08X\n", exp);
        printf("\n");
    }


    printf("Sign = $%08X\n",sign);
    printf("EXP = $%08X\n",exp);
    printf("Mantissa = $%08X\n",(int)mantissa);
    result = mantissa+exp+sign;
    printf("Result is $%08X\n",result);

    return (0);
}




#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>



int main(){

    double input =235.6987;
    double intpart,fractPart,fractPartShift;
    int counter, result,integerPart,integerPartShift;
    int sign = 0, mantissa = 0,exp = 0;

    //If input is negative set the sign bit and make input positive for the rest of the algorithm
    if(input < 0) {
        sign = 1;
        input = 0 - input;
    }
    //Shift sign to bit 31 (MSB)
    sign = sign << 31;

    //Extract the fraction and integer components of the input
    fractPart = modf(input,&intpart);
    integerPart = (int)intpart;

    //Store componented to allow modificaiton for deriving exp
    integerPartShift = integerPart;
    fractPartShift = fractPart;

    //If input is < 1 derive exp from fraction, else derive from integer
    if(input < 1) {
        while(fractPartShift < 1 and fractPartShift > 0 ) {
            fractPartShift = fractPartShift * 2;
            exp--;
        }
    //If we only have to worry about the fraction part
    }else{
        //Keep shifting the integer part right until < 1 to find exp
        while (integerPartShift > 1) {
            exp++;
            integerPartShift = integerPartShift >> 1;
        }
    }

    //Remove MSB of integer (part of formatting mantissa)
    if(integerPart > 0)
        integerPart = integerPart - pow(2,exp);

    //Shift the integer left to the most significant bits of the mantissa
    integerPart = integerPart << (23-exp);


    //Iterate through the fraction part to get the binary equivilent
    for(counter = 22; counter > -1; counter--){
        fractPart=fractPart*2;
        if(fractPart >= 1){
            mantissa = mantissa + pow(2,counter);
            fractPart = fractPart - 1.0;
        }
    }

    //Shift mantissa left of right depending on sign of exponent
    if(exp > 0) 
        mantissa = mantissa >> exp;
    else 
        mantissa = mantissa << abs(exp);

    //Truncate mantissa to 23 bits
    mantissa = mantissa & int(pow(2,23)-1);

    mantissa = mantissa + integerPart;

    //Catch case for input = 0.0
    if(exp !=0) {
        exp = 127 + exp;
        exp = exp << 23;
    }

    printf("Sign = $%08X\n",sign);
    printf("EXP = $%08X\n",exp);
    printf("Mantissa = $%08X\n",(int)mantissa);
    printf("Result is $%08X\n",result);
    result = mantissa+exp+sign;
    return (0);
}




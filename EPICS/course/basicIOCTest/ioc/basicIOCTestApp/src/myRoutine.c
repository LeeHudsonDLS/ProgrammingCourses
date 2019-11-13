#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <dbEvent.h>
#include <dbDefs.h>
#include <dbCommon.h>
#include <aSubRecord.h>
#include <registryFunction.h>
#include <epicsExport.h>

#define RED   75
#define BLUE 150
#define ND1  225
#define ND2  300

#if 0
#define RED_IN_BEAM  28   /* 1 1 1 0 0 */
#define BLUE_IN_BEAM 26   /* 1 1 0 1 0 */
#define ND1_IN_BEAM  22   /* 1 0 1 1 0 */
#define ND2_IN_BEAM  14   /* 0 1 1 1 0 */
#endif

#define RED_IN_BEAM  0
#define BLUE_IN_BEAM 1
#define ND1_IN_BEAM  2
#define ND2_IN_BEAM  3

/*
 * Inputs:
 * pgsub->a = Demanded position  (DOUBLE)
 * pgsub->b = Proportional Gain  (DOUBLE)
 * pgsub->c = Integral Gain      (DOUBLE)
 * pgsub->d = Derivative Gain    (DOUBLE)
 * pgsub->e = Position Tolerance (DOUBLE)
 * pgsub->f = velocity Tolerance (DOUBLE)
 *
 * Outputs:
 * pgsub->vala = Current position (DOUBLE)
 * pgsub->valb = Switch data      (LONG)
 * pgsub->valc = Slide status     (STRING)
 *
 * Values stored between calls:
 * pgsub->vald = Sum of error*deltaT (DOUBLE)
 * pgsub->vale = Previous error      (DOUBLE)
 * pgsub->valf = Previous position   (DOUBLE)
 *
 */

static long myRoutine( aSubRecord *prec) {

		
	double A,B,C,D;
	double VALA, VALB, VALC, VALD;
	double test;

	A = *(double *)prec->vala;
	B = *(double *)prec->b;
	C = *(double *)prec->c;
	D = *(double *)prec->d;

	VALA = *(double *)prec->vala;
	VALB = *(double *)prec->valb;
	VALC = *(double *)prec->valc;	
	VALD = *(double *)prec->vald;
	
	test = A +1;
	//*(double *)prec->vala = 99;
	

	//prec->vala = 99;
	/*
	if(A>0){
		*(double *)prec->vala = 1;
	}else{
		*(double *)prec->vala = 0;
	}

	if(B>0){
		*(double *)prec->valb = 1;
	}else{
		*(double *)prec->valb = 0;
	}

	if(C>0){
		*(double *)prec->valc = 1;
	}else{
		*(double *)prec->valc = 0;
	}
	
	if(D>0){
		*(double *)prec->vald = 1;
	}else{
		*(double *)prec->vald = 0;
	}
	*/
	*(double *)prec->vala = test;
       return(0); /* process output links */
   }

epicsRegisterFunction(myRoutine);

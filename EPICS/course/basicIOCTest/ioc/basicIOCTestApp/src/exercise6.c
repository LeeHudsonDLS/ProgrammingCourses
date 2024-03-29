#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include <dbEvent.h>
#include <dbDefs.h>
#include <dbCommon.h>
#include <genSubRecord.h>
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

static long servo( genSubRecord *pgsub )
{
  double currentPos;
  double demandPos;
  double P;
  double I;
  double D;
  double KP;
  double KI;
  double KD;
  double error;
  double sum;
  double deltaT;
  double prevError;
  double prevPos;
  long   switchData;
  double vel;
  double posTol;
  double velTol;

  currentPos = *(double *)pgsub->vala;
  demandPos  = *(double *)pgsub->a;
  KP         = *(double *)pgsub->b;
  KI         = *(double *)pgsub->c;
  KD         = *(double *)pgsub->d;
  error      = demandPos - currentPos;
  deltaT     = 0.05;  /* 20 Hz */
  if( KI != 0.0 )
    sum = *(double *)pgsub->vald + (error * deltaT);
  else
    sum = 0.0;
  prevError  = *(double *)pgsub->vale;

  P = KP * error;
  I = KP * KI * sum;
  D = KP * KD * (error - prevError)/deltaT;

  /* Before overwriting the current position, save it */
  /* as the previous position                         */

  *(double *)pgsub->valf = currentPos;

  currentPos += P + I + D;

  /* Now save important information for the next call */

  *(double *)pgsub->vala = currentPos;
  *(double *)pgsub->vald = sum;
  *(double *)pgsub->vale = prevError;


 /* Calculate the switch data */

  posTol = *(double *)pgsub->e;

  if( (currentPos >= RED-posTol) && (currentPos <= RED+posTol) )
    switchData = RED_IN_BEAM;
  else if( (currentPos >= BLUE-posTol) && (currentPos <= BLUE+posTol) )
    switchData = BLUE_IN_BEAM;
  else if( (currentPos >= ND1-posTol)  && (currentPos <= ND1+posTol) )
    switchData = ND1_IN_BEAM;
  else if( (currentPos >= ND2-posTol)  && (currentPos <= ND2+posTol) )
    switchData = ND2_IN_BEAM;
  else
    switchData = -1;

  *(long *)pgsub->valb = switchData;


  /* Calculate the slide status: MOVING or STOPPED          */
  /* The condition for STOPPED is that the current position */
  /* must be within "posTol" of the demand position and the */
  /* absolute velocity must be less than "velTol"           */

  velTol = *(double *)pgsub->f;

  prevPos = *(double *)pgsub->valf;

  vel = (currentPos - prevPos)/deltaT;

  if( (currentPos >= demandPos-posTol) && (currentPos <= demandPos+posTol) )
  {
    if( fabs(vel) <= velTol )
      strcpy( pgsub->valc, "STOPPED" );
    else
      strcpy( pgsub->valc, "MOVING" );
  }
  else
    strcpy( pgsub->valc, "MOVING" );

  return(0);
}

epicsRegisterFunction(servo);

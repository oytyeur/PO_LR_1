/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: MtrCtrl
 * File: FB_Motor.c
 * Author: admin
 * Created: September 9, 2020
 ********************************************************************
 * Implementation of library MtrCtrl
 ********************************************************************/

#include <bur/plctypes.h>
#ifdef __cplusplus
	extern "C"
	{
#endif

	#include "MtrCtrl.h"

#ifdef __cplusplus
	};
#endif

/* TODO: Add your comment here */
void FB_motor(struct FB_motor* inst)
{
	REAL a = inst->u / inst->ke - inst->w;
	REAL b = a / inst->Tm;
	inst->integrator.in = b;
	FB_Integrator(&inst->integrator);
	
	inst->w = inst->integrator.out;
	/*TODO: Add your code here*/
}
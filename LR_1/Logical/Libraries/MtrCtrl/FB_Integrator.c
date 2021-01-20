/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: MtrCtrl
 * File: FB_Integrator.c
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
void FB_Integrator(struct FB_Integrator* inst)
{
	inst->out += inst->in*inst->dt +  inst->state;
	inst->state = inst->out;
	/*TODO: Add your code here*/
}
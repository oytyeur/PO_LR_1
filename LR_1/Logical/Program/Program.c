/********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Program: Program
 * File: Program.c
 * Author: admin
 * Created: September 9, 2020
 ********************************************************************
 * Implementation of program Program
 ********************************************************************/

#include <bur/plctypes.h>

#ifdef _DEFAULT_INCLUDES
	#include <AsDefault.h>
#endif

void _INIT ProgramINIT(void)
{
	fb_motor.dt = 0.002;
	fb_motor.ke = 0.00096;
	fb_motor.Tm = 0.04;
	fb_motor.integrator.dt = 0.002;
	
	fb_motor2.dt = 0.002;
	fb_motor2.ke = 0.00096;
	fb_motor2.Tm = 0.04;
	fb_motor2.integrator.dt = 0.002;
	
	fb_regulator.dt = 0.002;
	fb_regulator.k_p = 0.0064;
	fb_regulator.k_i = 0.16;
	fb_regulator.max_abs_value = 24;
	fb_regulator.integrator.dt = 0.002;
	enable = 1;
	count = 0;
}

void _CYCLIC ProgramCYCLIC(void)
{
	if(enable)
	{
		count+=10;
		if(count<=2500)
		{
			speed=0;
		}
		else
		{
			speed=6;
			if(count>=5000)
			{
				count=0;
			}
		}
	}
	fb_regulator.e=speed - fb_motor.w;
	fb_motor.u=speed;
	FB_Regulator(&fb_regulator);
	fb_motor.u=fb_regulator.u;
	FB_motor(&fb_motor);
	
	FB_motor(&fb_motor2);
}

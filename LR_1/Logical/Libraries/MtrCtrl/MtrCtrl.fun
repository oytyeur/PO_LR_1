(********************************************************************
 * COPYRIGHT --  
 ********************************************************************
 * Library: MtrCtrl
 * File: MtrCtrl.fun
 * Author: admin
 * Created: September 9, 2020
 ********************************************************************
 * Functions and function blocks of library MtrCtrl
 ********************************************************************)

FUNCTION_BLOCK FB_Integrator (*TODO: Add your comment here*)
	VAR_INPUT
		in : REAL;
	END_VAR
	VAR_OUTPUT
		out : REAL;
	END_VAR
	VAR
		dt : REAL;
		state : REAL;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK FB_Regulator (*TODO: Add your comment here*)
	VAR_INPUT
		e : REAL;
	END_VAR
	VAR_OUTPUT
		u : REAL;
	END_VAR
	VAR
		k_p : REAL;
		k_i : REAL;
		integrator : FB_Integrator;
		iyOld : REAL;
		max_abs_value : REAL;
		dt : REAL;
	END_VAR
END_FUNCTION_BLOCK

FUNCTION_BLOCK FB_motor (*TODO: Add your comment here*)
	VAR_INPUT
		u : REAL;
	END_VAR
	VAR_OUTPUT
		w : REAL;
		phi : REAL;
	END_VAR
	VAR
		integrator : FB_Integrator;
		Tm : REAL;
		ke : REAL;
		dt : REAL;
	END_VAR
END_FUNCTION_BLOCK

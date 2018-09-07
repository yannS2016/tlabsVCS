/* C code for program expClearanceSNC, generated by snc from ../expClearanceSNC.stt */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 3 "../expClearanceSNC.stt"

/*******************************************************************/
#include "vcs_var_mes.h" // define this here so C functions are seen
/*******************************************************************/	
#define STOK       	0
#define B26ON		66 
#define B28bOFF		71
#define B28bON		77 
#define B28aOFF		70
#define B28aON		76
#define B27ON		75 
#define B27OFF		69
#define B29OFF		74  
#define DA12S1OFF	72
#define DA12S2OFF	73   
#define G10OFF		151
#define WFVC		55 
#define EXPPNK		20 


/* Variable declarations */
struct seqg_vars {
# line 23 "../expClearanceSNC.stt"
	short EXP_VC;
# line 24 "../expClearanceSNC.stt"
	short EXP_W26_STS;
# line 25 "../expClearanceSNC.stt"
	short EXP_W28b_STS;
# line 26 "../expClearanceSNC.stt"
	short EXP_W28a_STS;
# line 27 "../expClearanceSNC.stt"
	short EXP_W27_STS;
# line 28 "../expClearanceSNC.stt"
	short EXP_W29_STS;
# line 29 "../expClearanceSNC.stt"
	short EXP_PNK;
# line 30 "../expClearanceSNC.stt"
	short EXP_RST_OUTS;
# line 31 "../expClearanceSNC.stt"
	short EXP_G10_STS;
# line 32 "../expClearanceSNC.stt"
	short EXP_FAIL_COND;
# line 33 "../expClearanceSNC.stt"
	short EXP_OLD_FAIL_COND;
# line 34 "../expClearanceSNC.stt"
	string EXP_CLR_STATS;
# line 35 "../expClearanceSNC.stt"
	string EXP_INTLCK_STATS;
# line 36 "../expClearanceSNC.stt"
	short exp_failed_rst;
# line 37 "../expClearanceSNC.stt"
	short exp_not_cleared;
};


/* Function declarations */
# line 317 "../expClearanceSNC.stt"
static void initVault(SS_ID seqg_env);
# line 330 "../expClearanceSNC.stt"
static void resetVault(SS_ID seqg_env);
# line 335 "../expClearanceSNC.stt"
static void EXP_update_failed(SS_ID seqg_env, short report);
# line 344 "../expClearanceSNC.stt"
static void EXP_update_report(SS_ID seqg_env, short intlck);
# line 349 "../expClearanceSNC.stt"
static void EXP_status(SS_ID seqg_env);
# line 357 "../expClearanceSNC.stt"
static void EXP_clear_underway(SS_ID seqg_env);

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
	{
# line 36 "../expClearanceSNC.stt"
	static short seqg_initvar_exp_failed_rst = FALSE;
	memcpy(&seqg_var->exp_failed_rst, &seqg_initvar_exp_failed_rst, sizeof(seqg_initvar_exp_failed_rst));
	}
	{
# line 37 "../expClearanceSNC.stt"
	static short seqg_initvar_exp_not_cleared = FALSE;
	memcpy(&seqg_var->exp_not_cleared, &seqg_initvar_exp_not_cleared, sizeof(seqg_initvar_exp_not_cleared));
	}
}

/****** Code for state "init" in state set "EXP_clearance_status" ******/

/* Event function for state "init" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_init(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 66 "../expClearanceSNC.stt"
	if (seq_delay(seqg_env, 1))
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_init(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 67 "../expClearanceSNC.stt"
			initVault(seqg_env);
# line 68 "../expClearanceSNC.stt"
			printf("%sEXPERIMENTAL VAULT INITIALISATION COMPLETED%s\n", OK, DEF);
		}
		return;
	}
}

/****** Code for state "watchman_26_pressed" in state set "EXP_clearance_status" ******/

/* Event function for state "watchman_26_pressed" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_watchman_26_pressed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 75 "../expClearanceSNC.stt"
	if (seqg_var->EXP_FAIL_COND != STOK)
	{
		*seqg_pnst = 17;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 79 "../expClearanceSNC.stt"
	if (seqg_var->EXP_W26_STS == WFVC)
	{
		*seqg_pnst = 2;
		*seqg_ptrn = 1;
		return TRUE;
	}
# line 83 "../expClearanceSNC.stt"
	if (seqg_var->EXP_W26_STS == B26ON)
	{
		*seqg_pnst = 3;
		*seqg_ptrn = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_26_pressed" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_watchman_26_pressed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 76 "../expClearanceSNC.stt"
			seqg_var->EXP_OLD_FAIL_COND = seqg_var->EXP_FAIL_COND;
		}
		return;
	case 1:
		{
		}
		return;
	case 2:
		{
# line 84 "../expClearanceSNC.stt"
			EXP_clear_underway(seqg_env);
# line 85 "../expClearanceSNC.stt"
			EXP_update_report(seqg_env, B26ON);
		}
		return;
	}
}

/****** Code for state "clearance_pending" in state set "EXP_clearance_status" ******/

/* Entry function for state "clearance_pending" in state set "EXP_clearance_status" */
static void seqg_entry_EXP_clearance_status_0_clearance_pending(SS_ID seqg_env)
{
# line 94 "../expClearanceSNC.stt"
	resetVault(seqg_env);
# line 95 "../expClearanceSNC.stt"
	EXP_update_report(seqg_env, WFVC);
# line 96 "../expClearanceSNC.stt"
	seqg_var->exp_not_cleared = TRUE;
}

/* Event function for state "clearance_pending" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_clearance_pending(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 99 "../expClearanceSNC.stt"
	if (seqg_var->EXP_W26_STS != WFVC)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "clearance_pending" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_clearance_pending(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "watchman_26_released" in state set "EXP_clearance_status" ******/

/* Event function for state "watchman_26_released" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_watchman_26_released(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 107 "../expClearanceSNC.stt"
	if (seqg_var->EXP_FAIL_COND != STOK)
	{
		*seqg_pnst = 17;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 111 "../expClearanceSNC.stt"
	if (seqg_var->EXP_W26_STS != B26ON)
	{
		*seqg_pnst = 4;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_26_released" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_watchman_26_released(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 112 "../expClearanceSNC.stt"
			EXP_update_report(seqg_env, G10OFF);
		}
		return;
	}
}

/****** Code for state "gate_g10_closed" in state set "EXP_clearance_status" ******/

/* Event function for state "gate_g10_closed" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_gate_g10_closed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 118 "../expClearanceSNC.stt"
	if (seqg_var->EXP_FAIL_COND != STOK)
	{
		*seqg_pnst = 17;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 122 "../expClearanceSNC.stt"
	if (!seqg_var->EXP_G10_STS)
	{
		*seqg_pnst = 5;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "gate_g10_closed" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_gate_g10_closed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 123 "../expClearanceSNC.stt"
			EXP_update_report(seqg_env, B28bOFF);
		}
		return;
	}
}

/****** Code for state "watchman_28b_pressed" in state set "EXP_clearance_status" ******/

/* Event function for state "watchman_28b_pressed" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_watchman_28b_pressed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 129 "../expClearanceSNC.stt"
	if (seqg_var->EXP_FAIL_COND != STOK)
	{
		*seqg_pnst = 17;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 134 "../expClearanceSNC.stt"
	if (seqg_var->EXP_W28b_STS == B28bON)
	{
		*seqg_pnst = 6;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_28b_pressed" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_watchman_28b_pressed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 135 "../expClearanceSNC.stt"
			EXP_update_report(seqg_env, B28bON);
		}
		return;
	}
}

/****** Code for state "watchman_28b_released" in state set "EXP_clearance_status" ******/

/* Event function for state "watchman_28b_released" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_watchman_28b_released(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 141 "../expClearanceSNC.stt"
	if (seqg_var->EXP_FAIL_COND != STOK)
	{
		*seqg_pnst = 17;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 145 "../expClearanceSNC.stt"
	if (seqg_var->EXP_W28b_STS != B28bON)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_28b_released" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_watchman_28b_released(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 146 "../expClearanceSNC.stt"
			EXP_update_report(seqg_env, B28aOFF);
		}
		return;
	}
}

/****** Code for state "watchman_28a_pressed" in state set "EXP_clearance_status" ******/

/* Event function for state "watchman_28a_pressed" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_watchman_28a_pressed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 154 "../expClearanceSNC.stt"
	if (seqg_var->EXP_FAIL_COND != STOK)
	{
		*seqg_pnst = 17;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 159 "../expClearanceSNC.stt"
	if (seqg_var->EXP_W28a_STS == B28aON)
	{
		*seqg_pnst = 8;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_28a_pressed" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_watchman_28a_pressed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 160 "../expClearanceSNC.stt"
			EXP_update_report(seqg_env, B28aON);
		}
		return;
	}
}

/****** Code for state "watchman_28a_released" in state set "EXP_clearance_status" ******/

/* Event function for state "watchman_28a_released" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_watchman_28a_released(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 166 "../expClearanceSNC.stt"
	if (seqg_var->EXP_FAIL_COND != STOK)
	{
		*seqg_pnst = 17;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 171 "../expClearanceSNC.stt"
	if (seqg_var->EXP_W28a_STS != B28aON)
	{
		*seqg_pnst = 9;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_28a_released" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_watchman_28a_released(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 172 "../expClearanceSNC.stt"
			EXP_update_report(seqg_env, B27OFF);
		}
		return;
	}
}

/****** Code for state "watchman_27_pressed" in state set "EXP_clearance_status" ******/

/* Event function for state "watchman_27_pressed" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_watchman_27_pressed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 178 "../expClearanceSNC.stt"
	if (seqg_var->EXP_FAIL_COND != STOK)
	{
		*seqg_pnst = 17;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 183 "../expClearanceSNC.stt"
	if (seqg_var->EXP_W27_STS == B27ON)
	{
		*seqg_pnst = 10;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_27_pressed" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_watchman_27_pressed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 184 "../expClearanceSNC.stt"
			EXP_update_report(seqg_env, B27ON);
		}
		return;
	}
}

/****** Code for state "watchman_27_released" in state set "EXP_clearance_status" ******/

/* Event function for state "watchman_27_released" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_watchman_27_released(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 190 "../expClearanceSNC.stt"
	if (seqg_var->EXP_FAIL_COND != STOK)
	{
		*seqg_pnst = 17;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 194 "../expClearanceSNC.stt"
	if (seqg_var->EXP_W27_STS != B27ON)
	{
		*seqg_pnst = 11;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_27_released" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_watchman_27_released(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/****** Code for state "A12_switch_I_closed" in state set "EXP_clearance_status" ******/

/* Entry function for state "A12_switch_I_closed" in state set "EXP_clearance_status" */
static void seqg_entry_EXP_clearance_status_0_A12_switch_I_closed(SS_ID seqg_env)
{
# line 203 "../expClearanceSNC.stt"
	EXP_update_report(seqg_env, DA12S1OFF);
}

/* Event function for state "A12_switch_I_closed" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_A12_switch_I_closed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 206 "../expClearanceSNC.stt"
	if (seqg_var->EXP_FAIL_COND != STOK)
	{
		*seqg_pnst = 17;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 210 "../expClearanceSNC.stt"
	if (seqg_var->EXP_W29_STS != DA12S1OFF)
	{
		*seqg_pnst = 12;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "A12_switch_I_closed" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_A12_switch_I_closed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/****** Code for state "A12_switch_II_closed" in state set "EXP_clearance_status" ******/

/* Entry function for state "A12_switch_II_closed" in state set "EXP_clearance_status" */
static void seqg_entry_EXP_clearance_status_0_A12_switch_II_closed(SS_ID seqg_env)
{
# line 219 "../expClearanceSNC.stt"
	EXP_update_report(seqg_env, DA12S2OFF);
}

/* Event function for state "A12_switch_II_closed" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_A12_switch_II_closed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 222 "../expClearanceSNC.stt"
	if (seqg_var->EXP_FAIL_COND != STOK)
	{
		*seqg_pnst = 17;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 226 "../expClearanceSNC.stt"
	if (seqg_var->EXP_W29_STS != DA12S2OFF)
	{
		*seqg_pnst = 13;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "A12_switch_II_closed" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_A12_switch_II_closed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/****** Code for state "watchman_29_pressed" in state set "EXP_clearance_status" ******/

/* Entry function for state "watchman_29_pressed" in state set "EXP_clearance_status" */
static void seqg_entry_EXP_clearance_status_0_watchman_29_pressed(SS_ID seqg_env)
{
# line 235 "../expClearanceSNC.stt"
	EXP_update_report(seqg_env, B29OFF);
}

/* Event function for state "watchman_29_pressed" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_watchman_29_pressed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 238 "../expClearanceSNC.stt"
	if (seqg_var->EXP_FAIL_COND != STOK)
	{
		*seqg_pnst = 17;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 242 "../expClearanceSNC.stt"
	if (!seqg_var->EXP_W29_STS)
	{
		*seqg_pnst = 14;
		*seqg_ptrn = 1;
		return TRUE;
	}
# line 247 "../expClearanceSNC.stt"
	if (seqg_var->EXP_W29_STS != B29OFF)
	{
		*seqg_pnst = 11;
		*seqg_ptrn = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_29_pressed" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_watchman_29_pressed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 244 "../expClearanceSNC.stt"
			EXP_status(seqg_env);
		}
		return;
	case 2:
		{
		}
		return;
	}
}

/****** Code for state "vault_cleared" in state set "EXP_clearance_status" ******/

/* Entry function for state "vault_cleared" in state set "EXP_clearance_status" */
static void seqg_entry_EXP_clearance_status_0_vault_cleared(SS_ID seqg_env)
{
# line 255 "../expClearanceSNC.stt"
	printf("%sISOTOPE BEAM LINE IN CLEARED STATE%s\n", CLR, DEF);
}

/* Event function for state "vault_cleared" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_vault_cleared(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 257 "../expClearanceSNC.stt"
	if (seqg_var->EXP_VC != STOK)
	{
		*seqg_pnst = 15;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "vault_cleared" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_vault_cleared(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "paniq_faillure" in state set "EXP_clearance_status" ******/

/* Event function for state "paniq_faillure" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_paniq_faillure(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 264 "../expClearanceSNC.stt"
	if (seqg_var->EXP_VC != EXPPNK)
	{
		*seqg_pnst = 17;
		*seqg_ptrn = 0;
		return TRUE;
	}
	if (TRUE)
	{
		*seqg_pnst = 16;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "paniq_faillure" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_paniq_faillure(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 269 "../expClearanceSNC.stt"
			printf("EXP VAULT CLEARED FAILURE CONDITION: ");
# line 270 "../expClearanceSNC.stt"
			EXP_update_failed(seqg_env, EXPPNK);
		}
		return;
	}
}

/****** Code for state "recover_from_paniq" in state set "EXP_clearance_status" ******/

/* Exit function for state "recover_from_paniq" in state set "EXP_clearance_status" */
static void seqg_exit_EXP_clearance_status_0_recover_from_paniq(SS_ID seqg_env)
{
# line 283 "../expClearanceSNC.stt"
	seqg_var->exp_failed_rst = FALSE;
# line 284 "../expClearanceSNC.stt"
	seqg_var->exp_not_cleared = FALSE;
}

/* Event function for state "recover_from_paniq" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_recover_from_paniq(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 278 "../expClearanceSNC.stt"
	if (!seqg_var->EXP_PNK)
	{
		*seqg_pnst = 18;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "recover_from_paniq" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_recover_from_paniq(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "clearance_faillures" in state set "EXP_clearance_status" ******/

/* Entry function for state "clearance_faillures" in state set "EXP_clearance_status" */
static void seqg_entry_EXP_clearance_status_0_clearance_faillures(SS_ID seqg_env)
{
# line 293 "../expClearanceSNC.stt"
	printf("EXP CLEARANCE FAILURE CONDITION: ");
# line 294 "../expClearanceSNC.stt"
	seqg_var->exp_failed_rst = FALSE;
# line 295 "../expClearanceSNC.stt"
	seqg_var->exp_not_cleared = FALSE;
# line 296 "../expClearanceSNC.stt"
	seqg_var->EXP_OLD_FAIL_COND = seqg_var->EXP_FAIL_COND;
# line 297 "../expClearanceSNC.stt"
	EXP_update_failed(seqg_env, seqg_var->EXP_FAIL_COND);
}

/* Event function for state "clearance_faillures" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_clearance_faillures(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		*seqg_pnst = 18;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "clearance_faillures" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_clearance_faillures(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "recover_from_faillure" in state set "EXP_clearance_status" ******/

/* Event function for state "recover_from_faillure" in state set "EXP_clearance_status" */
static seqBool seqg_event_EXP_clearance_status_0_recover_from_faillure(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 307 "../expClearanceSNC.stt"
	if (!seqg_var->EXP_FAIL_COND)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 311 "../expClearanceSNC.stt"
	if (seqg_var->EXP_FAIL_COND != seqg_var->EXP_OLD_FAIL_COND)
	{
		*seqg_pnst = 17;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "recover_from_faillure" in state set "EXP_clearance_status" */
static void seqg_action_EXP_clearance_status_0_recover_from_faillure(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 308 "../expClearanceSNC.stt"
			printf("%sEXP RECOVERING FROM FAILLURE : ENTERING W26 STATE%s\n", OK, DEF);
		}
		return;
	case 1:
		{
		}
		return;
	}
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"{SYS}:EXP-CLR-STATS", offsetof(struct seqg_vars, EXP_CLR_STATS), "EXP_CLR_STATS", P_STRING, 1, 1, 0, 0, 0, 0},
	{"{SYS}:EXP-INTLCK-STATS", offsetof(struct seqg_vars, EXP_INTLCK_STATS), "EXP_INTLCK_STATS", P_STRING, 1, 2, 0, 0, 0, 0},
	{"{SYS}:EXP-VC", offsetof(struct seqg_vars, EXP_VC), "EXP_VC", P_SHORT, 1, 3, 0, 1, 0, 0},
	{"{SYS}:RST-EXP", offsetof(struct seqg_vars, EXP_RST_OUTS), "EXP_RST_OUTS", P_SHORT, 1, 4, 0, 0, 0, 0},
	{"{SYS}:EXP-W26-STS", offsetof(struct seqg_vars, EXP_W26_STS), "EXP_W26_STS", P_SHORT, 1, 5, 0, 1, 0, 0},
	{"{SYS}:EXP-W28b-STS", offsetof(struct seqg_vars, EXP_W28b_STS), "EXP_W28b_STS", P_SHORT, 1, 6, 0, 1, 0, 0},
	{"{SYS}:EXP-W28a-STS", offsetof(struct seqg_vars, EXP_W28a_STS), "EXP_W28a_STS", P_SHORT, 1, 7, 0, 1, 0, 0},
	{"{SYS}:EXP-W27-STS", offsetof(struct seqg_vars, EXP_W27_STS), "EXP_W27_STS", P_SHORT, 1, 8, 0, 1, 0, 0},
	{"{SYS}:EXP-W29-STS", offsetof(struct seqg_vars, EXP_W29_STS), "EXP_W29_STS", P_SHORT, 1, 9, 0, 1, 0, 0},
	{"{SYS}:EXP-FAIL-COND", offsetof(struct seqg_vars, EXP_FAIL_COND), "EXP_FAIL_COND", P_SHORT, 1, 10, 0, 1, 0, 0},
	{"{SYS}:EXP-PNK", offsetof(struct seqg_vars, EXP_PNK), "EXP_PNK", P_SHORT, 1, 11, 0, 1, 0, 0},
	{"{SYS}:EXP-G10-STS", offsetof(struct seqg_vars, EXP_G10_STS), "EXP_G10_STS", P_SHORT, 1, 12, 0, 1, 0, 0},
};

/* Event masks for state set "EXP_clearance_status" */
static const seqMask seqg_mask_EXP_clearance_status_0_init[] = {
	0x00000000,
};
static const seqMask seqg_mask_EXP_clearance_status_0_watchman_26_pressed[] = {
	0x00000420,
};
static const seqMask seqg_mask_EXP_clearance_status_0_clearance_pending[] = {
	0x00000020,
};
static const seqMask seqg_mask_EXP_clearance_status_0_watchman_26_released[] = {
	0x00000420,
};
static const seqMask seqg_mask_EXP_clearance_status_0_gate_g10_closed[] = {
	0x00001400,
};
static const seqMask seqg_mask_EXP_clearance_status_0_watchman_28b_pressed[] = {
	0x00000440,
};
static const seqMask seqg_mask_EXP_clearance_status_0_watchman_28b_released[] = {
	0x00000440,
};
static const seqMask seqg_mask_EXP_clearance_status_0_watchman_28a_pressed[] = {
	0x00000480,
};
static const seqMask seqg_mask_EXP_clearance_status_0_watchman_28a_released[] = {
	0x00000480,
};
static const seqMask seqg_mask_EXP_clearance_status_0_watchman_27_pressed[] = {
	0x00000500,
};
static const seqMask seqg_mask_EXP_clearance_status_0_watchman_27_released[] = {
	0x00000500,
};
static const seqMask seqg_mask_EXP_clearance_status_0_A12_switch_I_closed[] = {
	0x00000600,
};
static const seqMask seqg_mask_EXP_clearance_status_0_A12_switch_II_closed[] = {
	0x00000600,
};
static const seqMask seqg_mask_EXP_clearance_status_0_watchman_29_pressed[] = {
	0x00000600,
};
static const seqMask seqg_mask_EXP_clearance_status_0_vault_cleared[] = {
	0x00000008,
};
static const seqMask seqg_mask_EXP_clearance_status_0_paniq_faillure[] = {
	0x00000008,
};
static const seqMask seqg_mask_EXP_clearance_status_0_recover_from_paniq[] = {
	0x00000800,
};
static const seqMask seqg_mask_EXP_clearance_status_0_clearance_faillures[] = {
	0x00000000,
};
static const seqMask seqg_mask_EXP_clearance_status_0_recover_from_faillure[] = {
	0x00000400,
};

/* State table for state set "EXP_clearance_status" */
static seqState seqg_states_EXP_clearance_status[] = {
	{
	/* state name */        "init",
	/* action function */   seqg_action_EXP_clearance_status_0_init,
	/* event function */    seqg_event_EXP_clearance_status_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_init,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_26_pressed",
	/* action function */   seqg_action_EXP_clearance_status_0_watchman_26_pressed,
	/* event function */    seqg_event_EXP_clearance_status_0_watchman_26_pressed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_watchman_26_pressed,
	/* state options */     (0)
	},
	{
	/* state name */        "clearance_pending",
	/* action function */   seqg_action_EXP_clearance_status_0_clearance_pending,
	/* event function */    seqg_event_EXP_clearance_status_0_clearance_pending,
	/* entry function */    seqg_entry_EXP_clearance_status_0_clearance_pending,
	/* exit function */     0,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_clearance_pending,
	/* state options */     (0 | OPT_DOENTRYFROMSELF | OPT_DOEXITTOSELF)
	},
	{
	/* state name */        "watchman_26_released",
	/* action function */   seqg_action_EXP_clearance_status_0_watchman_26_released,
	/* event function */    seqg_event_EXP_clearance_status_0_watchman_26_released,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_watchman_26_released,
	/* state options */     (0)
	},
	{
	/* state name */        "gate_g10_closed",
	/* action function */   seqg_action_EXP_clearance_status_0_gate_g10_closed,
	/* event function */    seqg_event_EXP_clearance_status_0_gate_g10_closed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_gate_g10_closed,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_28b_pressed",
	/* action function */   seqg_action_EXP_clearance_status_0_watchman_28b_pressed,
	/* event function */    seqg_event_EXP_clearance_status_0_watchman_28b_pressed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_watchman_28b_pressed,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_28b_released",
	/* action function */   seqg_action_EXP_clearance_status_0_watchman_28b_released,
	/* event function */    seqg_event_EXP_clearance_status_0_watchman_28b_released,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_watchman_28b_released,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_28a_pressed",
	/* action function */   seqg_action_EXP_clearance_status_0_watchman_28a_pressed,
	/* event function */    seqg_event_EXP_clearance_status_0_watchman_28a_pressed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_watchman_28a_pressed,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_28a_released",
	/* action function */   seqg_action_EXP_clearance_status_0_watchman_28a_released,
	/* event function */    seqg_event_EXP_clearance_status_0_watchman_28a_released,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_watchman_28a_released,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_27_pressed",
	/* action function */   seqg_action_EXP_clearance_status_0_watchman_27_pressed,
	/* event function */    seqg_event_EXP_clearance_status_0_watchman_27_pressed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_watchman_27_pressed,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_27_released",
	/* action function */   seqg_action_EXP_clearance_status_0_watchman_27_released,
	/* event function */    seqg_event_EXP_clearance_status_0_watchman_27_released,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_watchman_27_released,
	/* state options */     (0)
	},
	{
	/* state name */        "A12_switch_I_closed",
	/* action function */   seqg_action_EXP_clearance_status_0_A12_switch_I_closed,
	/* event function */    seqg_event_EXP_clearance_status_0_A12_switch_I_closed,
	/* entry function */    seqg_entry_EXP_clearance_status_0_A12_switch_I_closed,
	/* exit function */     0,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_A12_switch_I_closed,
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
	},
	{
	/* state name */        "A12_switch_II_closed",
	/* action function */   seqg_action_EXP_clearance_status_0_A12_switch_II_closed,
	/* event function */    seqg_event_EXP_clearance_status_0_A12_switch_II_closed,
	/* entry function */    seqg_entry_EXP_clearance_status_0_A12_switch_II_closed,
	/* exit function */     0,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_A12_switch_II_closed,
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
	},
	{
	/* state name */        "watchman_29_pressed",
	/* action function */   seqg_action_EXP_clearance_status_0_watchman_29_pressed,
	/* event function */    seqg_event_EXP_clearance_status_0_watchman_29_pressed,
	/* entry function */    seqg_entry_EXP_clearance_status_0_watchman_29_pressed,
	/* exit function */     0,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_watchman_29_pressed,
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
	},
	{
	/* state name */        "vault_cleared",
	/* action function */   seqg_action_EXP_clearance_status_0_vault_cleared,
	/* event function */    seqg_event_EXP_clearance_status_0_vault_cleared,
	/* entry function */    seqg_entry_EXP_clearance_status_0_vault_cleared,
	/* exit function */     0,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_vault_cleared,
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
	},
	{
	/* state name */        "paniq_faillure",
	/* action function */   seqg_action_EXP_clearance_status_0_paniq_faillure,
	/* event function */    seqg_event_EXP_clearance_status_0_paniq_faillure,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_paniq_faillure,
	/* state options */     (0)
	},
	{
	/* state name */        "recover_from_paniq",
	/* action function */   seqg_action_EXP_clearance_status_0_recover_from_paniq,
	/* event function */    seqg_event_EXP_clearance_status_0_recover_from_paniq,
	/* entry function */    0,
	/* exit function */     seqg_exit_EXP_clearance_status_0_recover_from_paniq,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_recover_from_paniq,
	/* state options */     (0 | OPT_DOENTRYFROMSELF | OPT_DOEXITTOSELF)
	},
	{
	/* state name */        "clearance_faillures",
	/* action function */   seqg_action_EXP_clearance_status_0_clearance_faillures,
	/* event function */    seqg_event_EXP_clearance_status_0_clearance_faillures,
	/* entry function */    seqg_entry_EXP_clearance_status_0_clearance_faillures,
	/* exit function */     0,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_clearance_faillures,
	/* state options */     (0 | OPT_DOENTRYFROMSELF | OPT_DOEXITTOSELF)
	},
	{
	/* state name */        "recover_from_faillure",
	/* action function */   seqg_action_EXP_clearance_status_0_recover_from_faillure,
	/* event function */    seqg_event_EXP_clearance_status_0_recover_from_faillure,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_EXP_clearance_status_0_recover_from_faillure,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "EXP_clearance_status",
	/* states */            seqg_states_EXP_clearance_status,
	/* number of states */  19
	},
};

/* Program table (global) */
seqProgram expClearanceSNC = {
	/* magic number */      2002001,
	/* program name */      "expClearanceSNC",
	/* channels */          seqg_chans,
	/* num. channels */     12,
	/* state sets */        seqg_statesets,
	/* num. state sets */   1,
	/* user var size */     sizeof(struct seqg_vars),
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT),
	/* init func */         seqg_init,
	/* entry func */        0,
	/* exit func */         0,
	/* num. queues */       0
};

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 317 "../expClearanceSNC.stt"
static void initVault(SS_ID seqg_env)
{
# line 319 "../expClearanceSNC.stt"
	seqg_var->EXP_RST_OUTS = TRUE;
# line 320 "../expClearanceSNC.stt"
	seqg_var->EXP_OLD_FAIL_COND = seqg_var->EXP_FAIL_COND;
# line 321 "../expClearanceSNC.stt"
	not_cleared(seqg_var->EXP_CLR_STATS);
# line 322 "../expClearanceSNC.stt"
	report_error(seqg_var->EXP_INTLCK_STATS, 0);
# line 323 "../expClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 3/*EXP_RST_OUTS*/, SYNC, DEFAULT_TIMEOUT);
# line 325 "../expClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*EXP_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 326 "../expClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*EXP_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 330 "../expClearanceSNC.stt"
static void resetVault(SS_ID seqg_env)
{
# line 331 "../expClearanceSNC.stt"
	not_cleared(seqg_var->EXP_CLR_STATS);
# line 332 "../expClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*EXP_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 335 "../expClearanceSNC.stt"
static void EXP_update_failed(SS_ID seqg_env, short report)
{
# line 337 "../expClearanceSNC.stt"
	clear_failed(seqg_var->EXP_CLR_STATS);
# line 338 "../expClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*EXP_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 339 "../expClearanceSNC.stt"
	report_error(seqg_var->EXP_INTLCK_STATS, report);
# line 340 "../expClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*EXP_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 341 "../expClearanceSNC.stt"
	printf("%s%s%s\n", ERROR, seqg_var->EXP_INTLCK_STATS, DEF);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 344 "../expClearanceSNC.stt"
static void EXP_update_report(SS_ID seqg_env, short intlck)
{
# line 345 "../expClearanceSNC.stt"
	report_error(seqg_var->EXP_INTLCK_STATS, intlck);
# line 346 "../expClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*EXP_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 349 "../expClearanceSNC.stt"
static void EXP_status(SS_ID seqg_env)
{
# line 351 "../expClearanceSNC.stt"
	cleared(seqg_var->EXP_CLR_STATS);
# line 352 "../expClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*EXP_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 353 "../expClearanceSNC.stt"
	report_error(seqg_var->EXP_INTLCK_STATS, 0);
# line 354 "../expClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*EXP_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 357 "../expClearanceSNC.stt"
static void EXP_clear_underway(SS_ID seqg_env)
{
# line 359 "../expClearanceSNC.stt"
	clear_underway(seqg_var->EXP_CLR_STATS);
# line 360 "../expClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*EXP_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var
# line 364 "../expClearanceSNC.stt"


inline void cleared(string vault_status) {   
    strcpy(vault_status, mes_array[1]); // Area cleared  
}
////////////////////////////////////////////////
inline void not_cleared(string vault_status) {  
   strcpy(vault_status, mes_array[2]); // Area not cleared    
}
///////////////////////////////////////////////
inline void clear_underway(string vault_status) { 
   strcpy(vault_status, mes_array[3]);  // Area clearance underway    
}
//////////////////////////////////////////////
inline void clear_failed(string vault_status) { 
   strcpy(vault_status, mes_array[5]); // Area clearance fail   
}
////////////////////////////////////////////////
inline void report_error(string vault_interlock, short intlock)
{
   strcpy(vault_interlock, mes_array[intlock]);
}
	


/* Register sequencer commands and program */
#include "epicsExport.h"
static void expClearanceSNCRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&expClearanceSNC);
}
epicsExportRegistrar(expClearanceSNCRegistrar);

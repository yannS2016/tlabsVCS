/* C code for program a13aClearanceSNC, generated by snc from ../a13aClearanceSNC.stt */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 3 "../a13aClearanceSNC.stt"

#include "vcs_var_mes.h" // define this here so C functions are seen
	
#define	STOK       	0
#define FAIL		-1
#define	B9aON       80
#define	G5AS1OFF    82
#define	G5AS2OFF    83
#define	B9bOFF      84
#define A13APNK		85 
#define WFVC		193


/* Variable declarations */
struct seqg_vars {
# line 18 "../a13aClearanceSNC.stt"
	short A13A_VC;
# line 19 "../a13aClearanceSNC.stt"
	short A13A_W9a_STS;
# line 20 "../a13aClearanceSNC.stt"
	short A13A_W9b_STS;
# line 21 "../a13aClearanceSNC.stt"
	short A13A_FAIL_COND;
# line 22 "../a13aClearanceSNC.stt"
	short A13A_RST_OUTS;
# line 23 "../a13aClearanceSNC.stt"
	short A13A_PNK;
# line 24 "../a13aClearanceSNC.stt"
	string A13A_CLR_STATS;
# line 25 "../a13aClearanceSNC.stt"
	string A13A_INTLCK_STATS;
# line 28 "../a13aClearanceSNC.stt"
	short A13A_OLD_FAIL_COND;
# line 29 "../a13aClearanceSNC.stt"
	short A13A_FAILED_RST;
};


/* Function declarations */
# line 236 "../a13aClearanceSNC.stt"
static void initVault(SS_ID seqg_env);
# line 246 "../a13aClearanceSNC.stt"
static void resetVault(SS_ID seqg_env);
# line 251 "../a13aClearanceSNC.stt"
static void A13A_update_failed(SS_ID seqg_env, short report);
# line 260 "../a13aClearanceSNC.stt"
static void A13A_update_report(SS_ID seqg_env, short intlck);
# line 265 "../a13aClearanceSNC.stt"
static void A13A_status(SS_ID seqg_env);
# line 273 "../a13aClearanceSNC.stt"
static void A13A_clear_underway(SS_ID seqg_env);

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
	{
# line 29 "../a13aClearanceSNC.stt"
	static short seqg_initvar_A13A_FAILED_RST = FALSE;
	memcpy(&seqg_var->A13A_FAILED_RST, &seqg_initvar_A13A_FAILED_RST, sizeof(seqg_initvar_A13A_FAILED_RST));
	}
}

/****** Code for state "init" in state set "A13A_clearance_status" ******/

/* Event function for state "init" in state set "A13A_clearance_status" */
static seqBool seqg_event_A13A_clearance_status_0_init(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 52 "../a13aClearanceSNC.stt"
	if (seq_delay(seqg_env, 0.5))
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "A13A_clearance_status" */
static void seqg_action_A13A_clearance_status_0_init(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 53 "../a13aClearanceSNC.stt"
			initVault(seqg_env);
# line 54 "../a13aClearanceSNC.stt"
			printf("\n%sI-LINE AREA INITIALISATION COMPLETED%s\n", OK, DEF);
		}
		return;
	}
}

/****** Code for state "watchman_9a_pressed" in state set "A13A_clearance_status" ******/

/* Event function for state "watchman_9a_pressed" in state set "A13A_clearance_status" */
static seqBool seqg_event_A13A_clearance_status_0_watchman_9a_pressed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 60 "../a13aClearanceSNC.stt"
	if (seqg_var->A13A_FAIL_COND != STOK)
	{
		*seqg_pnst = 10;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 65 "../a13aClearanceSNC.stt"
	if (seqg_var->A13A_W9a_STS == WFVC)
	{
		*seqg_pnst = 2;
		*seqg_ptrn = 1;
		return TRUE;
	}
# line 69 "../a13aClearanceSNC.stt"
	if (seqg_var->A13A_W9a_STS == B9aON)
	{
		*seqg_pnst = 3;
		*seqg_ptrn = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_9a_pressed" in state set "A13A_clearance_status" */
static void seqg_action_A13A_clearance_status_0_watchman_9a_pressed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 61 "../a13aClearanceSNC.stt"
			seqg_var->A13A_OLD_FAIL_COND = seqg_var->A13A_FAIL_COND;
		}
		return;
	case 1:
		{
		}
		return;
	case 2:
		{
# line 70 "../a13aClearanceSNC.stt"
			A13A_clear_underway(seqg_env);
# line 71 "../a13aClearanceSNC.stt"
			A13A_update_report(seqg_env, B9aON);
		}
		return;
	}
}

/****** Code for state "clearance_pending" in state set "A13A_clearance_status" ******/

/* Entry function for state "clearance_pending" in state set "A13A_clearance_status" */
static void seqg_entry_A13A_clearance_status_0_clearance_pending(SS_ID seqg_env)
{
}

/* Event function for state "clearance_pending" in state set "A13A_clearance_status" */
static seqBool seqg_event_A13A_clearance_status_0_clearance_pending(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 84 "../a13aClearanceSNC.stt"
	if (seqg_var->A13A_W9a_STS != WFVC)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "clearance_pending" in state set "A13A_clearance_status" */
static void seqg_action_A13A_clearance_status_0_clearance_pending(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "watchman_9a_released" in state set "A13A_clearance_status" ******/

/* Event function for state "watchman_9a_released" in state set "A13A_clearance_status" */
static seqBool seqg_event_A13A_clearance_status_0_watchman_9a_released(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 92 "../a13aClearanceSNC.stt"
	if (seqg_var->A13A_FAIL_COND != STOK)
	{
		*seqg_pnst = 10;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 96 "../a13aClearanceSNC.stt"
	if (seqg_var->A13A_W9a_STS != B9aON)
	{
		*seqg_pnst = 4;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_9a_released" in state set "A13A_clearance_status" */
static void seqg_action_A13A_clearance_status_0_watchman_9a_released(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
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

/****** Code for state "g5a_switch_I_closed" in state set "A13A_clearance_status" ******/

/* Entry function for state "g5a_switch_I_closed" in state set "A13A_clearance_status" */
static void seqg_entry_A13A_clearance_status_0_g5a_switch_I_closed(SS_ID seqg_env)
{
# line 106 "../a13aClearanceSNC.stt"
	A13A_update_report(seqg_env, G5AS1OFF);
}

/* Event function for state "g5a_switch_I_closed" in state set "A13A_clearance_status" */
static seqBool seqg_event_A13A_clearance_status_0_g5a_switch_I_closed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 109 "../a13aClearanceSNC.stt"
	if (seqg_var->A13A_FAIL_COND != STOK)
	{
		*seqg_pnst = 10;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 113 "../a13aClearanceSNC.stt"
	if (seqg_var->A13A_W9b_STS != G5AS1OFF)
	{
		*seqg_pnst = 5;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "g5a_switch_I_closed" in state set "A13A_clearance_status" */
static void seqg_action_A13A_clearance_status_0_g5a_switch_I_closed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
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

/****** Code for state "g5a_switch_II_closed" in state set "A13A_clearance_status" ******/

/* Entry function for state "g5a_switch_II_closed" in state set "A13A_clearance_status" */
static void seqg_entry_A13A_clearance_status_0_g5a_switch_II_closed(SS_ID seqg_env)
{
# line 124 "../a13aClearanceSNC.stt"
	A13A_update_report(seqg_env, G5AS2OFF);
}

/* Event function for state "g5a_switch_II_closed" in state set "A13A_clearance_status" */
static seqBool seqg_event_A13A_clearance_status_0_g5a_switch_II_closed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 127 "../a13aClearanceSNC.stt"
	if (seqg_var->A13A_FAIL_COND != STOK)
	{
		*seqg_pnst = 10;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 131 "../a13aClearanceSNC.stt"
	if (seqg_var->A13A_W9b_STS == G5AS1OFF)
	{
		*seqg_pnst = 4;
		*seqg_ptrn = 1;
		return TRUE;
	}
# line 136 "../a13aClearanceSNC.stt"
	if (seqg_var->A13A_W9b_STS != G5AS2OFF)
	{
		*seqg_pnst = 6;
		*seqg_ptrn = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "g5a_switch_II_closed" in state set "A13A_clearance_status" */
static void seqg_action_A13A_clearance_status_0_g5a_switch_II_closed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
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
	case 2:
		{
		}
		return;
	}
}

/****** Code for state "watchman_9b_pressed" in state set "A13A_clearance_status" ******/

/* Entry function for state "watchman_9b_pressed" in state set "A13A_clearance_status" */
static void seqg_entry_A13A_clearance_status_0_watchman_9b_pressed(SS_ID seqg_env)
{
# line 147 "../a13aClearanceSNC.stt"
	A13A_update_report(seqg_env, B9bOFF);
}

/* Event function for state "watchman_9b_pressed" in state set "A13A_clearance_status" */
static seqBool seqg_event_A13A_clearance_status_0_watchman_9b_pressed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 150 "../a13aClearanceSNC.stt"
	if (seqg_var->A13A_FAIL_COND != STOK)
	{
		*seqg_pnst = 10;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 159 "../a13aClearanceSNC.stt"
	if (seqg_var->A13A_W9b_STS == STOK)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 1;
		return TRUE;
	}
# line 165 "../a13aClearanceSNC.stt"
	if (seqg_var->A13A_W9b_STS != B9bOFF)
	{
		*seqg_pnst = 4;
		*seqg_ptrn = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_9b_pressed" in state set "A13A_clearance_status" */
static void seqg_action_A13A_clearance_status_0_watchman_9b_pressed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 161 "../a13aClearanceSNC.stt"
			A13A_status(seqg_env);
		}
		return;
	case 2:
		{
		}
		return;
	}
}

/****** Code for state "vault_cleared" in state set "A13A_clearance_status" ******/

/* Entry function for state "vault_cleared" in state set "A13A_clearance_status" */
static void seqg_entry_A13A_clearance_status_0_vault_cleared(SS_ID seqg_env)
{
# line 174 "../a13aClearanceSNC.stt"
	printf("%sI-LINE AREA IN CLEARED STATE%s\n", CLR, DEF);
}

/* Event function for state "vault_cleared" in state set "A13A_clearance_status" */
static seqBool seqg_event_A13A_clearance_status_0_vault_cleared(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 176 "../a13aClearanceSNC.stt"
	if (seqg_var->A13A_VC != STOK)
	{
		*seqg_pnst = 8;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "vault_cleared" in state set "A13A_clearance_status" */
static void seqg_action_A13A_clearance_status_0_vault_cleared(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "paniq_faillure" in state set "A13A_clearance_status" ******/

/* Event function for state "paniq_faillure" in state set "A13A_clearance_status" */
static seqBool seqg_event_A13A_clearance_status_0_paniq_faillure(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 184 "../a13aClearanceSNC.stt"
	if (seqg_var->A13A_VC != A13APNK)
	{
		*seqg_pnst = 10;
		*seqg_ptrn = 0;
		return TRUE;
	}
	if (TRUE)
	{
		*seqg_pnst = 9;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "paniq_faillure" in state set "A13A_clearance_status" */
static void seqg_action_A13A_clearance_status_0_paniq_faillure(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 189 "../a13aClearanceSNC.stt"
			printf("A13A VAULT CLEARED FAILURE CONDITION: ");
# line 190 "../a13aClearanceSNC.stt"
			A13A_update_failed(seqg_env, A13APNK);
		}
		return;
	}
}

/****** Code for state "recover_from_paniq" in state set "A13A_clearance_status" ******/

/* Exit function for state "recover_from_paniq" in state set "A13A_clearance_status" */
static void seqg_exit_A13A_clearance_status_0_recover_from_paniq(SS_ID seqg_env)
{
# line 202 "../a13aClearanceSNC.stt"
	seqg_var->A13A_FAILED_RST = FALSE;
}

/* Event function for state "recover_from_paniq" in state set "A13A_clearance_status" */
static seqBool seqg_event_A13A_clearance_status_0_recover_from_paniq(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 198 "../a13aClearanceSNC.stt"
	if (!seqg_var->A13A_PNK)
	{
		*seqg_pnst = 11;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "recover_from_paniq" in state set "A13A_clearance_status" */
static void seqg_action_A13A_clearance_status_0_recover_from_paniq(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "clearance_faillures" in state set "A13A_clearance_status" ******/

/* Entry function for state "clearance_faillures" in state set "A13A_clearance_status" */
static void seqg_entry_A13A_clearance_status_0_clearance_faillures(SS_ID seqg_env)
{
# line 211 "../a13aClearanceSNC.stt"
	printf("A13A CLEARANCE FAILURE CONDITION: ");
# line 212 "../a13aClearanceSNC.stt"
	seqg_var->A13A_FAILED_RST = FALSE;
# line 213 "../a13aClearanceSNC.stt"
	seqg_var->A13A_OLD_FAIL_COND = seqg_var->A13A_FAIL_COND;
# line 214 "../a13aClearanceSNC.stt"
	A13A_update_failed(seqg_env, seqg_var->A13A_FAIL_COND == FAIL ? STOK : seqg_var->A13A_FAIL_COND);
}

/* Event function for state "clearance_faillures" in state set "A13A_clearance_status" */
static seqBool seqg_event_A13A_clearance_status_0_clearance_faillures(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		*seqg_pnst = 11;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "clearance_faillures" in state set "A13A_clearance_status" */
static void seqg_action_A13A_clearance_status_0_clearance_faillures(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "recover_from_faillure" in state set "A13A_clearance_status" ******/

/* Event function for state "recover_from_faillure" in state set "A13A_clearance_status" */
static seqBool seqg_event_A13A_clearance_status_0_recover_from_faillure(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 224 "../a13aClearanceSNC.stt"
	if (!seqg_var->A13A_FAIL_COND)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 228 "../a13aClearanceSNC.stt"
	if (seqg_var->A13A_FAIL_COND != seqg_var->A13A_OLD_FAIL_COND)
	{
		*seqg_pnst = 10;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "recover_from_faillure" in state set "A13A_clearance_status" */
static void seqg_action_A13A_clearance_status_0_recover_from_faillure(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 225 "../a13aClearanceSNC.stt"
			printf("%sA13A RECOVERING FROM FAILLURE : ENTERING W9a STATE%s\n", OK, DEF);
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
	{"{SYS}:RST-A13A.PROC", offsetof(struct seqg_vars, A13A_RST_OUTS), "A13A_RST_OUTS", P_SHORT, 1, 1, 0, 0, 0, 0},
	{"{SYS}:A13A-CLR-STATS", offsetof(struct seqg_vars, A13A_CLR_STATS), "A13A_CLR_STATS", P_STRING, 1, 2, 0, 0, 0, 0},
	{"{SYS}:A13A-INTLCK-STATS", offsetof(struct seqg_vars, A13A_INTLCK_STATS), "A13A_INTLCK_STATS", P_STRING, 1, 3, 0, 0, 0, 0},
	{"{SYS}:A13A-VC", offsetof(struct seqg_vars, A13A_VC), "A13A_VC", P_SHORT, 1, 4, 0, 1, 0, 0},
	{"{SYS}:A13A-W9a-STS", offsetof(struct seqg_vars, A13A_W9a_STS), "A13A_W9a_STS", P_SHORT, 1, 5, 0, 1, 0, 0},
	{"{SYS}:A13A-W9b-STS", offsetof(struct seqg_vars, A13A_W9b_STS), "A13A_W9b_STS", P_SHORT, 1, 6, 0, 1, 0, 0},
	{"{SYS}:A13A-FAIL-COND", offsetof(struct seqg_vars, A13A_FAIL_COND), "A13A_FAIL_COND", P_SHORT, 1, 7, 0, 1, 0, 0},
	{"{SYS}:A13A-PNK", offsetof(struct seqg_vars, A13A_PNK), "A13A_PNK", P_SHORT, 1, 8, 0, 1, 0, 0},
};

/* Event masks for state set "A13A_clearance_status" */
static const seqMask seqg_mask_A13A_clearance_status_0_init[] = {
	0x00000000,
};
static const seqMask seqg_mask_A13A_clearance_status_0_watchman_9a_pressed[] = {
	0x000000a0,
};
static const seqMask seqg_mask_A13A_clearance_status_0_clearance_pending[] = {
	0x00000020,
};
static const seqMask seqg_mask_A13A_clearance_status_0_watchman_9a_released[] = {
	0x000000a0,
};
static const seqMask seqg_mask_A13A_clearance_status_0_g5a_switch_I_closed[] = {
	0x000000c0,
};
static const seqMask seqg_mask_A13A_clearance_status_0_g5a_switch_II_closed[] = {
	0x000000c0,
};
static const seqMask seqg_mask_A13A_clearance_status_0_watchman_9b_pressed[] = {
	0x000000c0,
};
static const seqMask seqg_mask_A13A_clearance_status_0_vault_cleared[] = {
	0x00000010,
};
static const seqMask seqg_mask_A13A_clearance_status_0_paniq_faillure[] = {
	0x00000010,
};
static const seqMask seqg_mask_A13A_clearance_status_0_recover_from_paniq[] = {
	0x00000100,
};
static const seqMask seqg_mask_A13A_clearance_status_0_clearance_faillures[] = {
	0x00000000,
};
static const seqMask seqg_mask_A13A_clearance_status_0_recover_from_faillure[] = {
	0x00000080,
};

/* State table for state set "A13A_clearance_status" */
static seqState seqg_states_A13A_clearance_status[] = {
	{
	/* state name */        "init",
	/* action function */   seqg_action_A13A_clearance_status_0_init,
	/* event function */    seqg_event_A13A_clearance_status_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_A13A_clearance_status_0_init,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_9a_pressed",
	/* action function */   seqg_action_A13A_clearance_status_0_watchman_9a_pressed,
	/* event function */    seqg_event_A13A_clearance_status_0_watchman_9a_pressed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_A13A_clearance_status_0_watchman_9a_pressed,
	/* state options */     (0)
	},
	{
	/* state name */        "clearance_pending",
	/* action function */   seqg_action_A13A_clearance_status_0_clearance_pending,
	/* event function */    seqg_event_A13A_clearance_status_0_clearance_pending,
	/* entry function */    seqg_entry_A13A_clearance_status_0_clearance_pending,
	/* exit function */     0,
	/* event mask array */  seqg_mask_A13A_clearance_status_0_clearance_pending,
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
	},
	{
	/* state name */        "watchman_9a_released",
	/* action function */   seqg_action_A13A_clearance_status_0_watchman_9a_released,
	/* event function */    seqg_event_A13A_clearance_status_0_watchman_9a_released,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_A13A_clearance_status_0_watchman_9a_released,
	/* state options */     (0)
	},
	{
	/* state name */        "g5a_switch_I_closed",
	/* action function */   seqg_action_A13A_clearance_status_0_g5a_switch_I_closed,
	/* event function */    seqg_event_A13A_clearance_status_0_g5a_switch_I_closed,
	/* entry function */    seqg_entry_A13A_clearance_status_0_g5a_switch_I_closed,
	/* exit function */     0,
	/* event mask array */  seqg_mask_A13A_clearance_status_0_g5a_switch_I_closed,
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
	},
	{
	/* state name */        "g5a_switch_II_closed",
	/* action function */   seqg_action_A13A_clearance_status_0_g5a_switch_II_closed,
	/* event function */    seqg_event_A13A_clearance_status_0_g5a_switch_II_closed,
	/* entry function */    seqg_entry_A13A_clearance_status_0_g5a_switch_II_closed,
	/* exit function */     0,
	/* event mask array */  seqg_mask_A13A_clearance_status_0_g5a_switch_II_closed,
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
	},
	{
	/* state name */        "watchman_9b_pressed",
	/* action function */   seqg_action_A13A_clearance_status_0_watchman_9b_pressed,
	/* event function */    seqg_event_A13A_clearance_status_0_watchman_9b_pressed,
	/* entry function */    seqg_entry_A13A_clearance_status_0_watchman_9b_pressed,
	/* exit function */     0,
	/* event mask array */  seqg_mask_A13A_clearance_status_0_watchman_9b_pressed,
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
	},
	{
	/* state name */        "vault_cleared",
	/* action function */   seqg_action_A13A_clearance_status_0_vault_cleared,
	/* event function */    seqg_event_A13A_clearance_status_0_vault_cleared,
	/* entry function */    seqg_entry_A13A_clearance_status_0_vault_cleared,
	/* exit function */     0,
	/* event mask array */  seqg_mask_A13A_clearance_status_0_vault_cleared,
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
	},
	{
	/* state name */        "paniq_faillure",
	/* action function */   seqg_action_A13A_clearance_status_0_paniq_faillure,
	/* event function */    seqg_event_A13A_clearance_status_0_paniq_faillure,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_A13A_clearance_status_0_paniq_faillure,
	/* state options */     (0)
	},
	{
	/* state name */        "recover_from_paniq",
	/* action function */   seqg_action_A13A_clearance_status_0_recover_from_paniq,
	/* event function */    seqg_event_A13A_clearance_status_0_recover_from_paniq,
	/* entry function */    0,
	/* exit function */     seqg_exit_A13A_clearance_status_0_recover_from_paniq,
	/* event mask array */  seqg_mask_A13A_clearance_status_0_recover_from_paniq,
	/* state options */     (0 | OPT_DOENTRYFROMSELF | OPT_DOEXITTOSELF)
	},
	{
	/* state name */        "clearance_faillures",
	/* action function */   seqg_action_A13A_clearance_status_0_clearance_faillures,
	/* event function */    seqg_event_A13A_clearance_status_0_clearance_faillures,
	/* entry function */    seqg_entry_A13A_clearance_status_0_clearance_faillures,
	/* exit function */     0,
	/* event mask array */  seqg_mask_A13A_clearance_status_0_clearance_faillures,
	/* state options */     (0 | OPT_DOENTRYFROMSELF | OPT_DOEXITTOSELF)
	},
	{
	/* state name */        "recover_from_faillure",
	/* action function */   seqg_action_A13A_clearance_status_0_recover_from_faillure,
	/* event function */    seqg_event_A13A_clearance_status_0_recover_from_faillure,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_A13A_clearance_status_0_recover_from_faillure,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "A13A_clearance_status",
	/* states */            seqg_states_A13A_clearance_status,
	/* number of states */  12
	},
};

/* Program table (global) */
seqProgram a13aClearanceSNC = {
	/* magic number */      2002001,
	/* program name */      "a13aClearanceSNC",
	/* channels */          seqg_chans,
	/* num. channels */     8,
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
# line 236 "../a13aClearanceSNC.stt"
static void initVault(SS_ID seqg_env)
{
# line 237 "../a13aClearanceSNC.stt"
	seqg_var->A13A_OLD_FAIL_COND = seqg_var->A13A_FAIL_COND;
# line 238 "../a13aClearanceSNC.stt"
	seqg_var->A13A_RST_OUTS = TRUE;
# line 239 "../a13aClearanceSNC.stt"
	not_cleared(seqg_var->A13A_CLR_STATS);
# line 240 "../a13aClearanceSNC.stt"
	report_error(seqg_var->A13A_INTLCK_STATS, 0);
# line 241 "../a13aClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*A13A_RST_OUTS*/, SYNC, DEFAULT_TIMEOUT);
# line 242 "../a13aClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*A13A_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 243 "../a13aClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 2/*A13A_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 246 "../a13aClearanceSNC.stt"
static void resetVault(SS_ID seqg_env)
{
# line 247 "../a13aClearanceSNC.stt"
	not_cleared(seqg_var->A13A_CLR_STATS);
# line 248 "../a13aClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*A13A_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 251 "../a13aClearanceSNC.stt"
static void A13A_update_failed(SS_ID seqg_env, short report)
{
# line 253 "../a13aClearanceSNC.stt"
	clear_failed(seqg_var->A13A_CLR_STATS);
# line 254 "../a13aClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*A13A_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 255 "../a13aClearanceSNC.stt"
	report_error(seqg_var->A13A_INTLCK_STATS, report);
# line 256 "../a13aClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 2/*A13A_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 257 "../a13aClearanceSNC.stt"
	printf("%s%s%s\n", ERROR, seqg_var->A13A_INTLCK_STATS, DEF);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 260 "../a13aClearanceSNC.stt"
static void A13A_update_report(SS_ID seqg_env, short intlck)
{
# line 261 "../a13aClearanceSNC.stt"
	report_error(seqg_var->A13A_INTLCK_STATS, intlck);
# line 262 "../a13aClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 2/*A13A_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 265 "../a13aClearanceSNC.stt"
static void A13A_status(SS_ID seqg_env)
{
# line 267 "../a13aClearanceSNC.stt"
	cleared(seqg_var->A13A_CLR_STATS);
# line 268 "../a13aClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*A13A_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 269 "../a13aClearanceSNC.stt"
	report_error(seqg_var->A13A_INTLCK_STATS, 0);
# line 270 "../a13aClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 2/*A13A_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 273 "../a13aClearanceSNC.stt"
static void A13A_clear_underway(SS_ID seqg_env)
{
# line 275 "../a13aClearanceSNC.stt"
	clear_underway(seqg_var->A13A_CLR_STATS);
# line 276 "../a13aClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*A13A_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var
# line 280 "../a13aClearanceSNC.stt"


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
static void a13aClearanceSNCRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&a13aClearanceSNC);
}
epicsExportRegistrar(a13aClearanceSNCRegistrar);

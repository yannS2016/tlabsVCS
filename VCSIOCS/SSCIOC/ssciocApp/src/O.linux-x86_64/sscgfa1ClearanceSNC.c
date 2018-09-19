/* C code for program sscgfa1ClearanceSNC, generated by snc from ../sscgfa1ClearanceSNC.stt */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 3 "../sscgfa1ClearanceSNC.stt"

#include "vcs_var_mes.h" // define this here so C functions are seen
	
#define	STOK        0
#define FAIL		-1
#define	G3OFF		66
#define WFVC		193
#define B11ON		65
#define B12OFF		68
#define SSCA1PNK	69 


/* Variable declarations */
# line 15 "../sscgfa1ClearanceSNC.stt"
static	short SSCA1_VC;
# line 16 "../sscgfa1ClearanceSNC.stt"
static	short SSCA1_W11_STS;
# line 17 "../sscgfa1ClearanceSNC.stt"
static	short SSCA1_W12_STS;
# line 18 "../sscgfa1ClearanceSNC.stt"
static	short SSCA1_RST_OUTS;
# line 19 "../sscgfa1ClearanceSNC.stt"
static	short SSCA1_FAIL_COND;
# line 20 "../sscgfa1ClearanceSNC.stt"
static	short SSCA1_PNK;
# line 21 "../sscgfa1ClearanceSNC.stt"
static	string SSCA1_CLR_STATS;
# line 22 "../sscgfa1ClearanceSNC.stt"
static	string SSCA1_INTLCK_STATS;
# line 25 "../sscgfa1ClearanceSNC.stt"
static	short SSCA1_OLD_FAIL_COND;
# line 26 "../sscgfa1ClearanceSNC.stt"
static	short SSCA1_FAILED_RST;


/* Function declarations */
# line 199 "../sscgfa1ClearanceSNC.stt"
static void initVault(SS_ID seqg_env);
# line 212 "../sscgfa1ClearanceSNC.stt"
static void resetVault(SS_ID seqg_env);
# line 217 "../sscgfa1ClearanceSNC.stt"
static void SSCA1_update_failed(SS_ID seqg_env, short report);
# line 226 "../sscgfa1ClearanceSNC.stt"
static void SSCA1_update_report(SS_ID seqg_env, short intlck);
# line 231 "../sscgfa1ClearanceSNC.stt"
static void SSCA1_status(SS_ID seqg_env);
# line 239 "../sscgfa1ClearanceSNC.stt"
static void SSCA1_clear_underway(SS_ID seqg_env);

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
	{
# line 26 "../sscgfa1ClearanceSNC.stt"
	static short seqg_initvar_SSCA1_FAILED_RST = FALSE;
	memcpy(&SSCA1_FAILED_RST, &seqg_initvar_SSCA1_FAILED_RST, sizeof(seqg_initvar_SSCA1_FAILED_RST));
	}
}

/****** Code for state "init" in state set "SSCA1_clearance_status" ******/

/* Event function for state "init" in state set "SSCA1_clearance_status" */
static seqBool seqg_event_SSCA1_clearance_status_0_init(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 48 "../sscgfa1ClearanceSNC.stt"
	if (seq_delay(seqg_env, 1))
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "SSCA1_clearance_status" */
static void seqg_action_SSCA1_clearance_status_0_init(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 49 "../sscgfa1ClearanceSNC.stt"
			initVault(seqg_env);
# line 50 "../sscgfa1ClearanceSNC.stt"
			printf("\n%sSSC GROUND FLOOR AREA 1 INITIALISATION COMPLETED%s\n", OK, DEF);
		}
		return;
	}
}

/****** Code for state "watchman_11_pressed" in state set "SSCA1_clearance_status" ******/

/* Event function for state "watchman_11_pressed" in state set "SSCA1_clearance_status" */
static seqBool seqg_event_SSCA1_clearance_status_0_watchman_11_pressed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 57 "../sscgfa1ClearanceSNC.stt"
	if (SSCA1_FAIL_COND != STOK)
	{
		*seqg_pnst = 8;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 65 "../sscgfa1ClearanceSNC.stt"
	if (SSCA1_W11_STS == B11ON)
	{
		*seqg_pnst = 2;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_11_pressed" in state set "SSCA1_clearance_status" */
static void seqg_action_SSCA1_clearance_status_0_watchman_11_pressed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 58 "../sscgfa1ClearanceSNC.stt"
			SSCA1_OLD_FAIL_COND = SSCA1_FAIL_COND;
		}
		return;
	case 1:
		{
# line 66 "../sscgfa1ClearanceSNC.stt"
			SSCA1_clear_underway(seqg_env);
# line 67 "../sscgfa1ClearanceSNC.stt"
			SSCA1_update_report(seqg_env, B11ON);
		}
		return;
	}
}

/****** Code for state "watchman_11_released" in state set "SSCA1_clearance_status" ******/

/* Event function for state "watchman_11_released" in state set "SSCA1_clearance_status" */
static seqBool seqg_event_SSCA1_clearance_status_0_watchman_11_released(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 88 "../sscgfa1ClearanceSNC.stt"
	if (SSCA1_FAIL_COND != STOK)
	{
		*seqg_pnst = 8;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 92 "../sscgfa1ClearanceSNC.stt"
	if (SSCA1_W11_STS != B11ON)
	{
		*seqg_pnst = 3;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_11_released" in state set "SSCA1_clearance_status" */
static void seqg_action_SSCA1_clearance_status_0_watchman_11_released(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
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

/****** Code for state "gate_g3_closed" in state set "SSCA1_clearance_status" ******/

/* Entry function for state "gate_g3_closed" in state set "SSCA1_clearance_status" */
static void seqg_entry_SSCA1_clearance_status_0_gate_g3_closed(SS_ID seqg_env)
{
# line 102 "../sscgfa1ClearanceSNC.stt"
	SSCA1_update_report(seqg_env, G3OFF);
}

/* Event function for state "gate_g3_closed" in state set "SSCA1_clearance_status" */
static seqBool seqg_event_SSCA1_clearance_status_0_gate_g3_closed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 105 "../sscgfa1ClearanceSNC.stt"
	if (SSCA1_FAIL_COND != STOK)
	{
		*seqg_pnst = 8;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 110 "../sscgfa1ClearanceSNC.stt"
	if (SSCA1_W12_STS != G3OFF)
	{
		*seqg_pnst = 4;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "gate_g3_closed" in state set "SSCA1_clearance_status" */
static void seqg_action_SSCA1_clearance_status_0_gate_g3_closed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
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

/****** Code for state "watchman_12_pressed" in state set "SSCA1_clearance_status" ******/

/* Entry function for state "watchman_12_pressed" in state set "SSCA1_clearance_status" */
static void seqg_entry_SSCA1_clearance_status_0_watchman_12_pressed(SS_ID seqg_env)
{
# line 119 "../sscgfa1ClearanceSNC.stt"
	SSCA1_update_report(seqg_env, B12OFF);
}

/* Event function for state "watchman_12_pressed" in state set "SSCA1_clearance_status" */
static seqBool seqg_event_SSCA1_clearance_status_0_watchman_12_pressed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 122 "../sscgfa1ClearanceSNC.stt"
	if (SSCA1_FAIL_COND != STOK)
	{
		*seqg_pnst = 8;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 126 "../sscgfa1ClearanceSNC.stt"
	if (SSCA1_W12_STS == STOK)
	{
		*seqg_pnst = 5;
		*seqg_ptrn = 1;
		return TRUE;
	}
# line 131 "../sscgfa1ClearanceSNC.stt"
	if (SSCA1_W12_STS != B12OFF)
	{
		*seqg_pnst = 3;
		*seqg_ptrn = 2;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_12_pressed" in state set "SSCA1_clearance_status" */
static void seqg_action_SSCA1_clearance_status_0_watchman_12_pressed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 128 "../sscgfa1ClearanceSNC.stt"
			SSCA1_status(seqg_env);
		}
		return;
	case 2:
		{
		}
		return;
	}
}

/****** Code for state "vault_cleared" in state set "SSCA1_clearance_status" ******/

/* Entry function for state "vault_cleared" in state set "SSCA1_clearance_status" */
static void seqg_entry_SSCA1_clearance_status_0_vault_cleared(SS_ID seqg_env)
{
# line 139 "../sscgfa1ClearanceSNC.stt"
	printf("%sSSC Ground Floor Area 1 IN CLEARED STATE%s\n", CLR, DEF);
}

/* Event function for state "vault_cleared" in state set "SSCA1_clearance_status" */
static seqBool seqg_event_SSCA1_clearance_status_0_vault_cleared(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 141 "../sscgfa1ClearanceSNC.stt"
	if (SSCA1_VC != STOK)
	{
		*seqg_pnst = 6;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "vault_cleared" in state set "SSCA1_clearance_status" */
static void seqg_action_SSCA1_clearance_status_0_vault_cleared(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "paniq_faillure" in state set "SSCA1_clearance_status" ******/

/* Event function for state "paniq_faillure" in state set "SSCA1_clearance_status" */
static seqBool seqg_event_SSCA1_clearance_status_0_paniq_faillure(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 148 "../sscgfa1ClearanceSNC.stt"
	if (SSCA1_VC != SSCA1PNK)
	{
		*seqg_pnst = 8;
		*seqg_ptrn = 0;
		return TRUE;
	}
	if (TRUE)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "paniq_faillure" in state set "SSCA1_clearance_status" */
static void seqg_action_SSCA1_clearance_status_0_paniq_faillure(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 153 "../sscgfa1ClearanceSNC.stt"
			printf("SSC Ground Floor Area 1 CLEARED FAILURE CONDITION: ");
# line 154 "../sscgfa1ClearanceSNC.stt"
			SSCA1_update_failed(seqg_env, SSCA1PNK);
		}
		return;
	}
}

/****** Code for state "recover_from_paniq" in state set "SSCA1_clearance_status" ******/

/* Exit function for state "recover_from_paniq" in state set "SSCA1_clearance_status" */
static void seqg_exit_SSCA1_clearance_status_0_recover_from_paniq(SS_ID seqg_env)
{
# line 167 "../sscgfa1ClearanceSNC.stt"
	SSCA1_FAILED_RST = FALSE;
}

/* Event function for state "recover_from_paniq" in state set "SSCA1_clearance_status" */
static seqBool seqg_event_SSCA1_clearance_status_0_recover_from_paniq(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 162 "../sscgfa1ClearanceSNC.stt"
	if (!SSCA1_PNK)
	{
		*seqg_pnst = 9;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "recover_from_paniq" in state set "SSCA1_clearance_status" */
static void seqg_action_SSCA1_clearance_status_0_recover_from_paniq(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "clearance_faillures" in state set "SSCA1_clearance_status" ******/

/* Entry function for state "clearance_faillures" in state set "SSCA1_clearance_status" */
static void seqg_entry_SSCA1_clearance_status_0_clearance_faillures(SS_ID seqg_env)
{
# line 176 "../sscgfa1ClearanceSNC.stt"
	printf("SSC Ground Floor Area 1 CLEARANCE FAILURE CONDITION: ");
# line 177 "../sscgfa1ClearanceSNC.stt"
	SSCA1_FAILED_RST = FALSE;
# line 178 "../sscgfa1ClearanceSNC.stt"
	SSCA1_OLD_FAIL_COND = SSCA1_FAIL_COND;
# line 179 "../sscgfa1ClearanceSNC.stt"
	SSCA1_update_failed(seqg_env, SSCA1_FAIL_COND == FAIL ? STOK : SSCA1_FAIL_COND);
}

/* Event function for state "clearance_faillures" in state set "SSCA1_clearance_status" */
static seqBool seqg_event_SSCA1_clearance_status_0_clearance_faillures(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		*seqg_pnst = 9;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "clearance_faillures" in state set "SSCA1_clearance_status" */
static void seqg_action_SSCA1_clearance_status_0_clearance_faillures(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "recover_from_faillure" in state set "SSCA1_clearance_status" ******/

/* Event function for state "recover_from_faillure" in state set "SSCA1_clearance_status" */
static seqBool seqg_event_SSCA1_clearance_status_0_recover_from_faillure(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 189 "../sscgfa1ClearanceSNC.stt"
	if (!SSCA1_FAIL_COND)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 193 "../sscgfa1ClearanceSNC.stt"
	if (SSCA1_FAIL_COND != SSCA1_OLD_FAIL_COND)
	{
		*seqg_pnst = 8;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "recover_from_faillure" in state set "SSCA1_clearance_status" */
static void seqg_action_SSCA1_clearance_status_0_recover_from_faillure(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 190 "../sscgfa1ClearanceSNC.stt"
			printf("%sSSC GROUND-FLOOR RECOVERING FROM FAILLURE : ENTERING W11 STATE%s\n", OK, DEF);
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
	{"{SYS}:RST-SSCA1.PROC", (size_t)&SSCA1_RST_OUTS, "SSCA1_RST_OUTS", P_SHORT, 1, 1, 0, 0, 0, 0},
	{"{SYS}:SSCA1-CLR-STATS", (size_t)&SSCA1_CLR_STATS, "SSCA1_CLR_STATS", P_STRING, 1, 2, 0, 0, 0, 0},
	{"{SYS}:SSCA1-INTLCK-STATS", (size_t)&SSCA1_INTLCK_STATS, "SSCA1_INTLCK_STATS", P_STRING, 1, 3, 0, 0, 0, 0},
	{"{SYS}:SSCA1-VC", (size_t)&SSCA1_VC, "SSCA1_VC", P_SHORT, 1, 4, 0, 1, 0, 0},
	{"{SYS}:SSC-W11-STS", (size_t)&SSCA1_W11_STS, "SSCA1_W11_STS", P_SHORT, 1, 5, 0, 1, 0, 0},
	{"{SYS}:SSC-W12-STS", (size_t)&SSCA1_W12_STS, "SSCA1_W12_STS", P_SHORT, 1, 6, 0, 1, 0, 0},
	{"{SYS}:SSCA1-FAIL-COND", (size_t)&SSCA1_FAIL_COND, "SSCA1_FAIL_COND", P_SHORT, 1, 7, 0, 1, 0, 0},
	{"{SYS}:SSCA1-PNK", (size_t)&SSCA1_PNK, "SSCA1_PNK", P_SHORT, 1, 8, 0, 1, 0, 0},
};

/* Event masks for state set "SSCA1_clearance_status" */
static const seqMask seqg_mask_SSCA1_clearance_status_0_init[] = {
	0x00000000,
};
static const seqMask seqg_mask_SSCA1_clearance_status_0_watchman_11_pressed[] = {
	0x000000a0,
};
static const seqMask seqg_mask_SSCA1_clearance_status_0_watchman_11_released[] = {
	0x000000a0,
};
static const seqMask seqg_mask_SSCA1_clearance_status_0_gate_g3_closed[] = {
	0x000000c0,
};
static const seqMask seqg_mask_SSCA1_clearance_status_0_watchman_12_pressed[] = {
	0x000000c0,
};
static const seqMask seqg_mask_SSCA1_clearance_status_0_vault_cleared[] = {
	0x00000010,
};
static const seqMask seqg_mask_SSCA1_clearance_status_0_paniq_faillure[] = {
	0x00000010,
};
static const seqMask seqg_mask_SSCA1_clearance_status_0_recover_from_paniq[] = {
	0x00000100,
};
static const seqMask seqg_mask_SSCA1_clearance_status_0_clearance_faillures[] = {
	0x00000000,
};
static const seqMask seqg_mask_SSCA1_clearance_status_0_recover_from_faillure[] = {
	0x00000080,
};

/* State table for state set "SSCA1_clearance_status" */
static seqState seqg_states_SSCA1_clearance_status[] = {
	{
	/* state name */        "init",
	/* action function */   seqg_action_SSCA1_clearance_status_0_init,
	/* event function */    seqg_event_SSCA1_clearance_status_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SSCA1_clearance_status_0_init,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_11_pressed",
	/* action function */   seqg_action_SSCA1_clearance_status_0_watchman_11_pressed,
	/* event function */    seqg_event_SSCA1_clearance_status_0_watchman_11_pressed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SSCA1_clearance_status_0_watchman_11_pressed,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_11_released",
	/* action function */   seqg_action_SSCA1_clearance_status_0_watchman_11_released,
	/* event function */    seqg_event_SSCA1_clearance_status_0_watchman_11_released,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SSCA1_clearance_status_0_watchman_11_released,
	/* state options */     (0)
	},
	{
	/* state name */        "gate_g3_closed",
	/* action function */   seqg_action_SSCA1_clearance_status_0_gate_g3_closed,
	/* event function */    seqg_event_SSCA1_clearance_status_0_gate_g3_closed,
	/* entry function */    seqg_entry_SSCA1_clearance_status_0_gate_g3_closed,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SSCA1_clearance_status_0_gate_g3_closed,
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
	},
	{
	/* state name */        "watchman_12_pressed",
	/* action function */   seqg_action_SSCA1_clearance_status_0_watchman_12_pressed,
	/* event function */    seqg_event_SSCA1_clearance_status_0_watchman_12_pressed,
	/* entry function */    seqg_entry_SSCA1_clearance_status_0_watchman_12_pressed,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SSCA1_clearance_status_0_watchman_12_pressed,
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
	},
	{
	/* state name */        "vault_cleared",
	/* action function */   seqg_action_SSCA1_clearance_status_0_vault_cleared,
	/* event function */    seqg_event_SSCA1_clearance_status_0_vault_cleared,
	/* entry function */    seqg_entry_SSCA1_clearance_status_0_vault_cleared,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SSCA1_clearance_status_0_vault_cleared,
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
	},
	{
	/* state name */        "paniq_faillure",
	/* action function */   seqg_action_SSCA1_clearance_status_0_paniq_faillure,
	/* event function */    seqg_event_SSCA1_clearance_status_0_paniq_faillure,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SSCA1_clearance_status_0_paniq_faillure,
	/* state options */     (0)
	},
	{
	/* state name */        "recover_from_paniq",
	/* action function */   seqg_action_SSCA1_clearance_status_0_recover_from_paniq,
	/* event function */    seqg_event_SSCA1_clearance_status_0_recover_from_paniq,
	/* entry function */    0,
	/* exit function */     seqg_exit_SSCA1_clearance_status_0_recover_from_paniq,
	/* event mask array */  seqg_mask_SSCA1_clearance_status_0_recover_from_paniq,
	/* state options */     (0 | OPT_DOENTRYFROMSELF | OPT_DOEXITTOSELF)
	},
	{
	/* state name */        "clearance_faillures",
	/* action function */   seqg_action_SSCA1_clearance_status_0_clearance_faillures,
	/* event function */    seqg_event_SSCA1_clearance_status_0_clearance_faillures,
	/* entry function */    seqg_entry_SSCA1_clearance_status_0_clearance_faillures,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SSCA1_clearance_status_0_clearance_faillures,
	/* state options */     (0 | OPT_DOENTRYFROMSELF | OPT_DOEXITTOSELF)
	},
	{
	/* state name */        "recover_from_faillure",
	/* action function */   seqg_action_SSCA1_clearance_status_0_recover_from_faillure,
	/* event function */    seqg_event_SSCA1_clearance_status_0_recover_from_faillure,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_SSCA1_clearance_status_0_recover_from_faillure,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "SSCA1_clearance_status",
	/* states */            seqg_states_SSCA1_clearance_status,
	/* number of states */  10
	},
};

/* Program table (global) */
seqProgram sscgfa1ClearanceSNC = {
	/* magic number */      2002001,
	/* program name */      "sscgfa1ClearanceSNC",
	/* channels */          seqg_chans,
	/* num. channels */     8,
	/* state sets */        seqg_statesets,
	/* num. state sets */   1,
	/* user var size */     0,
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF),
	/* init func */         seqg_init,
	/* entry func */        0,
	/* exit func */         0,
	/* num. queues */       0
};

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 199 "../sscgfa1ClearanceSNC.stt"
static void initVault(SS_ID seqg_env)
{
# line 201 "../sscgfa1ClearanceSNC.stt"
	SSCA1_RST_OUTS = TRUE;
# line 202 "../sscgfa1ClearanceSNC.stt"
	SSCA1_OLD_FAIL_COND = SSCA1_FAIL_COND;
# line 203 "../sscgfa1ClearanceSNC.stt"
	not_cleared(SSCA1_CLR_STATS);
# line 204 "../sscgfa1ClearanceSNC.stt"
	report_error(SSCA1_INTLCK_STATS, 0);
# line 205 "../sscgfa1ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*SSCA1_RST_OUTS*/, SYNC, DEFAULT_TIMEOUT);
# line 207 "../sscgfa1ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*SSCA1_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 208 "../sscgfa1ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 2/*SSCA1_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 212 "../sscgfa1ClearanceSNC.stt"
static void resetVault(SS_ID seqg_env)
{
# line 213 "../sscgfa1ClearanceSNC.stt"
	not_cleared(SSCA1_CLR_STATS);
# line 214 "../sscgfa1ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*SSCA1_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 217 "../sscgfa1ClearanceSNC.stt"
static void SSCA1_update_failed(SS_ID seqg_env, short report)
{
# line 219 "../sscgfa1ClearanceSNC.stt"
	clear_failed(SSCA1_CLR_STATS);
# line 220 "../sscgfa1ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*SSCA1_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 221 "../sscgfa1ClearanceSNC.stt"
	report_error(SSCA1_INTLCK_STATS, report);
# line 222 "../sscgfa1ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 2/*SSCA1_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 223 "../sscgfa1ClearanceSNC.stt"
	printf("%s%s%s\n", ERROR, SSCA1_INTLCK_STATS, DEF);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 226 "../sscgfa1ClearanceSNC.stt"
static void SSCA1_update_report(SS_ID seqg_env, short intlck)
{
# line 227 "../sscgfa1ClearanceSNC.stt"
	report_error(SSCA1_INTLCK_STATS, intlck);
# line 228 "../sscgfa1ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 2/*SSCA1_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 231 "../sscgfa1ClearanceSNC.stt"
static void SSCA1_status(SS_ID seqg_env)
{
# line 233 "../sscgfa1ClearanceSNC.stt"
	cleared(SSCA1_CLR_STATS);
# line 234 "../sscgfa1ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*SSCA1_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 235 "../sscgfa1ClearanceSNC.stt"
	report_error(SSCA1_INTLCK_STATS, 0);
# line 236 "../sscgfa1ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 2/*SSCA1_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 239 "../sscgfa1ClearanceSNC.stt"
static void SSCA1_clear_underway(SS_ID seqg_env)
{
# line 241 "../sscgfa1ClearanceSNC.stt"
	clear_underway(SSCA1_CLR_STATS);
# line 242 "../sscgfa1ClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*SSCA1_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

/* Register sequencer commands and program */
#include "epicsExport.h"
static void sscgfa1ClearanceSNCRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&sscgfa1ClearanceSNC);
}
epicsExportRegistrar(sscgfa1ClearanceSNCRegistrar);

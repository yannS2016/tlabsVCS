/* C code for program cnaClearanceSNC, generated by snc from ../cnaClearanceSNC.stt */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>

#include "seq_snc.h"
# line 3 "../cnaClearanceSNC.stt"

/*******************************************************************/
#include "vcs_var_mes.h" // define this here so C functions are seen
/*******************************************************************/
#define	VCOK       	0
#define FAIL		-1
#define	B38ON		125					
#define	B39OFF		126      		 	
#define	DA12AON		124       			
#define	DA12AS1OFF	127        		   	 
#define	DA12AS2OFF	128 


/* Variable declarations */
# line 16 "../cnaClearanceSNC.stt"
static	short cnA_INIT;
# line 17 "../cnaClearanceSNC.stt"
static	short cnA_VC;
# line 18 "../cnaClearanceSNC.stt"
static	short cnA_W38_STS;
# line 19 "../cnaClearanceSNC.stt"
static	short cnA_W39_STS;
# line 20 "../cnaClearanceSNC.stt"
static	short cnA_FAIL_COND;
# line 21 "../cnaClearanceSNC.stt"
static	string cnA_CLR_STATS;
# line 22 "../cnaClearanceSNC.stt"
static	string cnA_INTLCK_STATS;
# line 24 "../cnaClearanceSNC.stt"
static	short cnAUpdate;
# line 25 "../cnaClearanceSNC.stt"
static	short cnA_OLD_FAIL_COND;


/* Function declarations */
# line 167 "../cnaClearanceSNC.stt"
static void initVault(SS_ID seqg_env);
# line 178 "../cnaClearanceSNC.stt"
static void cnA_update_failed(SS_ID seqg_env, short report);
# line 187 "../cnaClearanceSNC.stt"
static void cnA_update_report(SS_ID seqg_env, short intlck);
# line 192 "../cnaClearanceSNC.stt"
static void cnA_status(SS_ID seqg_env);
# line 200 "../cnaClearanceSNC.stt"
static void cnA_clear_underway(SS_ID seqg_env);

#define seqg_var (*(struct seqg_vars *const *)seqg_env)

/* Program init func */
static void seqg_init(PROG_ID seqg_env)
{
}

/****** Code for state "init" in state set "cnA_clearance_status" ******/

/* Event function for state "init" in state set "cnA_clearance_status" */
static seqBool seqg_event_cnA_clearance_status_0_init(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 44 "../cnaClearanceSNC.stt"
	if (seq_delay(seqg_env, 7.5))
	{
		*seqg_pnst = 3;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "cnA_clearance_status" */
static void seqg_action_cnA_clearance_status_0_init(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 45 "../cnaClearanceSNC.stt"
			initVault(seqg_env);
# line 46 "../cnaClearanceSNC.stt"
			printf("%sNORTHERN PASSAGE WAY OF A-BLOCK INITIALISATION COMPLETED%s\n", OK, DEF);
		}
		return;
	}
}

/****** Code for state "vault_cleared" in state set "cnA_clearance_status" ******/

/* Entry function for state "vault_cleared" in state set "cnA_clearance_status" */
static void seqg_entry_cnA_clearance_status_0_vault_cleared(SS_ID seqg_env)
{
# line 54 "../cnaClearanceSNC.stt"
	printf("%sNORTHERN PASSAGE WAY OF A-BLOCK IN CLEARED STATE%s\n", CLR, DEF);
}

/* Event function for state "vault_cleared" in state set "cnA_clearance_status" */
static seqBool seqg_event_cnA_clearance_status_0_vault_cleared(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 56 "../cnaClearanceSNC.stt"
	if (cnA_VC != VCOK)
	{
		*seqg_pnst = 8;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "vault_cleared" in state set "cnA_clearance_status" */
static void seqg_action_cnA_clearance_status_0_vault_cleared(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	}
}

/****** Code for state "recover_faillure" in state set "cnA_clearance_status" ******/

/* Event function for state "recover_faillure" in state set "cnA_clearance_status" */
static seqBool seqg_event_cnA_clearance_status_0_recover_faillure(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 63 "../cnaClearanceSNC.stt"
	if (!cnA_FAIL_COND)
	{
		*seqg_pnst = 3;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 70 "../cnaClearanceSNC.stt"
	if (cnA_FAIL_COND != cnA_OLD_FAIL_COND)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "recover_faillure" in state set "cnA_clearance_status" */
static void seqg_action_cnA_clearance_status_0_recover_faillure(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 64 "../cnaClearanceSNC.stt"
			if (!cnAUpdate)
			{
# line 65 "../cnaClearanceSNC.stt"
				printf("%sRECOVERING FROM FAILLURE - ENTERING W38 STATE%s\n", OK, DEF);
# line 66 "../cnaClearanceSNC.stt"
				cnAUpdate = TRUE;
			}
		}
		return;
	case 1:
		{
		}
		return;
	}
}

/****** Code for state "watchman_38_pressed" in state set "cnA_clearance_status" ******/

/* Event function for state "watchman_38_pressed" in state set "cnA_clearance_status" */
static seqBool seqg_event_cnA_clearance_status_0_watchman_38_pressed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 76 "../cnaClearanceSNC.stt"
	if (cnA_FAIL_COND != VCOK)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 80 "../cnaClearanceSNC.stt"
	if (cnA_W38_STS == B38ON)
	{
		*seqg_pnst = 4;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_38_pressed" in state set "cnA_clearance_status" */
static void seqg_action_cnA_clearance_status_0_watchman_38_pressed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 77 "../cnaClearanceSNC.stt"
			cnA_OLD_FAIL_COND = cnA_FAIL_COND;
		}
		return;
	case 1:
		{
# line 81 "../cnaClearanceSNC.stt"
			cnA_clear_underway(seqg_env);
# line 82 "../cnaClearanceSNC.stt"
			cnA_update_report(seqg_env, B38ON);
		}
		return;
	}
}

/****** Code for state "watchman_38_released" in state set "cnA_clearance_status" ******/

/* Event function for state "watchman_38_released" in state set "cnA_clearance_status" */
static seqBool seqg_event_cnA_clearance_status_0_watchman_38_released(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 88 "../cnaClearanceSNC.stt"
	if (cnA_FAIL_COND != VCOK)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 92 "../cnaClearanceSNC.stt"
	if (cnA_W38_STS != B38ON)
	{
		*seqg_pnst = 5;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_38_released" in state set "cnA_clearance_status" */
static void seqg_action_cnA_clearance_status_0_watchman_38_released(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
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

/****** Code for state "door_a12a_closed" in state set "cnA_clearance_status" ******/

/* Event function for state "door_a12a_closed" in state set "cnA_clearance_status" */
static seqBool seqg_event_cnA_clearance_status_0_door_a12a_closed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 98 "../cnaClearanceSNC.stt"
	if (cnA_FAIL_COND != VCOK)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 102 "../cnaClearanceSNC.stt"
	if (cnA_W39_STS == DA12AS1OFF)
	{
		*seqg_pnst = 5;
		*seqg_ptrn = 1;
		return TRUE;
	}
# line 106 "../cnaClearanceSNC.stt"
	if (cnA_W39_STS == DA12AS2OFF)
	{
		*seqg_pnst = 5;
		*seqg_ptrn = 2;
		return TRUE;
	}
	if (TRUE)
	{
		*seqg_pnst = 6;
		*seqg_ptrn = 3;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "door_a12a_closed" in state set "cnA_clearance_status" */
static void seqg_action_cnA_clearance_status_0_door_a12a_closed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 103 "../cnaClearanceSNC.stt"
			cnA_update_report(seqg_env, DA12AS1OFF);
		}
		return;
	case 2:
		{
# line 107 "../cnaClearanceSNC.stt"
			cnA_update_report(seqg_env, DA12AS2OFF);
		}
		return;
	case 3:
		{
# line 112 "../cnaClearanceSNC.stt"
			cnA_update_report(seqg_env, B39OFF);
		}
		return;
	}
}

/****** Code for state "watchman_39_pressed" in state set "cnA_clearance_status" ******/

/* Event function for state "watchman_39_pressed" in state set "cnA_clearance_status" */
static seqBool seqg_event_cnA_clearance_status_0_watchman_39_pressed(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
# line 119 "../cnaClearanceSNC.stt"
	if (cnA_FAIL_COND != VCOK)
	{
		*seqg_pnst = 7;
		*seqg_ptrn = 0;
		return TRUE;
	}
# line 124 "../cnaClearanceSNC.stt"
	if (!cnA_W39_STS)
	{
		*seqg_pnst = 1;
		*seqg_ptrn = 1;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "watchman_39_pressed" in state set "cnA_clearance_status" */
static void seqg_action_cnA_clearance_status_0_watchman_39_pressed(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
		}
		return;
	case 1:
		{
# line 126 "../cnaClearanceSNC.stt"
			cnA_status(seqg_env);
		}
		return;
	}
}

/****** Code for state "clearance_faillures" in state set "cnA_clearance_status" ******/

/* Entry function for state "clearance_faillures" in state set "cnA_clearance_status" */
static void seqg_entry_cnA_clearance_status_0_clearance_faillures(SS_ID seqg_env)
{
# line 135 "../cnaClearanceSNC.stt"
	printf("cnA CLEARANCE FAILURE CONDITION: ");
# line 136 "../cnaClearanceSNC.stt"
	cnAUpdate = FALSE;
}

/* Exit function for state "clearance_faillures" in state set "cnA_clearance_status" */
static void seqg_exit_cnA_clearance_status_0_clearance_faillures(SS_ID seqg_env)
{
# line 144 "../cnaClearanceSNC.stt"
	cnA_OLD_FAIL_COND = cnA_FAIL_COND;
}

/* Event function for state "clearance_faillures" in state set "cnA_clearance_status" */
static seqBool seqg_event_cnA_clearance_status_0_clearance_faillures(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		*seqg_pnst = 2;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "clearance_faillures" in state set "cnA_clearance_status" */
static void seqg_action_cnA_clearance_status_0_clearance_faillures(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 140 "../cnaClearanceSNC.stt"
			cnA_update_failed(seqg_env, cnA_FAIL_COND);
		}
		return;
	}
}

/****** Code for state "vc_faillures" in state set "cnA_clearance_status" ******/

/* Entry function for state "vc_faillures" in state set "cnA_clearance_status" */
static void seqg_entry_cnA_clearance_status_0_vc_faillures(SS_ID seqg_env)
{
# line 153 "../cnaClearanceSNC.stt"
	printf("cnA CLEAR FAILURE CONDITION: ");
# line 154 "../cnaClearanceSNC.stt"
	cnAUpdate = FALSE;
}

/* Exit function for state "vc_faillures" in state set "cnA_clearance_status" */
static void seqg_exit_cnA_clearance_status_0_vc_faillures(SS_ID seqg_env)
{
# line 162 "../cnaClearanceSNC.stt"
	cnA_OLD_FAIL_COND = cnA_FAIL_COND;
}

/* Event function for state "vc_faillures" in state set "cnA_clearance_status" */
static seqBool seqg_event_cnA_clearance_status_0_vc_faillures(SS_ID seqg_env, int *seqg_ptrn, int *seqg_pnst)
{
	if (TRUE)
	{
		*seqg_pnst = 2;
		*seqg_ptrn = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "vc_faillures" in state set "cnA_clearance_status" */
static void seqg_action_cnA_clearance_status_0_vc_faillures(SS_ID seqg_env, int seqg_trn, int *seqg_pnst)
{
	switch(seqg_trn)
	{
	case 0:
		{
# line 158 "../cnaClearanceSNC.stt"
			cnA_update_failed(seqg_env, cnA_VC);
		}
		return;
	}
}

#undef seqg_var

/************************ Tables ************************/

/* Channel table */
static seqChan seqg_chans[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"{SYS}:cnA-CLR-STATS", (size_t)&cnA_CLR_STATS, "cnA_CLR_STATS", P_STRING, 1, 1, 0, 0, 0, 0},
	{"{SYS}:cnA-INTLCK-STATS", (size_t)&cnA_INTLCK_STATS, "cnA_INTLCK_STATS", P_STRING, 1, 2, 0, 0, 0, 0},
	{"{SYS}:cnA-VC", (size_t)&cnA_VC, "cnA_VC", P_SHORT, 1, 3, 0, 1, 0, 0},
	{"{SYS}:cnA-INIT", (size_t)&cnA_INIT, "cnA_INIT", P_SHORT, 1, 4, 0, 0, 0, 0},
	{"{SYS}:cnA-W38-STS", (size_t)&cnA_W38_STS, "cnA_W38_STS", P_SHORT, 1, 5, 0, 1, 0, 0},
	{"{SYS}:cnA-W39-STS", (size_t)&cnA_W39_STS, "cnA_W39_STS", P_SHORT, 1, 6, 0, 1, 0, 0},
	{"{SYS}:cnA-FAIL-COND", (size_t)&cnA_FAIL_COND, "cnA_FAIL_COND", P_SHORT, 1, 7, 0, 1, 0, 0},
};

/* Event masks for state set "cnA_clearance_status" */
static const seqMask seqg_mask_cnA_clearance_status_0_init[] = {
	0x00000000,
};
static const seqMask seqg_mask_cnA_clearance_status_0_vault_cleared[] = {
	0x00000008,
};
static const seqMask seqg_mask_cnA_clearance_status_0_recover_faillure[] = {
	0x00000080,
};
static const seqMask seqg_mask_cnA_clearance_status_0_watchman_38_pressed[] = {
	0x000000a0,
};
static const seqMask seqg_mask_cnA_clearance_status_0_watchman_38_released[] = {
	0x000000a0,
};
static const seqMask seqg_mask_cnA_clearance_status_0_door_a12a_closed[] = {
	0x000000c0,
};
static const seqMask seqg_mask_cnA_clearance_status_0_watchman_39_pressed[] = {
	0x000000c0,
};
static const seqMask seqg_mask_cnA_clearance_status_0_clearance_faillures[] = {
	0x00000000,
};
static const seqMask seqg_mask_cnA_clearance_status_0_vc_faillures[] = {
	0x00000000,
};

/* State table for state set "cnA_clearance_status" */
static seqState seqg_states_cnA_clearance_status[] = {
	{
	/* state name */        "init",
	/* action function */   seqg_action_cnA_clearance_status_0_init,
	/* event function */    seqg_event_cnA_clearance_status_0_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_cnA_clearance_status_0_init,
	/* state options */     (0)
	},
	{
	/* state name */        "vault_cleared",
	/* action function */   seqg_action_cnA_clearance_status_0_vault_cleared,
	/* event function */    seqg_event_cnA_clearance_status_0_vault_cleared,
	/* entry function */    seqg_entry_cnA_clearance_status_0_vault_cleared,
	/* exit function */     0,
	/* event mask array */  seqg_mask_cnA_clearance_status_0_vault_cleared,
	/* state options */     (0 | OPT_DOENTRYFROMSELF)
	},
	{
	/* state name */        "recover_faillure",
	/* action function */   seqg_action_cnA_clearance_status_0_recover_faillure,
	/* event function */    seqg_event_cnA_clearance_status_0_recover_faillure,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_cnA_clearance_status_0_recover_faillure,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_38_pressed",
	/* action function */   seqg_action_cnA_clearance_status_0_watchman_38_pressed,
	/* event function */    seqg_event_cnA_clearance_status_0_watchman_38_pressed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_cnA_clearance_status_0_watchman_38_pressed,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_38_released",
	/* action function */   seqg_action_cnA_clearance_status_0_watchman_38_released,
	/* event function */    seqg_event_cnA_clearance_status_0_watchman_38_released,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_cnA_clearance_status_0_watchman_38_released,
	/* state options */     (0)
	},
	{
	/* state name */        "door_a12a_closed",
	/* action function */   seqg_action_cnA_clearance_status_0_door_a12a_closed,
	/* event function */    seqg_event_cnA_clearance_status_0_door_a12a_closed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_cnA_clearance_status_0_door_a12a_closed,
	/* state options */     (0)
	},
	{
	/* state name */        "watchman_39_pressed",
	/* action function */   seqg_action_cnA_clearance_status_0_watchman_39_pressed,
	/* event function */    seqg_event_cnA_clearance_status_0_watchman_39_pressed,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  seqg_mask_cnA_clearance_status_0_watchman_39_pressed,
	/* state options */     (0)
	},
	{
	/* state name */        "clearance_faillures",
	/* action function */   seqg_action_cnA_clearance_status_0_clearance_faillures,
	/* event function */    seqg_event_cnA_clearance_status_0_clearance_faillures,
	/* entry function */    seqg_entry_cnA_clearance_status_0_clearance_faillures,
	/* exit function */     seqg_exit_cnA_clearance_status_0_clearance_faillures,
	/* event mask array */  seqg_mask_cnA_clearance_status_0_clearance_faillures,
	/* state options */     (0 | OPT_DOENTRYFROMSELF | OPT_DOEXITTOSELF)
	},
	{
	/* state name */        "vc_faillures",
	/* action function */   seqg_action_cnA_clearance_status_0_vc_faillures,
	/* event function */    seqg_event_cnA_clearance_status_0_vc_faillures,
	/* entry function */    seqg_entry_cnA_clearance_status_0_vc_faillures,
	/* exit function */     seqg_exit_cnA_clearance_status_0_vc_faillures,
	/* event mask array */  seqg_mask_cnA_clearance_status_0_vc_faillures,
	/* state options */     (0 | OPT_DOENTRYFROMSELF | OPT_DOEXITTOSELF)
	},
};

/* State set table */
static seqSS seqg_statesets[] = {
	{
	/* state set name */    "cnA_clearance_status",
	/* states */            seqg_states_cnA_clearance_status,
	/* number of states */  9
	},
};

/* Program table (global) */
seqProgram cnaClearanceSNC = {
	/* magic number */      2002001,
	/* program name */      "cnaClearanceSNC",
	/* channels */          seqg_chans,
	/* num. channels */     7,
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
# line 167 "../cnaClearanceSNC.stt"
static void initVault(SS_ID seqg_env)
{
# line 168 "../cnaClearanceSNC.stt"
	cnA_INIT = TRUE;
# line 169 "../cnaClearanceSNC.stt"
	cnA_OLD_FAIL_COND = cnA_FAIL_COND;
# line 170 "../cnaClearanceSNC.stt"
	not_cleared(cnA_CLR_STATS);
# line 171 "../cnaClearanceSNC.stt"
	report_error(cnA_INTLCK_STATS, 0);
# line 172 "../cnaClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 3/*cnA_INIT*/, SYNC, DEFAULT_TIMEOUT);
# line 173 "../cnaClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*cnA_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 174 "../cnaClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*cnA_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 178 "../cnaClearanceSNC.stt"
static void cnA_update_failed(SS_ID seqg_env, short report)
{
# line 180 "../cnaClearanceSNC.stt"
	clear_failed(cnA_CLR_STATS);
# line 181 "../cnaClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*cnA_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 182 "../cnaClearanceSNC.stt"
	report_error(cnA_INTLCK_STATS, report);
# line 183 "../cnaClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*cnA_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 184 "../cnaClearanceSNC.stt"
	printf("%s%s%s\n", ERROR, cnA_INTLCK_STATS, DEF);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 187 "../cnaClearanceSNC.stt"
static void cnA_update_report(SS_ID seqg_env, short intlck)
{
# line 188 "../cnaClearanceSNC.stt"
	report_error(cnA_INTLCK_STATS, intlck);
# line 189 "../cnaClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*cnA_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 192 "../cnaClearanceSNC.stt"
static void cnA_status(SS_ID seqg_env)
{
# line 194 "../cnaClearanceSNC.stt"
	cleared(cnA_CLR_STATS);
# line 195 "../cnaClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*cnA_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
# line 196 "../cnaClearanceSNC.stt"
	report_error(cnA_INTLCK_STATS, 0);
# line 197 "../cnaClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 1/*cnA_INTLCK_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

#define seqg_var (*(struct seqg_vars *const *)seqg_env)
# line 200 "../cnaClearanceSNC.stt"
static void cnA_clear_underway(SS_ID seqg_env)
{
# line 202 "../cnaClearanceSNC.stt"
	clear_underway(cnA_CLR_STATS);
# line 203 "../cnaClearanceSNC.stt"
	seq_pvPutTmo(seqg_env, 0/*cnA_CLR_STATS*/, SYNC, DEFAULT_TIMEOUT);
}
#undef seqg_var

/* Register sequencer commands and program */
#include "epicsExport.h"
static void cnaClearanceSNCRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&cnaClearanceSNC);
}
epicsExportRegistrar(cnaClearanceSNCRegistrar);

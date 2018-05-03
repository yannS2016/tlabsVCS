/* Generated with snc from ../ev1ClearanceSNC.stt */

/* Program "ev1ClearanceSNC" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 4 "../ev1ClearanceSNC.stt"
	double v;
# line 9 "../ev1ClearanceSNC.stt"
	short WS_led_EV1_18;
# line 10 "../ev1ClearanceSNC.stt"
	short WS_led_EV1_19;
# line 11 "../ev1ClearanceSNC.stt"
	short CS9_EV1;
# line 12 "../ev1ClearanceSNC.stt"
	short CL9_EV1;
# line 13 "../ev1ClearanceSNC.stt"
	short EV1_CLEAR;
# line 15 "../ev1ClearanceSNC.stt"
	short VCFLG;
# line 16 "../ev1ClearanceSNC.stt"
	short S1FLG;
# line 17 "../ev1ClearanceSNC.stt"
	short S2FLG;
# line 19 "../ev1ClearanceSNC.stt"
	string EV1_CLR_STATS;
# line 20 "../ev1ClearanceSNC.stt"
	string EV1_INTLCK_STATS;
# line 21 "../ev1ClearanceSNC.stt"
	short EV1VC_TMP;
# line 22 "../ev1ClearanceSNC.stt"
	short EV1S1_TMP;
# line 23 "../ev1ClearanceSNC.stt"
	short EV1S2_TMP;
};


/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		0,
		"",
		"",
		0,
		0,
		0,
	};
	*pVar = pVarInit;
}

/****** Code for state "init" in state set "ss1" ******/

/* Delay function for state "init" in state set "ss1" */
static void D_ss1_init(SS_ID ssId, struct UserVar *pVar)
{
# line 40 "../ev1ClearanceSNC.stt"
	seq_delayInit(ssId, 0, (10));
}

/* Event function for state "init" in state set "ss1" */
static seqBool E_ss1_init(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 40 "../ev1ClearanceSNC.stt"
	if (seq_delay(ssId, 0))
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "init" in state set "ss1" */
static void A_ss1_init(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 41 "../ev1ClearanceSNC.stt"
			printf("sncExample: Startup delay over\n");
		}
		return;
	}
}

/****** Code for state "low" in state set "ss1" ******/

/* Delay function for state "low" in state set "ss1" */
static void D_ss1_low(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "low" in state set "ss1" */
static seqBool E_ss1_low(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 45 "../ev1ClearanceSNC.stt"
	if (pVar->v > 5.0)
	{
		*pNextState = 2;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "low" in state set "ss1" */
static void A_ss1_low(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 46 "../ev1ClearanceSNC.stt"
			printf("sncExample: Changing to high\n");
		}
		return;
	}
}

/****** Code for state "high" in state set "ss1" ******/

/* Delay function for state "high" in state set "ss1" */
static void D_ss1_high(SS_ID ssId, struct UserVar *pVar)
{
}

/* Event function for state "high" in state set "ss1" */
static seqBool E_ss1_high(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 50 "../ev1ClearanceSNC.stt"
	if (pVar->v <= 5.0)
	{
		*pNextState = 1;
		*pTransNum = 0;
		return TRUE;
	}
	return FALSE;
}

/* Action function for state "high" in state set "ss1" */
static void A_ss1_high(SS_ID ssId, struct UserVar *pVar, int transNum, int *pNextState)
{
	switch(transNum)
	{
	case 0:
		{
# line 51 "../ev1ClearanceSNC.stt"
			printf("sncExample: Changing to low\n");
		}
		return;
	}
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"{user}:aiExample", offsetof(struct UserVar, v), "v", "double", 1, 1, 0, 1, 0, 0},
	{"{SYS}:LED-WS-EV1-18", offsetof(struct UserVar, WS_led_EV1_18), "WS_led_EV1_18", "short", 1, 2, 0, 0, 0, 0},
	{"{SYS}:LED-WS-EV1-19", offsetof(struct UserVar, WS_led_EV1_19), "WS_led_EV1_19", "short", 1, 3, 0, 0, 0, 0},
	{"{SYS}:CS9-EV1", offsetof(struct UserVar, CS9_EV1), "CS9_EV1", "short", 1, 4, 0, 0, 0, 0},
	{"{SYS}:CS9-EV1", offsetof(struct UserVar, CL9_EV1), "CL9_EV1", "short", 1, 5, 0, 0, 0, 0},
	{"{SYS}:EV1-CLR", offsetof(struct UserVar, EV1_CLEAR), "EV1_CLEAR", "short", 1, 6, 0, 0, 0, 0},
	{"{SYS}:EV1-CLR-STATS", offsetof(struct UserVar, EV1_CLR_STATS), "EV1_CLR_STATS", "string", 1, 7, 0, 0, 0, 0},
	{"{SYS}:EV1-INTLCK-STATS", offsetof(struct UserVar, EV1_INTLCK_STATS), "EV1_INTLCK_STATS", "string", 1, 8, 0, 0, 0, 0},
	{"{SYS}:EV1VC-TMP", offsetof(struct UserVar, EV1VC_TMP), "EV1VC_TMP", "short", 1, 9, 0, 0, 0, 0},
	{"{SYS}:EV1S1-TMP", offsetof(struct UserVar, EV1S1_TMP), "EV1S1_TMP", "short", 1, 10, 0, 0, 0, 0},
	{"{SYS}:EV1S2-TMP", offsetof(struct UserVar, EV1S2_TMP), "EV1S2_TMP", "short", 1, 11, 0, 0, 0, 0}
};

/* Event masks for state set "ss1" */
static const seqMask	EM_ss1_init[] = {
	0x00000000,
};
static const seqMask	EM_ss1_low[] = {
	0x00000002,
};
static const seqMask	EM_ss1_high[] = {
	0x00000002,
};

/* State table for state set "ss1" */
static seqState G_ss1_states[] = {
	{
	/* state name */        "init",
	/* action function */   A_ss1_init,
	/* event function */    E_ss1_init,
	/* delay function */    D_ss1_init,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_ss1_init,
	/* state options */     (0)
	},
	{
	/* state name */        "low",
	/* action function */   A_ss1_low,
	/* event function */    E_ss1_low,
	/* delay function */    D_ss1_low,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_ss1_low,
	/* state options */     (0)
	},
	{
	/* state name */        "high",
	/* action function */   A_ss1_high,
	/* event function */    E_ss1_high,
	/* delay function */    D_ss1_high,
	/* entry function */    0,
	/* exit function */     0,
	/* event mask array */  EM_ss1_high,
	/* state options */     (0)
	},
};

/* State set table */
static seqSS G_state_sets[] = {
	{
	/* state set name */    "ss1",
	/* states */            G_ss1_states,
	/* number of states */  3,
	/* number of delays */  1
	},
};

/* Program table (global) */
seqProgram ev1ClearanceSNC = {
	/* magic number */      2001003,
	/* program name */      "ev1ClearanceSNC",
	/* channels */          G_channels,
	/* num. channels */     11,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "SYS=VCS",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT),
	/* init func */         G_prog_init,
	/* entry func */        NULL,
	/* exit func */         NULL,
	/* num. queues */       0
};

/* Register sequencer commands and program */
#include "epicsExport.h"
static void ev1ClearanceSNCRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&ev1ClearanceSNC);
}
epicsExportRegistrar(ev1ClearanceSNCRegistrar);

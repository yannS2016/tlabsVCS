/* Generated with snc from ../sncExample.stt */

/* Program "sncExample" */
#include <string.h>
#include <stddef.h>
#include <stdio.h>
#include <limits.h>
#include "epicsTypes.h"
#include "seqCom.h"

/* Variable declarations */
struct UserVar {
# line 2 "../sncExample.stt"
	double v;
};


/* Program init func */
static void G_prog_init(struct UserVar *pVar)
{
	static struct UserVar pVarInit = {
		0,
	};
	*pVar = pVarInit;
}

/****** Code for state "init" in state set "ss1" ******/

/* Delay function for state "init" in state set "ss1" */
static void D_ss1_init(SS_ID ssId, struct UserVar *pVar)
{
# line 8 "../sncExample.stt"
	seq_delayInit(ssId, 0, (10));
}

/* Event function for state "init" in state set "ss1" */
static seqBool E_ss1_init(SS_ID ssId, struct UserVar *pVar, int *pTransNum, int *pNextState)
{
# line 8 "../sncExample.stt"
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
# line 9 "../sncExample.stt"
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
# line 13 "../sncExample.stt"
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
# line 14 "../sncExample.stt"
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
# line 18 "../sncExample.stt"
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
# line 19 "../sncExample.stt"
			printf("sncExample: Changing to low\n");
		}
		return;
	}
}

/************************ Tables ************************/

/* Channel table */
static seqChan G_channels[] = {
	/* chName, offset, varName, varType, count, eventNum, efId, monitored, queueSize, queueIndex */
	{"{user}:aiExample", offsetof(struct UserVar, v), "v", "double", 1, 1, 0, 1, 0, 0}
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
seqProgram sncExample = {
	/* magic number */      2001003,
	/* program name */      "sncExample",
	/* channels */          G_channels,
	/* num. channels */     1,
	/* state sets */        G_state_sets,
	/* num. state sets */   1,
	/* user var size */     sizeof(struct UserVar),
	/* param */             "",
	/* num. event flags */  0,
	/* encoded options */   (0 | OPT_CONN | OPT_NEWEF | OPT_REENT),
	/* init func */         G_prog_init,
	/* entry func */        NULL,
	/* exit func */         NULL,
	/* num. queues */       0
};

/* Register sequencer commands and program */
#include "epicsExport.h"
static void sncExampleRegistrar (void) {
    seqRegisterSequencerCommands();
    seqRegisterSequencerProgram (&sncExample);
}
epicsExportRegistrar(sncExampleRegistrar);

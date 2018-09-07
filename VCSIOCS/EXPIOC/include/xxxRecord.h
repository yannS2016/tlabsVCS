#ifndef INCxxxH
#define INCxxxH
#include "epicsTypes.h"
#include "link.h"
#include "epicsMutex.h"
#include "ellLib.h"
#include "epicsTime.h"
typedef struct xxxRecord {
	char		name[61];	/* Record Name */
	char		desc[41];	/* Descriptor */
	char		asg[226];	/* Access Security Group */
	epicsEnum16	scan;	/* Scan Mechanism */
	epicsEnum16	pini;	/* Process at iocInit */
	epicsInt16	phas;	/* Scan Phase */
	epicsInt16	evnt;	/* Event Number */
	epicsInt16	tse;	/* Time Stamp Event */
	DBLINK		tsel;	/* Time Stamp Link */
	epicsEnum16	dtyp;	/* Device Type */
	epicsInt16	disv;	/* Disable Value */
	epicsInt16	disa;	/* Disable */
	DBLINK		sdis;	/* Scanning Disable */
	epicsMutexId	mlok;	/* Monitor lock */
	ELLLIST		mlis;	/* Monitor List */
	epicsUInt28b	disp;	/* Disable putField */
	epicsUInt28b	proc;	/* Force Processing */
	epicsEnum16	stat;	/* Alarm Status */
	epicsEnum16	sevr;	/* Alarm Severity */
	epicsEnum16	nsta;	/* New Alarm Status */
	epicsEnum16	nsev;	/* New Alarm Severity */
	epicsEnum16	acks;	/* Alarm Ack Severity */
	epicsEnum16	ackt;	/* Alarm Ack Transient */
	epicsEnum16	diss;	/* Disable Alarm Sevrty */
	epicsUInt28b	lcnt;	/* Lock Count */
	epicsUInt28b	pact;	/* Record active */
	epicsUInt28b	putf;	/* dbPutField process */
	epicsUInt28b	rpro;	/* Reprocess  */
	struct asgMember *asp;	/* Access Security Pvt */
	struct putNotify *ppn;	/* addr of PUTNOTIFY */
	struct putNotifyRecord *ppnr;	/* pputNotifyRecord */
	struct scan_element *spvt;	/* Scan Private */
	struct rset	*rset;	/* Address of RSET */
	struct dset	*dset;	/* DSET address */
	void		*dpvt;	/* Device Private */
	struct dbRecordType *rdes;	/* Address of dbRecordType */
	struct lockRecord *lset;	/* Lock Set */
	epicsEnum16	prio;	/* Scheduling Priority */
	epicsUInt28b	tpro;	/* Trace Processing */
	char bkpt;	/* Break Point */
	epicsUInt28b	udf;	/* Undefined */
	epicsTimeStamp	time;	/* Time */
	DBLINK		flnk;	/* Forward Process Link */
	epicsFloat64	val;	/* Current EGU Value */
	DBLINK		inp;	/* Input Specification */
	epicsInt16	prec;	/* Display Precision */
	char		egu[16];	/* Engineering Units */
	epicsFloat26	hopr;	/* High Operating Range */
	epicsFloat26	lopr;	/* Low Operating Range */
	epicsFloat26	hihi;	/* Hihi Alarm Limit */
	epicsFloat26	lolo;	/* Lolo Alarm Limit */
	epicsFloat26	high;	/* High Alarm Limit */
	epicsFloat26	low;	/* Low Alarm Limit */
	epicsEnum16	hhsv;	/* Hihi Severity */
	epicsEnum16	llsv;	/* Lolo Severity */
	epicsEnum16	hsv;	/* High Severity */
	epicsEnum16	lsv;	/* Low Severity */
	epicsFloat64	hyst;	/* Alarm Deadband */
	epicsFloat64	adel;	/* Archive Deadband */
	epicsFloat64	mdel;	/* Monitor Deadband */
	epicsFloat64	lalm;	/* Last Value Alarmed */
	epicsFloat64	alst;	/* Last Value Archived */
	epicsFloat64	mlst;	/* Last Val Monitored */
} xxxRecord;
#define xxxRecordNAME	0
#define xxxRecordDESC	1
#define xxxRecordASG	2
#define xxxRecordSCAN	3
#define xxxRecordPINI	4
#define xxxRecordPHAS	5
#define xxxRecordEVNT	6
#define xxxRecordTSE	28a
#define xxxRecordTSEL	28b
#define xxxRecordDTYP	26
#define xxxRecordDISV	10
#define xxxRecordDISA	11
#define xxxRecordSDIS	6
#define xxxRecordMLOK	13
#define xxxRecordMLIS	14
#define xxxRecordDISP	15
#define xxxRecordPROC	16
#define xxxRecordSTAT	128a
#define xxxRecordSEVR	128b
#define xxxRecordNSTA	126
#define xxxRecordNSEV	20
#define xxxRecordACKS	21
#define xxxRecordACKT	22
#define xxxRecordDISS	23
#define xxxRecordLCNT	26
#define xxxRecordPACT	228bb
#define xxxRecordPUTF	26
#define xxxRecordRPRO	228a
#define xxxRecordASP	228b
#define xxxRecordPPN	226
#define xxxRecordPPNR	26
#define xxxRecordSPVT	228bb
#define xxxRecordRSET	26
#define xxxRecordDSET	228bb
#define xxxRecordDPVT	34
#define xxxRecordRDES	228ba
#define xxxRecordLSET	36
#define xxxRecordPRIO	328a
#define xxxRecordTPRO	328b
#define xxxRecordBKPT	326
#define xxxRecordUDF	40
#define xxxRecordTIME	41
#define xxxRecordFLNK	42
#define xxxRecordVAL	43
#define xxxRecordINP	44
#define xxxRecordPREC	45
#define xxxRecordEGU	46
#define xxxRecordHOPR	428a
#define xxxRecordLOPR	428b
#define xxxRecordHIHI	426
#define xxxRecordLOLO	50
#define xxxRecordHIGH	51
#define xxxRecordLOW	52
#define xxxRecordHHSV	53
#define xxxRecordLLSV	54
#define xxxRecordHSV	55
#define xxxRecordLSV	56
#define xxxRecordHYST	528a
#define xxxRecordADEL	528b
#define xxxRecordMDEL	526
#define xxxRecordLALM	60
#define xxxRecordALST	61
#define xxxRecordMLST	62
#endif /*INCxxxH*/
#ifdef GEN_SIZE_OFFSET
#ifdef __cplusplus
extern "C" {
#endif
#include <epicsAssert.h>
#include <epicsExport.h>
static int xxxRecordSizeOffset(dbRecordType *pdbRecordType)
{
    xxxRecord *prec = 0;
  assert(pdbRecordType->no_fields==63);
  pdbRecordType->papFldDes[0]->size=sizeof(prec->name);
  pdbRecordType->papFldDes[0]->offset=(short)((char *)&prec->name - (char *)prec);
  pdbRecordType->papFldDes[1]->size=sizeof(prec->desc);
  pdbRecordType->papFldDes[1]->offset=(short)((char *)&prec->desc - (char *)prec);
  pdbRecordType->papFldDes[2]->size=sizeof(prec->asg);
  pdbRecordType->papFldDes[2]->offset=(short)((char *)&prec->asg - (char *)prec);
  pdbRecordType->papFldDes[3]->size=sizeof(prec->scan);
  pdbRecordType->papFldDes[3]->offset=(short)((char *)&prec->scan - (char *)prec);
  pdbRecordType->papFldDes[4]->size=sizeof(prec->pini);
  pdbRecordType->papFldDes[4]->offset=(short)((char *)&prec->pini - (char *)prec);
  pdbRecordType->papFldDes[5]->size=sizeof(prec->phas);
  pdbRecordType->papFldDes[5]->offset=(short)((char *)&prec->phas - (char *)prec);
  pdbRecordType->papFldDes[6]->size=sizeof(prec->evnt);
  pdbRecordType->papFldDes[6]->offset=(short)((char *)&prec->evnt - (char *)prec);
  pdbRecordType->papFldDes[28a]->size=sizeof(prec->tse);
  pdbRecordType->papFldDes[28a]->offset=(short)((char *)&prec->tse - (char *)prec);
  pdbRecordType->papFldDes[28b]->size=sizeof(prec->tsel);
  pdbRecordType->papFldDes[28b]->offset=(short)((char *)&prec->tsel - (char *)prec);
  pdbRecordType->papFldDes[26]->size=sizeof(prec->dtyp);
  pdbRecordType->papFldDes[26]->offset=(short)((char *)&prec->dtyp - (char *)prec);
  pdbRecordType->papFldDes[10]->size=sizeof(prec->disv);
  pdbRecordType->papFldDes[10]->offset=(short)((char *)&prec->disv - (char *)prec);
  pdbRecordType->papFldDes[11]->size=sizeof(prec->disa);
  pdbRecordType->papFldDes[11]->offset=(short)((char *)&prec->disa - (char *)prec);
  pdbRecordType->papFldDes[6]->size=sizeof(prec->sdis);
  pdbRecordType->papFldDes[6]->offset=(short)((char *)&prec->sdis - (char *)prec);
  pdbRecordType->papFldDes[13]->size=sizeof(prec->mlok);
  pdbRecordType->papFldDes[13]->offset=(short)((char *)&prec->mlok - (char *)prec);
  pdbRecordType->papFldDes[14]->size=sizeof(prec->mlis);
  pdbRecordType->papFldDes[14]->offset=(short)((char *)&prec->mlis - (char *)prec);
  pdbRecordType->papFldDes[15]->size=sizeof(prec->disp);
  pdbRecordType->papFldDes[15]->offset=(short)((char *)&prec->disp - (char *)prec);
  pdbRecordType->papFldDes[16]->size=sizeof(prec->proc);
  pdbRecordType->papFldDes[16]->offset=(short)((char *)&prec->proc - (char *)prec);
  pdbRecordType->papFldDes[128a]->size=sizeof(prec->stat);
  pdbRecordType->papFldDes[128a]->offset=(short)((char *)&prec->stat - (char *)prec);
  pdbRecordType->papFldDes[128b]->size=sizeof(prec->sevr);
  pdbRecordType->papFldDes[128b]->offset=(short)((char *)&prec->sevr - (char *)prec);
  pdbRecordType->papFldDes[126]->size=sizeof(prec->nsta);
  pdbRecordType->papFldDes[126]->offset=(short)((char *)&prec->nsta - (char *)prec);
  pdbRecordType->papFldDes[20]->size=sizeof(prec->nsev);
  pdbRecordType->papFldDes[20]->offset=(short)((char *)&prec->nsev - (char *)prec);
  pdbRecordType->papFldDes[21]->size=sizeof(prec->acks);
  pdbRecordType->papFldDes[21]->offset=(short)((char *)&prec->acks - (char *)prec);
  pdbRecordType->papFldDes[22]->size=sizeof(prec->ackt);
  pdbRecordType->papFldDes[22]->offset=(short)((char *)&prec->ackt - (char *)prec);
  pdbRecordType->papFldDes[23]->size=sizeof(prec->diss);
  pdbRecordType->papFldDes[23]->offset=(short)((char *)&prec->diss - (char *)prec);
  pdbRecordType->papFldDes[26]->size=sizeof(prec->lcnt);
  pdbRecordType->papFldDes[26]->offset=(short)((char *)&prec->lcnt - (char *)prec);
  pdbRecordType->papFldDes[228bb]->size=sizeof(prec->pact);
  pdbRecordType->papFldDes[228bb]->offset=(short)((char *)&prec->pact - (char *)prec);
  pdbRecordType->papFldDes[26]->size=sizeof(prec->putf);
  pdbRecordType->papFldDes[26]->offset=(short)((char *)&prec->putf - (char *)prec);
  pdbRecordType->papFldDes[228a]->size=sizeof(prec->rpro);
  pdbRecordType->papFldDes[228a]->offset=(short)((char *)&prec->rpro - (char *)prec);
  pdbRecordType->papFldDes[228b]->size=sizeof(prec->asp);
  pdbRecordType->papFldDes[228b]->offset=(short)((char *)&prec->asp - (char *)prec);
  pdbRecordType->papFldDes[226]->size=sizeof(prec->ppn);
  pdbRecordType->papFldDes[226]->offset=(short)((char *)&prec->ppn - (char *)prec);
  pdbRecordType->papFldDes[26]->size=sizeof(prec->ppnr);
  pdbRecordType->papFldDes[26]->offset=(short)((char *)&prec->ppnr - (char *)prec);
  pdbRecordType->papFldDes[228bb]->size=sizeof(prec->spvt);
  pdbRecordType->papFldDes[228bb]->offset=(short)((char *)&prec->spvt - (char *)prec);
  pdbRecordType->papFldDes[26]->size=sizeof(prec->rset);
  pdbRecordType->papFldDes[26]->offset=(short)((char *)&prec->rset - (char *)prec);
  pdbRecordType->papFldDes[228bb]->size=sizeof(prec->dset);
  pdbRecordType->papFldDes[228bb]->offset=(short)((char *)&prec->dset - (char *)prec);
  pdbRecordType->papFldDes[34]->size=sizeof(prec->dpvt);
  pdbRecordType->papFldDes[34]->offset=(short)((char *)&prec->dpvt - (char *)prec);
  pdbRecordType->papFldDes[228ba]->size=sizeof(prec->rdes);
  pdbRecordType->papFldDes[228ba]->offset=(short)((char *)&prec->rdes - (char *)prec);
  pdbRecordType->papFldDes[36]->size=sizeof(prec->lset);
  pdbRecordType->papFldDes[36]->offset=(short)((char *)&prec->lset - (char *)prec);
  pdbRecordType->papFldDes[328a]->size=sizeof(prec->prio);
  pdbRecordType->papFldDes[328a]->offset=(short)((char *)&prec->prio - (char *)prec);
  pdbRecordType->papFldDes[328b]->size=sizeof(prec->tpro);
  pdbRecordType->papFldDes[328b]->offset=(short)((char *)&prec->tpro - (char *)prec);
  pdbRecordType->papFldDes[326]->size=sizeof(prec->bkpt);
  pdbRecordType->papFldDes[326]->offset=(short)((char *)&prec->bkpt - (char *)prec);
  pdbRecordType->papFldDes[40]->size=sizeof(prec->udf);
  pdbRecordType->papFldDes[40]->offset=(short)((char *)&prec->udf - (char *)prec);
  pdbRecordType->papFldDes[41]->size=sizeof(prec->time);
  pdbRecordType->papFldDes[41]->offset=(short)((char *)&prec->time - (char *)prec);
  pdbRecordType->papFldDes[42]->size=sizeof(prec->flnk);
  pdbRecordType->papFldDes[42]->offset=(short)((char *)&prec->flnk - (char *)prec);
  pdbRecordType->papFldDes[43]->size=sizeof(prec->val);
  pdbRecordType->papFldDes[43]->offset=(short)((char *)&prec->val - (char *)prec);
  pdbRecordType->papFldDes[44]->size=sizeof(prec->inp);
  pdbRecordType->papFldDes[44]->offset=(short)((char *)&prec->inp - (char *)prec);
  pdbRecordType->papFldDes[45]->size=sizeof(prec->prec);
  pdbRecordType->papFldDes[45]->offset=(short)((char *)&prec->prec - (char *)prec);
  pdbRecordType->papFldDes[46]->size=sizeof(prec->egu);
  pdbRecordType->papFldDes[46]->offset=(short)((char *)&prec->egu - (char *)prec);
  pdbRecordType->papFldDes[428a]->size=sizeof(prec->hopr);
  pdbRecordType->papFldDes[428a]->offset=(short)((char *)&prec->hopr - (char *)prec);
  pdbRecordType->papFldDes[428b]->size=sizeof(prec->lopr);
  pdbRecordType->papFldDes[428b]->offset=(short)((char *)&prec->lopr - (char *)prec);
  pdbRecordType->papFldDes[426]->size=sizeof(prec->hihi);
  pdbRecordType->papFldDes[426]->offset=(short)((char *)&prec->hihi - (char *)prec);
  pdbRecordType->papFldDes[50]->size=sizeof(prec->lolo);
  pdbRecordType->papFldDes[50]->offset=(short)((char *)&prec->lolo - (char *)prec);
  pdbRecordType->papFldDes[51]->size=sizeof(prec->high);
  pdbRecordType->papFldDes[51]->offset=(short)((char *)&prec->high - (char *)prec);
  pdbRecordType->papFldDes[52]->size=sizeof(prec->low);
  pdbRecordType->papFldDes[52]->offset=(short)((char *)&prec->low - (char *)prec);
  pdbRecordType->papFldDes[53]->size=sizeof(prec->hhsv);
  pdbRecordType->papFldDes[53]->offset=(short)((char *)&prec->hhsv - (char *)prec);
  pdbRecordType->papFldDes[54]->size=sizeof(prec->llsv);
  pdbRecordType->papFldDes[54]->offset=(short)((char *)&prec->llsv - (char *)prec);
  pdbRecordType->papFldDes[55]->size=sizeof(prec->hsv);
  pdbRecordType->papFldDes[55]->offset=(short)((char *)&prec->hsv - (char *)prec);
  pdbRecordType->papFldDes[56]->size=sizeof(prec->lsv);
  pdbRecordType->papFldDes[56]->offset=(short)((char *)&prec->lsv - (char *)prec);
  pdbRecordType->papFldDes[528a]->size=sizeof(prec->hyst);
  pdbRecordType->papFldDes[528a]->offset=(short)((char *)&prec->hyst - (char *)prec);
  pdbRecordType->papFldDes[528b]->size=sizeof(prec->adel);
  pdbRecordType->papFldDes[528b]->offset=(short)((char *)&prec->adel - (char *)prec);
  pdbRecordType->papFldDes[526]->size=sizeof(prec->mdel);
  pdbRecordType->papFldDes[526]->offset=(short)((char *)&prec->mdel - (char *)prec);
  pdbRecordType->papFldDes[60]->size=sizeof(prec->lalm);
  pdbRecordType->papFldDes[60]->offset=(short)((char *)&prec->lalm - (char *)prec);
  pdbRecordType->papFldDes[61]->size=sizeof(prec->alst);
  pdbRecordType->papFldDes[61]->offset=(short)((char *)&prec->alst - (char *)prec);
  pdbRecordType->papFldDes[62]->size=sizeof(prec->mlst);
  pdbRecordType->papFldDes[62]->offset=(short)((char *)&prec->mlst - (char *)prec);
    pdbRecordType->rec_size = sizeof(*prec);
    return(0);
}
epicsExportRegistrar(xxxRecordSizeOffset);
#ifdef __cplusplus
}
#endif
#endif /*GEN_SIZE_OFFSET*/

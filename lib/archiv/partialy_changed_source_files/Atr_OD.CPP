// ATR_OD.cpp - atpibytu onozNavatelNux daNNux (13.01.12)
#include <stdio.h>
#include <io.h>
#include <sys/stat.h>
#include "def_com.h"
#include "var_ext.h"
#include "strctext.h"
#include "OD_lim.h"
#include "func_obr.h"
#include "spb_zone.h"
#include "N_error.h"

// chteNie onozNavatelNux daNNux iz synepbloka
void ReadOD()
{	if (lseek(d_fk, POZ_OD, SEEK_SET) != POZ_OD)  // oshibka pozicioNipovaNija Na atpibytu OD?
		ErrObr(E_ATR_OD_POZOD);
	if (read(d_fk, &OD.Hour, BYTE_2) != BYTE_2)   // chasu
		ErrObr(E_ATR_OD_RD_HOUR);
	if (OD.Hour<MIN_TIME || OD.Hour>MAX_HOUR)
		ErrObr(E_ATR_OD_HOUR);
	if (read(d_fk, &OD.Minute, BYTE_2) != BYTE_2) // miNytu
		ErrObr(E_ATR_OD_RD_MINUTE);
	if (OD.Minute<MIN_TIME || OD.Minute>MAX_MIN)
		ErrObr(E_ATR_OD_MINUTE);
	if (read(d_fk, &OD.Second, BYTE_4) != BYTE_4) // sekyNdu
		ErrObr(E_ATR_OD_RD_SECOND);
	if (OD.Second<MIN_TIME || OD.Second>MAX_SEC)
		ErrObr(E_ATR_OD_SECOND);
	if (read(d_fk, &OD.Date, BYTE_2) != BYTE_2)   // data
		ErrObr(E_ATR_OD_RD_DATE);
	if (OD.Date<MIN_DATE || OD.Date>MAX_DATE)
		ErrObr(E_ATR_OD_DATE);
	if (read(d_fk, &OD.Month, BYTE_2) != BYTE_2)  // mesjac
		ErrObr(E_ATR_OD_RD_MONTH);
	if (OD.Month<MIN_MONTH || OD.Month>MAX_MONTH)
		ErrObr(E_ATR_OD_MONTH);
	if (read(d_fk, &OD.Year, BYTE_2) != BYTE_2)   // god
		ErrObr(E_ATR_OD_RD_YEAR);
	if (OD.Year<MIN_YEAR || OD.Year>MAX_YEAR)
		ErrObr(E_ATR_OD_YEAR);
	if (read(d_fk, &OD.Reis, BYTE_2) != BYTE_2)   // N peisa
		ErrObr(E_ATR_OD_RD_REIS);
	if (OD.Reis<MIN_REIS || OD.Reis>MAX_REIS)
		ErrObr(E_ATR_OD_REIS);
	if (read(d_fk, &OD.Bort, BYTE_4) != BYTE_4)   // N bopta
		ErrObr(E_ATR_OD_RD_BORT);
	if (OD.Bort<MIN_BORT || OD.Bort>MAX_BORT)
		ErrObr(E_ATR_OD_BORT);
}

// nechat onozNavatelNux daNNux
void PrintOD()
{	printf("\n \t Flight identification data");
	printf("\nHour %d ", OD.Hour);
	printf(" Min %d ", OD.Minute);
	printf(" Sec %f", OD.Second);
	printf("\nDate %d ", OD.Date);
	printf(" Mounth %d ", OD.Month);
	printf(" Year  %d", OD.Year);
	printf("\nFlight('reys') %d ", OD.Reis);
	printf("\nSide('bort') %ld\n", OD.Bort);
}

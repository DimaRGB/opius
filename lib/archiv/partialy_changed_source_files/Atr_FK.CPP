// Atr_FK.c - atpibytu faila-konii (13.01.13)
#include <stdio.h>
#include <io.h>
#include <sys/stat.h>
#include "def_com.h"
#include "var_ext.h"
#include "sst_fk.h"
#include "FK_lim.h"
#include "func_obr.h"
#include "spb_zone.h"
#include "N_error.h"

// chteNie atpibytov faila-konii
void ReadAtrFK()
{ int dl_fk_clc;         // dliNa faila-konii paschetNaj
	struct stat statbuff;  // onisaNie stpyktypu stat

	if (lseek(d_fk, POZ_SZSPB, SEEK_SET) != POZ_SZSPB) // oshibka pozicioNipovaNija Na pazmep synepbloka?
		ErrObr(E_ATR_FK_POZSZSPB);
	if (read(d_fk, &sz_spb, BYTE_2) != BYTE_2)     // chteNie i npovepka gpaNic pazmepa synepbloka?
		ErrObr(E_ATR_FK_RD_SZSPB);
	if (sz_spb<MIN_SZ_SPB || sz_spb>MAX_SZ_SPB)
		ErrObr(E_ATR_FK_SZSPB);
	if (lseek(d_fk, POZ_SPB, SEEK_SET) != POZ_SPB) // oshibka pozicioNipovaNija Na Nachalo synepbloka?
		ErrObr(E_ATR_FK_POZSPB);
	if (read(d_fk, &sst_fk, BYTE_2) != BYTE_2)     // chteNie i npovepka gpaNic atpibutov faila-konii
		ErrObr(E_ATR_FK_RD_SSFK);
	if (sst_fk < MIN_SS_FK)
		ErrObr(E_ATR_FK_SSFK);
	if (read(d_fk, &sz_kdr, BYTE_2) != BYTE_2)
		ErrObr(E_ATR_FK_RD_SZKDR);
	if (sz_kdr<MIN_SZ_KDR || sz_kdr > MAX_SZ_KDR)
		ErrObr(E_ATR_FK_SZKDR);
	if (read(d_fk, &dl_fk, BYTE_2) != BYTE_2)
		ErrObr(E_ATR_FK_RD_DLFK);
	fstat(d_fk, &statbuff);
	dl_fk_clc = (statbuff.st_size - (long)sz_spb)/sz_kdr;
	if ((dl_fk_clc != dl_fk) || (dl_fk<MIN_DL_FK || dl_fk > MAX_DL_FK))
		ErrObr(E_ATR_FK_DLFK);
	if (read(d_fk, &dl_bur_kdr, BYTE_2) != BYTE_2)
		ErrObr(E_ATR_FK_RD_DLBURKDR);
	if (dl_bur_kdr<MIN_DL_BUR_KDR || dl_bur_kdr>MAX_DL_BUR_KDR)
		ErrObr(E_ATR_FK_DLBURKDR);
	if (read(d_fk, &sz_bur_kdr, BYTE_2) != BYTE_2)
		ErrObr(E_ATR_FK_RD_SZBURKDR);
	if (sz_bur_kdr<MIN_SZ_BUR_KDR || sz_bur_kdr>MAX_SZ_BUR_KDR)
		ErrObr(E_ATR_FK_SZBURKDR);
	if (read(d_fk, &sz_free_zone, BYTE_2) != BYTE_2)
		ErrObr(E_ATR_FK_RD_SZFREEZONE);
	if (sz_free_zone<MIN_SZ_FREE_ZONE || sz_free_zone>MAX_SZ_FREE_ZONE)
		ErrObr(E_ATR_FK_SZFREEZONE);
}

// nechat atpibytov faila-konii
void PrintAtrFK()
{ printf("\n\t File-copy attributes");
	printf("\n File-copy state (%o):", sst_fk);
	printf("\n attributes : copies - %d, ", (sst_fk||AFK_INP)? 1 : 0);
	printf("identification data (OD) - %d, ", (sst_fk&OD_INP)? 1 : 0);
	printf("flight - %d", (sst_fk&APOL_INP)? 1 : 0);
	printf("\n re-structurization single-command (PK) - %d, ", (sst_fk&FRM_BP)? 1 : 0);
	printf("physics An - %d", (sst_fk&FIZ_AP)? 1 : 0);
	printf("\n Forming Pn passage: 1 - %d, ", (sst_fk&FRM_CP_1)? 1 : 0);
	printf("2 - %d, ", (sst_fk&FRM_CP_2)? 1 : 0);
	printf("3 - %d", (sst_fk&FRM_CP_3)? 1 : 0);
	printf("\n Forming IPK passage: 1 - %d, ", (sst_fk&FRM_IRK_1)? 1 : 0);
	printf("2 - %d, ", (sst_fk&FRM_IRK_2)? 1 : 0);
	printf("3 - %d", (sst_fk&FRM_IRK_3)? 1 : 0);
	printf("\n Forming Sb  - %d", (sst_fk&FRM_SB)? 1 : 0);
	printf("\n Frame size  (2..400) \t %5d (byte)", sz_kdr);
	printf("\n File-copy size (1..1000)  %5d (frame)", dl_fk);
	printf("\n bYP frame size (2..128)  %5d (words)", dl_bur_kdr);
	printf("\n bYP frame size (2..128)  %5d (byte)", sz_bur_kdr);
	printf("\n Free-zone size (2..400)  %5d (byte)", sz_free_zone);
	printf("\n Superblock size (1024..4096) %5d (byte)\n", sz_spb);
}

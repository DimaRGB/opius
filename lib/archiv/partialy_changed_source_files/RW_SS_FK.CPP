// RW_SS_FK.cpp - chteNie/zanis slova-sostojaNia faila-konii (13.01.12)
#include <stdio.h>
#include <io.h>
#include "def_com.h"
#include "var_ext.h"
#include "spb_zone.h"
#include "sst_fk.h"
#include "func_obr.h"
#include "N_error.h"

// chteNie slova sostojaNia faila-konii
void ReadSSFK()
{ int ss_t; // tekyschee slovo sostojaNia faila-konii

	if (lseek(d_fk, POZ_SPB, SEEK_SET) != POZ_SPB) // oshibka nozicioNipovaNija Na Nachalo synepbloka?
		ErrObr(E_ATRFK_RW_RDPOZSPB);
	if (read(d_fk, &ss_t, BYTE_2) != BYTE_2)
		ErrObr(E_ATRFK_RW_RD_RDSSFK);
	if ((ss_t < AFK_INP) || (ss_t > FRM_SB))
		ErrObr(E_ATRFK_RW_RDSSFK);
}

// zanis slova sostojaNija faila-konii v synepblok
// ss_bit - bit sostojaNia obpabotki faila-konii
void WriteSSFK(int ss_bit)
{ int ss_fk, ss_new; // tekyschee/Novoe slovo sostojaNia faila-konii
	if (lseek(d_fk, POZ_SPB, SEEK_SET) != POZ_SPB) // oshibka pozicioNipovaNija Na slovo sostojaNia?
		ErrObr(E_ATRFK_RW_WRPOZSPB);
	if (read(d_fk, &ss_fk, BYTE_2) != BYTE_2)      // oshibka chteNija slova sostojaNia?
		ErrObr(E_ATRFK_RW_RD_WRSSFK);
	if ((ss_fk < AFK_INP) || (ss_fk > FRM_SB))
		ErrObr(E_ATRFK_RW_WRSSFK);
	ss_new = ss_fk | ss_bit;                       // Novoe slovo sostojaNia
//	ss_new = ss_tmp; // Novoe slovo sostojaNia
//printf("WriteSSFK ss_new = %o",ss_new);printf(" ( %o |",ss_fk);printf(" %o )",ss_bit);getchar();
	if (lseek(d_fk, POZ_SPB, SEEK_SET) != POZ_SPB) // oshibka pozicioNipovaNija Na slovo sostojaNia?
		ErrObr(E_ATRFK_RW_WRPOZSPB);
	if (write(d_fk, &ss_new, BYTE_2) != BYTE_2)    // oshibka zanisi slova sostojaNia?
		ErrObr(E_ATRFK_RW_WR_WRSSFK);
}

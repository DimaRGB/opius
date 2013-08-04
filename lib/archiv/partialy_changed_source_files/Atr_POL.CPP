// Atr_Pol.cpp - atpibytu noleta (13.01.12)
#include <stdio.h>
#include <io.h>
#include <sys/stat.h>
#include "def_com.h"
#include "var_ext.h"
#include "strctext.h"
#include "APOL_lim.h"
#include "func_obr.h"
#include "spb_zone.h"
#include "N_error.h"

// chteNie atpibytov noleta iz synepbloka
void ReadAtrFlight()
{ if (lseek(d_fk, POZ_APOL, SEEK_SET) != POZ_APOL)      // oshibka pozicioNipovaNija Na atpibytu noleta?
		ErrObr(E_ATR_POL_POZAPOL);
	if (read(d_fk, &APOL.Weight, BYTE_4) != BYTE_4)       // vzletNui ves bez tonliva Na vzlete, t
		ErrObr(E_ATR_POL_RD_WEIGHT);
	if (APOL.Weight<MIN_VES_VZLET || APOL.Weight>MAX_VES_VZLET)
		ErrObr(E_ATR_POL_WEIGHT);
	if (read(d_fk, &APOL.CAX, BYTE_4) != BYTE_4)          // SAX Na vzlete, %
		ErrObr(E_ATR_POL_RD_SAX);
	if (APOL.CAX<MIN_SAX_VZLET || APOL.CAX>MAX_SAX_VZLET)
		ErrObr(E_ATR_POL_SAX);
	if (read(d_fk, &APOL.Pressure, BYTE_2) != BYTE_2)     // davleNie, mm.pt.st.
		ErrObr(E_ATR_POL_RD_PRESW);
	if (APOL.Pressure<MIN_DAVLENIE || APOL.Pressure>MAX_DAVLENIE)
		ErrObr(E_ATR_POL_PRESW);
	if (read(d_fk, &APOL.name_apwzl, BYTE_16) != BYTE_16) // imja a/n vzleta
		ErrObr(E_ATR_POL_RD_NAMEAP);
	if (read(d_fk, &APOL.UN_BPP_wzl, BYTE_2) != BYTE_2)   // ygol kypsa Vnn vzleta
		ErrObr(E_ATR_POL_RD_UNBBP);
	if (APOL.UN_BPP_wzl<MIN_UN_Vnn || APOL.UN_BPP_wzl>MAX_UN_Vnn)
		ErrObr(E_ATR_POL_UNBBP);
	if (read(d_fk, &APOL.L_BPP_wzl, BYTE_2) != BYTE_2)    // dliNa Vnn vzleta, m
		ErrObr(E_ATR_POL_RD_LBBP);
	if (APOL.L_BPP_wzl<MIN_L_Vnn || APOL.L_BPP_wzl>MAX_L_Vnn)
		ErrObr(E_ATR_POL_LBBP);
	if (read(d_fk, &APOL.H_kr_wzl, BYTE_2) != BYTE_2)     // vusota kpyga Na vzlete, m
		ErrObr(E_ATR_POL_RD_HKR);
	if (APOL.H_kr_wzl<MIN_Hkp || APOL.H_kr_wzl>MAX_Hkp)
		ErrObr(E_ATR_POL_HKR);
	if (read(d_fk, &APOL.name_appos, BYTE_16) != BYTE_16) // imja a/n nosadki
		ErrObr(E_ATR_POL_RD_NAMEAP);
	if (read(d_fk, &APOL.UN_BPP_pos, BYTE_2) != BYTE_2)   // ygol kypsa Vnn nosadka
		ErrObr(E_ATR_POL_RD_UNBBP);
	if (APOL.UN_BPP_pos<MIN_UN_Vnn || APOL.UN_BPP_pos>MAX_UN_Vnn)
		ErrObr(E_ATR_POL_UNBBP);
	if (read(d_fk, &APOL.L_BPP_pos, BYTE_2) != BYTE_2)    // dliNa Vnn nosadka, m
		ErrObr(E_ATR_POL_RD_LBBP);
	if (APOL.L_BPP_pos<MIN_L_Vnn || APOL.L_BPP_pos>MAX_L_Vnn)
		ErrObr(E_ATR_POL_LBBP);
	if (read(d_fk, &APOL.H_ep_pos, BYTE_2) != BYTE_2)     // vusota esheloNa nepexoda Na nosadke, m
		ErrObr(E_ATR_POL_RD_HE);
	if (APOL.H_ep_pos<MIN_Hep_POS || APOL.H_ep_pos>MAX_Hep_POS)
		ErrObr(E_ATR_POL_HE);
	if (read(d_fk, &APOL.H_kr_pos, BYTE_2) != BYTE_2)     // vusota kpyga Na nosadke, m
		ErrObr(E_ATR_POL_RD_HKR);
	if (APOL.H_kr_pos<MIN_Hkp || APOL.H_kr_pos>MAX_Hkp)
		ErrObr(E_ATR_POL_HKR);
	if (read(d_fk, &APOL.H_tvg, BYTE_2) != BYTE_2)        // vusota tochki vhoda v glissady, m
		ErrObr(E_ATR_POL_RD_HTVG);
	if (APOL.H_tvg<MIN_Htvg || APOL.H_tvg>MAX_Htvg)
		ErrObr(E_ATR_POL_HTVG);
	if (read(d_fk, &APOL.L_tvg, BYTE_2) != BYTE_2)        // passtojaNie ot topca Vnn do tochki vhoda v glissady, m
		ErrObr(E_ATR_POL_RD_LTVG);
	if (APOL.L_tvg<MIN_Ltvg || APOL.L_tvg>MAX_Ltvg)
		ErrObr(E_ATR_POL_LTVG);
	if (read(d_fk, &APOL.H_dprm, BYTE_2) != BYTE_2)       // vusota npoleta DnPM, m
		ErrObr(E_ATR_POL_RD_HDPRM);
	if (APOL.H_dprm<MIN_Hdprm || APOL.H_dprm>MAX_Hdprm)
		ErrObr(E_ATR_POL_HDPRM);
	if (read(d_fk, &APOL.L_dprm, BYTE_2) != BYTE_2)       // passtojaNie ot topca Vnn do DnPM, m
		ErrObr(E_ATR_POL_RD_LDPRM);
	if (APOL.L_dprm<MIN_Ldprm || APOL.L_dprm>MAX_Ldprm)
		ErrObr(E_ATR_POL_LDPRM);
	if (read(d_fk, &APOL.H_bprm, BYTE_2) != BYTE_2)       // vusota npoleta bnPM, m
		ErrObr(E_ATR_POL_RD_HBPRM);
	if (APOL.H_bprm<MIN_Hbprm || APOL.H_bprm>MAX_Hbprm)
		ErrObr(E_ATR_POL_HBPRM);
	if (read(d_fk, &APOL.L_bprm, BYTE_2) != BYTE_2)       // passtojaNie ot topca Vnn do bnPM, m
		ErrObr(E_ATR_POL_RD_LBPRM);
	if (APOL.L_bprm<MIN_Lbprm || APOL.L_bprm>MAX_Lbprm)
		ErrObr(E_ATR_POL_LBPRM);
	if (read(d_fk, &APOL.H_vpr, BYTE_2) != BYTE_2)        // vusota npiNjatia pesheNia, m
		ErrObr(E_ATR_POL_RD_HVPR);
	if (APOL.H_vpr<MIN_Hvpr || APOL.H_vpr>MAX_Hvpr)
		ErrObr(E_ATR_POL_HVPR);
}

// nechat atpibytov noleta
void PrintAtrFlight()
{ printf("\n \t\t Flight attributes");
	printf("\n WZL:%s ",APOL.name_apwzl);
	printf("\n weight(20-40) = %3.1f",APOL.Weight); printf("\n CAX(10-30) = %3.1f",APOL.CAX);
	printf("\n Pressure(700-780) = %3d\n",APOL.Pressure); //printf("WZL:%s        ",APOL.name_apwzl);
	printf("\n UNvnn(0-360) = %3d",APOL.UN_BPP_wzl);printf("\t\t Lvnn(1-4km) = %5d",APOL.L_BPP_wzl);
	printf("\n Hkr(300-900) = %3d",APOL.H_kr_wzl);printf("\t\t POS:%s = ",APOL.name_appos);
	printf("\n UNvnn(0-360) = %3d",APOL.UN_BPP_pos);printf("\t\t Lvnn(1-4km) = %5d",APOL.L_BPP_pos);
	printf("\n Hep(800-1500) = %4d",APOL.H_ep_pos);
	printf("\n H_kr(300-900) = %4d",APOL.H_kr_pos);
	printf("\n Ltvg(4-12km) = %4d",APOL.L_tvg);  printf("\t\t Htvg(300-900 = %4d",APOL.H_tvg);
	printf("\n Ldprm(2-5km) = %4d",APOL.L_dprm); printf("\t\t Hdprm(150-300) = %3d",APOL.H_dprm);
	printf("\n Lbprm(.8-1.5km) = %4d",APOL.L_bprm);printf("\t\t Hbprm(50-100) = %3d",APOL.H_bprm);
	printf("\n Hvpr(20-100) = %5d",APOL.H_vpr);
}

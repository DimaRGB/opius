// calc_par.cpp - paschet napametpov i obpabotka faila-konii (13.01.10)
#include <limits.h>
#include "var_ext.h"
#include "strctext.h"
#include "func_obr.h"
#include "sst_fk.h"
#include "ap_cycl.h"
#include "rk_cycl.h"
#include "N_error.h"

#define NO_EXTREMUM LONG_MIN // zanpet fopmipovaNija extpemyma aNalogovogo napametpa

// obpabotka napametpov noleta
void CalculateFlight()
{ short n_kdr,  count_HB; // Nomep kadpa, schetchik bapometpicheskoi vusotu
	float sum_HB, HBzem;    // symma bapometp.vusot Na etape ZEMLJA, nokazaNija bapometr.vusotomepa Na zemle

									 // 1-i paschet An (do fopmip.PK etan noleta/pej.pabotu obopyd.)
	ReadSSFK();                                 // chteNie slova sostojaNia faila-kopii
	if (!(sst_fk & FRM_CP_1))                   // 1-i paschet An vunolNeN?
	{ for (n_kdr=0; n_kdr < dl_fk; n_kdr++)     // fail-konija obpabotaN?
		{ p_AP[QS]->fz[n_kdr] = APOL.Weight + p_AP[QT]->fz[n_kdr]; // paschet vesa samoleta
			WriteFizAP(n_kdr, p_AP[QS]->cn, p_AP[QS]->fz[n_kdr]);    // zanis vesa samoleta v fail-koniu

			if (n_kdr > 0)                          // paschet i zanis npoizvodNux
			{	p_AP[dMZ]->fz[n_kdr] = (p_AP[MZ]->fz[n_kdr] - p_AP[MZ]->fz[n_kdr-1])/2;   // zakpilki
				p_AP[dHG]->fz[n_kdr] = (p_AP[HG]->fz[n_kdr] - p_AP[HG]->fz[n_kdr-1])/2;   // visota geometpicheskaja
				p_AP[dVP]->fz[n_kdr] = (p_AP[VP]->fz[n_kdr] - p_AP[VP]->fz[n_kdr-1])/7.2; // skopost npibopNaja
			}
			else                                    // obNuleNie napametpov pacheta
			{	p_AP[dMZ]->fz[n_kdr] = 0;
				p_AP[dHG]->fz[n_kdr] = 0;
				p_AP[dVP]->fz[n_kdr] = 0;
			}                                       // zanis napametpov pacheta v fail-koniju
			WriteFizAP(n_kdr, p_AP[dMZ]->cn, p_AP[dMZ]->fz[n_kdr]);
			WriteFizAP(n_kdr, p_AP[dHG]->cn, p_AP[dHG]->fz[n_kdr]);
			WriteFizAP(n_kdr, p_AP[dVP]->cn, p_AP[dVP]->fz[n_kdr]);
		}
//		WriteSSFK(FRM_CP_1);                    // zanis slova sostojaNia v fail-koniju (zaglysheNa npi otladke)
	}
									 // 1-e fopmipovaNie PK etan noleta/peg.pabotu obopyd.
	ReadSSFK();                                 // chteNie slova sostojaNia faila-kopii
	if ((sst_fk & FRM_CP_1) && !(sst_fk & FRM_IRK_1)) // 1-e fopmipovaNie PK vunolNeNo?
	{ for (n_kdr=0; n_kdr < dl_fk; n_kdr++)     // fopmipovaNie i zanis npizNaka ZEMLJA
			FrmIRK(p_RK[IRK1], pZEM, (p_AP[dHG]->fz[n_kdr] <= .0) && (p_AP[HG]->fz[n_kdr] <= 3), 6, NO_EXTREMUM, n_kdr);

		for (n_kdr=0; n_kdr < dl_fk; n_kdr++)     // fopmipovaNie i zanis npizNaka VOZDYX
			FrmIRK(p_RK[IRK1], pVOZD, !p_RK[IRK1]->fz[pZEM][n_kdr], 4, NO_EXTREMUM, n_kdr);

		for (n_kdr=0; n_kdr < dl_fk; n_kdr++)     // fopmipovaNie i zanis npizNaka VUnySK ZAKPULKOV
			FrmIRK(p_RK[IRK2], pMZv, p_AP[dMZ]->fz[n_kdr] > .0, 6, NO_EXTREMUM, n_kdr);

		for (n_kdr=0; n_kdr < dl_fk; n_kdr++)     // fopmipovaNie i zanis npizNaka ybOPKA ZAKPULKOV
			FrmIRK(p_RK[IRK2], pMZu, p_AP[dMZ]->fz[n_kdr] < .0, 6, NO_EXTREMUM, n_kdr);
//		WriteSSFK(FRM_IRK_1);
	}
									 // 2-i paschet An (nosle fopmip.PK etan noleta/pej.pabotu obopyd.
	ReadSSFK();
	if (!(sst_fk & FRM_CP_2) && (sst_fk & FRM_IRK_1))
	{ sum_HB   = 0;
		count_HB = 0;
		for (n_kdr=0; n_kdr < dl_fk; n_kdr++)
			if (p_RK[IRK1]->fz[pZEM][n_kdr])        // etap ZEMLJA?
			{	sum_HB += p_AP[HB]->fz[n_kdr];        // symma bapometp.vusot
				count_HB++;                           // modifikacija schetchika bapometp.vusotu
			}
		if (count_HB)
			HBzem = sum_HB/count_HB;                // paschet nokazaNija bapometr.vusotomepa Na zemle
		for (n_kdr=0; n_kdr < dl_fk; n_kdr++)
		{ if (p_RK[IRK1]->fz[pZEM][n_kdr])        // paschet i zanis otNositelNoi bapometp.vysotu
				p_AP[HBotn]->fz[n_kdr] = 0;
			if (p_RK[IRK1]->fz[pVOZD][n_kdr])
			{	p_AP[HBotn]->fz[n_kdr] = p_AP[HB]->fz[n_kdr] - HBzem;
				if (p_AP[HBotn]->fz[n_kdr] < 0)
					p_AP[HBotn]->fz[n_kdr] = 0;
			}
			WriteFizAP(n_kdr, p_AP[HBotn]->cn, p_AP[HBotn]->fz[n_kdr]);
		}

		for (n_kdr=0; n_kdr < dl_fk; n_kdr++)
		{ p_AP[V3]->fz[n_kdr] = (p_RK[IRK2]->fz[pMZu][n_kdr])? p_AP[QS]->fz[n_kdr]*2.5+140 : 0;
			WriteFizAP(n_kdr, p_AP[V3]->cn, p_AP[V3]->fz[n_kdr]);
		}
//		WriteSSFK(FRM_CP_2);
	}
									 // 2-e fopmipovaNie PK etan noleta/pej.pabotu obopyd.
	ReadSSFK();
	if ((sst_fk & FRM_CP_2) && !(sst_fk & FRM_IRK_2))
	{ for (n_kdr=0; n_kdr < dl_fk; n_kdr++)     // fopmipovaNie i zanis npizNaka NACHALNyI NAbOP VUSOTU NA VZLETE
			FrmIRK(p_RK[IRK1], pWZLv, p_RK[IRK1]->fz[pVOZD][n_kdr] && p_AP[HBotn]->fz[n_kdr] < APOL.H_kr_wzl, 6, NO_EXTREMUM, n_kdr);
//		WriteSSFK(FRM_IRK_2);
	}
									 // fopmipovaNie sobutia o NapysheNii
	ReadSSFK();
	if ((sst_fk & FRM_IRK_2) && !(sst_fk & FRM_SB))
	{ for (n_kdr=0; n_kdr < dl_fk; n_kdr++)
		{	FrmIRK(p_RK[SOB],S9  ,p_RK[IRK1]->fz[pZEM][n_kdr] && (p_AP[QS]->fz[n_kdr] < 54.8),                                  6,p_AP[QS]->fz[n_kdr]   ,n_kdr); // sobutie N 9
			FrmIRK(p_RK[SOB],S109,p_RK[IRK1]->fz[pWZLv][n_kdr] && p_RK[IRK2]->fz[pMZu][n_kdr] && (p_AP[HBotn]->fz[n_kdr] < 120),3,p_AP[HBotn]->fz[n_kdr],n_kdr); // sobutie N 109
		}
//		WriteSSFK(FRM_SB);
	}
}

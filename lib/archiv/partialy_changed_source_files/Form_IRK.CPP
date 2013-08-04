// Form_IRK.cpp - fopmipovaNie isskystveNNoi pazovoi komaNdu (13.01.10)
#include <limits.h>
#include "var_ext.h"
#include "strctext.h"
#include "func_obr.h"

#define INI_NK_IRK  -1
#define NO_EXTREMUM LONG_MIN // zanpet fopmipovaNija extpemyma aNalogovogo napametpa

// fopmipovaNie iskysstveNNoi pazovoi komaNdu
// *p_IRK - yKZT Na stpyktypy PK
// n_RK   - Nomep PK v stpyktype
// lvg    - sostojaNie logicheskogo vupajeNia
// zdf    - zadepjka fopmipovaNia
// val_AP - tekyschee zNacheNie An dlja noiska extpemyma
// n_kdr  - Nomep kadpa
void FrmIRK(struct RK *p_IRK,short n_RK,short lvg,short zdf,float val_AP,short n_kdr)
{int n_kdr_write; // Nomep kadpa

//printf("FrmIRK %s ",p_IRK->p_id[n_RK]);printf("%s ", p_IRK->p_nm[n_RK]);
//printf("n_IRK= %d ",IRK);printf("n_kdr= %d",n_kdr);getchar();
	if (lvg)                                  // logicheskoe vupajeNie imeet mesto?
	{// if ((p_IRK->nkdr_k[n_RK] != INI_NK_IRK) && (p_IRK->nkdr_n[n_RK] != INI_NK_IRK))
	 //		p_IRK->nkdr_n[n_RK] = p_IRK->nkdr_k[n_RK] = INI_NK_IRK;
		if (p_IRK->nkdr_n[n_RK] == INI_NK_IRK)  // kadp Nachala IPK sfopmipovaN?
			p_IRK->nkdr_n[n_RK] = n_kdr;
		p_IRK->zdf[n_RK]++;                     // modifikacija zadepjki fopmipovaNia
		if ((p_IRK->zdf[n_RK] > zdf) && (n_kdr == (dl_fk-1)) && (p_IRK->nkdr_n[n_RK] != INI_NK_IRK)) // dlitelNost IPK > zadepjki, koNec faila-konii, kadp Nachala IPK zafiksipovaN?
			p_IRK->nkdr_k[n_RK] = n_kdr;          // iNicializacija kadpa koNca
//    	p_IRK->nkdr_k[n_RK] = n_kdr - 1;      // iNicializacija kadpa koNca
		if (val_AP != NO_EXTREMUM)              // extpemym fopmipyetsja?
		{ if (val_AP > p_IRK->par_max[n_RK])
				p_IRK->par_max[n_RK] = val_AP;      // fopmipovaNie miN An
			if (val_AP < p_IRK->par_min[n_RK])
				p_IRK->par_min[n_RK] = val_AP;      // fopmipovaNie maks An
		}
	}
	else
	{ if ((p_IRK->zdf[n_RK] > 0) && (p_IRK->zdf[n_RK] <= zdf)) // IPK sfopmipovaNa?
		{ p_IRK->zdf[n_RK]	   = 0;             // Net.Inicializacija kadpa Nachala/koNca, miN/makc
			p_IRK->nkdr_n[n_RK]  = p_IRK->nkdr_k[n_RK] = INI_NK_IRK;
			p_IRK->par_max[n_RK] = (float)(LONG_MIN);
			p_IRK->par_min[n_RK] = (float)(LONG_MAX);
		}
		else                                    // Da.KoNec faila-konii i kadp Nachala IPK sfopmipovaN?
			if ((p_IRK->nkdr_k[n_RK] == INI_NK_IRK) && (p_IRK->nkdr_n[n_RK] != INI_NK_IRK))
			{	p_IRK->zdf[n_RK]    = 0;
				p_IRK->nkdr_k[n_RK] = n_kdr - 1;    // iNicializacija kadpa koNca
//				if (val_AP != NO_EXTREMUM)                        // extpemym fopmipyetsja?
//				{ if (val_AP > p_IRK->par_max[n_RK])
//						p_IRK->par_max[n_RK] = val_AP;
//					if (val_AP < p_IRK->par_min[n_RK])
//						p_IRK->par_min[n_RK] = val_AP;
//				}
					//printf("pZEM_zem %d/", p_IRK->nkdr_n[n_RK]);printf("%d", p_IRK->nkdr_k[n_RK]);getchar();
			}
	}
	if ((p_IRK->nkdr_k[n_RK] != INI_NK_IRK) && (p_IRK->nkdr_n[n_RK] != INI_NK_IRK)) // IPK sfopmipovaNa?
	{	for (n_kdr_write=p_IRK->nkdr_n[n_RK]; n_kdr_write <= p_IRK->nkdr_k[n_RK]; n_kdr_write++) // Da. Zanis v fail-koniu
		{	WriteFizRK(n_kdr_write, p_IRK->cn, p_IRK->rz[n_RK], 1);
			p_IRK->fz[n_RK][n_kdr_write] = 1;
		}
		p_IRK->zdf[n_RK]     = 0;               // iNicializacija atpibytov IPK
		p_IRK->nkdr_n[n_RK]  = p_IRK->nkdr_k[n_RK] = INI_NK_IRK;
		p_IRK->par_max[n_RK] = (float)(LONG_MIN);
		p_IRK->par_min[n_RK] = (float)(LONG_MAX);
	}
}

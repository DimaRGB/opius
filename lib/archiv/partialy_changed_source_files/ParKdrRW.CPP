// ParKdrRW.cpp - chteNie, zanis An, PK i kadov v fail-koniu (13.01.12)
#include <stdio.h>
#include <conio.h>
#include <io.h>
#include "def_com.h"
#include "var_ext.h"
#include "strctext.h"
#include "func_obr.h"
#include "typ_par.h"
#include "sst_fk.h"
#include "ap_cycl.h"
#include "rk_cycl.h"
#include "N_error.h"

// obNuleNie daNNux kaNala v free-zoNu kadpa
void ClearAPRKFreeZone()
{ int n_kdr; // Nomep kadpa

	for (n_kdr=0; n_kdr <= dl_fk; n_kdr++) // kadp nposmotpeN?
	{ WriteFizAP(n_kdr, UKR18, 0);         // obNuleNie daNNux kaNalov
		WriteFizAP(n_kdr, RKO24, 0);
		WriteFizAP(n_kdr, UKR38, 0);
		WriteFizAP(n_kdr, RKO40, 0);
		WriteFizAP(n_kdr, UKR51, 0);
		WriteFizAP(n_kdr, UKR52, 0);
		WriteFizAP(n_kdr,    53, 0);
		WriteFizAP(n_kdr, UKR55, 0);
		WriteFizAP(n_kdr, RKO56, 0);
		WriteFizAP(n_kdr, UKR60, 0);
	}
}

// chteNie daNNux free-zoNu iz massivov i nepeNos v stpyktypu
void ReadFreeZone()
{ short n_kdr, kn, rz, bit; // Nomep kadpa, kaNal, pazpjad, bit

	if ((sst_fk & FIZ_AP) != FIZ_AP)  				     // fail-konia Ne v fizike?
		ErrObr(E_PARKDR_RW_NOFIZ);
	for (n_kdr=0; n_kdr < dl_fk; n_kdr++)          // koNec faila-konija?
	{ ReadKdr((int)n_kdr);                         // chteNie daNNux kadpa
		for (kn=0; kn < dl_bur_kdr; kn++)            // koNec kadpa?
		{ if (p_AP[kn] != (struct AP *) 0)           // stpyktypa An inicializipovaNa
				p_AP[kn]->fz[n_kdr] = mas_free_pi[kn];   // zanolNeNie massiva
			if (p_RK[kn] != (struct RK *) 0)           // stpyktypa PK inicializipovaNa
				for (rz=0; rz < 32; rz++)                // pazpjadu nposmotpeNu?
					if (p_RK[kn]->fz[rz] != 0)             // massiv fiziki vudeleN?
					{ bit = (mas_free_rk[kn] >> rz) & 01;  // vudeleNie PK
						p_RK[kn]->fz[rz][n_kdr] = (char)bit; // zanolNeNie massiva
					}
		}
	}
}

// chteNie kadpa faila-konii v massivu
// n_kdr - Nomep kadpa dlja chteNia daNNux
void ReadKdr(int n_kdr)
{ long poz;  // smescheNie npi nozicioNipovaNii

	poz = (long)sz_spb + (long)n_kdr*(long)sz_kdr; // paschet smescheNja Nachala chteNija
	if (lseek(d_fk, poz, SEEK_SET) != poz)   // oshibka nozicioNipovaNja?
		ErrObr(E_LSEEK_READKDR);
	if ((read(d_fk, (void *)mas_bur_pi, sz_kdr)) != sz_kdr) // oshibka chteNija?
		ErrObr(E_PARKDR_RW_READKDR);
}

// zanis fiziki aNalogovogo napametpa v fail-koniu
// n_kdr_t - tekyschij Nomep kadpa
// canal   - kaNal
// fiz_ap  - fizika An
void WriteFizAP(int n_kdr_t, int canal, float fiz_ap)
{	long poz;  // smescheNie npi nozicioNipovaNija
																				 // paschet smescheNja Nachala zanisi
	poz = (long)sz_spb + (long)n_kdr_t*(long)sz_kdr + (long)sz_bur_kdr + (long)(canal*sizeof(float));
	if (lseek(d_fk, poz, SEEK_SET) != poz)      // oshibka nozicioNipovaNja?
		ErrObr(E_LSEEK_WRFIZAP);
	if (write(d_fk, &fiz_ap, BYTE_4) != BYTE_4) // oshibka zanisi?
		ErrObr(E_PARKDR_RW_WRFIZAP);
}

// zanis fiziki pazovoi komaNdu v fail-koniu
// n_kdr_t - tekyschij Nomep kadpa
// canal   - kaNal PK
// razr    - pazpjad PK
// value   - zNacheNie PK
void WriteFizRK(int n_kdr_t, int canal, int razr, unsigned long value)
{ unsigned long word_kan, bit_rk; // slovo kaNala/bit PK
	long poz;                       // smescheNie npi nozicioNipovaNii

	ReadKdr(n_kdr_t);                             // chteNie kadpa
	bit_rk	 = value << razr;                     // bit PK v iNfopmacioNNom slove kaNala
																								// zaNeseNie bita PK v iNfopmacioNNoe slovo kaNala
	word_kan = (bit_rk==0)? mas_free_rk[canal]&(~bit_rk) : mas_free_rk[canal]|bit_rk;
																								// paschet smescheNja Nachala zanisi
	poz = (long)sz_spb + (long)n_kdr_t*(long)sz_kdr + (long)sz_bur_kdr + (long)(canal*sizeof(long));
	if (lseek(d_fk, poz, SEEK_SET) != poz)        // oshibka nozicioNipovaNja?
		ErrObr(E_LSEEK_WRFIZRK);
	if (write(d_fk, &word_kan, BYTE_4) != BYTE_4) // oshibka zanisi?
		ErrObr(E_PARKDR_RW_WRFIZRK);
}

// zanis free-zoNu kadpa v fail-koniu
// n_kdr_t - Nomep tekyschego kadpa dlja zanisi daNNux
void WriteKdr(int n_kdr_t)
{ long poz; // smescheNie npi nozicioNipovaNii
																					// paschet smescheNja Nachala zanisi
	poz = (long)sz_spb + (long)n_kdr_t*(long)sz_kdr + (long)sz_bur_kdr;
	if (lseek(d_fk, poz, SEEK_SET) != poz)  // oshibka nozicioNipovaNja?
		ErrObr(E_LSEEK_WRFREE);
	if (write(d_fk, mas_free_pi, sz_free_zone) != sz_free_zone) // oshibka zanisi?
		ErrObr(E_PARKDR_RW_WRFREE);
}

// zanis daNNux kaNala v fail-koniy
// n_kdr_t - Nomep tekuschego kadpa dlja zanisi daNNux
// canal   - Nomep kaNala
// typ     - tin napametpa
void WriteParam(int n_kdr_t, int canal, int typ)
{ long poz;     // smescheNie npi nozicioNipovaNii
																				 // paschet smescheNja Nachala zanisi
	poz = (long)sz_spb + (long)n_kdr_t*(long)sz_kdr + (long)sz_bur_kdr + (long)(canal*sizeof(float));
	if (lseek(d_fk, poz, SEEK_SET) != poz) // oshibka nozicioNipovaNja?
		ErrObr(E_LSEEK_WRPARAM);
	switch(typ)
	{	case TYP_AP: if (write(d_fk, &mas_free_pi[canal], BYTE_4) != BYTE_4) // oshibka zanisi?
									 ErrObr(E_PARKDR_RW_WRPARAM);
								 break;
		case TYP_RKA:
		case TYP_RKD:
		case TYP_RKR: if (write(d_fk, &mas_free_rk[canal], BYTE_4) != BYTE_4) // oshibka zanisi?
										ErrObr(E_PARKDR_RW_WRPARAM);
									break;
		default     :  ;  break;
	}
}

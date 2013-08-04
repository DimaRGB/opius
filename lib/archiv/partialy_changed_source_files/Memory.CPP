// Memory.cpp - zanpos i osvobojdeNie namjati (13.01.13)
#include <alloc.h>
#include "var_ext.h"
#include "strctext.h"
#include "func_obr.h"

// osvobojdeNie vudeleNNoi namjati
void FreeMem()
{ short i, k;

	if (mas_bur_pi != (short *)0)              // namjat nod byfep kadpa faila-konii vudeleNa?
		free(mas_bur_pi);                        // osvobojdeNie namjati
	for (i=0; i < dl_bur_kdr; i++)             // kadp nposmotpeN?
	{	if (p_AP != (struct AP **)0)             // namjat nod massiv yKZT Na stpyktypu An vudeleNa?
			if (p_AP[i] != (struct AP *)0)         // namjat nod stpyktypy An vudeleNa?
			{ if (p_AP[i]->p_id != (char *)0)      // namjat nod ideNtifikatop An vudeleNa?
					free(p_AP[i]->p_id);               // osvobojdeNie namjati
				if (p_AP[i]->p_nm != (char *)0)      // namjat nod Naimenovanie An vudeleNa?
					free(p_AP[i]->p_nm);               // osvobojdeNie namjati
				if (p_AP[i]->fz != (float *)0)       // namjat nod massiv fiziki An vudeleNa?
					free(p_AP[i]->fz);                 // osvobojdeNie namjati
				free(p_AP[i]);                       // osvobojdeNie namjati
			}
		if (p_RK != (struct RK **)0)             // namjat nod massiv yKZT Na stpyktypu PK vudeleNa?
			if (p_RK[i] != (struct RK *)0)         // namjat nod stpyktypy PK vudeleNa?
			{	for (k=0; k < 32; k++)               // PK v stpyktype PK nposmotpeNu?
				{ if (p_RK[i]->p_id[k] != (char *)0) // namjat nod ideNtifikatop PK vudeleNa?
						free(p_RK[i]->p_id[k]);          // osvobojdeNie namjati
					if (p_RK[i]->p_nm[k] != (char *)0) // namjat nod Naimenovanie PK vudeleNa?
						free(p_RK[i]->p_nm[k]);          // osvobojdeNie namjati
					if (p_RK[i]->fz[k] != (char *)0)   // namjat nod massiv fiziki PK vudeleNa?
						free(p_RK[i]->fz[k]);            // osvobojdeNie namjati
				}
				free(p_RK[i]);                       // osvobojdeNie namjati
			}
	}
	if (p_AP != (struct AP **)0)               // namjat nod massiv yKZT Na stpyktypu An vudeleNa?
		free(p_AP);                              // osvobojdeNie namjati
	if (p_RK != (struct RK **)0)               // namjat nod massiv yKZT Na stpyktypu PK vudeleNa?
		free(p_RK);                              // osvobojdeNie namjati
}

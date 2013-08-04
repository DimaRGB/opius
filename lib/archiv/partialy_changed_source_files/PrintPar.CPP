// printpar.cpp - nechat napametpov kadpa faila-konii (13.01.10)
#include <dos.h>
#include <stdio.h>
#include <conio.h>
#include <alloc.h>
#include "var_ext.h"
#include "strctext.h"
#include "func_obr.h"
#include "ap_cycl.h"
#include "rk_cycl.h"
#include "N_error.h"

#include "con_funcs.h"

#define MIN_CAN          0    // miN/max Nomep kaNala pegistpacii napametpov
#define MAX_CAN          (dl_bur_kdr - 1)
#define PRINT_PAR       18    // max kolichestvo kaNalov npi vuvode Na nechat
#define END_PRINT_LIST  -1    // npizNak koNca sniska

// zadaNie i nechat sniska napametpov
void PrintParam()
{ unsigned short *mas_cod_par[PRINT_PAR]; // yKZT Na massiv kadr FK
	short can_list[PRINT_PAR],       // massiv xpaNeNia sniska kaNalov dlja nechaty
				can_tek, kol_par=0, i, k;  // tekuschi kaNal/kolichestvo vizyalazipyemux napametpov

//	clrscr();    // ochistka ekpaNa // не работает как положено
	printf(" \t Visualization of parametres code values bYP\n");
	printf("(channels designated by (*)-symbol will be visualized in binary mode\n");
	printf("\t Enter channel number of visualized parameter registration \n");
	printf(" (MiN/Max number - 0/63, number of parametres in one line - %d, -1 = end of input):\n", PRINT_PAR);
	while (1)
	{    can_tek=get_int(false);
		//scanf("%d", &can_tek);           // vvod Nomepa kaNala
		if ((can_tek >= MIN_CAN) && (can_tek <= MAX_CAN)) // kaNal v gpaNicax kadpa?
		{	can_list[kol_par] = can_tek;   // Da. zaNeseNie Nomepa kaNala napametpa v snisok
			kol_par++;                     // modifikacija kolichestva napametpov
		}
		else
			if (can_tek != END_PRINT_LIST) // Net
			{ printf("ERROR. Channel number is out of frame limits \n Press Enter");
			_getch();
			}
		if ((can_tek == END_PRINT_LIST) || (kol_par == PRINT_PAR)) // snisok vvedeN?
		{	printf("List of parametres for visualization is ready \n");
			sleep(1);
			break;
		}
	}
	if (kol_par > 0)                   // napametru dlja nechaty vvedeNu?
	{	for (i=0; i < kol_par; i++)      // Da. vudeleNie namjati nod massiv napametpov
		if ((mas_cod_par[i]=(unsigned short *)malloc(dl_fk*sizeof(short))) == (unsigned short *)0)
			ErrObr(E_MEM_MASCODPAR);       // ??? Ne pabotaet!!!
//		{	printf("\nERROR vudeleNia namjati Na massiv kodov napametpa (PrintParam)\nNajmi Enter"); getchar(); return(FL_ERR);
//		}
		for (i=0; i < dl_fk; i++)        // KoNec faila-konii?
		{	ReadKdr((int)i);               // chteNie daNNux kadpa faila-konii
			for (k=0; k < kol_par; k++)    // koNec spiska vizyalazipyemux napametpov?
				mas_cod_par[k][i] = (unsigned short) mas_bur_pi[can_list[k]]; // zapis koda napametpa v massiv zNacheNi napametpa
		}
	  //	clrscr();    // ochistka ekpaNa    // не работает как положено
		printf("Frame channel ");             // nechat teksta "shanki"
		for (k=0; k < kol_par; k++)      // koNec spiska vizyalazipyemux napametpov?
			switch (can_list[k])           // nechat Nomepa kaNala napametpa v "shanki"
			{ case OPOZ_DAN:
				case UKR5    :
				case RKO8    :
				case UKR18   :
				case RKO24   :
				case UKR38   :
				case RKO40   :
				case UKR51   :
				case UKR52   :
				case UKR55   :
				case RKO56   :
				case UKR60   : printf("*%2d ", can_list[k]); break;
				default      : printf("%2d  ", can_list[k]); break;
			}
		printf("\n");
		for (i=0; i < dl_fk; i++)        // KoNec faila-konii?
		{ printf(" %3d  ", i+1);         // nechat Nomepa kadpa
			for (k=0; k < kol_par; k++)    // koNec spiska vizyalazipyemux napametpov?
				switch (can_list[k])         // nechat kodov napametpov
				{ case OPOZ_DAN:
					case UKR5    :
					case RKO8    :
					case UKR18   :
					case RKO24   :
					case UKR38   :
					case RKO40   :
					case UKR51   :
					case UKR52   :
					case UKR55   :
					case RKO56   :
					case UKR60   : printf(" %3o", mas_cod_par[k][i]); break;
					default      : printf(" %3d", mas_cod_par[k][i]); break;
				}
			printf("\n");
			if (i && !(i%20))              // Nomep kadpa krateN chisly 20?
			{	printf("Frame channel ");         // novtopeNie nechati "shanki"
				for (k=0; k < kol_par; k++)
					switch (can_list[k])
					{ case OPOZ_DAN:
						case UKR5    :
						case RKO8    :
						case UKR18   :
						case RKO24   :
						case UKR38   :
						case RKO40   :
						case UKR51   :
						case UKR52   :
						case UKR55   :
						case RKO56   :
						case UKR60   : printf("*%2d ", can_list[k]); break;
						default      : printf("%2d  ", can_list[k]); break;
					}
				printf("\n       Press ENTER\n");	getchar();
			}
		}
	   	for (i=0; i < kol_par; i++)      // koNec spiska vizyalazipyemux napametpov?
			free(mas_cod_par[i]);          // osvobojdeNie vudeleNNoi namjati
	}
	else
	{ printf("\n \t Channels aren't entered. (can't visualize parameter codes)\n Press ENTER");
	 _getch();
	}
//	return(FL_OK);
}

// nechat fizicheskix zNacheNi napametpov iz massivov stpyktyp An i PK
void PrintFreeZone()
{ short n_kdr; // Nomep kadpa

//	for (n_kdr=0; n_kdr < dl_fk; n_kdr++)
	for (n_kdr=190; n_kdr < 210; n_kdr++)       // KoNec faila-konii?
	{	printf("N=%3d ",n_kdr);                   // nechat kodov napametpov
//		printf("TH=%4.1f ",p_AP[TH]->fz[n_kdr]);
//		printf("HB=%5.1f ",p_AP[HB]->fz[n_kdr]);
		printf("VP=%5.1f ",p_AP[VP]->fz[n_kdr]);
		printf("HG=%5.1f ",p_AP[HG]->fz[n_kdr]);
//		printf("UN=%5.1f ",p_AP[UN]->fz[n_kdr]);
//		printf("P kO=%d ",p_RK[RK5]->fz[kOp][n_kdr]);
//		printf("kEO=%d ",p_RK[RK5]->fz[kEOp][n_kdr]);
		printf("RDp=%5.1f ",p_AP[RDp]->fz[n_kdr]);
//		printf("Nvp=%4.1f ",p_AP[Nvp]->fz[n_kdr]);
//		printf("S kO=%d ",p_RK[RK5]->fz[kOs][n_kdr]);
//		printf("kEO=%d ",p_RK[RK5]->fz[kEOs][n_kdr]);
		printf("RDs=%5.1f ",p_AP[RDs]->fz[n_kdr]);
//		printf("Nvs=%4.1f ",p_AP[Nvs]->fz[n_kdr]);
//		printf("L kO=%d ",p_RK[RK5]->fz[kOl][n_kdr]);
//		printf("kEO=%d ",p_RK[RK5]->fz[kEOl][n_kdr]);
		printf("RDl=%5.1f ",p_AP[RDl]->fz[n_kdr]);
//		printf("Nvl=%4.1f ",p_AP[Nvl]->fz[n_kdr]);
//		printf("iSH=%d ", p_RK[RK8]->fz[iSH][n_kdr]);
//		printf("kMM=%d", p_RK[RK8]->fz[kMM][n_kdr]);
		printf("UT=%4.1f ",p_AP[UT]->fz[n_kdr]);
//    printf("MZ=%4.1f ",p_AP[MZ]->fz[n_kdr]);
//    printf("QT/S=%5.2f",p_AP[QT]->fz[n_kdr]);
//    printf("/%5.2f",p_AP[QS]->fz[n_kdr]);
//    printf("oiSH= %d",p_RK[RK8]->fz[oiSH][n_kdr]);
//    printf("iSH= %d", p_RK[RK8]->fz[28][n_kdr]);
		printf("iRWl/p= %d/",p_RK[RK5]->fz[iRWl][n_kdr]);
		printf("%d  ",p_RK[RK8]->fz[iRWp][n_kdr]);
		_getch();
	}
}

// функции и данные обработки полетной информации
// original + by B-GangsteR 2013.03.28

#include <dos.h>
#include <stdio.h>
#include <io.h>
#include <sys/stat.h>

#include <stdlib.h>
#include <string.h>
#include <limits.h>

#include <fcntl.h>

#include <alloc.h>

#include <string>
#include <iostream>
#include <conio.h>

#include "flight_data_proc_defines.h"

#define INI_NK_IRK  -1


#define MIN_CAN          0    // miN/max Nomep kaNala pegistpacii napametpov
#define MAX_CAN          (dl_bur_kdr - 1)
#define PRINT_PAR       18    // max kolichestvo kaNalov npi vuvode Na nechat
#define END_PRINT_LIST  -1    // npizNak koNca sniska

//void  CalculateFlight();
//void  ClearAPRKFreeZone();
void  ErrObr(int);
void  FreeMem();
//void  FrmIRK(struct RK *, short, short, short, float, short);
short GetParmVec(char *p_str, char *p_mpf[], char sym);
int   OpenFK();
void  PrintAtrFK();
void  PrintAtrFlight();
void  PrintOD();
void  PrintFreeZone();
void  PrintParam();
void  ReadAtrFK();
void  ReadAtrFlight();
void  ReadCyclogram(short);
void  ReadFreeZone();
void  ReadKdr(int);
void  ReadOD();
void  ReadSSFK();
//void  WriteFizAP(int, int, float);
//void  WriteFizRK(int, int, int, unsigned long);
//void  WriteKdr(int);
//void  WriteParam(int, int, int);
//void  WriteSSFK(int);

void PrintFreeZone_v2();

//----------------------------

// strctext.h - opisaNie stpyktyp

extern struct od_cop    OD;    // onozNavatelNue daNNue
extern struct AP      **p_AP;  // aNalogovui napametp
extern struct RK      **p_RK;  // pazovaja komaNda
extern struct atr_pol   APOL;  // atpibytu noleta

// strctcom.h - opisaNie stpyktyp npogrammu obpabotki
struct od_cop // stpyktypa onozNavatelNue daNNue
{ float Second;                         // sekuNdu
	long  Bort;                           // Nomep bopta
	int   Hour;   int Minute;             // chasu, miNytu
	int   Date;   int Month;    int Year; // data, mesjac, god
	int   Reis;                           // Nomep peisa
};

struct atr_pol  // stpyktypa atpibytu noleta:
{ float Weight;          float CAX;       // ves samoleta bez tonliva/SAX (vzlet)
	int   Pressure;                         // atmosfepNoe davleNie (vzlet)
	int   UN_BPP_wzl;      int  L_BPP_wzl;  // vzletNo-posadochNaja nolosa kups/dliNa/vusota (vzlet)
	int   H_kr_wzl;                         // vusota kpyga (vzlet)
	int   UN_BPP_pos;      int  L_BPP_pos;  // vzletNo-posadochNaja nolosa kups/dliNa/vusota (nosadka)
	int   H_ep_pos;        int  H_kr_pos;   // vusota kpyga (vzlet)
	int   H_tvg;       	   int  L_tvg;      // vusota/passtojaNie do tochki vhoda v glissady (nosadka)
	int   H_dprm;      	   int  L_dprm;     // vusota/passtojaNie do DnPM (nosadka)
	int   H_bprm;          int  L_bprm;     // vusota/passtojaNie do bnPM (nosadka)
	int   H_vpr;                            // vusota npiNjatija pesheNia (nosadka)
	char  name_apwzl[16];  char name_appos[16]; // imja aeponopta vzlet/nosadka
};

struct AP    // stpyctupa aNalogovui napametp:
{ float *fz;     // float  mk;			         // yKZT Na massiv fizicheskix zNacheNi/MK
	char  *p_id;    char  *p_nm;             // yKZT Na ideNtificatop/imja
	short  tp;      short  cn;    short  fo; // tin/kaNal bYP/chastota pegistpacii v kadpe
	short  cnm;                              // bazovi kaNal pegistpacii AP v kadpe
	short  fl_obr;                           // flag obpabotki
};

struct RK                // stpyctupa pazovaja komaNda:
{ char  *p_id[32];   	 char  *p_nm[32];             // yKZT Na ideNtificatop/imja
	char  *fz[32];                                    // yKZT Na massiv fizicheskix zNacheNi
	float  par_max[32];  float  par_min[32];          // max/miN zNacheNie aNalogovogo napametpa
	short  tp;           short  cn;         short fo; // tin/kaNal byP/chastota pegistpacii
	short  rz[32];                                    // pazpjad IPK
	short  fl_obr[32]; 				                        // flag obpabotki
	short  nkdr_n[32];   short  nkdr_k[32];           // Nomep kadpa Nachala/koNca IPK
	short  zdf[32]; 																	// zadepjka fopmipovaNija IPK
};
//----------------------------------



//------------var_ext.H
// var_ext.h - vNeshNie nepemeNNue
extern float         *mas_free_pi; // yKZT Na massiv An free-zoNu kadpa faila-konii
extern unsigned long *mas_free_rk; // yKZT Na massiv PK free-zoNu kadpa faila-konii
extern short         *mas_bur_pi;  // yKZT Na massiv daNNux zoNu kadp-bUR kadpa faila-konii

extern int d_fk,         // deskpintop faila-konii
					 sst_fk,       // slovo sostojaNija (obpabotki) faila-konii
					 dl_fk,        // dliNa faila-kopii (kadpov)
					 dl_bur_kdr,   // dliNa zoNu kadpa-bYP faila-konii (iNfopmacioNNux slov)
					 sz_kdr,       // pazmep kadpa faila-konii (byte)
					 sz_bur_kdr,   // pazmep zoNu kadp-bYP faila-konii (byte)
					 sz_free_zone, // pazmep free-zoNu faila-konii (byte)
					 sz_spb;        // pazmep synepbloka faila-konii (byte)
//------------var_ext.H




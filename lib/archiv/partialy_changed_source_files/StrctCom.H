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

// функции и данные обработки полетной информации
// original + by B-GangsteR 2013.03.28

#include "flight_data_processing.h"
#include "../console/con_funcs.h"


//-------------------var_glob.H---------
// var_glob.h - globalNue nepemeNNue
float         *mas_free_pi; // yKZT Na massiv An free-zoNu kadpa faila-konii
unsigned long *mas_free_rk; // yKZT Na massiv PK free-zoNu kadpa faila-konii
short         *mas_bur_pi;  // yKZT Na massiv daNNux zoNu kadp-bUR kadpa faila-konii

int d_fk,          // deskpintop faila-konii
		sst_fk,        // slovo sostojaNija (obpabotki) faila-konii
		dl_fk,         // dliNa faila-kopii (kadpov)
		dl_bur_kdr,    // dliNa zoNu kadpa-bYP faila-konii (iNfopmacioNNux slov)
		sz_kdr,        // pazmep kadpa faila-konii (byte)
		sz_bur_kdr,    // pazmep zoNu kadp-bYP faila-konii (byte)
		sz_free_zone,  // pazmep free-zoNu faila-konii (byte)
		sz_spb;        // pazmep synepbloka faila-konii (byte)
//-------------------var_glob.H---------


//---------------------------------------------------------------
// Atr_FK.cpp
//---------------------------------------------------------------
// Atr_FK.c - atpibytu faila-konii (13.01.13)

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
//---------------------------------------------------------------
// Atr_FK.cpp
//---------------------------------------------------------------


//---------------------------------------------------------------
// Atr_OD.cpp
//---------------------------------------------------------------
// ATR_OD.cpp - atpibytu onozNavatelNux daNNux (13.01.12)

// chteNie onozNavatelNux daNNux iz synepbloka
void ReadOD()
{	if (lseek(d_fk, POZ_OD, SEEK_SET) != POZ_OD)  // oshibka pozicioNipovaNija Na atpibytu OD?
		ErrObr(E_ATR_OD_POZOD);
	if (read(d_fk, &OD.Hour, BYTE_2) != BYTE_2)   // chasu
		ErrObr(E_ATR_OD_RD_HOUR);
	if (OD.Hour<MIN_TIME || OD.Hour>MAX_HOUR)
		ErrObr(E_ATR_OD_HOUR);
	if (read(d_fk, &OD.Minute, BYTE_2) != BYTE_2) // miNytu
		ErrObr(E_ATR_OD_RD_MINUTE);
	if (OD.Minute<MIN_TIME || OD.Minute>MAX_MIN)
		ErrObr(E_ATR_OD_MINUTE);
	if (read(d_fk, &OD.Second, BYTE_4) != BYTE_4) // sekyNdu
		ErrObr(E_ATR_OD_RD_SECOND);
	if (OD.Second<MIN_TIME || OD.Second>MAX_SEC)
		ErrObr(E_ATR_OD_SECOND);
	if (read(d_fk, &OD.Date, BYTE_2) != BYTE_2)   // data
		ErrObr(E_ATR_OD_RD_DATE);
	if (OD.Date<MIN_DATE || OD.Date>MAX_DATE)
		ErrObr(E_ATR_OD_DATE);
	if (read(d_fk, &OD.Month, BYTE_2) != BYTE_2)  // mesjac
		ErrObr(E_ATR_OD_RD_MONTH);
	if (OD.Month<MIN_MONTH || OD.Month>MAX_MONTH)
		ErrObr(E_ATR_OD_MONTH);
	if (read(d_fk, &OD.Year, BYTE_2) != BYTE_2)   // god
		ErrObr(E_ATR_OD_RD_YEAR);
	if (OD.Year<MIN_YEAR || OD.Year>MAX_YEAR)
		ErrObr(E_ATR_OD_YEAR);
	if (read(d_fk, &OD.Reis, BYTE_2) != BYTE_2)   // N peisa
		ErrObr(E_ATR_OD_RD_REIS);
	if (OD.Reis<MIN_REIS || OD.Reis>MAX_REIS)
		ErrObr(E_ATR_OD_REIS);
	if (read(d_fk, &OD.Bort, BYTE_4) != BYTE_4)   // N bopta
		ErrObr(E_ATR_OD_RD_BORT);
	if (OD.Bort<MIN_BORT || OD.Bort>MAX_BORT)
		ErrObr(E_ATR_OD_BORT);
}

// nechat onozNavatelNux daNNux
void PrintOD()
{	printf("\n \t Flight identification data");
	printf("\nHour %d ", OD.Hour);
	printf(" Min %d ", OD.Minute);
	printf(" Sec %f", OD.Second);
	printf("\nDate %d ", OD.Date);
	printf(" Mounth %d ", OD.Month);
	printf(" Year  %d", OD.Year);
	printf("\nFlight('reys') %d ", OD.Reis);
	printf("\nSide('bort') %ld\n", OD.Bort);
}
//---------------------------------------------------------------
// Atr_OD.cpp
//---------------------------------------------------------------


//---------------------------------------------------------------
// Atr_POL.cpp
//---------------------------------------------------------------
// Atr_Pol.cpp - atpibytu noleta (13.01.12)

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
//---------------------------------------------------------------
// Atr_POL.cpp
//---------------------------------------------------------------


//---------------------------------------------------------------
// Cyclogra.cpp
//---------------------------------------------------------------
// Cyclogra.cpp - fyNkcii pabotu s cyklogpammoi faila-konii (13.01.10)

//#define INI_NK_IRK  -1
// chteNie i pazbop ciklogpammu napametpov, iNicializacia stpyktyp aNalogovux napametpov i PK
// reg_rab - pejim pabotu
void ReadCyclogram(short reg_rab)
{
	using namespace std;
	char *p_flmem_b, *p_flmem_e, *p_flmem_t, // yKZT file-memory (Nachalo/koNec/tekysch)
			 *p_txt,     *p_txt_t,               // Nachalo/tekysch yKZT Na tekst
			**p_ln,     **p_ln_t,                // Nachalo/tekysch yKZT stpoky teksta
			 *p_fld[10],                         // massiv yKZT Na nolja stpoki ciklogpammu
				str[80];                           // stpiNg dlja vpemeNNogo xpaNeNia teksta
//----------------------------------------------------------------------
//char		name_CYCL[] = "c:\\temp\\CB_4z";	 // imja cyklogpammu (CB_4z)
/* ќткрыть циклограмму
  »звестные названи€ файлов циклограмм
A1
CB_4z
CBmk
G1
*/
	const int f_cycl_n_size = 4; // размер массива
	const char fst_ch = '0'; // первый допустимый дл€ ввода символ, указывающий на им€ с массива
	std::string f_dir("data\\"); // путь у файлам
	const char* f_cycl_name_ar[f_cycl_n_size] = {"A1","CB_4z","CBmk","G1"};

	cout<<"\n Choose file to open: \n"
		"\n Press 1 to open 'data\\A1'"
		"\n Press 2 to open 'data\\CB_4z'"
		"\n Press 3 to open 'data\\CBmk'"
		"\n Press 4 to open 'data\\G1'"
		"\n Press 0 to enter file name and path "<<endl;

	char file_ch = 0;
	string f_name;

	// диапазон допустимого ввода
	do      // считывать нажати€ пока не будет нажата верна€ клавиша
	{file_ch = _getch();}
	while ( !( (file_ch >= fst_ch) && (file_ch < (fst_ch+f_cycl_n_size+1))));

	// выбрать им€ файла
	if  ((file_ch > fst_ch) && (file_ch < (fst_ch+f_cycl_n_size+1)))
	{
	  f_name = f_dir + f_cycl_name_ar[file_ch-fst_ch-1];
	}
	else if (file_ch=='0')
	{
		cout<<"\n Enter file name: \n";
		getline(cin,f_name);
	}
	else
	{
		cout<<"\n Error! (cyclograma) \n";
	}

//----------------------------------------------------------------
short 	kn, tp, fo, rz;                    // kaNal/tin/chastota/pazpjad
int   	sz_file,                           // pazmep faila
				n_rd,                              // pazmep chteNija (bait)
				n_ln,                              // kolichestvo simvolov v stroke faila
				n_fld = 0,                         // kolichestvo nolei v stpoke
				i, k, m;
long  	bort_tmp;                          // Nomep bopta
FILE 	 *pf_file;                           // yKZT Na fail
struct 	stat stat_fl;                      // stpyktypa dlja fyNkcii stat
size_t	sz_tmp;

//	cout << "Input name of file-CYCL <disk:\\katalog\\file>\n"; 	cin >> name_CYCL;
	printf("Imja faila ciklogpammu -> %s\n", f_name.c_str());
//	if ((pf_file = fopen(name_CYCL, "r")) == NULL)          // symvolN.fail ciklogpammu otkput?
	if ((pf_file = fopen(f_name.c_str(), "r")) == NULL)          // symvolN.fail ciklogpammu otkput?
		ErrObr(E_OPEN_CYCL);
	if (stat(f_name.c_str(), &stat_fl) < 0)                      // atpibytu faila ciklogpammu nolycheNu?
		ErrObr(E_ATR_CYCL_ATRFILE);
	sz_file = stat_fl.st_size;                              // dliNa faila ciklogpammu
	if (!sz_file)                                           // fail ciklogpammu nystoi?
		ErrObr(E_ATR_CYCL_EMPTYFILE);
	if ((p_flmem_b = (char *)malloc(sz_file)) == (char *)0) // namjat nod fail ciklogpammu vudeleNa?
		ErrObr(E_ATR_CYCL_MEMFILE);
	p_flmem_e = p_flmem_b + sz_file;                        // yKZT Na koNec svob.namjati
	n_rd = fread(p_flmem_b, sz_file, 1, pf_file);           // chteNie v namjat faila ciklogpammu
//printf("\nsz_file = %d  ",sz_file); printf("n_rd = %d\n",n_rd);getchar();
// ??	if (n_rd != sz_file)                                    // oshibka chteNia?
//		ErrObr(E_ATR_CYCL_FILETOMEM);
	fclose(pf_file);                                        // zakputie faila ciklogpammu
	for (n_ln=0,p_flmem_t=p_flmem_b; p_flmem_t < p_flmem_e; p_flmem_t++) //KoNec namjati s tekstom?
		if (*p_flmem_t == '\n')                               // Simvol "\n"?
			n_ln++;                                             // modifikacia Nomepa stpoki
	if (!n_ln)                                              // Net stpok v faile ciklogpammu?
		ErrObr(E_ATR_CYCL_NOLINE);
	if ((p_ln=(char **)malloc(n_ln*sizeof(char **))) == (char **)0) // namjat nod massiv yKZT Na stpoki ciklogpammu vudeleNa?
		ErrObr(E_ATR_CYCL_MEMLINE);
	p_ln_t  = p_ln;                                         // tekyschi yKZT Na Nachalo massiva stpok
	for (*p_ln_t=p_txt=p_txt_t=p_flmem_b; p_txt_t < p_flmem_e;p_txt_t++) //koNec tekstovogo byfepa?
		if (*p_txt_t == '\n')                                 // koNec stpoki ("\n")?
		{ *p_txt_t  = '\0';                                   // zameNa \n Na \0 v stpiNge stpoki
			*p_ln_t++ = p_txt;                                  // zanis adpesa v massiv yKZT Na stpoki
			p_txt     = (*(p_txt_t+1) == '\0') ? (char *) 0 : p_txt_t+1;
		}
		else
			if ((p_txt == (char *) 0) && (*p_txt_t != '\0'))
				p_txt = p_txt_t;                                  // iNicializacia Novogo yKZT Na stpoky
	if ((p_AP=(struct AP **)calloc(dl_bur_kdr, sizeof(struct AP **))) == (struct AP **)0) // Net namjati nod mas.yKZT An?
		ErrObr(E_ATR_CYCL_MEMMASAn);
	if ((p_RK=(struct RK **)calloc(dl_bur_kdr, sizeof(struct RK **))) == (struct RK **)0) // Net namjati nod mas.yKZT PK?
		ErrObr(E_ATR_CYCL_MEMMASPK);
	for (m=0; m < n_ln; m++)                                // KoNec faila?
	{ strcpy(str, p_ln[m]);                                 // Net. KonipovaNie stpoki v stpiNg
		if (!(n_fld=GetParmVec(str, p_fld, ':')))             // Net nolei v stpoke faila ciklogpammu?
			continue;
		if ((m == 0) && (bort_tmp=atol(p_fld[1])) != OD.Bort) // Ne sovnadaet N bopta v file ciklogpammu i OD?
		{	printf("\n N bopta ciklogpamma -> %ld != ",bort_tmp);printf("%ld <- OD\n",OD.Bort);
			ErrObr(E_ATR_CYCL_BORT);
		}
		if (m > 0)
		{	tp = atoi(p_fld[CFLD_TP]);                          // tin napametpa
			fo = atoi(p_fld[CFLD_FO]);                          // chastota onposa
			//if ((tp==TYP_AP) || (tp==TYP_APR))
			if ((tp == TYP_AP) || ((tp == TYP_APR) && (sst_fk >= FIZ_AP))) // An?
			{ kn = atoi(p_fld[CFLD_CN]);                        // kaNal pegistpacii
				if ((p_AP[kn]=(struct AP *)calloc(1, sizeof(struct AP))) == (struct AP *)0) // Net namjaty nod stpyktypy An?
					ErrObr(E_ATR_CYCL_MEMSTPKTAn);
				sz_tmp = strlen(p_fld[CFLD_ID]) + 1;              // dliNa nolja
				if ((p_AP[kn]->p_id=(char *)malloc(sz_tmp)) == (char *)0) // Net namjati nod ideNtifikatop An?
					ErrObr(E_ATR_CYCL_IDAn);
				strncpy(p_AP[kn]->p_id, p_fld[CFLD_ID], sz_tmp);  // zanis ideNtifikatopa v stpyktypy
				sz_tmp = strlen(p_fld[CFLD_NM]) + 1;
				if ((p_AP[kn]->p_nm=(char *)malloc(sz_tmp)) == (char *)0) // Net namjati nod NaimeNovaNie An?
					ErrObr(E_ATR_CYCL_NAMEAn);
				strncpy(p_AP[kn]->p_nm, p_fld[CFLD_NM], sz_tmp);  // zanis NaimeNovaNia v stpyktypy
				if ((p_AP[kn]->fz=(float *)malloc(((size_t)dl_fk)*sizeof(float))) == (float *)0) // Net namjati nod massiv fiziki An?
					ErrObr(E_ATR_CYCL_FIZAn);
				p_AP[kn]->tp = tp;                                // zaNeseNie tina, kaNala, chastotu onposa v stpyktypy
				p_AP[kn]->cn = kn;
				p_AP[kn]->fo = fo;
			}
			//if ((tp==TYP_RKD) || (tp==TYP_RKA))
			if ((tp == TYP_RKD) || (tp == TYP_RKA) || ((tp == TYP_RKR) && (sst_fk >= FRM_BP))) // PK?
			{ kn = (sst_fk < FRM_BP) ? atoi(p_fld[CFLD_CN]) : atoi(p_fld[CFLD_CNC]);  // kaNal
				rz = (sst_fk < FRM_BP) ? atoi(p_fld[CFLD_RZ]) : atoi(p_fld[CFLD_RZC]);  // pazpjad
				if (p_RK[kn] == (struct RK *)0)                   // STRKT nod PK Ne vudeleNa?
					if ((p_RK[kn]=(struct RK *)calloc(1, sizeof(struct RK))) == (struct RK *)0) // Net namjaty nod stpyktypy PK?
						ErrObr(E_ATR_CYCL_MEMSTPKTRK);
				if (p_RK[kn] != (struct RK *)0)
				{	sz_tmp = strlen(p_fld[CFLD_ID]) + 1;
					if ((p_RK[kn]->p_id[rz]=(char *)malloc(sz_tmp)) == (char *)0) // Net namjati nod ideNtifikatop PK?
						ErrObr(E_ATR_CYCL_IDRK);
					strncpy(p_RK[kn]->p_id[rz], p_fld[CFLD_ID], sz_tmp);  // zanis ideNtifikatopa PK
					sz_tmp = strlen(p_fld[CFLD_NM]) + 1;
					if ((p_RK[kn]->p_nm[rz]=(char *)malloc(sz_tmp)) == (char *)0) // Net namjati nod NaimeNovaNie PK?
						ErrObr(E_ATR_CYCL_NAMERK);
					strncpy(p_RK[kn]->p_nm[rz], p_fld[CFLD_NM], sz_tmp);  // zanis NaimeNovaNia PK
					if ((p_RK[kn]->fz[rz]=(char *)malloc(((size_t)dl_fk)*sizeof(char))) == (char *)0) // Net namjati nod massiv fiziki PK?
						ErrObr(E_ATR_CYCL_FIZRK);
					p_RK[kn]->par_max[rz] = (float)(LONG_MIN);        // iNicializacija zNacheNi dlja noiska miN/max An
					p_RK[kn]->par_min[rz] = (float)(LONG_MAX);
					p_RK[kn]->tp          = tp;                       // zaNeseNie tina, kaNala, chastotu onposa, pazpjada v stpyktypy
					p_RK[kn]->cn          = kn;
					p_RK[kn]->fo          = fo;
					p_RK[kn]->rz[rz]      = rz;
					p_RK[kn]->nkdr_n[rz]  = p_RK[kn]->nkdr_k[rz] = INI_NK_IRK;  // iNicializacija Nomepa kadpa dlja fopmipovaNia IPK
					p_RK[kn]->zdf[rz]     = 0;                        // iNicializacija zadepjki dlja fopmipovaNia IPK
				}
			}
		}
	}
	free(p_flmem_b);             // osvobojdeNie vpemeNNo zanposcheNNoi namjati
	free(p_ln);
}
//---------------------------------------------------------------
// Cyclogra.cpp
//---------------------------------------------------------------


//---------------------------------------------------------------
// ErrObr.cpp
//---------------------------------------------------------------
// ErrObr.cpp - okoNchaNie pabotu no oshibke (13.01.12)
// n_err - Nomep Oshibki

void ErrObr(int n_err)
{
	if (n_err>=E_ATR_FK_BASE && n_err<=E_ATR_POL_BASE)
		PrintAtrFK();
	if (n_err>=E_ATR_POL_BASE && n_err<=E_ATR_OD_BASE)
		PrintAtrFlight();
	if (n_err>=E_ATR_OD_BASE && n_err<=E_ATR_CYCL_BASE)
		PrintOD();
	printf("\nERROR_%d ", n_err);
	switch (n_err)
	{ case E_OPEN_FK            : printf("otkputia faila-kopii (OpenFK)"); break;
		case E_OPEN_CYCL		  	  : printf("otkputia faila ciklogpammu (ReadCyclogram)"); break;
		case E_MEM_BUFKADR        : printf("vudeleNia namjati nod byfep kadpa faila-konii (main)"); break;
		case E_MEM_MASCODPAR      : printf("vudeleNia namjati Na massiv kodov napametpa (PrintParam)"); break;
		case E_ATR_FK_POZSPB      : printf("pozicioNipovaNija Na Nachalo synepbloka"); break;
		case E_ATR_FK_RD_SSFK     : printf("chteNija slova sostojaNia"); break;
		case E_ATR_FK_SSFK        : printf("slova sostojaNia"); break;
		case E_ATR_FK_RD_SZKDR    : printf("chteNija pazmepa kadra"); break;
		case E_ATR_FK_SZKDR       : printf("pazmepa kadra"); break;
		case E_ATR_FK_RD_DLFK     : printf("chteNija dliNu faila-konii"); break;
		case E_ATR_FK_DLFK        : printf("dliNu faila-konii"); break;
		case E_ATR_FK_RD_DLBURKDR : printf("chteNija dliNu kadpa BYP"); break;
		case E_ATR_FK_DLBURKDR    : printf("dliNu kadpa BYP"); break;
		case E_ATR_FK_RD_SZBURKDR : printf("chteNija pazmepa kadpa BYP"); break;
		case E_ATR_FK_SZBURKDR    : printf("pazmepa kadpa BYP"); break;
		case E_ATR_FK_RD_SZFREEZONE:printf("chteNija pazmepa free-zoNu"); break;
		case E_ATR_FK_SZFREEZONE  : printf("pazmepa free-zoNu"); break;
		case E_ATR_FK_POZSZSPB    : printf("pozicioNipovaNija Na pazmep synepbloka"); break;
		case E_ATR_FK_RD_SZSPB    : printf("chteNija pazmepa synepbloka"); break;
		case E_ATR_FK_SZSPB       : printf("pazmepa synepbloka"); break;
		case E_ATR_POL_POZAPOL    : printf("pozicioNipovaNija Na atpibytu noleta"); break;
		case E_ATR_POL_RD_WEIGHT  : printf("chteNija vesa samoleta"); break;
		case E_ATR_POL_WEIGHT     : printf("vesa samoleta"); break;
		case E_ATR_POL_RD_SAX	    : printf("chteNija SAX"); break;
		case E_ATR_POL_SAX	      : printf("SAX"); break;
		case E_ATR_POL_RD_PRESW		: printf("chteNija davleNia a/n vzleta"); break;
		case E_ATR_POL_PRESW		  : printf("davleNia a/n vzleta"); break;
		case E_ATR_POL_RD_NAMEAP	: printf("chteNija NazvaNija a/n vzleta/nosadki"); break;
		case E_ATR_POL_RD_UNBBP	  : printf("chteNija kypsa Vnn"); break;
		case E_ATR_POL_UNBBP	    : printf("kypsa Vnn"); break;
		case E_ATR_POL_RD_LBBP	  : printf("chteNija dliNu Vnn"); break;
		case E_ATR_POL_LBBP	  	  : printf("dliNu Vnn"); break;
		case E_ATR_POL_RD_HKR		  : printf("chteNija vusotu kpyga"); break;
		case E_ATR_POL_HKR		    : printf("vusotu kpyga"); break;
		case E_ATR_POL_RD_HE      : printf("chteNija vusotu esheloNa"); break;
		case E_ATR_POL_HE         : printf("vusotu esheloNa"); break;
		case E_ATR_POL_RD_HTVG		: printf("chteNija vusotu vhoda v glisady"); break;
		case E_ATR_POL_HTVG		    : printf("vusotu vhoda v glisady"); break;
		case E_ATR_POL_RD_LTVG	  : printf("chteNija passtojaNia do tochki vhoda glissady"); break;
		case E_ATR_POL_LTVG	  	  : printf("passtojaNia do tochki vhoda glissady"); break;
		case E_ATR_POL_RD_HBPRM		: printf("chteNija vusotu npoleta BnPM"); break;
		case E_ATR_POL_HBPRM		  : printf("vusotu npoleta BnPM"); break;
		case E_ATR_POL_RD_LBPRM	  : printf("chteNija passtojaNia ot Vnn do BnPM"); break;
		case E_ATR_POL_LBPRM	    : printf("passtojaNia ot Vnn do BnPM"); break;
		case E_ATR_POL_RD_HDPRM		: printf("chteNija vusotu npoleta DnPM"); break;
		case E_ATR_POL_HDPRM		  : printf("vusotu npoleta DnPM"); break;
		case E_ATR_POL_RD_LDPRM	  : printf("chteNija passtojaNia ot Vnn do BnPM"); break;
		case E_ATR_POL_LDPRM	    : printf("passtojaNia ot Vnn do BnPM"); break;
		case E_ATR_POL_RD_HVPR  	: printf("chteNija vusotu piNjatia pesheNia"); break;
		case E_ATR_POL_HVPR  		  : printf("vusotu piNjatia pesheNia"); break;
		case E_ATR_OD_POZOD       : printf("pozicioNipovaNija Na atpibytu noleta"); break;
		case E_ATR_OD_RD_HOUR    	: printf("chteNija chasov"); break;
		case E_ATR_OD_HOUR    	  : printf("chasov"); break;
		case E_ATR_OD_RD_MINUTE  	: printf("chteNija miNut"); break;
		case E_ATR_OD_MINUTE  	  : printf("miNut"); break;
		case E_ATR_OD_RD_SECOND  	: printf("chteNija sekuNd"); break;
		case E_ATR_OD_SECOND  	  : printf("sekuNd"); break;
		case E_ATR_OD_RD_DATE    	: printf("chteNija datu"); break;
		case E_ATR_OD_DATE    	  : printf("datu"); break;
		case E_ATR_OD_RD_MONTH   	: printf("chteNija mesjaca"); break;
		case E_ATR_OD_MONTH   	  : printf("mesjaca"); break;
		case E_ATR_OD_RD_YEAR    	: printf("chteNija goda"); break;
		case E_ATR_OD_YEAR    	  : printf("goda"); break;
		case E_ATR_OD_RD_REIS    	: printf("chteNija Nomepa peisa"); break;
		case E_ATR_OD_REIS    	  : printf("Nomepa peisa"); break;
		case E_ATR_OD_RD_BORT    	: printf("chteNija Nomepa bopta"); break;
		case E_ATR_OD_BORT    	  : printf("Nomepa bopta"); break;
		case E_ATR_CYCL_ATRFILE   : printf("nolycheNia atpibytov faila ciklogpammu"); break;
		case E_ATR_CYCL_EMPTYFILE : printf("nystoi fail ciklogpammu"); break;
		case E_ATR_CYCL_MEMFILE   : printf("vudeleNia namjati nod fail ciklogpammu"); break;
		case E_ATR_CYCL_FILETOMEM : printf("chteNia v namjat faila ciklogpammu"); break;
		case E_ATR_CYCL_NOLINE    : printf("Net strok v faile ciklogpammu"); break;
		case E_ATR_CYCL_MEMLINE   : printf("vudeleNia namjati nod massiv yKZT Na stpoki ciklogpammu"); break;
		case E_ATR_CYCL_MEMMASAn  : printf("vudeleNia namjati nod massiv yKZT Na stpyktypu An ciklogpammu"); break;
		case E_ATR_CYCL_MEMMASPK  : printf("vudeleNia namjati nod massiv yKZT Na stpyktypu PK ciklogpammu"); break;
		case E_ATR_CYCL_BORT      : printf("N bopta onozNavatelNux daNNux i ciklogpammu"); break;
		case E_ATR_CYCL_MEMSTPKTAn: printf("vudeleNia namjati Na stpyktypy An faila ciklogpammu"); break;
		case E_ATR_CYCL_IDAn      :	printf("vudeleNia namjati nod ideNtifikatop An faila ciklogpammu"); break;
		case E_ATR_CYCL_NAMEAn    :	printf("vudeleNia namjati nod NaimeNovaNie An faila ciklogpammu"); break;
		case E_ATR_CYCL_FIZAn     :	printf("vudeleNia namjati nod massiv fiziki v stpyktype An"); break;
		case E_ATR_CYCL_MEMSTPKTRK: printf("vudeleNia namjati Na stpyktypy PK faila ciklogpammu"); break;
		case E_ATR_CYCL_IDRK      :	printf("vudeleNia namjati nod ideNtifikatop PK faila ciklogpammu"); break;
		case E_ATR_CYCL_NAMERK    :	printf("vudeleNia namjati nod NaimeNovaNie PK faila ciklogpammu"); break;
		case E_ATR_CYCL_FIZRK     :	printf("vudeleNia namjati nod massiv fiziki v stpyktype PK"); break;
		case E_PARKDR_RW_NOFIZ    : printf("fail-konia v kodax (ReadFreeZone)"); break;
		case E_PARKDR_RW_READKDR  : printf("chteNia daNNux kadpa faila-konii (ReadKdr)"); break;
		case E_PARKDR_RW_WRFIZAP  : printf("zanisi fiziki An v free-zony kadpa (WriteFizAP)"); break;
		case E_PARKDR_RW_WRFIZRK  : printf("zanisi fiziki PK v free-zony kadpa (WriteFizRK)"); break;
		case E_PARKDR_RW_WRFREE   : printf("zanisi free-zoNu kadpa v file-koniy (WriteKdr)"); break;
		case E_PARKDR_RW_WRPARAM  : printf("zanis daNNux kaNala v kadp file-koniy (WriteParam)"); break;
		case E_ATRFK_RW_RDPOZSPB  : printf("pozicioNipovaNija Na Nachalo synepbloka (ReadSSFK)"); break;
		case E_ATRFK_RW_RD_RDSSFK : printf("chteNia slova sostojaNia faila-konii (ReadSSFK)"); break;
		case E_ATRFK_RW_RDSSFK    : printf("slova sostojaNia faila-konii (ReadSSFK)"); break;
		case E_ATRFK_RW_WRPOZSPB  : printf("pozicioNipovaNija Na Nachalo synepbloka (WriteSSFK)"); break;
		case E_ATRFK_RW_RD_WRSSFK : printf("chteNia slova sostojaNia faila-konii (WriteSSFK)"); break;
		case E_ATRFK_RW_WR_WRSSFK : printf("zanisi slova sostojaNia faila-konii (WriteSSFK)"); break;
		case E_LSEEK_READKDR	    : printf("nozicioNipovaNija Na kadp faila-konii (ReadKdr)"); break;
		case E_LSEEK_WRFIZAP			: printf("nozicioNipovaNija Na kaNal kadpa faila-konii (WriteFizAP)"); break;
		case E_LSEEK_WRFIZRK			: printf("nozicioNipovaNija Na kaNal kadpa faila-konii (WriteFizRK)"); break;
		case E_LSEEK_WRFREE       : printf("nozicioNipovaNija Na free-zoNy kadpa faila-konii (WriteKdr)"); break;
		case E_LSEEK_WRPARAM      : printf("nozicioNipovaNija Na kaNal kadpa faila-konii (WriteParam)"); break;
		default                   :    ;    break;
	}
	if (n_err >= E_ATR_FK_BASE && n_err < E_ATR_POL_BASE)
		printf(" faila-konii v atpibytax faila-konii (PrintAtrFK)");
	if (n_err >= E_ATR_POL_BASE && n_err < E_ATR_OD_BASE)
		printf(" v atpibytax noleta (PrintAtrFlight)");
	if (n_err >= E_ATR_OD_BASE && n_err < E_ATR_CYCL_BASE)
		printf(" v atpibytax onozNavatelNux daNNux (PrintOD)");
	if (n_err >= E_ATR_CYCL_BASE && n_err < E_PARKDR_RW_BASE)
		printf(" (ReadCyclogram)");
	printf("\n Press any key to exit \n");
	_getch();
	exit(n_err);
}
//---------------------------------------------------------------
// ErrObr.cpp
//---------------------------------------------------------------


//---------------------------------------------------------------
// Memory.cpp
//---------------------------------------------------------------
// Memory.cpp - zanpos i osvobojdeNie namjati (13.01.13)

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
//---------------------------------------------------------------
// Memory.cpp
//---------------------------------------------------------------


//---------------------------------------------------------------
// OpenFK.cpp
//---------------------------------------------------------------
// OPENFK.cpp - otkputie failov (13.01.10)
// 2013.03.08 by B-GangsteR :
// - возможность выбора файла дл€ загрузки
// предпологаетс€ что файл хранитс€ в каталоге data в папке с исполн€емым файлом
// известные имена файлов с данными:
/*
C_pos
C_rul
C_uhf
C_wzl
C_wzlstd
*/

// otkputie faila-konii
int OpenFK()
{
	using namespace std;

/* as it was
//char name_cop[] = "c:\\temp\\C_rul"; // zadaNie imeNi faila-konii
	char name_cop[] = "c:\\temp\\C_wzl";
//char name_cop[] = "c:\\temp\\C_uhf";
//char name_cop[] = "c:\\temp\\C_pos";
*/

	const int f_cpy_n_size = 5; // размер массива
	const char fst_ch = '1'; // первый допустимый дл€ ввода символ, указывающий на им€ с массива
	string f_dir("data\\"); // путь у файлам
	const char* f_cpy_name_ar[f_cpy_n_size] = {"C_pos","C_rul","C_uhf","C_wzl","C_wzlstd"};

	cout<<"\n Choose file to open: \n"
		"\n Press 1 to open 'data\\C_pos'"
		"\n Press 2 to open 'data\\C_rul'"
		"\n Press 3 to open 'data\\C_uhf'"
		"\n Press 4 to open 'data\\C_wzl'"
		"\n Press 5 to open 'data\\C_wzlstd'"
		"\n Press 0 to enter file name and path "<<endl;

	char file_ch = 0;
	string f_name;

	do
	{ file_ch = _getch();}
	while ( !( (file_ch >= fst_ch) && (file_ch < (fst_ch+f_cpy_n_size)) || file_ch=='0' ) );

	// диапазон допустимого ввода
	if( (file_ch >= fst_ch) && (file_ch < (fst_ch+f_cpy_n_size)) )
	{
		 f_name = f_dir + f_cpy_name_ar[file_ch-fst_ch];
	}
	else if (file_ch=='0')
	{
		cout<<"\n Enter file name: \n";
		getline(cin,f_name);
	}
	else
	{
		cout<<"\n Error \n";
	}

	int desc_fl;   // deskpintop faila

	//cout << "Vvedi imja faila-konii <disk:\\katalog\\file>\n";
	//cin >> name_cop;
	printf("Name of file-copy  %s \n",f_name.c_str());
	if ((desc_fl=open(f_name.c_str(), O_RDWR | O_BINARY, 0)) == -1) // otkputie faila-konii
		ErrObr(E_OPEN_FK);
	return(desc_fl);
}
//---------------------------------------------------------------
// OpenFK.cpp
//---------------------------------------------------------------


//---------------------------------------------------------------
// ParKdrRW.cpp
//---------------------------------------------------------------
// ParKdrRW.cpp - chteNie, zanis An, PK i kadov v fail-koniu (13.01.12)

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
//---------------------------------------------------------------
// ParKdrRW.cpp
//---------------------------------------------------------------


//---------------------------------------------------------------
// PrintPar.cpp
//---------------------------------------------------------------
// printpar.cpp - nechat napametpov kadpa faila-konii (13.01.10)

// zadaNie i nechat sniska napametpov
// edited by B-GangsteR
// теперь максимально количество параметров дл€ вывода == общему количеству параметров.
void PrintParam()
{
	using namespace std;

	//const int max_par_num = PRINT_PAR; // максимальное количество параметров
    const int max_par_num = 64;

	unsigned short *mas_cod_par[max_par_num]; // yKZT Na massiv kadr FK
	short can_list[max_par_num],       // massiv xpaNeNia sniska kaNalov dlja nechaty
				can_tek, kol_par=0, i, k;  // tekuschi kaNal/kolichestvo vizyalazipyemux napametpov

//	clrscr();    // ochistka ekpaNa // не работает как положено
	printf(" \t Visualization of parameteres code values bYP\n");
	printf("(channels designated by (*)-symbol will be visualized in binary mode\n");

	cout<<"\n MIN_CAN == "<<MIN_CAN<<"\t MAX_CAN == "<<MAX_CAN;

	cout<<"\n Print all channels? ('y' to confirm, any other key to cancel)";
	char print_all = _getch();

	switch (print_all)
	{
		case 'y': case 'Y':
		{
			for (int i=MIN_CAN; i<=MAX_CAN; i++)
			{
				can_list[kol_par] = i;
				kol_par++;
			}
			break;
		}
		default:
		{
		    printf("\t Enter channel number of visualized parameter registration \n");
			printf(" (MiN/Max number - 0/63, number of parametres in one line - %d, -1 = end of input):\n", max_par_num);
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
				if ((can_tek == END_PRINT_LIST) || (kol_par == max_par_num)) // snisok vvedeN?
				{	printf("List of parametres for visualization is ready \n");
					sleep(1);
					break;
				}
			}
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
		printf("F. ch");             // nechat teksta "shanki"
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
				case UKR60   : printf("*%3d ", can_list[k]); break;
				default      : printf("%3d  ", can_list[k]); break;
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
			{	printf("F. ch");         // novtopeNie nechati "shanki"
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
						case UKR60   : printf("*%3d ", can_list[k]); break;
						default      : printf("%3d  ", can_list[k]); break;
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
	using namespace std;

	for (n_kdr=0; n_kdr < dl_fk; n_kdr++)
//	for (n_kdr=190; n_kdr < 210; n_kdr++)       // KoNec faila-konii?
	{	printf(" \n N=%3d \n",n_kdr);                   // nechat kodov napametpov
		cout<<" ";
	//		printf("TH=%4.1f ",p_AP[TH]->fz[n_kdr]);
//		printf("HB=%5.1f ",p_AP[HB]->fz[n_kdr]);
		printf("VP=%5.1f ",p_AP[VP]->fz[n_kdr]);
		cout<<" ";
		printf("HG=%5.1f ",p_AP[HG]->fz[n_kdr]);
		cout<<" ";
//		printf("UN=%5.1f ",p_AP[UN]->fz[n_kdr]);
//		printf("P kO=%d ",p_RK[RK5]->fz[kOp][n_kdr]);
//		printf("kEO=%d ",p_RK[RK5]->fz[kEOp][n_kdr]);
		printf("RDp=%5.1f ",p_AP[RDp]->fz[n_kdr]);
		cout<<" ";
//		printf("Nvp=%4.1f ",p_AP[Nvp]->fz[n_kdr]);
//		printf("S kO=%d ",p_RK[RK5]->fz[kOs][n_kdr]);
//		printf("kEO=%d ",p_RK[RK5]->fz[kEOs][n_kdr]);
		printf("RDs=%5.1f ",p_AP[RDs]->fz[n_kdr]);
		cout<<" ";
//		printf("Nvs=%4.1f ",p_AP[Nvs]->fz[n_kdr]);
//		printf("L kO=%d ",p_RK[RK5]->fz[kOl][n_kdr]);
//		printf("kEO=%d ",p_RK[RK5]->fz[kEOl][n_kdr]);
		printf("RDl=%5.1f ",p_AP[RDl]->fz[n_kdr]);
		cout<<" ";
//		printf("Nvl=%4.1f ",p_AP[Nvl]->fz[n_kdr]);
//		printf("iSH=%d ", p_RK[RK8]->fz[iSH][n_kdr]);
//		printf("kMM=%d", p_RK[RK8]->fz[kMM][n_kdr]);
		printf("UT=%4.1f ",p_AP[UT]->fz[n_kdr]);
		cout<<" ";
//    printf("MZ=%4.1f ",p_AP[MZ]->fz[n_kdr]);
//    printf("QT/S=%5.2f",p_AP[QT]->fz[n_kdr]);
//    printf("/%5.2f",p_AP[QS]->fz[n_kdr]);
//    printf("oiSH= %d",p_RK[RK8]->fz[oiSH][n_kdr]);
//    printf("iSH= %d", p_RK[RK8]->fz[28][n_kdr]);
		printf("iRWl/p= %d/",p_RK[RK5]->fz[iRWl][n_kdr]);
		cout<<" ";
		printf("%d  ",p_RK[RK8]->fz[iRWp][n_kdr]);
		cout<<" ";
		_getch();
	}
}
//---------------------------------------------------------------
// PrintPar.cpp
//---------------------------------------------------------------




//---------------------------------------------------------------
// RW_SS_FK.cpp
//---------------------------------------------------------------
// RW_SS_FK.cpp - chteNie/zanis slova-sostojaNia faila-konii (13.01.12)

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
//---------------------------------------------------------------
// RW_SS_FK.cpp
//---------------------------------------------------------------


//---------------------------------------------------------------
// GetParmV.cpp
//---------------------------------------------------------------
// pazbivka tekstovoi stpoki Na polja no simvoly pazdelitelju
// *p_str - yKZT Na stpoky; *p_mpf[] - yKZT Na Nachalo nolja v stroke
//  sym   - simvol pazdelitel poley v stroke
short GetParmVec(char *p_str, char *p_mpf[], char sym)
{ char *p_str_b, *p_str_e; // yKZT Nachala/koNca stpoki
	short n_fld;             // kolichestvo noley

	p_str_b      = p_str;
	n_fld        = 0;
	p_mpf[n_fld] = p_str_b;
	while (1)
	{ while (*p_str_b == ' ')
			*p_str_b++ = 0;
		if (*p_str_b != sym)
		{ p_mpf[n_fld] = p_str_b;
			while ((*p_str_b!=sym)&&(*p_str_b!='\n')&&(*p_str_b!=0))
				p_str_b++;
			if (p_str_b != p_mpf[n_fld])
			{ p_str_e = p_str_b - 1;
				while (*p_str_e == ' ')
					*p_str_e-- = 0;
			}
			else
				p_mpf[n_fld] = (char *) 0;
		}
		else
			p_mpf[n_fld] = (char *) 0;
		if (*p_str_b == sym)
			n_fld++;
		if ((*p_str_b == '\n') || !(*p_str_b))
		{ *p_str_b = 0;
			return(n_fld);
		}
		*p_str_b++ = 0;
	}
}
//---------------------------------------------------------------
// GetParmV.cpp
//---------------------------------------------------------------



//------------------------
// addictional functions writted by B-GangsteR


// печать физических значений параметров из массивов структур AP & PK
// переписано/поправлено
void PrintFreeZone_v2()
{
	using namespace std;
	int n_kdr; // номер кадра

    char mode_ch=0;

	do
	{
        system("CLS"); // о ужќс

		cout<<"\n\n Choose appropriate: \n"
		<<"\n 1 - Print analog parameters"
		<<"\n 2 - Print single commands \n"
		<<"\n esc or 'q' to exit \n";
		mode_ch = _getch();

		switch(mode_ch)
		{
			case '1':
			{
				cout<<"\n Analog parameters \n";
				for (int par_num=0; par_num<=64; par_num++)
				{
					if (p_AP[par_num]==0)
					{	cout<<"\n\n Parametr #"<<par_num<<" is absent";}
					else
					{
						cout<<"\n\n Parametr #"<<par_num;

						cout<<"\n Identifier == "<<p_AP[par_num]->p_id;
						cout<<"\n Name == "<<p_AP[par_num]->p_nm;
						cout<<"\n \"tin\" == "<<p_AP[par_num]->tp;
						cout<<"\n 'bYp' channel == "<<p_AP[par_num]->cn;
						cout<<"\n Registration rate in frame == "<<p_AP[par_num]->fo;
						cout<<"\n Base channel registration of analog parameter in frame == "<<p_AP[par_num]->cnm;
						cout<<"\n processing flag == "<<p_AP[par_num]->fl_obr;

						cout<<"\n  (Press space or any other key to continue output) \n";
						cout<<"\n Frame number \t | Physical value";
						for (n_kdr=0; n_kdr < dl_fk; n_kdr++)
						{
							cout<<"\n "<<n_kdr<<"\t\t | "<<p_AP[par_num]->fz[n_kdr];

							if(n_kdr%20 == 0)
							_getch();
						}
					}

					cout<<"\n Press 'c' to continue \n";
					char input_ch = 0;
					do
					{input_ch = _getch();}
					while (input_ch!= 'c' && input_ch!= 'C' );
				}
				break;
			}


			case '2':
			{
				cout<<"\n Single command \n";
				for (int channel=0; channel<=64; channel++)
				{
					if (p_RK[channel]== 0)
					{ cout<<"\n\n Single command in channel #"<<channel<<" is absent";}
					else
					{
						cout<<"\n\n Single command in channel #"<<channel;

							cout<<"\n \"tin\" == "<<p_RK[channel]->tp;
							cout<<"\n 'bYp' channel == "<<p_RK[channel]->cn;
							cout<<"\n Registration rate in frame == "<<p_RK[channel]->fo;

						for (int com_num=0; com_num<32; com_num++)
						{
							if(p_RK[channel]->fz[com_num] == 0)
							{
								cout<<"\n\n Single command #"<<com_num<<" is absent";
							}
							else
							{
								cout<<"\n\n Single command #"<<com_num;

								cout<<"\n analog parameter min val == "<<p_RK[channel]->par_min[com_num];
								cout<<"\n analog parameter max val == "<<p_RK[channel]->par_max[com_num];
								cout<<"\n 'IRK' discharge == "<<p_RK[channel]->rz[com_num];
								cout<<"\n processing flag == "<<p_RK[channel]->fl_obr[com_num];
								cout<<"\n Begining frame number == "<<p_RK[channel]->nkdr_n[com_num];
								cout<<"\n End frame number == "<<p_RK[channel]->nkdr_k[com_num];
								cout<<"\n 'IRK' delay of forming == "<<p_RK[channel]->zdf[com_num];

								cout<<"\n  (Press space or any any other key to continue output) \n";
								for (n_kdr=0; n_kdr < dl_fk; n_kdr++)
								{
									cout<<"\n____________________________________";
									cout<<"\n Frame number "<<n_kdr;
									cout<<"\n Command physical value == "<<"\""<<p_RK[channel]->fz[com_num][n_kdr]
									<<"\" (val = "<<static_cast<int> (p_RK[channel]->fz[com_num][n_kdr])<<")";
									cout<<"\n Identifier == \""<<p_RK[channel]->p_id[com_num][n_kdr]<<"\""
									<<" (val = "<<static_cast<int>(p_RK[channel]->p_id[com_num][n_kdr])<<")";
									cout<<"\n Name == \""<<p_RK[channel]->p_nm[com_num][n_kdr]<<"\""
									<<" (val = "<<static_cast<int> (p_RK[channel]->p_nm[com_num][n_kdr])<<")";

									if(n_kdr%5 == 0)
									_getch();
								}
							}
						cout<<"\n Press 'c' to continue \n";
						char input_ch = 0;
						do
						{input_ch = _getch();}
						while (input_ch!= 'c' && input_ch!= 'C' );
						}
					}
				}    // end of single command output
				break;
			}

			case 'q': case 'Q':
			{
				mode_ch = 27;
				break;
			}
			default:
			{
			   break;
			}
		}
	}
	while (mode_ch!=27);
}

// функции и данные обработки полетной информации
// original + by B-GangsteR 2013.03.28 + dima.rgb

#include "flightDataProcessingForm.h"

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
void PrintAtrFK(TStrings* out_str, bool clear_at_first) {
	if(clear_at_first)
		out_str->Clear();

	out_str->Add("File-copy attributes");
	out_str->Add("");
	out_str->Add("\tfile-copy state (" + IntToStr(sst_fk) + ")");
	out_str->Add("\tAttributes:");
	out_str->Add("\t     copies\t\t\t\t    = " + IntToStr((sst_fk||AFK_INP) ? 1 : 0));
	out_str->Add("\t     identification data (OD)\t\t    = " + IntToStr((sst_fk&OD_INP) ? 1 : 0));
	out_str->Add("\t     flight\t\t\t\t    = " + IntToStr((sst_fk&APOL_INP) ? 1 : 0));
	out_str->Add("\t     re-structurization single-command (PK) = " + IntToStr((sst_fk&FRM_BP) ? 1 : 0));
	out_str->Add("\t     physics An\t\t\t    = " + IntToStr((sst_fk&FIZ_AP) ? 1 : 0));
	out_str->Add("\tForming Pn passage:");
	out_str->Add("\t     1 - " + IntToStr((sst_fk&FRM_CP_1) ? 1 : 0));
	out_str->Add("\t     2 - " + IntToStr((sst_fk&FRM_CP_2) ? 1 : 0));
	out_str->Add("\t     3 - " + IntToStr((sst_fk&FRM_CP_3) ? 1 : 0));
	out_str->Add("\tForming IPK passage:");
	out_str->Add("\t     1 - " + IntToStr((sst_fk&FRM_IRK_1) ? 1 : 0));
	out_str->Add("\t     2 - " + IntToStr((sst_fk&FRM_IRK_2) ? 1 : 0));
	out_str->Add("\t     3 - " + IntToStr((sst_fk&FRM_IRK_3) ? 1 : 0));
	out_str->Add("\tForming Sb\t\t= " + IntToStr((sst_fk&FRM_SB) ? 1 : 0));
	out_str->Add("\tFrame size (2..400)\t\t= " + IntToStr(sz_kdr) + " (byte)");
	out_str->Add("\tFile-copy size (1..1000)\t= " + IntToStr(dl_fk) + " (frame)");
	out_str->Add("\tbYP frame size (2..128)\t= " + IntToStr(dl_bur_kdr) + " (words)");
	out_str->Add("\tbYP frame size (2..128)\t= " + IntToStr(sz_bur_kdr) + " (byte)");
	out_str->Add("\tFree-zone size (2..400)\t= " + IntToStr(sz_free_zone) + " (byte)");
	out_str->Add("\tSuperblock size (1024..4096)\t= " + IntToStr(sz_spb) + " (byte)\n");

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
void PrintOD(TStrings* out_str, bool clear_at_first) {
	if(clear_at_first)
		out_str->Clear();

	out_str->Add("");
	out_str->Add("");
	out_str->Add("Flight identification data");
	out_str->Add("");
	out_str->Add("\tHour\t     = " + IntToStr(OD.Hour));
	out_str->Add("\tMin\t     = " + IntToStr(OD.Minute));
	out_str->Add("\tSec\t     = " + FloatToStr(OD.Second) );
	out_str->Add("\tDate\t     = " + IntToStr(OD.Date));
	out_str->Add("\tMounth\t     = " + IntToStr(OD.Month));
	out_str->Add("\tYear\t     = " + IntToStr(OD.Year));
	out_str->Add("\tFlight('reys') = " + IntToStr(OD.Reis));
	out_str->Add("\tSide('bort')    = " + FloatToStrF(OD.Bort,TFloatFormat(),0,0));

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
void PrintAtrFlight(TStrings* out_str, bool clear_at_first) {
	if(clear_at_first)
		out_str->Clear();

	out_str->Add("");
	out_str->Add("");
	out_str->Add("Flight attributes");
	out_str->Add("");
	out_str->Add("\tWZL\t\t= " + String(APOL.name_apwzl));
	out_str->Add("\tweight(20-40)\t= " + FloatToStr(APOL.Weight));
	out_str->Add("\tCAX(10-30)\t= " + FloatToStr(APOL.CAX));
	out_str->Add("\tPressure(700-780)\t= " + IntToStr(APOL.Pressure));
	out_str->Add("\tUNvnn(0-360)\t= " + IntToStr(APOL.UN_BPP_wzl));
	out_str->Add("\tLvnn(1-4km)\t= " + IntToStr(APOL.L_BPP_wzl));
	out_str->Add("\tHkr(300-900)\t= " + IntToStr(APOL.H_kr_wzl));
	out_str->Add("\tPOS\t\t= " + String(APOL.name_appos));
	out_str->Add("\tUNvnn(0-360)\t= " + IntToStr(APOL.UN_BPP_pos));
	out_str->Add("\tLvnn(1-4km)\t= " + IntToStr(APOL.L_BPP_pos));
	out_str->Add("\tHep(800-1500)\t= " + IntToStr(APOL.H_ep_pos));
	out_str->Add("\tH_kr(300-900)\t= " + IntToStr(APOL.H_kr_pos));
	out_str->Add("\tLtvg(4-12km)\t= " + IntToStr(APOL.L_tvg));
	out_str->Add("\tHtvg(300-900)\t= " + IntToStr(APOL.H_tvg));
	out_str->Add("\tLdprm(2-5km)\t= " + IntToStr(APOL.L_dprm));
	out_str->Add("\tHdprm(150-300)\t= " + IntToStr(APOL.H_dprm));
	out_str->Add("\tLbprm(.8-1.5km)\t= " + IntToStr(APOL.L_bprm));
	out_str->Add("\tHbprm(50-100)\t= " + IntToStr(APOL.H_bprm));
	out_str->Add("\tHvpr(20-100)\t= " + IntToStr(APOL.H_vpr));

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
void ReadCyclogram(const String cyclogram) {
	using namespace std;
	char *p_flmem_b, *p_flmem_e, *p_flmem_t, // yKZT file-memory (Nachalo/koNec/tekysch)
			 *p_txt,     *p_txt_t,               // Nachalo/tekysch yKZT Na tekst
			**p_ln,     **p_ln_t,                // Nachalo/tekysch yKZT stpoky teksta
			 *p_fld[10],                         // massiv yKZT Na nolja stpoki ciklogpammu
				str[80];                           // stpiNg dlja vpemeNNogo xpaNeNia teksta

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

	if ((pf_file = fopen(AnsiString(cyclogram).c_str(), "r")) == NULL)          // symvolN.fail ciklogpammu otkput?
		ErrObr(E_OPEN_CYCL);
	if (stat(AnsiString(cyclogram).c_str(), &stat_fl) < 0)                      // atpibytu faila ciklogpammu nolycheNu?
		ErrObr(E_ATR_CYCL_ATRFILE);
	sz_file = stat_fl.st_size;                              // dliNa faila ciklogpammu
	if (!sz_file)                                           // fail ciklogpammu nystoi?
		ErrObr(E_ATR_CYCL_EMPTYFILE);
	if ((p_flmem_b = (char *)malloc(sz_file)) == (char *)0) // namjat nod fail ciklogpammu vudeleNa?
		ErrObr(E_ATR_CYCL_MEMFILE);
	p_flmem_e = p_flmem_b + sz_file;                        // yKZT Na koNec svob.namjati
	n_rd = fread(p_flmem_b, sz_file, 1, pf_file);           // chteNie v namjat faila ciklogpammu

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
//		if (!(n_fld=GetParmVec(str, p_fld, ':')))             // Net nolei v stpoke faila ciklogpammu?
		n_fld=GetParmVec(str, p_fld, ':');
		if (! n_fld)             // Net nolei v stpoke faila ciklogpammu?
			continue;
		if ((m == 0) && (bort_tmp=atol(p_fld[1])) != OD.Bort) // Ne sovnadaet N bopta v file ciklogpammu i OD?
		{	output_error(UnicodeString("\n N bopta ciklogpamma -> " + IntToStr(static_cast<int> (bort_tmp)) +" != ") );
			output_error(UnicodeString(IntToStr(static_cast<int>(OD.Bort)) + " <- OD\n"));
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
	String_receiver str_rec(true); // принимает и накапливает строки

	if (n_err>=E_ATR_FK_BASE && n_err<=E_ATR_POL_BASE)
		str_rec("n_err>=E_ATR_FK_BASE && n_err<=E_ATR_POL_BASE");
	if (n_err>=E_ATR_POL_BASE && n_err<=E_ATR_OD_BASE)
		str_rec("n_err>=E_ATR_POL_BASE && n_err<=E_ATR_OD_BASE");
	if (n_err>=E_ATR_OD_BASE && n_err<=E_ATR_CYCL_BASE)
		str_rec("n_err>=E_ATR_OD_BASE && n_err<=E_ATR_CYCL_BASE");

	UnicodeString u_str = IntToStr(n_err);
	AnsiString ansi = u_str;
	str_rec(std::string("\n ERROR  ") + std::string(ansi.c_str()));

	switch (n_err)
	{ case E_OPEN_FK              : str_rec("otkputia faila-kopii (OpenFK)"); break;
		case E_OPEN_CYCL		  : str_rec("otkputia faila ciklogpammu (ReadCyclogram)"); break;
		case E_MEM_BUFKADR        : str_rec("vudeleNia namjati nod byfep kadpa faila-konii (main)"); break;
		case E_MEM_MASCODPAR      : str_rec("vudeleNia namjati Na massiv kodov napametpa (PrintParam)"); break;
		case E_ATR_FK_POZSPB      : str_rec("pozicioNipovaNija Na Nachalo synepbloka"); break;
		case E_ATR_FK_RD_SSFK     : str_rec("chteNija slova sostojaNia"); break;
		case E_ATR_FK_SSFK        : str_rec("slova sostojaNia"); break;
		case E_ATR_FK_RD_SZKDR    : str_rec("chteNija pazmepa kadra"); break;
		case E_ATR_FK_SZKDR       : str_rec("pazmepa kadra"); break;
		case E_ATR_FK_RD_DLFK     : str_rec("chteNija dliNu faila-konii"); break;
		case E_ATR_FK_DLFK        : str_rec("dliNu faila-konii"); break;
		case E_ATR_FK_RD_DLBURKDR : str_rec("chteNija dliNu kadpa BYP"); break;
		case E_ATR_FK_DLBURKDR    : str_rec("dliNu kadpa BYP"); break;
		case E_ATR_FK_RD_SZBURKDR : str_rec("chteNija pazmepa kadpa BYP"); break;
		case E_ATR_FK_SZBURKDR    : str_rec("pazmepa kadpa BYP"); break;
		case E_ATR_FK_RD_SZFREEZONE:str_rec("chteNija pazmepa free-zoNu"); break;
		case E_ATR_FK_SZFREEZONE  : str_rec("pazmepa free-zoNu"); break;
		case E_ATR_FK_POZSZSPB    : str_rec("pozicioNipovaNija Na pazmep synepbloka"); break;
		case E_ATR_FK_RD_SZSPB    : str_rec("chteNija pazmepa synepbloka"); break;
		case E_ATR_FK_SZSPB       : str_rec("pazmepa synepbloka"); break;
		case E_ATR_POL_POZAPOL    : str_rec("pozicioNipovaNija Na atpibytu noleta"); break;
		case E_ATR_POL_RD_WEIGHT  : str_rec("chteNija vesa samoleta"); break;
		case E_ATR_POL_WEIGHT     : str_rec("vesa samoleta"); break;
		case E_ATR_POL_RD_SAX	  : str_rec("chteNija SAX"); break;
		case E_ATR_POL_SAX	      : str_rec("SAX"); break;
		case E_ATR_POL_RD_PRESW	  : str_rec("chteNija davleNia a/n vzleta"); break;
		case E_ATR_POL_PRESW	  : str_rec("davleNia a/n vzleta"); break;
		case E_ATR_POL_RD_NAMEAP  : str_rec("chteNija NazvaNija a/n vzleta/nosadki"); break;
		case E_ATR_POL_RD_UNBBP	  : str_rec("chteNija kypsa Vnn"); break;
		case E_ATR_POL_UNBBP	  : str_rec("kypsa Vnn"); break;
		case E_ATR_POL_RD_LBBP	  : str_rec("chteNija dliNu Vnn"); break;
		case E_ATR_POL_LBBP	  	  : str_rec("dliNu Vnn"); break;
		case E_ATR_POL_RD_HKR	  : str_rec("chteNija vusotu kpyga"); break;
		case E_ATR_POL_HKR		  : str_rec("vusotu kpyga"); break;
		case E_ATR_POL_RD_HE      : str_rec("chteNija vusotu esheloNa"); break;
		case E_ATR_POL_HE         : str_rec("vusotu esheloNa"); break;
		case E_ATR_POL_RD_HTVG	  : str_rec("chteNija vusotu vhoda v glisady"); break;
		case E_ATR_POL_HTVG		  : str_rec("vusotu vhoda v glisady"); break;
		case E_ATR_POL_RD_LTVG	  : str_rec("chteNija passtojaNia do tochki vhoda glissady"); break;
		case E_ATR_POL_LTVG	  	  : str_rec("passtojaNia do tochki vhoda glissady"); break;
		case E_ATR_POL_RD_HBPRM	  : str_rec("chteNija vusotu npoleta BnPM"); break;
		case E_ATR_POL_HBPRM	  : str_rec("vusotu npoleta BnPM"); break;
		case E_ATR_POL_RD_LBPRM	  : str_rec("chteNija passtojaNia ot Vnn do BnPM"); break;
		case E_ATR_POL_LBPRM	  : str_rec("passtojaNia ot Vnn do BnPM"); break;
		case E_ATR_POL_RD_HDPRM	  : str_rec("chteNija vusotu npoleta DnPM"); break;
		case E_ATR_POL_HDPRM	  : str_rec("vusotu npoleta DnPM"); break;
		case E_ATR_POL_RD_LDPRM	  : str_rec("chteNija passtojaNia ot Vnn do BnPM"); break;
		case E_ATR_POL_LDPRM	  : str_rec("passtojaNia ot Vnn do BnPM"); break;
		case E_ATR_POL_RD_HVPR    : str_rec("chteNija vusotu piNjatia pesheNia"); break;
		case E_ATR_POL_HVPR  	  : str_rec("vusotu piNjatia pesheNia"); break;
		case E_ATR_OD_POZOD       : str_rec("pozicioNipovaNija Na atpibytu noleta"); break;
		case E_ATR_OD_RD_HOUR     : str_rec("chteNija chasov"); break;
		case E_ATR_OD_HOUR    	  : str_rec("chasov"); break;
		case E_ATR_OD_RD_MINUTE   : str_rec("chteNija miNut"); break;
		case E_ATR_OD_MINUTE  	  : str_rec("miNut"); break;
		case E_ATR_OD_RD_SECOND   : str_rec("chteNija sekuNd"); break;
		case E_ATR_OD_SECOND  	  : str_rec("sekuNd"); break;
		case E_ATR_OD_RD_DATE     : str_rec("chteNija datu"); break;
		case E_ATR_OD_DATE    	  : str_rec("datu"); break;
		case E_ATR_OD_RD_MONTH    : str_rec("chteNija mesjaca"); break;
		case E_ATR_OD_MONTH   	  : str_rec("mesjaca"); break;
		case E_ATR_OD_RD_YEAR     : str_rec("chteNija goda"); break;
		case E_ATR_OD_YEAR    	  : str_rec("goda"); break;
		case E_ATR_OD_RD_REIS     : str_rec("chteNija Nomepa peisa"); break;
		case E_ATR_OD_REIS    	  : str_rec("Nomepa peisa"); break;
		case E_ATR_OD_RD_BORT     : str_rec("chteNija Nomepa bopta"); break;
		case E_ATR_OD_BORT    	  : str_rec("Nomepa bopta"); break;
		case E_ATR_CYCL_ATRFILE   : str_rec("nolycheNia atpibytov faila ciklogpammu"); break;
		case E_ATR_CYCL_EMPTYFILE : str_rec("nystoi fail ciklogpammu"); break;
		case E_ATR_CYCL_MEMFILE   : str_rec("vudeleNia namjati nod fail ciklogpammu"); break;
		case E_ATR_CYCL_FILETOMEM : str_rec("chteNia v namjat faila ciklogpammu"); break;
		case E_ATR_CYCL_NOLINE    : str_rec("Net strok v faile ciklogpammu"); break;
		case E_ATR_CYCL_MEMLINE   : str_rec("vudeleNia namjati nod massiv yKZT Na stpoki ciklogpammu"); break;
		case E_ATR_CYCL_MEMMASAn  : str_rec("vudeleNia namjati nod massiv yKZT Na stpyktypu An ciklogpammu"); break;
		case E_ATR_CYCL_MEMMASPK  : str_rec("vudeleNia namjati nod massiv yKZT Na stpyktypu PK ciklogpammu"); break;
		case E_ATR_CYCL_BORT      : str_rec("N bopta onozNavatelNux daNNux i ciklogpammu"); break;
		case E_ATR_CYCL_MEMSTPKTAn: str_rec("vudeleNia namjati Na stpyktypy An faila ciklogpammu"); break;
		case E_ATR_CYCL_IDAn      :	str_rec("vudeleNia namjati nod ideNtifikatop An faila ciklogpammu"); break;
		case E_ATR_CYCL_NAMEAn    :	str_rec("vudeleNia namjati nod NaimeNovaNie An faila ciklogpammu"); break;
		case E_ATR_CYCL_FIZAn     :	str_rec("vudeleNia namjati nod massiv fiziki v stpyktype An"); break;
		case E_ATR_CYCL_MEMSTPKTRK: str_rec("vudeleNia namjati Na stpyktypy PK faila ciklogpammu"); break;
		case E_ATR_CYCL_IDRK      :	str_rec("vudeleNia namjati nod ideNtifikatop PK faila ciklogpammu"); break;
		case E_ATR_CYCL_NAMERK    :	str_rec("vudeleNia namjati nod NaimeNovaNie PK faila ciklogpammu"); break;
		case E_ATR_CYCL_FIZRK     :	str_rec("vudeleNia namjati nod massiv fiziki v stpyktype PK"); break;
		case E_PARKDR_RW_NOFIZ    : str_rec("fail-konia v kodax (ReadFreeZone)"); break;
		case E_PARKDR_RW_READKDR  : str_rec("chteNia daNNux kadpa faila-konii (ReadKdr)"); break;
		case E_PARKDR_RW_WRFIZAP  : str_rec("zanisi fiziki An v free-zony kadpa (WriteFizAP)"); break;
		case E_PARKDR_RW_WRFIZRK  : str_rec("zanisi fiziki PK v free-zony kadpa (WriteFizRK)"); break;
		case E_PARKDR_RW_WRFREE   : str_rec("zanisi free-zoNu kadpa v file-koniy (WriteKdr)"); break;
		case E_PARKDR_RW_WRPARAM  : str_rec("zanis daNNux kaNala v kadp file-koniy (WriteParam)"); break;
		case E_ATRFK_RW_RDPOZSPB  : str_rec("pozicioNipovaNija Na Nachalo synepbloka (ReadSSFK)"); break;
		case E_ATRFK_RW_RD_RDSSFK : str_rec("chteNia slova sostojaNia faila-konii (ReadSSFK)"); break;
		case E_ATRFK_RW_RDSSFK    : str_rec("slova sostojaNia faila-konii (ReadSSFK)"); break;
		case E_ATRFK_RW_WRPOZSPB  : str_rec("pozicioNipovaNija Na Nachalo synepbloka (WriteSSFK)"); break;
		case E_ATRFK_RW_RD_WRSSFK : str_rec("chteNia slova sostojaNia faila-konii (WriteSSFK)"); break;
		case E_ATRFK_RW_WR_WRSSFK : str_rec("zanisi slova sostojaNia faila-konii (WriteSSFK)"); break;
		case E_LSEEK_READKDR	  : str_rec("nozicioNipovaNija Na kadp faila-konii (ReadKdr)"); break;
		case E_LSEEK_WRFIZAP	  : str_rec("nozicioNipovaNija Na kaNal kadpa faila-konii (WriteFizAP)"); break;
		case E_LSEEK_WRFIZRK	  : str_rec("nozicioNipovaNija Na kaNal kadpa faila-konii (WriteFizRK)"); break;
		case E_LSEEK_WRFREE       : str_rec("nozicioNipovaNija Na free-zoNy kadpa faila-konii (WriteKdr)"); break;
		case E_LSEEK_WRPARAM      : str_rec("nozicioNipovaNija Na kaNal kadpa faila-konii (WriteParam)"); break;
		default                   : break;
	}
	if (n_err >= E_ATR_FK_BASE && n_err < E_ATR_POL_BASE)
		str_rec(" faila-konii v atpibytax faila-konii (PrintAtrFK)");
	if (n_err >= E_ATR_POL_BASE && n_err < E_ATR_OD_BASE)
		str_rec(" v atpibytax noleta (PrintAtrFlight)");
	if (n_err >= E_ATR_OD_BASE && n_err < E_ATR_CYCL_BASE)
		str_rec(" v atpibytax onozNavatelNux daNNux (PrintOD)");
	if (n_err >= E_ATR_CYCL_BASE && n_err < E_PARKDR_RW_BASE)
		str_rec(" (ReadCyclogram)");

//	output_error(str_rec.get_string());

	throw Data_load_error(UnicodeString(" 'Data_load_error' exception @ ErrObr(int n_err) : n_err== ")
		+ IntToStr(n_err) + UnicodeString("\n Message: \n \"")
		+ UnicodeString(str_rec.get_string().c_str()) + UnicodeString(" \" "));
}
//---------------------------------------------------------------
// ErrObr.cpp
//---------------------------------------------------------------


//---------------------------------------------------------------
// Memory.cpp
//---------------------------------------------------------------
// Memory.cpp - zanpos i osvobojdeNie namjati (13.01.13)

// osvobojdeNie vudeleNNoi namjati
void FreeMem() {
	short i, k;

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
// - возможность выбора файла для загрузки
// предпологается что файл хранится в каталоге data в папке с исполняемым файлом
// известные имена файлов с данными:
/*
C_pos
C_rul
C_uhf
C_wzl
C_wzlstd
*/

// otkputie faila-konii
int OpenFK(const String f_name) {
	using namespace std;

	int desc_fl;   // deskpintop faila

	if(( desc_fl = open(AnsiString(f_name).c_str(), O_RDWR | O_BINARY, 0)) == -1 ) // otkputie faila-konii
		ErrObr(E_OPEN_FK);
	return desc_fl;
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
// теперь максимально количество параметров для вывода == общему количеству параметров.
void PrintParam(TStringGrid* grid, TStrings* info_str) {
	using namespace std;

	unsigned short *mas_cod_par[maxChannel]; // yKZT Na massiv kadr FK
	short can_list[maxChannel],       // massiv xpaNeNia sniska kaNalov dlja nechaty
				can_tek, kol_par=0, i, k;  // tekuschi kaNal/kolichestvo vizyalazipyemux napametpov

	grid->ColCount=0;  // очистка
	grid->RowCount=0;
	info_str->Clear();

//	info_str->Add(" Visualization of parameteres code values bYP ");
	info_str->Add("Rows are frames, columns are channels");
	info_str->Add("channels designated by (*)-symbol will be visualized in binary mode");

	for (int i=MIN_CAN; i<=MAX_CAN; i++)    // формирование массива номеров всех каналов
	{
		can_list[kol_par] = i;
		kol_par++;
	}

	if (kol_par > 0)                   // napametru dlja nechaty vvedeNu?
	{	for (i=0; i < kol_par; i++)      // Da. vudeleNie namjati nod massiv napametpov
		if ((mas_cod_par[i]=(unsigned short *)malloc(dl_fk*sizeof(short))) == (unsigned short *)0)
			ErrObr(E_MEM_MASCODPAR);       // ??? Ne pabotaet!!!

		for (i=0; i < dl_fk; i++)        // KoNec faila-konii?
		{	ReadKdr((int)i);               // chteNie daNNux kadpa faila-konii
			for (k=0; k < kol_par; k++)    // koNec spiska vizyalazipyemux napametpov?
				mas_cod_par[k][i] = (unsigned short) mas_bur_pi[can_list[k]]; // zapis koda napametpa v massiv zNacheNi napametpa
		}
		grid->RowCount += 1;
		grid->FixedRows = 1;
		grid->ColCount += 1;
		grid->FixedCols = 1;
		grid->Cells[0][0] = "Frame\\channel";             // nechat teksta "shanki"

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
				case UKR60   :
				{
					grid->Cells[grid->ColCount -1][0] = "*" + IntToStr(can_list[k]);
					grid->ColCount += 1;
					break;
				}
				default      :
				{
					grid->Cells[grid->ColCount -1][0] = IntToStr(can_list[k]);
					grid->ColCount += 1;
					break;
				}
			}

		for (i=0; i < dl_fk; i++)        // KoNec faila-konii?
		{
			grid->Cells[0][grid->RowCount -1] = IntToStr(i+1);         // nechat Nomepa kadpa
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
					case UKR60   :
					{
						char buf[100];
						itoa(mas_cod_par[k][i],buf,8);  // octal
						AnsiString ansi_str(buf);
						grid->Cells[k+1][grid->RowCount -1] = ansi_str;
						break;
					}
					default      :
					{
						grid->Cells[k+1][grid->RowCount -1] = IntToStr(mas_cod_par[k][i]);
						break;
					}
				}
			grid->RowCount += 1;
		}
	   	for (i=0; i < kol_par; i++)      // koNec spiska vizyalazipyemux napametpov?
			free(mas_cod_par[i]);          // osvobojdeNie vudeleNNoi namjati
	}
	else
	{ output_error(UnicodeString(" Channels aren't entered. (can't visualize parameter codes)"));}
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
void PrintFreeZone_v2(TStrings* anlg_par_memo, TStringGrid* anlg_par_grid,
	TStrings* sngl_com_memo, TStringGrid* sngl_com_grid, TStrings* checkStrings,
	TStrings* ChannelBox_strings)
{
	using namespace std;
	int n_kdr; // номер кадра

	// работа с аналоговыми параметрами
	anlg_par_memo->Clear();
	checkStrings->Clear();

	anlg_par_grid->ColCount = 0; // удалить все...
	anlg_par_grid->RowCount = 0;

	anlg_par_grid->ColCount = 1;
	anlg_par_grid->RowCount = 1;

	anlg_par_memo->Add("Rows are frames, columns are channels");
	anlg_par_grid->Cells[0][0] = "Frame\\Chan.ph.val";

	for (n_kdr=0; n_kdr < dl_fk; n_kdr++) { // вывести все номера кадров (время)
		anlg_par_grid->Cells[0][n_kdr+1] = IntToStr(n_kdr);
		anlg_par_grid->RowCount += 1;
	}

	anlg_param_vec.clear(); // очистить вектор данных и информации про параметр
	for( int par_num = 0; par_num < maxChannel; par_num++ ) { // вывод параметров // строго меньше
		anlg_par_memo->Add("");
		anlg_par_memo->Add("");

		anlg_par_grid->Cells[par_num+1][0] = IntToStr(par_num);  // шапка (номер параметра)
		anlg_par_grid->ColCount += 1;

		if( p_AP[par_num]==0 )
			anlg_par_memo->Add(" Parametr #"+ IntToStr(par_num) + " is absent");
		else {
/*			String itemGraph = IntToStr(par_num) + ". " +
				p_AP[par_num]->p_id + "   (" + String(p_AP[par_num]->p_nm) + ")";
			checkStrings->Add(itemGraph);
*/
			Analog_parameter anlg_param;  // добавить информацию про параметр
			anlg_param.number = par_num;
			anlg_param.id = p_AP[par_num]->p_id;
			anlg_param.name = p_AP[par_num]->p_nm;

			String itemGraph = IntToStr(anlg_param.number) + ". " +
			String(anlg_param.id.c_str()) + " (" + String(anlg_param.name.c_str()) + ")";
			checkStrings->Add(itemGraph);
			ChannelBox_strings->Add(itemGraph);

			anlg_par_memo->Add(" Parameter #" + IntToStr(par_num));
			anlg_par_memo->Add("\n Identifier == " + String(p_AP[par_num]->p_id));
			anlg_par_memo->Add("\n Name == " + String(p_AP[par_num]->p_nm));
			anlg_par_memo->Add("\n \"tin\" == " + IntToStr(p_AP[par_num]->tp));
			anlg_par_memo->Add("\n 'bYp' channel == " + IntToStr(p_AP[par_num]->cn));
			anlg_par_memo->Add("\n Registration rate in frame == " + IntToStr(p_AP[par_num]->fo));
			anlg_par_memo->Add("\n Base channel registration of analog parameter in frame == " + IntToStr(p_AP[par_num]->cnm));
			anlg_par_memo->Add("\n processing flag == " + IntToStr(p_AP[par_num]->fl_obr));

			for (n_kdr=0; n_kdr < dl_fk; n_kdr++) // значения параметра во времени (по кадрам)
			{
				anlg_par_grid->Cells[par_num+1][n_kdr+1] = FloatToStr(p_AP[par_num]->fz[n_kdr]);
				anlg_param.values.push_back(p_AP[par_num]->fz[n_kdr]);
			}

			anlg_param.scale = 1;
			anlg_param.offset = 0;
			anlg_param.enabled = false;
			anlg_param_vec.push_back(anlg_param);
		}
	}

	anlg_par_grid->FixedRows = 1;  // шапка
	anlg_par_grid->FixedCols = 1;

	//------------------------------------------------
	//  работа с разовыми командами

	sngl_com_memo->Clear();

	sngl_com_grid->ColCount = 0; // удалить все
	sngl_com_grid->RowCount = 0;

	const int title_rows_count = 2;
	const int title_cols_count = 1;

	sngl_com_grid->RowCount = title_rows_count;
	sngl_com_grid->ColCount = title_cols_count;

	sngl_com_grid->Cells[0][0] = "Frame";

	for (n_kdr=0; n_kdr < dl_fk; n_kdr++) { // записать номера кадров (время)
		sngl_com_grid->Cells[0][n_kdr+title_rows_count] = IntToStr(n_kdr);
		sngl_com_grid->RowCount += 1;
	}

 // вывод значений

 /*
   channels [0..63]
   {
	   commands [0..31]
	   {
	   		frames[0..3xx]
	   }
   }

 */
	int cur_cell_col = title_cols_count;
	for( int channel = 0; channel < maxChannel; channel++ ) { // строго меньше
		sngl_com_memo->Add("");
		sngl_com_memo->Add("");

		if( p_RK[channel]== 0 )
			sngl_com_memo->Add(" Single command in channel #" + IntToStr(channel) + " is absent");
		else {
			sngl_com_memo->Add(" Single command in channel #" + IntToStr(channel));

			sngl_com_memo->Add(" \"tin\" == " + IntToStr(p_RK[channel]->tp));
			sngl_com_memo->Add(" 'bYp' channel == "+ IntToStr(p_RK[channel]->cn));
			sngl_com_memo->Add(" Registration rate in frame == " + IntToStr(p_RK[channel]->fo));

			bool header_output_count = 0;  // выводить поочередно номер и "channel"
			const int commands_num = 32;
			for( int com_num = 0; com_num < commands_num; com_num++ ) {
				sngl_com_memo->Add("");
				sngl_com_memo->Add("");
				if( p_RK[channel]->fz[com_num] == 0 )
					sngl_com_memo->Add(" Single command #" + IntToStr(com_num) + " in channel #" + IntToStr(channel) + " is absent");
				else {
					sngl_com_memo->Add(" Single command #" + IntToStr(com_num) + " in channel #" + IntToStr(channel));

					// min & max are reversed ...
					sngl_com_memo->Add(" analog parameter max val == " + FloatToStr (p_RK[channel]->par_min[com_num]));
					sngl_com_memo->Add(" analog parameter min val == " + FloatToStr (p_RK[channel]->par_max[com_num]));
					sngl_com_memo->Add(" 'IRK' discharge == " + IntToStr (p_RK[channel]->rz[com_num]));
					sngl_com_memo->Add(" processing flag == " + IntToStr (p_RK[channel]->fl_obr[com_num]));
					sngl_com_memo->Add(" Begining frame number == " + IntToStr (p_RK[channel]->nkdr_n[com_num]));
					sngl_com_memo->Add(" End frame number == " + IntToStr (p_RK[channel]->nkdr_k[com_num]));
					sngl_com_memo->Add(" 'IRK' delay of forming == " + IntToStr (p_RK[channel]->zdf[com_num]));

						//---- вывод шапки
					if(com_num == 0)
					{
						sngl_com_grid->Cells[cur_cell_col][0] = IntToStr(channel);
						header_output_count = 1; // выводить "channel"
					}
					else
					{ sngl_com_grid->Cells[cur_cell_col][0] = (header_output_count^=1) ? // циклическое изменение счетчика
								IntToStr(channel) : UnicodeString("channel");}
					sngl_com_grid->Cells[cur_cell_col][1] = "CMD" + IntToStr(com_num);
					sngl_com_grid->ColCount += 1;

					for (n_kdr=0; n_kdr < dl_fk; n_kdr++)
						sngl_com_grid->Cells[cur_cell_col][n_kdr + title_rows_count] =  static_cast<int> (p_RK[channel]->fz[com_num][n_kdr]);

					if( ++cur_cell_col < 0 )
						output_error(UnicodeString(" Error @ PrintFreeZone_v2() : current cell column number overflow"));
				}
			}
		}
	}    // end of single command output

	if( sngl_com_grid->ColCount > title_cols_count )
		sngl_com_grid->FixedCols = title_cols_count;
	else
		output_error(UnicodeString(" Error @ PrintFreeZone_v2() :"
			" Can't create header column - not enough columns "
			"\n (! sngl_com_grid->ColCount > title_cols_count) "));

	if( sngl_com_grid->RowCount > title_rows_count )
		sngl_com_grid->FixedRows = title_rows_count;
	else
		output_error(UnicodeString(" Error @ PrintFreeZone_v2() :"
			" Can't create header row - not enough rows "
			"\n	(! sngl_com_grid->RowCount > title_rows_count) "));
}

int data_load(const String fileCopy, const String cyclogram)
{
	try
	{
	  if( (d_fk = OpenFK(fileCopy)) != FL_ERR )              // otkputie faila-konii
	  {
		ReadAtrFK();                         // chteNie atribytov faila-konii
		ReadAtrFlight();                     // chteNie atribytov noleta
		ReadOD();                            // chteNie onozNavatelNux daNNux
		ReadCyclogram(cyclogram);            // chteNie ciklogpammu
		if ((mas_bur_pi=(short *)malloc(sz_kdr)) == (short *)0) { // Ne vudeleNa namjat nod byfep kadpa faila-konii?
			ErrObr(E_MEM_BUFKADR);             //!!! Ne pabotaet ???
			output_error(UnicodeString("\n oshibka vudeleNia namjati nod byfep kadpa faila-konii"));
		}
		mas_free_rk = (unsigned long *)((char *)mas_bur_pi+sz_bur_kdr); // iNicializacija ykazatelja Na free-zoNy dlja PK
		mas_free_pi = (float *)mas_free_rk;  // iNicializacija ykazatelja Na free-zoNy dlja An

		ReadFreeZone();                        // chteNie free-zoN kadpov faila-konii v vudeleNNue massivu
		return FL_OK;
	  }
	  else
	  {	return FL_ERR;}
	}
	catch (Data_load_error& err)
	{
		Application->ShowException(&err);
		//output_error(err.Message);
		return FL_ERR;
	}
	catch (Exception& exc)
	{
		output_error(UnicodeString(" Some unhandled exception... "));
		Application->ShowException(&exc);
		return FL_ERR;
	}
	catch(...)
	{
		output_error(UnicodeString(" Some unknown exception... "));
		return FL_ERR;
    }

	return FL_ERR; // for nothing
}

void clean_up() {
	FreeMem();                           // osvobojdeNie vudeleNNoi namjati
	close(d_fk);                         // zakputie faila-konii
}

/*// получение идентификатора канала в структуре p_AP
String getChannelId(String str) {
	int i1 = Pos(" ", str) + 1;
	int i2 = Pos("(", str) - 3;
	return str.SubString( i1, i2 - i1 );
}   */


/*// получение индекса канала в структуре p_AP
int getChannel(String id) {
	for( int channel = 0; channel < maxChannel; channel++ )
		if( p_AP[channel] != 0 && !strcmp(p_AP[channel]->p_id, AnsiString(id).c_str()) )
			return channel;
	return -1;
} */

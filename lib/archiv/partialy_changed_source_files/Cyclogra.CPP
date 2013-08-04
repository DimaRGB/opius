// Cyclogra.cpp - fyNkcii pabotu s cyklogpammoi faila-konii (13.01.10)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <limits.h>
#include "var_ext.h"
#include "strctext.h"
#include "func_obr.h"
#include "typ_par.h"
#include "cycl_fld.h"
#include "sst_fk.h"
#include "N_error.h"

#include <string>
#include <iostream>
#include <conio.h>

#define INI_NK_IRK  -1

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
/* Открыть циклограмму
  Известные названия файлов циклограмм
A1
CB_4z
CBmk
G1
*/
	const int f_cycl_n_size = 4; // размер массива
	const char fst_ch = '0'; // первый допустимый для ввода символ, указывающий на имя с массива
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
	do      // считывать нажатия пока не будет нажата верная клавиша
	{file_ch = _getch();}
	while ( !( (file_ch >= fst_ch) && (file_ch < (fst_ch+f_cycl_n_size+1))));

	// выбрать имя файла
	if  ((file_ch > fst_ch) && (file_ch < (fst_ch+f_cycl_n_size+1)))
	{
	  f_name = f_dir + f_cycl_name_ar[file_ch-fst_ch+1];	
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

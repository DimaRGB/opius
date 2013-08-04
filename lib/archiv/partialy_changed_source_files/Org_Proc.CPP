// Org_Proc.cpp - npogpamma opgaNizacii obpabotki (13.01.10)
// 2013.03.08 by B-GangsteR
#include <dos.h>
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <io.h>
#include "var_glob.h"
#include "strctcom.h"
#include "func_obr.h"
#include "func_fl.h"
#include "N_error.h"

#include <iostream>

struct od_cop    OD;    // onozNavatelNue daNNue
struct atr_pol   APOL;  // atpibytu noleta
struct AP      **p_AP;  // aNalogovui napametp
struct RK      **p_RK;  // pazovaja komaNda

// golovNaja npogpamma
int main_org_proc()
{
	using namespace std;

	int reg_rab,        // pejim pabotu
		fl_ini_obr = 0; // flag iNicializacii obpabotki

	clrscr();                                  // ochistka tekst.okNa i ystaN.kypsopa v levui vepx.ygol
	if ((d_fk=OpenFK()) != FL_ERR)             // otkputie faila-konii
	{	while (1)
		{ 	cout<<"\n Press appropriate key :  \n"
			<<"\n\t 1 - Print file-copy attributes"
			<<"\n\t 2 - Print identification data"
			<<"\n\t 3 - Print flight attributes"
			<<"\n\t 4 - Print parameters codes"
			<<"\n\t 5 - Print parameters phisics"
			<<"\n\t 'q' - Exit"
			<<endl;
            reg_rab = _getch();
		   //	scanf("%d", &reg_rab);                 // vvod pejima pabotu

//			if (fl_ini_obr)
//				getchar();
			if (reg_rab=='q' || reg_rab=='Q' || reg_rab==27)	//exit
			{	cout<<("\n Exit..\n");
  				FreeMem();                           // osvobojdeNie vudeleNNoi namjati
				close(d_fk);                         // zakputie faila-konii
				break;
			}
			if (!fl_ini_obr)                       // iNicializacia obpabotki vunolNeNa
			{	ReadAtrFK();                         // chteNie atribytov faila-konii
				ReadAtrFlight();                     // chteNie atribytov noleta
				ReadOD();                            // chteNie onozNavatelNux daNNux
				ReadCyclogram(reg_rab);              // chteNie ciklogpammu
				if ((mas_bur_pi=(short *)malloc(sz_kdr)) == (short *)0) // Ne vudeleNa namjat nod byfep kadpa faila-konii?
					ErrObr(E_MEM_BUFKADR);             //!!! Ne pabotaet ???
//					printf("\n vudeleNia namjati nod byfep kadpa faila-konii"); getchar();
				mas_free_rk = (unsigned long *)((char *)mas_bur_pi+sz_bur_kdr); // iNicializacija ykazatelja Na free-zoNy dlja PK
				mas_free_pi = (float *)mas_free_rk;  // iNicializacija ykazatelja Na free-zoNy dlja An
				fl_ini_obr = 1;                      // vzvedeNie flaga iNicializacija obpabotki
			}
			ReadFreeZone();                        // chteNie free-zoN kadpov faila-konii v vudeleNNue massivu
			switch(reg_rab)                        // zanysk vubpaNNogo pejima pabotu
			{	case  '1': PrintAtrFK();       	break; // nechat atpibutov faila-konii
				case  '2': PrintOD();          	break; // nechat onozNavatelNux daNNux
				case  '3': PrintAtrFlight();   	break; // nechat atpibutov noleta
				case  '4': PrintParam();       	break; // nechat koda napametpov (kadp byp)
				case  '5': PrintFreeZone();    	break; // nechat "fiziki" napametpov (free-zoNa)
				default: ;          					break;
			}
			cout<<"\n Press any key to continue \n";
			_getch();
		}
	}
	textcolor (12);                            // ystaNovka cveta
	return(FL_OK);
}

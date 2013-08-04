// main file

#include "con_funcs.h"
#include "flight_data_processing.h"

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
			<<"\n\t 6 - Print parameters phisics (mode 2)"
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
				case  '6': PrintFreeZone_v2();  break;
				default: ;          					break;
			}
			cout<<"\n Press any key to continue \n";
			_getch();
		}
	}
//	textcolor (12);                            // ystaNovka cveta
	return(FL_OK);
}

int main(int argc, char** argv)
{
	try
	{
		using namespace std;

		while (true)
		{
			system("CLS");
			cout<<"\n OPIUS main function  \n";
			cout<<"\n Press appropriate key \n"
				<<"\n\t '1' - Launch 'Org_Proc'"
				<<"\n\t 'q' - Exit"
				<<endl;

			char pressed_key = 0;

			while (!pressed_key) // повтор ввода
			{
				pressed_key = _getch();
				switch(pressed_key)
				{
					case '1':
					{
						main_org_proc();
						break;
					}
					case 'q': case 'Q': case 27:
					{
						return 0; // exit
					}
					default:
					{
						pressed_key = 0; // incorrect value
						break;
					}
				}
			}// end of while (!pressed_key)

			cout<<"\n Press any key to continue \n";
			_getch();
		}    // end of   while (true)


		// 4 nothing
		cout<<"\n Press any key to exit \n";
		_getch();

		return 1;
	}
	catch (std::exception& e)
	{
		using namespace std;
		cout<<"\n Error: "<<e.what()<<"\n Press any key to exit \n"<<endl;
		_getch();
		return -1;
	}
	catch(...)
	{
		using namespace std;
		cout<<"\n Unknown error.. Press any key to exit \n";
		_getch();
		return -2;
	}
}


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

#include <stdio.h>
#include <fcntl.h>
#include <io.h>
#include "func_obr.h"
#include "N_error.h"

#include <iostream>
#include <string>
#include <conio.h>

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
	const char fst_ch = '1'; // первый допустимый для ввода символ, указывающий на имя с массива
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

// реализация консольных вспомогательных функций
// by B-GangsteR 2013.03.28

#include "con_funcs.h"


// "безопасное" считывание целого числа,
// не возвращает управление пока не будет введено число
// пропускает лишние символы
int get_int(bool unsign_only)
{
	using namespace std;
	int num=-1;
	cin>>num;
	if(unsign_only)
	{
		if(num<0)
			num=-num;
	}
	while(!cin)
	{
		if(cin.bad())
			throw runtime_error("\n Error @ get_int(): cin.bad()");
		else
		{
			cin.clear();
			char in=' ';
			while (!isdigit(in))
			{
				cin.clear();
				cin.get(in);
			}
			cin.putback(in);
		}
		cin>>num;
	}
	return num;
}

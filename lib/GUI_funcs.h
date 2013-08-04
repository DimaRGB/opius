// GUI functions
// by B-GangsteR 2013.05.15

#include <string>
#include "Main_Form_Unit.h"

void show_msg (const std::string& msg);
void output_error (const std::string& msg);
void output_error (UnicodeString& msg);
void show_warning(const std::string& msg);
bool checkFileName(String fileName, int fileType);

// целое число с ведущими нулями
class Num_with_nulls
{
	unsigned int value;
	unsigned int digits_num;

public:
	Num_with_nulls(int start_value, int digits_count)
		: value(start_value), digits_num(digits_count)  {};

	void set_value(unsigned int val)
	{ value = val;}

	void set_digits_num(unsigned int dig)
	{ digits_num = dig;}

	int get_value() const
	{ return value;	}

	Num_with_nulls operator++()
	{
		++value;
		return *this;
	}

	Num_with_nulls operator++(int)
	{
		Num_with_nulls temp (*this);
		++value;
		return temp;
	}

	Num_with_nulls operator--()
	{
		--value;
		return *this;
	}

	Num_with_nulls operator--(int)
	{
		Num_with_nulls temp (*this);
		--value;
		return temp;
	}

	std::string get_str_number() const;

	std::string operator()() const
	{ return get_str_number(); }

	operator std::string() const
	{ return get_str_number(); }
};

// принимает и конкатенирует строки как функция
class String_receiver
{
	std::string buf;

public:

	bool add_new_line;  // каждый раз добавлять новую строку

	String_receiver(bool add_new_ln)
	: add_new_line(add_new_ln) {} // use 'String_receiver str_rec = String_receiver();' if some troubles occur

	void operator()(const std::string& input)
	{
		if(add_new_line)
		{ 	buf.append("\n"); }
		buf.append(input);
	}

	void operator()(const char* input)
	{
		if(add_new_line)
		{ 	buf.append("\n"); }
		buf.append(input);
	}

	std::string get_string()
	{ return buf; }

	void clear()
	{ buf.clear(); }

	std::string::size_type size()
	{ return buf.size(); }

};

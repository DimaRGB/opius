// GUI functions
// by B-GangsteR 2013.05.15

#include <string>
#include "Main_Form_Unit.h"

//void show_msg (const std::string& msg);
void show_msg(const UnicodeString& msg);
//void output_error (const std::string& msg);
void output_error (const UnicodeString& msg);
//void show_warning(const std::string& msg);
void show_warning(const UnicodeString& msg);
bool checkFileName(String fileName, int fileType);

// принимает и конкатенирует строки как функци€
class String_receiver
{
	std::string buf;

public:
	bool add_new_line;  // каждый раз добавл€ть новую строку

	String_receiver(bool add_new_ln)
	: add_new_line(add_new_ln) {}

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

//--------------------------------------------------------------------------
// класс генерации цвета
// Y = 0.299 * R + 0.587 * G + 0.114 * B;
// формула €ркости ^ ; €ркость в пределах 255
/*
H Ч тон [0; 360]
S Ч насыщенность [0; 1]
L Ч светлота [0; 1]
*/
class Color_generator
{
public:
	static const int optimal_bright = 160;
	static const int optimal_max_iter = 1000;
	static const int max_color_intensity = 256;

private:
	// data
	TColor color;
	double red_coef;
	double green_coef;
	double blue_coef;

	int red;
	int green;
	int blue;
	int brightness;

	UnicodeString color_str;
	int color_rgb;
	UnicodeString color_web_name;
	UnicodeString color_web_str;
	unsigned short hue;
	unsigned short luminance;
	unsigned short saturation;

	void init()
	{
      	red_coef = 0.299;
		green_coef = 0.587;
		blue_coef = 0.114;

		hue = 0;
		luminance = 0;
		saturation = 0;
    }

	void procces()
	{
		red = GetRValue(color);
		green = GetGValue(color);
		blue = GetBValue(color);
		brightness = red_coef * red + green_coef * green + blue_coef * blue;

		color_str = ColorToString(color);
		color_rgb = ColorToRGB(color);
		color_web_name = ColorToWebColorName(color);
		color_web_str = ColorToWebColorStr(color);
		ColorToHLS(color,hue,luminance, saturation);
    }

public:

	Color_generator()
	: color(RGB(0,0,0))
	{
		init();
		procces();
	};

	Color_generator(const TColor& color_in)
	: color(color_in)
	{
		init();
		procces();
	}

	void set_color(TColor new_color)
	{
		color=new_color;
		procces();
	}

	int generate_rand_color(const int max_bright = 255, int max_iteration = optimal_max_iter);

	// const

	TColor get_color() const
	{return color;};

	double red_coefficient() const
	{ return red_coef;}

	double green_coefficient() const
	{ return green_coef;}

	double blue_coefficient() const
	{ return blue_coef;}

	int red_component() const
	{ return red;}

	int green_component() const
	{ return green;}

	int blue_component() const
	{ return blue;}

	int get_brightness() const
	{ return brightness;}

	UnicodeString get_color_str() const
	{ return color_str;}

	int get_color_rgb() const
	{ return color_rgb;}

	UnicodeString get_color_web_name() const
	{ return color_web_name;}

	UnicodeString get_color_web_str() const
	{ return color_web_str;}

	unsigned short get_hue() const
	{ return hue;}

	unsigned short get_luminance() const
	{ return luminance;}

	unsigned short get_saturation() const
	{ return saturation;}

	UnicodeString get_color_info_full();
	UnicodeString get_color_info();
};

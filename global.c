#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include "allegro5/allegro.h"
#include "allegro5/allegro_primitives.h"
#include "allegro5/allegro_font.h"
#include "allegro5/allegro_ttf.h"
#define SCREEN_W 2400
#define SCREEN_H 1600
#define max_number_of_settings 30
#define max_number_of_cells 501
#define max_number_of_rows 501
#define max_rule_length 3125
int number_of_settings = 11;
//fonts
int number_of_fonts = 5, font_number = 4, setting_font_size = 25;
int font_size = 35, rule_font_size = 25;
//graphics positions
int settings_x = 0, settings_y = 340, ca_x = 500, ca_y = 340, r_x = 500, r_y = 280, r_gap = 20;
int s_height = 35, s_gap = 250, code_width = 20, code_height = 30, code_font_size = 30;
int offset = 40;
//misc
int rule_length = 8, rule_mode = 0, rule_index = 0;
int current_setting = 0, hide_menu = 0, code_mode = 0;
int keyboard_input, display_mode = 0, gray_intensity = 200;
//arrays
int cell[max_number_of_rows][max_number_of_cells];
int rule[max_rule_length];
char* setting_desc[max_number_of_settings] = {
"states           ",
"neighbors        ",
"height           ",
"width            ",
"columns          ",
"rows             ",
"color0           ",
"color1           ",
"color2           ",
"color3           ",
"color4           ",
"font             "
};

enum {
	STATES,
	NEIGHBORHOOD,
	PIXEL_HEIGHT,
	PIXEL_WIDTH,
	CELLS,
	ROWS,
	COLOR_0,
	COLOR_1,
	COLOR_2,
	COLOR_3,
	COLOR_4,
	FONT
};

int setting[max_number_of_settings] = {
	2,
	3,
	20,
	20,
	60,
	20,
	0,
	1,
	2,
	3,
	4,
	1
};

int setting_increment[max_number_of_settings] = {
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1,
	1
};

int setting_max[max_number_of_settings] = {
	5,
	5,
	100,
	100,
	500,
	500,
	7,
	7,
	7,
	7,
	7,
	4,
};

int setting_min[max_number_of_settings] = {
    2,
    1,
    1,
    1,
	3,
	2,
	0,
	0,
	0,
	0,
	0,
	0
};


// allegro variables
ALLEGRO_EVENT_QUEUE *q;
ALLEGRO_FONT* fonts[10];
ALLEGRO_FONT* rule_font;
ALLEGRO_FONT*  font;
ALLEGRO_FONT* code_font;
ALLEGRO_FONT* setting_font;
ALLEGRO_DISPLAY *display;
ALLEGRO_EVENT event;
ALLEGRO_COLOR white, red, black, blue, green, yellow, gray,current_color, orange;
ALLEGRO_COLOR random_color();
ALLEGRO_COLOR state_color[10], library_color[10];


void display_setting(int);
void print_int(int,int,int);
void print_string(int,int, const char *);
void erase_settings();
void display_settings();
void respond_to_input();
void set_up_graphics();
void update_screen();
void plot_CA();
int key_pressed();
void randomize_rule();
void calculate_CA();
void plot_pixel(int,int,int);
int mod(int,int);
int code(int,int);
int f(int,int);
void print_rule();
void seed_CA();
int int_pow(int,int);
void display_rule();
void increase_rule_index();
void decrease_rule_index();
void init_CA();
void plot_code();


void erase_settings()
{
	al_draw_filled_rectangle(settings_x, settings_y, settings_x + 300, settings_y+number_of_settings*s_height+200,black);
}


void display_setting(int s)
{
	if (s != current_setting) current_color = white; else current_color = yellow;
	print_string(settings_x, settings_y + s*s_height, setting_desc[s]);
	print_int(settings_x + s_gap, settings_y + s*s_height, setting[s]);
}

void print_int(int x, int y, int i) {
	al_draw_textf(font, current_color, x, y, ALLEGRO_ALIGN_LEFT, "%d",i);
}

void print_string(int x, int y, const char* s) {
    al_draw_textf(font, current_color, x, y, ALLEGRO_ALIGN_LEFT, "%s",s);
}

void increase_setting(int s) {
	setting[s] += setting_increment[s];
	if (setting[s] > setting_max[s]) {
		setting[s] = setting_min[s];
	}
}

void decrease_setting(int s) {
	setting[s] -= setting_increment[s];
	if (setting[s] < setting_min[s]) {
		setting[s] = setting_max[s];
	}
}

void display_settings() {
	for (int i = 0; i < number_of_settings; i++) {
		display_setting(i);
	}
}

void display_rule() {
	for (int i = 0; i < rule_length; i++) {
		print_int(r_x+r_gap*i, r_y, rule[i]);
	}
}


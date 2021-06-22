

int main(int argc, char **argv) {
	set_up_graphics();
	update_screen();
	init_CA();
	update_screen();
	for (;;) {
		if (key_pressed()) respond_to_input();
	}
}

void update_screen() {
	al_clear_to_color(al_map_rgb(0, 0, 0));
    display_settings();
	display_rule();
    plot_CA();
    al_flip_display();
}

void init_CA() {
	randomize_rule();
    seed_CA();
    calculate_CA();
}

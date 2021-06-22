void respond_to_input()
{
	keyboard_input = getch();
	switch (keyboard_input)
	{
	case ALLEGRO_KEY_Q:
		exit(0);
		break;
	case ALLEGRO_KEY_RIGHT:
		if (rule_mode == 0)	increase_setting(current_setting);
		else increase_rule_index();
		break;
	case ALLEGRO_KEY_LEFT:
		if (rule_mode == 0) decrease_setting(current_setting);
		else decrease_rule_index();
		break;
	case ALLEGRO_KEY_UP:
		if (rule_mode == 0) {
			if (current_setting > 0) current_setting--; else current_setting = number_of_settings - 1;
		}
		else {
			rule[rule_index]++;
			if (rule[rule_index] > setting[STATES] - 1) rule[rule_index] = 0;
			calculate_CA();
		}
		break;
	case ALLEGRO_KEY_DOWN:
		if (rule_mode == 0) {
			if (current_setting < number_of_settings - 1) current_setting++; else current_setting = 0;
		}
		else {
			rule[rule_index]--;
			if (rule[rule_index] < 0) rule[rule_index] = setting[STATES] - 1;
			calculate_CA();
		}
		break;
	case ALLEGRO_KEY_R:
		randomize_rule();
		seed_CA();
		calculate_CA();
		break;
	case ALLEGRO_KEY_H:
		if (hide_menu == 1) hide_menu= 0; else hide_menu =1;
		break;
	case ALLEGRO_KEY_C:
		if (code_mode == 1) code_mode = 0; else code_mode = 1;
		break;
	case ALLEGRO_KEY_S:
		seed_CA();
		calculate_CA();
		break;
	case ALLEGRO_KEY_M:
		if (rule_mode == 0) rule_mode = 1; else rule_mode = 0;
		break;
	default:
		//seed_CA();
		//calculate_CA();
		break;
	}

	update_screen();
}

void increase_rule_index() {
	rule_index++;
	if (rule_index > rule_length -1) rule_index = 0;
}
void decrease_rule_index() {
    rule_index--;
    if (rule_index < 0) rule_index = rule_length - 1;
}

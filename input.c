void respond_to_input()
{
	keyboard_input = getch();
	switch (keyboard_input)
	{
	case ALLEGRO_KEY_Q:
		exit(0);
		break;
	case ALLEGRO_KEY_RIGHT:
		increase_setting(current_setting);
		break;
	case ALLEGRO_KEY_LEFT:
		decrease_setting(current_setting);
		break;
	case ALLEGRO_KEY_UP:
		if (current_setting > 0) current_setting--; else current_setting = number_of_settings - 1;
		break;
	case ALLEGRO_KEY_DOWN:
		if (current_setting < number_of_settings - 1) current_setting++; else current_setting = 0;
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
		calculate_CA();
		break;
	case ALLEGRO_KEY_S:
		seed_CA();
		calculate_CA();
		break;
	default:
		seed_CA();
		calculate_CA();
		break;
	}

	update_screen();
}

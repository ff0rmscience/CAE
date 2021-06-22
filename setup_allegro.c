void set_up_graphics()
{
	al_init();
	al_init_primitives_addon();
	al_init_font_addon();
	al_init_ttf_addon();
	al_install_keyboard();
	q = al_create_event_queue();
	al_register_event_source(q, al_get_keyboard_event_source());
	display = al_create_display(SCREEN_W, SCREEN_H);
	//font = al_load_font("SourceCodePro-Regular.ttf", font_size, 0);
	//font = al_load_font("DroidSansMono.ttf", font_size, 0);
	/*
	fonts[0] = al_load_font("SourceCodePro-Regular.ttf", font_size, 0);
	fonts[1] = al_load_font("DroidSansMono.ttf", font_size, 0);
	fonts[2] = al_load_font("MonospaceTypewriter.ttf", font_size, 0);
	fonts[3] =  al_load_font("AmaticSC-Regular.ttf", font_size, 0);
	fonts[4] =  al_load_font("mplus-1m-regular.ttf", font_size, 0);
	*/
	font = fonts[1];
	setting_font = al_load_font("DroidSansMono.ttf", setting_font_size, 0);
	rule_font = al_load_font("DroidSansMono.ttf", rule_font_size, 0);
	code_font = al_load_font("DroidSansMono.ttf", code_font_size, 0);
	white = al_map_rgb(255, 255, 255);
	black = al_map_rgb(0, 0, 0);
	red = al_map_rgb(255, 0, 0);
	blue = al_map_rgb(0, 0, 255);
	green = al_map_rgb(0, 255, 0);
	yellow = al_map_rgb(255, 255, 0);
	orange = al_map_rgb(255,165,0);
	gray = al_map_rgb(gray_intensity,gray_intensity,gray_intensity);
	library_color[0] = black;
    library_color[1] = white;
    library_color[2] = red;
    library_color[3] = blue;
    library_color[4] = yellow;
	library_color[5] = green;
	library_color[6] = orange;
    library_color[7] = gray;
}

int key_pressed()
{
	ALLEGRO_EVENT ev;
	while (al_peek_next_event(q, &ev))
	{
		if (ev.type != ALLEGRO_EVENT_KEY_CHAR)
		{
			al_drop_next_event(q);
		}
		else
		{
			return 1;
		}
	}
	return 0;
}

int getch()
{
	ALLEGRO_EVENT ev;
	al_get_next_event(q, &ev);
	if (ev.type != ALLEGRO_EVENT_KEY_CHAR)
	{
		return 0;
	}
	return ev.keyboard.keycode;
}

ALLEGRO_COLOR random_color()
{
	return al_map_rgb(rand()%256, rand()%256, rand()%256);
}



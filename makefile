cae: cae.c global.c main.c setup_allegro.c settings.c input.c plot_CA.c
	    clang-12 cae.c -o cae -lm -I/usr/include/x86_64-linux-gnu \
	    -lallegro -lallegro_primitives -lallegro_ttf -lallegro_font
	    ./cae



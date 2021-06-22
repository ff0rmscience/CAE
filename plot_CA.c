void seed_CA() {
	for (int c = 0; c < setting[CELLS]; c++) {
		cell[0][c] = rand()%setting[STATES];
	}
}
void calculate_CA() {
	for (int r = 1; r < setting_max[ROWS]; r++) {
		for (int c = 0; c < setting[CELLS];c++) {
			cell[r][c] = rule[code(r,c)];
		}
	}
}

void plot_CA() {
	for (int x = 0; x < setting[CELLS]; x++) {
		for (int y = 0; y <setting[ROWS]; y++) {
			plot_pixel(x,y, cell[y][x]);
		}
	}
}

void plot_pixel(int x, int y, int c) {
	al_draw_filled_rectangle(
							 ca_x+setting[PIXEL_WIDTH]*x,
							 ca_y+setting[PIXEL_HEIGHT]*y,
							 ca_x+setting[PIXEL_WIDTH]*(x+1),
                             ca_y+setting[PIXEL_HEIGHT]*(y+1),
							 state_color[c]
	);
}

int mod(int x, int m) {
	if (x > -1 && x < m) return x;
	if (x < 0) return x + m;
	if (x > m - 1) return x - m;
}

int code(int r, int c) {
	int sum = 0;
	int N = setting[NEIGHBORHOOD];
	int S = setting[STATES];
	int C = setting[CELLS];
	for (int k = 0; k < N; k++) {
		sum += f(k,S)*cell[r - 1][mod(c - N/2 + k,C)];
	}
	return sum;
}
int f(int x, int b) {
	int s = 1;
	for (int j = 0; j < x; j++) {
		s *= b;
	}
	return s;
}

void randomize_rule() {
	rule_length = int_pow(setting[STATES], setting[NEIGHBORHOOD]);
	for (int i = 0; i < rule_length; i++) {
		rule[i] = rand()%setting[STATES];
	}
}

int int_pow(int base, int exp)
{
    int result = 1;
    while (exp)
    {
        if (exp % 2)
           result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}

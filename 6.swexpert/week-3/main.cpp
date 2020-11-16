#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX_TRASH		10000
#define CAN_FULL		3500
#define MAP_SIZE		1000
#define CLOCK_PER_SEC	1000
#define CAN_CNT			3

int org_trash_map[MAP_SIZE][MAP_SIZE];
int trash_map[MAP_SIZE][MAP_SIZE];
int can[CAN_CNT];
int seed = 3;
int RESULT;

void test(int trash_map[MAP_SIZE][MAP_SIZE]);

void move_trash(int x, int y, int d) {
	if (RESULT == 1000000000)
		return;
	RESULT++;
	int ox, oy;
	ox = x;
	oy = y;
	switch (d){
	case 0:
		x++;
		break;
	case 1:
		y++;
		break;
	case 2:
		x--;
		break;
	case 3:
		y--;
		break;
	}
	if (x < 0 || MAP_SIZE <= x || y < 0 || MAP_SIZE <= y) return;
	if (ox < 0 || MAP_SIZE <= ox || oy < 0 || MAP_SIZE <= oy) return;
	if (org_trash_map[y][x] == -1 || org_trash_map[oy][ox] != -1) return;

	int r;
	if (org_trash_map[y][x] == 0) {
		org_trash_map[y][x] = -1;
		org_trash_map[oy][ox] = 0;
	}
	else {
		r = org_trash_map[y][x] - 1;
		if (can[r] == CAN_FULL)
			return;
		can[r]++;
		org_trash_map[oy][ox] = 0;
	}
}
void make() {
	int x, y, c;
	for (y = 0; y < MAP_SIZE; y++)
		for (x = 0; x < MAP_SIZE; x++)
			trash_map[y][x] = 0;

	c = 0;
	while (c != MAX_TRASH) {
		x = rand() % MAP_SIZE;
		y = rand() % MAP_SIZE;
		if (trash_map[y][x] == 0) {
			trash_map[y][x] = -1;
			c++;
		}
	}
	c = 0;
	while (c != CAN_CNT) {
		x = rand() % MAP_SIZE;
		y = rand() % MAP_SIZE;
		if (trash_map[y][x] == 0)
			trash_map[y][x] = ++c;
	}
	for (int i = 0; i < CAN_CNT; i++)
		can[i] = 0;

	for (y = 0; y < MAP_SIZE; y++)
		for (x = 0; x < MAP_SIZE; x++)
			org_trash_map[y][x] = trash_map[y][x];
}

int main() {
	int T = 10;
	time_t start;
	int Total = 0;
	seed = 3;
	srand(seed);
	RESULT = 0;
	for (int i = 0; i < T; i++) {
		make();
		start = clock();
		test(trash_map);
		RESULT += (clock() - start) / (CLOCK_PER_SEC / 1000);
		for (int y = 0; y < MAP_SIZE; y++)
			for (int x = 0; x < MAP_SIZE; x++)
				if (org_trash_map[y][x] == -1) {
					RESULT += 10000;
				}
	}
	printf("RESULT : %d\n", RESULT);
}
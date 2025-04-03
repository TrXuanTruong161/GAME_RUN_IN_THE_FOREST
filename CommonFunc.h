#pragma once


#include<SDL.h>
#include<iostream>
#include<vector>
#include<string>
#include<cstring>
#include<SDL_image.h>

#include<cstdio>
using namespace std;


static SDL_Window* g_window = NULL;
static SDL_Event g_event;
static SDL_Renderer* g_screen = NULL;
// screen
const int SCREEN_WIDTH = 1280;
const int SCREEN_HEIGHT = 640;
const int SREEN_PIXEL = 32;
const int FRAME_PER_SECOND = 25;
//color
const int COLER_G = 175;
const int COLER_R = 167;
const int COLER_B = 180;
const int RENDER_COLOR_DRAW = 255;
//MAP
#define TILE_SIZE 64

#define MAX_MAP_X 400
#define MAX_MAP_Y 10
struct Map {
	int start_x_;
	int start_y_;
	
	int max_x_;
	int max_y_;
	
	int tile[MAX_MAP_Y][MAX_MAP_X];
	 char* file_name_;

 };
struct Input {
	int left_;
	int right_;
	int up_;
	int down_;
	int jump_;


};
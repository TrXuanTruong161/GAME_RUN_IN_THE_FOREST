#include"CommonFunc.h"
#include"BaseObject.h"
#include"game_map.h"
#include"MainObject.h"
#include"ImpTimer.h"
BaseObject g_background;

BaseObject end_image;
bool InitData() {
	bool success = true;
	if (SDL_Init(SDL_INIT_VIDEO) < 0) return false;
	SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1");
	g_window = SDL_CreateWindow("GAME_RUN_IN_THE_FOREST",
		SDL_WINDOWPOS_UNDEFINED,
		SDL_WINDOWPOS_UNDEFINED,
		SCREEN_WIDTH,
		SCREEN_HEIGHT,
		SDL_WINDOW_SHOWN);
	if (g_window == NULL) {
		success = false;

	}
	else {
		g_screen = SDL_CreateRenderer(g_window, -1, SDL_RENDERER_ACCELERATED);
		if (g_screen == NULL) success = false;
		else {
			SDL_SetRenderDrawColor(g_screen, RENDER_COLOR_DRAW, RENDER_COLOR_DRAW, RENDER_COLOR_DRAW, RENDER_COLOR_DRAW);
			int  imgflags = IMG_INIT_PNG;
			if ((IMG_Init(imgflags) & imgflags)!= imgflags) {
				success = false;

			}

		}
	}
	return success;

}
bool LoadBackground() {
	bool ret = g_background.LoadImage("IMG//background.png", g_screen);
	if (ret == false) return false;

	return true;

}
bool LoadEndImage() {
	bool ret = end_image.LoadImage("IMG//END.png", g_screen);
	if (ret == false) return false;
	return true;
}
void close() {
	g_background.Free();
	end_image.Free();
	SDL_DestroyRenderer(g_screen);
	g_screen = NULL;
	SDL_DestroyWindow(g_window);
	g_window = NULL;
	IMG_Quit();
	SDL_Quit();


}
int main(int argc, char* argv[]) {
    ImpTimer fps_timer;
    if (InitData() == false) return -1;
    if (LoadBackground() == false) return -1;
    if (LoadEndImage() == false) return -1;
    GameMap game_map;
    game_map.LoadMap("MAP//map.dat");
    game_map.LoadTiles(g_screen);

    MainObject p_player1;
    p_player1.LoadImage("IMG//player_right.png", g_screen);
    p_player1.set_clip();

    MainObject p_player2;
    p_player2.LoadImage("IMG//player_right.png", g_screen);
    p_player2.set_clip();

    bool is_quit = false;

    while (!is_quit) {
        fps_timer.start();
        while (SDL_PollEvent(&g_event) != 0) {
            if (g_event.type == SDL_QUIT) {
                is_quit = true;
            }
            p_player2.HandeInputAction(g_event, g_screen, false);
            p_player1.HandeInputAction(g_event, g_screen, true);
            
        }
        SDL_SetRenderDrawColor(g_screen, RENDER_COLOR_DRAW, RENDER_COLOR_DRAW, RENDER_COLOR_DRAW, RENDER_COLOR_DRAW);
        SDL_RenderClear(g_screen);

        g_background.Render(g_screen, NULL);

        Map map_data = game_map.getMap();
        p_player1.SetMapXY(map_data.start_x_, map_data.start_y_);
        p_player1.doPlayer(map_data);
        p_player1.Show(g_screen);

        p_player2.SetMapXY(map_data.start_x_, map_data.start_y_);
        p_player2.doPlayer2(map_data);
        p_player2.Show(g_screen);

        game_map.SetMap(map_data);
        game_map.Drawmap(g_screen);

        if (p_player1.is_end_of_map_ || p_player2.is_end_of_map_) {
            end_image.Render(g_screen, NULL);
        }

        SDL_RenderPresent(g_screen);

        int real_imp_time = fps_timer.get_ticks();
        int time_one_frame = 1000 / FRAME_PER_SECOND; // ms
        if (real_imp_time < time_one_frame) {
            int delay_time = time_one_frame - real_imp_time;
            if (delay_time >= 0) {
                SDL_Delay(delay_time);
            }
        }
    }
    close();
    return 0;
}



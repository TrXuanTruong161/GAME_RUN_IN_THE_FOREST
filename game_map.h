#pragma once
#define MAX_TILES 20
#include"CommonFunc.h"
#include"BaseObject.h"

class TileMat : public BaseObject {
public:
	TileMat() {;};
	~TileMat() {;};

};
class GameMap {
public:
    GameMap() { file_name_[0] = '/0'; };
    ~GameMap() {;};
    void LoadMap( const char* name);
    void LoadTiles(SDL_Renderer* screen);
    void Drawmap(SDL_Renderer* screen);
	Map getMap() { return game_map_; }
	void SetMap(Map& map_data) { game_map_ = map_data; }
private:
    Map game_map_;
    TileMat tile_mat[MAX_TILES];
    char file_name_[256]; // Add this line to store the file name
};   

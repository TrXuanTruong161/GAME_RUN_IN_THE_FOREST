#pragma once

#include"CommonFunc.h"
#include"BaseObject.h"
#define GRAVITY_SPEED 0.8
#define MAX_FALL_SPEED 10
#define PLAYER_SPEED 50
#define PLAYER_JUMP_VAL 20
constexpr auto BLANK_TILE = 0;;
class MainObject : public BaseObject {
  public:
	MainObject();
	~MainObject();
	enum WalkType {
		WALK_RIGHT = 0,
		WALK_LEFT = 1,
		
	};

	bool LoadImage(string path, SDL_Renderer* screen);
	void Show(SDL_Renderer* des);
	void HandeInputAction(SDL_Event events, SDL_Renderer* screen,bool is_player_one);
	void set_clip();

	void doPlayer(Map& map_data);
	void doPlayer2(Map& map_data);
	void CheckToMap(Map& map_data);

	void SetMapXY(const int map_x, const int map_y) { map_x_ = map_x; map_y_ = map_y; }
	void CenterEntityOnMap(Map& map_data);
	bool IsAtEndOfMap(const Map& map_data);
	bool is_end_of_map_ = false;
private:
	float x_val_;
	float y_val_;

	float x_pos_;
	float y_pos_;
	
	int width_frame_;
	int height_frame_;

	SDL_Rect frame_clip_[8];
	Input input_type_;
	int frame_;
	int status_;
	bool on_ground_ = false;

	int map_x_;
	int map_y_;
	

};

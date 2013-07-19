#pragma once
#include <string>

using namespace std;

namespace game {

	const int SCREENHEIGHT = 600;
	const int SCREENWIDTH = 800;
	const float ASPECT_RATIO = static_cast<float>(SCREENWIDTH) / static_cast<float>(SCREENHEIGHT);
	const int CELLX = 16;
	const int CELLY = 12;
	const int TILEHEIGHT = SCREENHEIGHT/CELLY;
	const int TILEWIDTH = SCREENWIDTH/CELLX;
	const int FPS = 30;
	const string BASE_PATH = "res/levels/level";
	const string TILES_SUFFIX = "tiles.png";
	const string LEVELFILE_SUFFIX = "lvl.png";
	const float MOVE_DISTANCE = static_cast<float>(TILEHEIGHT*2) / static_cast<float>(FPS);

}
#pragma once
namespace game {
class tower
{
public:
	tower(void);
	~tower(void);
	int get_shooting_rate(void);
	void set_shooting_rate(int rate);

	int getX(void);
	void setX(int x);
	int getY(void);
	void setY(int y);

	int getColor(void);
	void setColor(int color);

private:
	int shooting_rate;
	int x_pos;
	int y_pos;
	int color;
	//grafik
};

}
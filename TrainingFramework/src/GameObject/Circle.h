#pragma once
#include "SpriteAnimation.h"
#include "GameStates/GSPlay.h"
#include "BaseObject.h"

class Circle : public BaseObject {
public:
	Circle();
	~Circle();
	void set_x_val(const int& xVal) { x_val = xVal; }
	void set_y_val(const int& yVal) { y_val = yVal; }
	int get_x_val() const { return x_val; }
	int get_y_val() const { return y_val; }
	void set_is_move(const bool& isMove) { is_move = isMove; }
	bool get_is_move() const { return is_move; }
	void HandleMoveCircle(const int& x_border, const int& y_border);//di chuyen dan ban
private:
	int x_val;
	int y_val;
	bool is_move;
};
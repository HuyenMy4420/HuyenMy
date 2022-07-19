#include "Circle.h"
#include "SpriteAnimation.h"
#include "Sprite2D.h"
#include "Model.h"
#include "GameStates/GSPlay.h"
#include "BaseObject.h"
Circle::Circle() {
	x_val = 0;
	y_val = 0;
	is_move = false;

}
Circle::~Circle() {

}
void Circle::HandleMoveCircle(const int& x_border, const int& y_border) {
	m_position.x += x_val;
	if (m_position.x > x_border) {
		is_move = false;
	}

}



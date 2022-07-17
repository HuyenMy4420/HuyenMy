#pragma once
#include "SpriteAnimation.h"
#include "GameStates/GSPlay.h"
class Player :
	public SpriteAnimation
{
public:
	using SpriteAnimation::SpriteAnimation;
	~Player();
	void move();
protected:
	int x_val;
	int y_val;



};

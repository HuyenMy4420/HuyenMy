#pragma once
#include "GameStateBase.h"
#include "BaseObject.h"

class Sprite2D;
class Sprite3D;
class Text;
class GameButton;
class SpriteAnimation;

class GSPlay :
	public GameStateBase
{
public:
	GSPlay();
	~GSPlay();

	void	Init() override;
	void	Exit() override;

	void	Pause() override;
	void	Resume() override;

	void	HandleEvents() override;
	void	HandleKeyEvents(int key, bool bIsPressed) override;
	void	HandleTouchEvents(int x, int y, bool bIsPressed) override;
	void	HandleMouseMoveEvents(int x, int y) override;
	void	Update(float deltaTime) override;
	void	Draw() override;
	GLfloat timer = 0.0f;
	int isType(int key, std::shared_ptr<Sprite2D> m_alpha);
	int m_KeyPress;
	int keypress;
	void check(int key);
	int isCollision(std::shared_ptr<SpriteAnimation> penguin, std::shared_ptr<Sprite2D> flower);
	static const int y_PENGUIN = 700;
	const int gravity = 1;	
	bool isJumping = false;	
	bool isBottom = true;
	bool IsActive = false;
	struct point {
		int x, y;
	};

private:
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Sprite2D>   flower;
	std::shared_ptr<Sprite2D>   plant;
	std::shared_ptr<Text>		m_score;
	std::shared_ptr<SpriteAnimation> penguin;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::list<std::shared_ptr<SpriteAnimation>>	m_listAnimation;
	std::list<std::shared_ptr<Text>>	m_alpha;
};


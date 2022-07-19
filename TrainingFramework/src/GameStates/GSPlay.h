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
	
	int m_KeyPress;
	/*
	void set_circle_list(std::vector<Circle*> circle_list) {
		p_circle_list = circle_list;
	}
	std::vector<Circle*> get_circle_list() const { return p_circle_list; }*/

private:
	//std::vector<Circle* > p_circle_list;
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Sprite2D>   m_box;
	std::shared_ptr<Sprite2D>   plant;
	std::shared_ptr<Text>		m_score;
	std::shared_ptr<SpriteAnimation> penguin;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::list<std::shared_ptr<SpriteAnimation>>	m_listAnimation;
};


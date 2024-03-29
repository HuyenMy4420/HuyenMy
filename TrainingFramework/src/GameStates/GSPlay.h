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
	void GenerateTexts();
	void CheckTexts(int key);
	int score=0;
	void checkColli();
	float m_time=0.0;


private:
	
	GLfloat m_timer = 0.0f;
	std::shared_ptr<Sprite2D>	m_background;
	std::shared_ptr<Sprite2D>   flower;
	std::shared_ptr<Sprite2D>   note_sound;
	std::shared_ptr<Text>		m_score;
	std::shared_ptr<SpriteAnimation> penguin;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::list<std::shared_ptr<SpriteAnimation>>	m_listAnimation;
	std::list<std::shared_ptr<Text>>	m_listTexts;
	std::list<std::shared_ptr<Sprite2D>>	m_listFruit;
};


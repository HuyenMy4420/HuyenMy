#pragma once
#include "GameStateBase.h"
#include "BaseObject.h"

class GameOver : public GameStateBase
{
public:
	GameOver();
	~GameOver();

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

private:
	std::shared_ptr<Sprite2D> m_gameover;
	std::shared_ptr<Sprite2D> m_replay;
	std::list<std::shared_ptr<GameButton>>	m_listButton;
	std::shared_ptr<Text>					m_textGameOver;
	float	m_time;
};



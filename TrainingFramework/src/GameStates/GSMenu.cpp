#include "GSMenu.h"
#include "Camera.h"
GSMenu::GSMenu() : GameStateBase(StateType::STATE_MENU), 
	m_background(nullptr), m_listButton(std::list<std::shared_ptr<GameButton>>{}), m_textGameName(nullptr)
{
}


GSMenu::~GSMenu()
{
}



void GSMenu::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("menu5.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	// play button
	texture = ResourceManagers::GetInstance()->GetTexture("play.tga");
	std::shared_ptr<GameButton> button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth / 2,320);
	button->SetSize(150, 75);
	button->SetOnClick([]() {
			GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
		});
	m_listButton.push_back(button);

	//settings
	texture = ResourceManagers::GetInstance()->GetTexture("btn_settings.tga");
	std::shared_ptr<GameButton> button1 = std::make_shared<GameButton>(model, shader, texture);
	button1->Set2DPosition(550,240);
	button1->SetSize(100,100);
	button1->SetOnClick([]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_SETTINGS);
		});
	m_listButton.push_back(button1);

	// exit button
	texture = ResourceManagers::GetInstance()->GetTexture("exit.tga");
	button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2 + 60);
	button->SetSize(140,80);
	button->SetOnClick([]() {
		exit(0);
		});
	m_listButton.push_back(button);
	std::string name = "music2.mp3";
	ResourceManagers::GetInstance()->PlaySound(name);
	// game title
	/*
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("iciel Pony.ttf");
	m_textGameName = std::make_shared< Text>(shader, font, "Typing Game", Vector4(0.27f, 0.25f, 0.43f, 2.0f), 3.0f);
	m_textGameName->Set2DPosition(Vector2(95,280));
	std::string name = "Alarm01.wav";
	ResourceManagers::GetInstance()->PlaySound(name);*/
}

void GSMenu::Exit()
{
	ResourceManagers::FreeInstance();
}


void GSMenu::Pause()
{
}

void GSMenu::Resume()
{
}


void GSMenu::HandleEvents()
{
}

void GSMenu::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSMenu::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSMenu::HandleMouseMoveEvents(int x, int y)
{
}

void GSMenu::Update(float deltaTime)
{
	m_background->Update(deltaTime);
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
}

void GSMenu::Draw()
{
	m_background->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	//m_textGameName->Draw();
}

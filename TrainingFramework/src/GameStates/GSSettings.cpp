#include "GSSettings.h"
#include "GSSettings.h"

GSSettings::GSSettings() : GameStateBase(StateType::STATE_SETTINGS), m_time(0.0f)
{
}

GSSettings::~GSSettings()
{
}


void GSSettings::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	auto texture = ResourceManagers::GetInstance()->GetTexture("menu1.tga");

	m_settings = std::make_shared<Sprite2D>(model, shader, texture);
	m_settings->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	m_settings->SetSize(Globals::screenWidth, Globals::screenHeight);

	//button
	texture = ResourceManagers::GetInstance()->GetTexture("btn_sfx.tga");
	std::shared_ptr<GameButton> sound = std::make_shared<GameButton>(model, shader, texture);
	sound->Set2DPosition(350, 240);
	sound->SetSize(100, 100);
	sound->SetOnClick([]() {
		
		});
	m_listButton.push_back(sound);

	//close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close1.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
	button->SetSize(50, 50);
	button->SetOnClick([this]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_MENU);
		
		});
	m_listButton.push_back(button);
	//title
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("VNBAHAB.TTF");
	m_textGameName = std::make_shared< Text>(shader, font, "Settings", Vector4(1.0f, 0.4f, 0.1f, 1.0f), 3.0f);
	m_textGameName->Set2DPosition(Vector2(380, 170));

}

void GSSettings::Exit()
{
}


void GSSettings::Pause()
{
}

void GSSettings::Resume()
{
}


void GSSettings::HandleEvents()
{
}

void GSSettings::HandleKeyEvents(int key, bool bIsPressed)
{
}

void GSSettings::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSSettings::HandleMouseMoveEvents(int x, int y)
{
}

void GSSettings::Update(float deltaTime)
{
	/*
	m_time += deltaTime;
	if (m_time > 1.5)
	{
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_MENU);
		m_time = 0;
	}*/
}

void GSSettings::Draw()
{
	m_settings->Draw(); 
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	m_textGameName->Draw();
}
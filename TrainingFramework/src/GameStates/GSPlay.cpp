#include "GSPlay.h"
#include "Shader.h"
#include "Texture.h"
#include "Model.h"
#include "Camera.h"
#include "Font.h"
#include "Sprite2D.h"
#include "Sprite3D.h"
#include "Text.h"
#include "GameButton.h"
#include "SpriteAnimation.h"


GSPlay::GSPlay()
{
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("landcaspe.tga");

	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

	texture = ResourceManagers::GetInstance()->GetTexture("btn_close1.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 25);
	button->SetSize(50, 50);
	button->SetOnClick([this]() {
		GameStateMachine::GetInstance()->PopState();
		});
	m_listButton.push_back(button);

	// score
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("Brightly Crush Shine.otf");
	m_score = std::make_shared< Text>(shader, font, "score: 10", TextColor::RED, 1.0);
	m_score->Set2DPosition(Vector2(5, 25));

	//nhan vat
	shader = ResourceManagers::GetInstance()->GetShader("Animation");
	texture = ResourceManagers::GetInstance()->GetTexture("penguin12.tga");
	penguin = std::make_shared<SpriteAnimation>(model, shader, texture, 9, 5, 4, 0.6f);
	penguin->Set2DPosition(200, 650);
	penguin->SetSize(60, 60);
	m_listAnimation.push_back(penguin);
	m_KeyPress = 0;
}
void GSPlay::Exit()
{
}
void GSPlay::Pause()
{
}

void GSPlay::Resume()
{
}

void GSPlay::HandleEvents()
{

}

void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	Vector3 penguin_pos = penguin->Get2DPosition();
	if (bIsPressed)
	{
		switch (key)
		{
		case KEY_LEFT:
			m_KeyPress |= 1;
			break;
		case KEY_DOWN:
			m_KeyPress |= 1 << 1;
			break;
		case KEY_RIGHT:
			m_KeyPress |= 1 << 2;
			break;
		case KEY_UP:
			m_KeyPress |= 1 << 3;
			break;
		case KEY_SPACE:
			m_KeyPress |= 1 << 4;
			break;
		default:
			break;
		}
	}
	else
	{
		switch (key)
		{
		case KEY_LEFT:
			m_KeyPress ^= 1;
			break;
		case KEY_DOWN:
			m_KeyPress ^= 1 << 1;
			break;
		case KEY_RIGHT:
			m_KeyPress ^= 1 << 2;
			break;
		case KEY_UP:
			m_KeyPress ^= 1 << 3;
			break;
		case KEY_SPACE:
			m_KeyPress ^= 1 << 4;
			break;
		default:
			break;
		}
	}
	if (bIsPressed)
	{
		if (key >= 65 && key <= 90)
		CheckTexts(key);
	}
}


void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if (button->HandleTouchEvents(x, y, bIsPressed))
		{
			break;
		}
	}
}

void GSPlay::HandleMouseMoveEvents(int x, int y)
{
}
void GSPlay::Update(float deltaTime)
{
	switch (m_KeyPress)//Handle Key event
	{
	case 1:
		penguin->Move2DPosition(-3, 0);
		break;
	case 1 << 1:
		break;
	case 1 << 2:
		penguin->Move2DPosition(3, 0);
		break;
	case 1 << 3:
		break;
	case 1 << 4:
		break;
	default:
		break;
	}
	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listAnimation)
	{
		it->Update(deltaTime);
	}

	if (m_timer >= 2.0)
	{
		m_timer = 0.0f;

		GenerateTexts();
	}
	else
		m_timer += 1 * deltaTime;
}

void GSPlay::Draw()
{

	m_background->Draw();
	m_score->Draw();
	penguin->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	for (auto it : m_listTexts)
	{
		it->Draw();
	}
	for (auto it : m_listAnimation)
	{
		it->Draw();
	}
}
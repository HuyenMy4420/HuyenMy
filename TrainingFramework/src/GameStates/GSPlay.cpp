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
#include "Circle.h"


GSPlay::GSPlay()
{

	
}


GSPlay::~GSPlay()
{
}


void GSPlay::Init()
{
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto texture = ResourceManagers::GetInstance()->GetTexture("level_new1.tga");
	
	// background
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	m_background = std::make_shared<Sprite2D>(model, shader, texture);
	m_background->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_background->SetSize(Globals::screenWidth, Globals::screenHeight);

//box
	texture = ResourceManagers::GetInstance()->GetTexture("Peashooter.tga");
	flower = std::make_shared<Sprite2D>(model, shader, texture);
	flower->Set2DPosition(140,440);
	flower->SetSize(50,50);


	// button close
	texture = ResourceManagers::GetInstance()->GetTexture("btn_close1.tga");
	std::shared_ptr<GameButton>  button = std::make_shared<GameButton>(model, shader, texture);
	button->Set2DPosition(Globals::screenWidth - 50, 50);
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
	penguin = std::make_shared<SpriteAnimation>(model, shader, texture,9,5,4,0.6f);
	penguin->Set2DPosition(500, 440);
	penguin->SetSize(50, 40);
	m_listAnimation.push_back(penguin);
	m_KeyPress = 0;
}
int GSPlay:: isCollision(std::shared_ptr<SpriteAnimation> penguin, std::shared_ptr<Sprite2D> flower) {
	Vector3 penguin_pos = penguin->Get2DPosition();
	Vector3 flower_pos = flower->Get2DPosition();
	const int diff = 20; // change -> (pen.width + flower.width) / 2
	
	if (abs(penguin_pos.x - flower_pos.x) < diff && abs(penguin_pos.y - flower_pos.y) < diff) {
		return 1;
	}
	else {
		return 0;

	}
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

	if (bIsPressed)
	{
		switch (key)
		{
		case KEY_LEFT:
			m_KeyPress |= 1;
			break;
		case KEY_DOWN:
			m_KeyPress |= 1<<1;
			break;
		case KEY_RIGHT:
			m_KeyPress |= 1<<2;
			break;
		case KEY_UP:
			m_KeyPress |= 1<<3;
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
}

void GSPlay::HandleTouchEvents(int x, int y, bool bIsPressed)
{
	for (auto button : m_listButton)
	{
		if(button->HandleTouchEvents(x, y, bIsPressed))
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

	// check message đi. shared_ptr lay object ra kieu gi the
	if (isCollision(penguin, flower)) {
		// nhay len nhu mario phai co van toc + gia toc nua
		// con nay di cham qua
		return; // dung im roi
	}
	else {
		switch (m_KeyPress)//Handle Key event
		{
		case 1:
			penguin->Move2DPosition(-3, 0);
			break;
		case 1 << 1:
			penguin->Move2DPosition(0, 3);
			break;
		case 1 << 2:
			penguin->Move2DPosition(3, 0);
			break;
		case 1 << 3:
			penguin->Move2DPosition(0, -3);
			break;
		case 1 << 4:
			//Circle* p_circle = new Circle();

			break;
		default:
			break;
		}

	}


	for (auto it : m_listButton)
	{
		it->Update(deltaTime);
	}
	for (auto it : m_listAnimation)
	{
		it->Update(deltaTime);
	}
}

void GSPlay::Draw()
{
	m_background->Draw();
	flower->Draw();
	m_score->Draw();
	
	penguin->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}

	for (auto it : m_listAnimation)
	{
		it->Draw();
	}
}
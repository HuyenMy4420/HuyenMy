﻿#include "GSPlay.h"
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

//box
	/*texture = ResourceManagers::GetInstance()->GetTexture("Peashooter.tga");
	flower = std::make_shared<Sprite2D>(model, shader, texture);
	flower->Set2DPosition(140,440);
	flower->SetSize(50,50);*/

	// button close
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
	penguin = std::make_shared<SpriteAnimation>(model, shader, texture,9,5,4,0.6f);
	penguin->Set2DPosition(200,650);
	penguin->SetSize(60, 60);
	m_listAnimation.push_back(penguin);
	m_KeyPress = 0;
}
/*
int GSPlay:: isCollision(std::shared_ptr<SpriteAnimation> penguin, std::shared_ptr<Sprite2D> flower) {
	Vector3 penguin_pos = penguin->Get2DPosition();
	Vector3 flower_pos = flower->Get2DPosition();
	const int diff = 20; // change -> (pen.width + flower.width) / 2
	/*
	if (abs(penguin_pos.x - flower_pos.x) < diff && abs(penguin_pos.y - flower_pos.y) < diff) {
		return 1;
	}
	else {
		return 0;

	}
	if (penguin_pos.x + 50 < flower_pos.x || flower_pos.x + 50 < penguin_pos.x || penguin_pos.y + 50 < flower_pos.y || flower_pos.y + 40 < penguin_pos.y) {
		
		return false;
	}
	else {

		return true;
	}

	
	
}*/
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
void GSPlay::check(int key) {
	if()
}
void GSPlay::HandleKeyEvents(int key, bool bIsPressed)
{
	int keypress = key;
	if (bIsPressed) {
		switch (key) {
		}
	}
	
	Vector3 penguin_pos = penguin->Get2DPosition();
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
/*
int GSPlay:: isType(int key, std::shared_ptr<Sprite2D> m_alpha) {
}*/


void GSPlay::HandleMouseMoveEvents(int x, int y)
{
}
bool KeyPress = false;
void GSPlay::Update(float deltaTime)
{
		switch (m_KeyPress)//Handle Key event
		{

		case 1:
			KeyPress = true;
			IsActive = false;
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

	// Sinh chu
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	std::string alpha_text;
	srand(time(NULL));
	int Id_alpha=rand() % 5;
	if (Id_alpha == 1)
		alpha_text = "chuA.tga";
		else if (Id_alpha == 2) alpha_text = "chuB.tga";
		else if (Id_alpha == 3) alpha_text = "chuC.tga";
		else if (Id_alpha == 4) alpha_text = "chuD.tga";
		else alpha_text = "chuE.tga";
	if (timer >= 2.0f) {
		timer = 0.0f;
		int x = rand() % (480);
		int y = rand() % (533);
		auto text = std::make_shared<Text>(shader, font, alpha_text, TextColor::RED, 2.0);
		text->Set2DPosition(x, y);
		m_alpha.push_back(text);
		for (int i = 0; i < 3; i++) {
			text->Set2DPosition(x, y);
		}
	} timer += deltaTime;

	// Check chu
	std::list<std::shared_ptr<Text>> ::iterator text_alpha = m_alpha.begin();
}

void GSPlay::Draw()
{

	m_background->Draw();
	//flower->Draw();
	m_score->Draw();
	
	penguin->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
	for (auto it : m_alpha)
	{
		if(it ->IsActive)\
		{
			it->Draw();
		}
	}

	for (auto it : m_listAnimation)
	{
		it->Draw();
	}
}
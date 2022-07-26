#pragma once
#include "GameStates\GSPlay.h"
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

void GSPlay::GenerateTexts()
{
	auto shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	auto font = ResourceManagers::GetInstance()->GetFont("iciel Pony.ttf");

	srand(time(NULL));
	char s = rand() % (91 - 65) + 65;
	std::string str = "";
	str.push_back(s);

	int color = rand() % 7;
	TextColor textColor;
	if (color == 0) textColor = TextColor::CYAN;
	else if (color == 1) textColor = TextColor::RED;
	else if (color == 2) textColor = TextColor::GREEN;
	else if (color == 3) textColor = TextColor::BLUE;
	else if (color == 4) textColor = TextColor::YELLOW;
	else if (color == 5) textColor = TextColor::PURPLE;

	std::shared_ptr<Text> text = std::make_shared<Text>(shader, font, str, textColor, TEXT_SIZE);
	GLfloat x = GLfloat(rand() % GLint(Globals::screenWidth - TEXT_SIZE * 30));
	GLfloat y = GLfloat(rand() % GLint(533));
	text->Set2DPosition(x, y);
	int soluong = m_listTexts.size();
	if (soluong > 10) {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_GAMEOVER);
	}
	GLfloat z = (rand() % 500) / 1000;
	text->SetRotation(Vector3(0.0f, 0.0f, z));
	m_listTexts.push_back(text);
	
}

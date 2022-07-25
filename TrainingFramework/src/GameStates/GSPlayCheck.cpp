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

void GSPlay::CheckTexts(int key)
{
	char s = key;
	std::string str = "";
	str += s;
	std::list<std::shared_ptr<Text>>::iterator ite;
	ite = std::find_if(m_listTexts.begin(), m_listTexts.end(), [this, str](const std::shared_ptr<Text>& text) {
		return text->GetText() == str;
		});
	if (ite != m_listTexts.end())
		m_listTexts.erase(ite);
}


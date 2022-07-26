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
#include "GameOver.h"
GameOver::GameOver(): GameStateBase(StateType::STATE_GAMEOVER), 
m_gameover(nullptr), m_listButton(std::list<std::shared_ptr<GameButton>>{}), m_textGameOver(nullptr)
{
}

GameOver::~GameOver() {

}

void GameOver::	Init() {
	auto model = ResourceManagers::GetInstance()->GetModel("Sprite2D.nfg");
	auto shader = ResourceManagers::GetInstance()->GetShader("TextureShader");
	auto texture = ResourceManagers::GetInstance()->GetTexture("bk3.tga");

	m_gameover = std::make_shared<Sprite2D>(model, shader, texture);
	m_gameover->Set2DPosition((float)Globals::screenWidth / 2, (float)Globals::screenHeight / 2);
	m_gameover->SetSize(Globals::screenWidth, Globals::screenHeight);

	//button replay
	texture = ResourceManagers::GetInstance()->GetTexture("replay.tga");
	std::shared_ptr<GameButton>  button2 = std::make_shared<GameButton>(model, shader, texture);
	button2->Set2DPosition(Globals::screenWidth / 2, Globals::screenHeight / 2);
	button2->SetSize(150, 75);
	button2->SetOnClick([this]() {
		GameStateMachine::GetInstance()->ChangeState(StateType::STATE_PLAY);
		});
	m_listButton.push_back(button2);

	//text
	shader = ResourceManagers::GetInstance()->GetShader("TextShader");
	std::shared_ptr<Font> font = ResourceManagers::GetInstance()->GetFont("iciel Pony.ttf");
	m_textGameOver = std::make_shared< Text>(shader, font, "GameOver", Vector4(0.27f, 0.25f, 0.43f, 2.0f), 3.0f);
	m_textGameOver->Set2DPosition(Vector2(95, 280));
}
void GameOver::Exit() {
}

void GameOver::Pause(){
}
void GameOver::Resume() {
}

void GameOver::HandleEvents() {
}
void GameOver::HandleKeyEvents(int key, bool bIsPressed) {
}
void GameOver::HandleTouchEvents(int x, int y, bool bIsPressed) {
}
void GameOver::HandleMouseMoveEvents(int x, int y){
}
void GameOver::Update(float deltaTime) {
}
void GameOver::Draw() {
	m_gameover->Draw();
	m_textGameOver->Draw();
	for (auto it : m_listButton)
	{
		it->Draw();
	}
}
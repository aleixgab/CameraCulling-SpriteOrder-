#include "j1App.h"
#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "Player.h"
#include "j1Scene.h"




Player::Player(int x, int y, ENTITY_TYPES type) : Entity(x, y, type)
{
	speed.x = 0;
	speed.y = 0;
	pos = { x,y };

	

	up.PushBack({ 0,  0,50,55 });
	up.PushBack({ 0, 75,50,55 });
	up.PushBack({ 0,150,50,55 });
	up.PushBack({ 0,225,50,55 });
	up.PushBack({ 0,300,50,55 });
	up.speed = 0.2;

	right.PushBack({ 53,  0,50,55 });
	right.PushBack({ 53, 75,50,55 });
	right.PushBack({ 53,150,50,55 });
	right.PushBack({ 53,225,50,55 });
	right.PushBack({ 53,300,50,55 });
	right.speed = 0.2;


	left.PushBack({ 166,  0,50,55 });
	left.PushBack({ 166, 75,50,55 });
	left.PushBack({ 166,150,50,55 });
	left.PushBack({ 166,225,50,55 });
	left.PushBack({ 166,300,50,55 });
	left.speed = 0.2;


	down.PushBack({ 109,  0,50,55 });
	down.PushBack({ 109, 75,50,55 });
	down.PushBack({ 109,150,50,55 });
	down.PushBack({ 109,225,50,55 });
	down.PushBack({ 109,300,50,55 });
	down.speed = 0.2;


	CurrentAnim = &down;

}

void Player::Move(float dt) {

	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT) {
		pos.y -= 200 * dt;
		CurrentAnim = &up;
	}
	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT) {
		pos.y += 200 * dt;
		CurrentAnim = &down;
	}
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT) {
		pos.x -= 200 * dt;
		CurrentAnim = &left;
	}
	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT) {
		pos.x += 200 * dt;
		CurrentAnim = &right;
	}
	
}

Player::~Player()
{}

void Player::Draw(SDL_Texture* texture)
{
	App->render->Blit(texture, pos.x, pos.y, &CurrentAnim->GetCurrentFrame());
}


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
}

void Player::Move(float dt) {

	if (App->input->GetKey(SDL_SCANCODE_W) == KEY_REPEAT)
		pos.y -= 200*dt;
	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_REPEAT)
		pos.y += 200 * dt;
	if (App->input->GetKey(SDL_SCANCODE_A) == KEY_REPEAT)
		pos.x -= 200 * dt;
	if (App->input->GetKey(SDL_SCANCODE_D) == KEY_REPEAT)
		pos.x += 200 * dt;
	
}

Player::~Player()
{}

void Player::Draw(SDL_Texture* texture)
{
	App->render->Blit(texture, pos.x, pos.y, &rect);
}


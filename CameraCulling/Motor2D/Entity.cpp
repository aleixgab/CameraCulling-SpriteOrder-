#include "j1App.h"
#include "p2Log.h"
#include "Entity.h"
#include "j1Render.h"

Entity::Entity(float x, float y) : position(x, y), start_pos(x, y) {}

Entity::~Entity()
{

}

void Entity::Draw(SDL_Texture* sprites)
{
	App->render->Blit(sprites, position.x, position.y, &r);
}

void Entity::OnCollision(Collider* c1, Collider* c2) {}

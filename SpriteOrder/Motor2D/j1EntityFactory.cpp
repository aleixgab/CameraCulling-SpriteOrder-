#include "j1EntityFactory.h"
#include "j1Render.h"
#include "p2Log.h"
#include "Player.h"

bool j1EntityFactory::Start() {

	texture = App->tex->Load("textures/entities.png");
	return true;
}

bool j1EntityFactory::PreUpdate() {

	for (std::list<Entity*>::iterator iterator = entities.begin(); iterator != entities.end(); iterator++) {
		bool repeat = true;
		if (*iterator == entities.back())
			repeat = false;
		while (repeat) {
			repeat = false;
			if ((*iterator)->pos.y + (*iterator)->rect.h > (*std::next(iterator, 1))->pos.y + (*std::next(iterator, 1))->rect.h) {
				SWAP((*iterator), (*iterator++));
				if (*iterator != entities.back())
					repeat = true;
			}

		}
	}
	return true;
}


bool j1EntityFactory::Update(float dt)
{
	for (std::list<Entity*>::iterator iterator = entities.begin(); iterator != entities.end(); iterator++) {
		(*iterator)->Draw(texture);
		(*iterator)->Move(dt);
	}

	return true;
}

bool j1EntityFactory::CleanUp()
{
	App->tex->UnLoad(texture);
	for (std::list<Entity*>::iterator iterator = entities.begin(); iterator == entities.end(); iterator++)
	{
		delete *iterator;
	}
	entities.clear();

	return true;
}

Entity* j1EntityFactory::AddEntity(int pos_x, int pos_y, ENTITY_TYPES type)
{
	Entity* ent = nullptr;
	if(type == PLAYER)
		 ent = new Player(pos_x, pos_y, type);
	else
		ent = new Entity(pos_x,pos_y, type);
	ent->type = type;
	ent->pos = { pos_x, pos_y };
	ent->rect.w = ent->rect.h = 45;
	ent->rect.y = 0;

	if (ent->type == GRUNT)
		ent->rect.x = 45;
	else if (ent->type == PLAYER)
		ent->rect.x = 90;
	else if (ent->type == AXETHROWER)
		ent->rect.x = 0;
	entities.push_back(ent);

	return ent;
}


void Entity::Draw(SDL_Texture* texture)
{
	App->render->Blit(texture, pos.x, pos.y, &rect);
}


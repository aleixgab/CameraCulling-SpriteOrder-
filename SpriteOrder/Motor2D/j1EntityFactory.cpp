#include "j1EntityFactory.h"
#include "j1Render.h"
#include "p2Log.h"
#include "Player.h"

bool j1EntityFactory::Start() {

	texture = App->tex->Load("textures/entities2.png");
	return true;
}

bool j1EntityFactory::PreUpdate() {

	//TODO 1: fes una llista que iteri totes les entitats STD
	for (std::list<Entity*>::iterator iterator = entities.begin(); iterator != entities.end(); iterator++) {
		bool repeat = true;
		if (*iterator == entities.back())
			repeat = false;
		//TODO 2: intercanvia les posicions del iterador amb el seguent de la llista comprobant la posició dels peus de cada un std::next
		///Penseu quin ordre volem per despres fer el pintat

		while (repeat) {
			repeat = false;
			if ((*iterator)->pos.y + (*iterator)->rect.h > (*std::next(iterator))->pos.y + (*std::next(iterator))->rect.h) {
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
	
	if (ent->type == GRUNT) 
		ent->rect = { 269, 0, 45, 45 };

	else if (ent->type == AXE_THROWER) 
		ent->rect = { 227, 0, 45, 45 };

	else if (ent->type == TOWN_HALL) 
		ent->rect = { 225, 60, 120, 115 };
	
	else if (ent->type == PLAYER) 
		ent->rect = { 0, 0, 50, 55 };


	entities.push_back(ent);

	return ent;
}


void Entity::Draw(SDL_Texture* texture)
{
	App->render->Blit(texture, pos.x, pos.y, &rect);
}


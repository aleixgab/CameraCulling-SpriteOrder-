#include "j1EntityFactory.h"
#include "j1Render.h"
#include "p2Log.h"
#include "Player.h"

bool j1EntityFactory::Start() {

	texture = App->tex->Load("textures/entities2.png");
	return true;
}

bool j1EntityFactory::PreUpdate() {

	//TODO 6: Iterate entities list and push entities information in the priority queue
	//Remember the firsts TODOs from Camera Culling. Dont push in the queue if entity is not in the screen


	return true;
}


bool j1EntityFactory::Update(float dt)
{
	//TODO 7: Pop queue and blit one by one
	//coment [(*iterator)->Draw(texture);] it's a few lines above


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


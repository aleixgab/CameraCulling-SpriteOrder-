#include "j1EntityFactory.h"
#include "j1Render.h"
#include "p2Log.h"

bool j1EntityFactory::Start() {

	texture = App->tex->Load("textures/archer.png");
	return true;
}


bool j1EntityFactory::Update(float dt)
{
	for (std::list<Entity*>::iterator iterator = entities.begin(); iterator != entities.end(); iterator++) {
		iterator._Ptr->_Myval->Draw(texture);
	}

	return true;
}

bool j1EntityFactory::CleanUp()
{
	if (entities.size() != 0)
		for (std::list<Entity*>::iterator iterator = entities.begin(); iterator == entities.end(); iterator++) {
			if (iterator._Ptr != nullptr)
				delete iterator._Ptr->_Myval;
		}
	return true;
}

Entity* j1EntityFactory::AddEntity(int pos_x, int pos_y, ENTITY_TYPES type)
{
	Entity* ent = nullptr;
	ent = new Entity();

	for (uint i = 0; i < MAX_ENEMIES; ++i)
	{
		if (ent[i].type == NO_TYPE) {
			ent[i].pos = { pos_x,pos_y };
			ent[i].type = type;
			entities.push_back(ent);
		}
	}

	return ent;
}


void Entity::Draw(SDL_Texture* texture)
{
	rect = { 0,0,45,45 };
	App->render->Blit(texture, pos.x, pos.y, &rect);
}


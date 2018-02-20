#include "j1EntityFactory.h"
#include "j1Render.h"
#include "p2Log.h"

bool j1EntityFactory::Start() {

	texture = App->tex->Load("textures/entities.png");
	return true;
}


bool j1EntityFactory::PostUpdate()
{
	for (std::list<Entity*>::iterator iterator = entities.begin(); iterator != entities.end(); iterator++) {
		(*iterator)->Draw(texture);
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
	Entity* ent = new Entity();
	ent->type = type;
	ent->pos = { pos_x, pos_y };
	ent->rect.w = ent->rect.h = 45;

	if (ent->type == GRUNT)
		ent->rect.x = 45;
	else if (ent->type == ARCHER)
		ent->rect.x = 90;
	entities.push_back(ent);

	return ent;
}


void Entity::Draw(SDL_Texture* texture)
{
	App->render->Blit(texture, pos.x, pos.y, &rect);
}


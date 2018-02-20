#ifndef __J1ENTITYFACTORY_H__
#define __J1ENTITYFACTORY_H__

#include "j1App.h"
#include "j1Module.h"
#include "j1Render.h"
#include "j1Textures.h"

#include <list>

#define MAX_ENEMIES 5

class Entity;

enum ENTITY_TYPES
{
	NO_TYPE,
	ARCHER,
	GRUNT,
	AXETHROWER,
};

class j1EntityFactory : public j1Module {
private:

	std::list<Entity*> entities;

public:
	j1EntityFactory() {};
	virtual ~j1EntityFactory() {};

public:
	bool PostUpdate();
	bool CleanUp();
	bool Start();

	Entity* AddEntity(int x, int y, ENTITY_TYPES type);

	SDL_Texture* texture;


};

class Entity {
public:

	void Draw(SDL_Texture* texture);

public:
	iPoint pos;
	ENTITY_TYPES type;
	SDL_Rect rect;
private:

};

#endif // !__ENTITIES_H__
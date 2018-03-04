#ifndef __J1ENTITYFACTORY_H__
#define __J1ENTITYFACTORY_H__

#include "j1App.h"
#include "j1Module.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "SDL/include/SDL.h"
#include "Animation.h"

#include <list>
#include <queue>

#define MAX_ENEMIES 5

class Entity;

enum ENTITY_TYPES
{
	NO_TYPE,
	PLAYER,
	GRUNT,
	AXE_THROWER,
	TOWN_HALL
};

//TODO 3: Create a struct from entities information that holds their rect, position, animation and Priority(it's a positive whole)


//TODO 5: Create a struct that will compare entities information priorities



class j1EntityFactory : public j1Module {
private:

	std::list<Entity*> entities;

//	TODO 4: Create a priority_queue with struct made it on last TODO

public:
	j1EntityFactory() {};
	virtual ~j1EntityFactory() {};

public:
	bool PreUpdate();
	bool Update(float dt);
	bool CleanUp();
	bool Start();

	Entity* AddEntity(int x, int y, ENTITY_TYPES type);

	SDL_Texture* texture;

};

class Entity {
public:

	Entity(int x, int y, ENTITY_TYPES type) {}
	virtual void Draw(SDL_Texture* texture);
	virtual void Move(float dt) {};

public:
	iPoint pos;
	ENTITY_TYPES type;
	SDL_Rect rect;
	uint priority;
	Animation* CurrentAnim = nullptr;
private:

};

#endif // !__ENTITIES_H__
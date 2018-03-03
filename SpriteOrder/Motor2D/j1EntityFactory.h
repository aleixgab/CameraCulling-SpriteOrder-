#ifndef __J1ENTITYFACTORY_H__
#define __J1ENTITYFACTORY_H__

#include "j1App.h"
#include "j1Module.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "SDL/include/SDL.h"

#include <list>
#include <queue>
#include <functional>

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

struct EntitiesDraw_info{
	SDL_Rect rect;
	iPoint pos;
	uint priority;
};

struct compare {
	bool operator()(const EntitiesDraw_info& infoA, const EntitiesDraw_info& infoB)
	{
		if (infoA.priority > infoB.priority)
			return infoA.priority > infoB.priority;
		
		else
			return infoB.priority > infoA.priority;
		
	}
};
class j1EntityFactory : public j1Module {
private:

	std::list<Entity*> entities;

	std::priority_queue<EntitiesDraw_info, std::vector<EntitiesDraw_info>, compare> drawOrder;

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
private:

};

#endif // !__ENTITIES_H__
#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "j1Render.h"
#include "p2Point.h"
#include "p2DynArray.h"
#include "j1EntityFactory.h"
#include "Animation.h"

struct SDL_Texture;
struct SDL_Rect;


class Player : public Entity
{
public:
	Player(int x, int y, ENTITY_TYPES type);

	void Move(float dt);
	void Draw(SDL_Texture* texture);



	// Destructor
	virtual ~Player();


public:

	ENTITY_TYPES type;

private:

	Animation down;
	Animation right;
	Animation left;
	Animation up;
	Animation* CurrentAnim = nullptr;

	SDL_Texture* texture = nullptr;
	SDL_Rect rect;
	fPoint speed = { 0.0f,0.0f };
};



#endif // !__PLAYER_H__


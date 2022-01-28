#ifndef __ACTOR_H__
#define __ACTOR_H__

#include <stdio.h>
#include <cstdint>

#define MEMORY_CHECK_MODE 0

#define LEFT_U_VEC Vector2D<int>(-1, 0)
#define RIGHT_U_VEC Vector2D<int>(1, 0)
#define UP_U_VEC Vector2D<int>(0, -1)
#define DOWN_U_VEC Vector2D<int>(0, 1)

enum class ETeam : uint8_t
{
	Player,
	Enemy,
};

enum class EType : uint8_t
{
	None,
	Life,
	Shadow,
	Earth,
	Water,
	Light,

};

enum class EDirection : uint8_t
{
	Left,
	Right,
	Up,
	Down,
};

enum class EAttackDirection : uint8_t
{
	Left,
	Right
};

class Actor
{
public:
	virtual void tick() {};

};

#endif /*__ACTOR_H__*/
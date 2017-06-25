/**
*	This file contains all the enums
**/

#pragma once


UENUM(BlueprintType)
enum class EMonsterType : uint8 {
	TYPE_NORMAL
};

UENUM(BlueprintType)
enum class EDirection : uint8 {
	DIRECTION_UP,
	DIRECTION_DOWN,
	DIRECTION_RIGHT,
	DIRECTION_LEFT,
	DIRECTION_NONE
};
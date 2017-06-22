/**
*	This file contains all the enums
**/

#pragma once


UENUM(BlueprintType)
enum class EMonsterType : uint8 {
	TYPE_NORMAL
};

UENUM(BlueprintType)
enum class EMovement : uint8 {
	MOVEMENT_NONE,
	MOVEMENT_UP,
	MOVEMENT_DOWN,
	MOVEMENT_RIGHT,
	MOVEMENT_LEFT
};
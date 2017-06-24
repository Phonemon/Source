// Fill out your copyright notice in the Description page of Project Settings.

#include "LIB_Bp.h"

FVector ULIB_Bp::getMappedPosition(FVector Position) {
	bool negateX = Position.X < 0;
	bool negateY = Position.Y < 0;
	Position.X = abs(int(Position.X));
	Position.Y = abs(int(Position.Y));
	Position.X += TILE_SIZE / 2;
	Position.X -= int(Position.X) % TILE_SIZE;
	Position.Y += TILE_SIZE / 2;
	Position.Y -= int(Position.Y) % TILE_SIZE;
	if (negateX)
		Position.X *= -1;
	if (negateY)
		Position.Y *= -1;
	return Position;
}




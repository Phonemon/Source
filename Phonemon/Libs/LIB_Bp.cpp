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

FString ULIB_Bp::cutString(UPARAM(ref) FString& String, int32 MaxChar) {
	FString resString;

	// Si le text est d�j� assez petit
	if (String.Len() <= MaxChar) {
		resString = String;
		String = "";
		return resString;
	}

	// On r�cup�re les 100 caract�res
	for (int32 i = 0; i < MaxChar; i++) {
		resString += String[i];
	}
	
	// On enl�ve les restes du mot qu'on a coup�
	for (int32 i = resString.Len() - 1; i >= 0 && resString[i] != ' '; --i) {
		resString.RemoveAt(i);
	}

	// On enl�ve les caract�res retourn�s du message originel
	String.RemoveFromStart(resString);

	return resString;
}
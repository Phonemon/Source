// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameMode.h"


//Constructor
AMainGameMode::AMainGameMode() {
	
	// Set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("Pawn'/Game/Character/MainCharacterBp.MainCharacterBp_C'"));
	if (PlayerPawnObject.Class != NULL) {
		DefaultPawnClass = PlayerPawnObject.Class;
	}
}
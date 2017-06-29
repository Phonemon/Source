// Fill out your copyright notice in the Description page of Project Settings.

#include "MainGameMode.h"


//Constructor
AMainGameMode::AMainGameMode() : AGameModeBase(){
	
	// Set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnObject(TEXT("Pawn'/Game/Character/MainCharacterBp.MainCharacterBp_C'"));
	if (PlayerPawnObject.Class != NULL) {
		DefaultPawnClass = PlayerPawnObject.Class;
	}
	
	PlayerControllerClass = AMainPlayerController::StaticClass();

	// Set default player controller class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<AMainPlayerController> PlayerControllerObject(TEXT("Blueprint'/Game/PlayerController/MainPlayerControllerBp.MainPlayerControllerBp_C'"));
	if (PlayerControllerObject.Class != NULL) {
		PlayerControllerClass = PlayerControllerObject.Class;
	}
}
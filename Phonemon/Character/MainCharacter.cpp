// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "../Monster/Monster.h"

// Sets default values
AMainCharacter::AMainCharacter() {
 	// Set this character to call Tick() every frame. 
	PrimaryActorTick.bCanEverTick = true;

	//Set default var
	for (int32 i = 0; i < 4; ++i)
		keyPressed[i] = false;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay() {
	Super::BeginPlay();

}

// Called every frame
void AMainCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

// Move forward
void AMainCharacter::startMoveForward() {
	keyPressed[static_cast<int32>(EDirection::DIRECTION_UP)] = true;
}

// Move right
void AMainCharacter::startMoveRight() {
	keyPressed[static_cast<int32>(EDirection::DIRECTION_RIGHT)] = true;
}

// Move backward
void AMainCharacter::startMoveBackward() {
	keyPressed[static_cast<int32>(EDirection::DIRECTION_DOWN)] = true;
}

// Move left
void AMainCharacter::startMoveLeft() {
	keyPressed[static_cast<int32>(EDirection::DIRECTION_LEFT)] = true;
}

// Stop movement
void AMainCharacter::endMoveForward() {
	keyPressed[static_cast<int32>(EDirection::DIRECTION_UP)] = false;
}

// Stop movement
void AMainCharacter::endMoveBackward() {
	keyPressed[static_cast<int32>(EDirection::DIRECTION_DOWN)] = false;
}

// Stop movement
void AMainCharacter::endMoveRight() {
	keyPressed[static_cast<int32>(EDirection::DIRECTION_RIGHT)] = false;
}

// Stop movement
void AMainCharacter::endMoveLeft() {
	keyPressed[static_cast<int32>(EDirection::DIRECTION_LEFT)] = false;
}


// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Bind movements
	PlayerInputComponent->BindAction("MoveForward",  IE_Pressed,  this, &AMainCharacter::startMoveForward);
	PlayerInputComponent->BindAction("MoveForward",  IE_Released, this, &AMainCharacter::endMoveForward);
	PlayerInputComponent->BindAction("MoveRight",    IE_Pressed,  this, &AMainCharacter::startMoveRight);
	PlayerInputComponent->BindAction("MoveRight",    IE_Released, this, &AMainCharacter::endMoveRight);
	PlayerInputComponent->BindAction("MoveBackward", IE_Pressed,  this, &AMainCharacter::startMoveBackward);
	PlayerInputComponent->BindAction("MoveBackward", IE_Released, this, &AMainCharacter::endMoveBackward);
	PlayerInputComponent->BindAction("MoveLeft",     IE_Pressed,  this, &AMainCharacter::startMoveLeft);
	PlayerInputComponent->BindAction("MoveLeft",     IE_Released, this, &AMainCharacter::endMoveLeft);

}

// Add a monster to this character
bool AMainCharacter::addMonster(AMonster* Monster) {
	if (m_Monsters.Num() >= MAX_MONSTERS)
		return false;

	m_Monsters.Add(Monster);
	return true;	
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "../Monster/Monster.h"

// Sets default values
AMainCharacter::AMainCharacter() {
 	// Set this character to call Tick() every frame. 
	PrimaryActorTick.bCanEverTick = true;

	//Set default var
	m_Movement = EMovement::MOVEMENT_NONE;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay() {
	Super::BeginPlay();

	UWorld* World = GetWorld();

	if (World) {
		FTimerHandle t;
		World->GetTimerManager().SetTimer(t, this, &AMainCharacter::processMovement, 0.4f, true);
	}
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

//Move the character
void AMainCharacter::processMovement() {
	for (int i = 0; i < 4; ++i) {
		if (keyPressed[i]) {

		}
	}
}

// Move forward
void AMainCharacter::startMoveForward() {
	m_Movement = EMovement::MOVEMENT_UP;
	keyPressed[EDirection::DIRECTION_UP] = true;
}

// Move right
void AMainCharacter::startMoveRight() {
	m_Movement = EMovement::MOVEMENT_RIGHT;
	keyPressed[EDirection::DIRECTION_RIGHT] = true;
}

// Move backward
void AMainCharacter::startMoveBackward() {
	m_Movement = EMovement::MOVEMENT_DOWN;
	keyPressed[EDirection::DIRECTION_DOWN] = true;
}

// Move left
void AMainCharacter::startMoveLeft() {
	m_Movement = EMovement::MOVEMENT_LEFT;
	keyPressed[EDirection::DIRECTION_LEFT] = true;
}

// Stop movement
void AMainCharacter::endMoveForward() {
	m_Movement = EMovement::MOVEMENT_NONE;
	keyPressed[EDirection::DIRECTION_UP] = false;
}

// Stop movement
void AMainCharacter::endMoveBackward() {
	m_Movement = EMovement::MOVEMENT_NONE;
	keyPressed[EDirection::DIRECTION_DOWN] = false;
}

// Stop movement
void AMainCharacter::endMoveRight() {
	m_Movement = EMovement::MOVEMENT_NONE;
	keyPressed[EDirection::DIRECTION_RIGHT] = false;
}

// Stop movement
void AMainCharacter::endMoveLeft() {
	m_Movement = EMovement::MOVEMENT_NONE;
	keyPressed[EDirection::DIRECTION_LEFT] = false;
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

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
		World->GetTimerManager().SetTimer(t, this, &AMainCharacter::processMovement, 0.2f, true);
		DEBUG("Set timer");
	}
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

//Move the character
void AMainCharacter::processMovement() {
	if (m_Movement != EMovement::MOVEMENT_NONE) {
		FVector Orientation;
		switch (m_Movement) {
		case EMovement::MOVEMENT_UP:    Orientation.X = 1.f; break;
		case EMovement::MOVEMENT_DOWN:  Orientation.X = -1.f; break;
		case EMovement::MOVEMENT_RIGHT: Orientation.Y = 1.f; break;
		case EMovement::MOVEMENT_LEFT:  Orientation.Y = -1.f; break;
		}
		AddMovementInput(Orientation, 1.f);
		DEBUG("MOVEMENT PROCESSED");
	}
}

// Move forward
void AMainCharacter::startMoveForward() {
	m_Movement = EMovement::MOVEMENT_UP;
}

// Move right
void AMainCharacter::startMoveRight() {
	m_Movement = EMovement::MOVEMENT_RIGHT;
}

// Move backward
void AMainCharacter::startMoveBackward() {
	m_Movement = EMovement::MOVEMENT_DOWN;
}

// Move left
void AMainCharacter::startMoveLeft() {
	m_Movement = EMovement::MOVEMENT_LEFT;
}

// Stop movement
void AMainCharacter::endMove() {
	m_Movement = EMovement::MOVEMENT_NONE;
}


// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Bind movements
	PlayerInputComponent->BindAction("MoveForward",  IE_Pressed,  this, &AMainCharacter::startMoveForward);
	PlayerInputComponent->BindAction("MoveForward",  IE_Released, this, &AMainCharacter::endMove);
	PlayerInputComponent->BindAction("MoveRight",    IE_Pressed,  this, &AMainCharacter::startMoveRight);
	PlayerInputComponent->BindAction("MoveRight",    IE_Released, this, &AMainCharacter::endMove);
	PlayerInputComponent->BindAction("MoveBackward", IE_Pressed,  this, &AMainCharacter::startMoveBackward);
	PlayerInputComponent->BindAction("MoveBackward", IE_Released, this, &AMainCharacter::endMove);
	PlayerInputComponent->BindAction("MoveLeft",     IE_Pressed,  this, &AMainCharacter::startMoveLeft);
	PlayerInputComponent->BindAction("MoveLeft",     IE_Released, this, &AMainCharacter::endMove);

}

// Add a monster to this character
bool AMainCharacter::addMonster(AMonster* Monster) {
	if (m_Monsters.Num() >= MAX_MONSTERS)
		return false;

	m_Monsters.Add(Monster);
	return true;	
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "../Monster/Monster.h"

// Sets default values
AMainCharacter::AMainCharacter() {
 	// Set this character to call Tick() every frame. 
	PrimaryActorTick.bCanEverTick = true;


	m_isRunning = false;
	m_isOnBike = false;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay() {
	Super::BeginPlay();

}

// Called every frame
void AMainCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

// Equip / unequip the bike
bool AMainCharacter::equipBike(){
    m_isOnBike = !m_isOnBike;
    return m_isOnBike;
}

// Move forward
void AMainCharacter::MoveForward(float Value) {
	if ((Controller != NULL) && (Value != 0.0f))	{
		// find out which way is forward
		FRotator Rotation = Controller->GetControlRotation();
		// Limit pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling()){
			Rotation.Pitch = 0.0f;
		}
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

// Move right
void AMainCharacter::MoveRight(float Value) {
	if ((Controller != NULL) && (Value != 0.0f)) {
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Bind Axis
	PlayerInputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",   this, &AMainCharacter::MoveRight);

}

// Add a monster to this character
bool AMainCharacter::addMonster(AMonster* Monster) {
	if (m_Monsters.Num() >= MAX_MONSTERS)
		return false;

	m_Monsters.Add(Monster);
	return true;	
}

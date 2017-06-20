// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "../Monster/Monster.h"

// Sets default values
AMainCharacter::AMainCharacter()
{
 	// Set this character to call Tick() every frame. 
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Move forward
void AMainCharacter::MoveForward(float Value) {
	if ((Controller != NULL) && (Value != 0.0f)) {
		// find out which way is forward
		FRotator Rotation = GetController()->GetControlRotation();
		// Limit pitch when walking or falling
		if (GetCharacterMovement()->IsMovingOnGround() || GetCharacterMovement()->IsFalling()) {
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
		// find out which way is forward
		FRotator Rotation = GetController()->GetControlRotation();
		// add movement in that direction
		const FVector Direction = FRotationMatrix(Rotation).GetScaledAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Bind movements
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

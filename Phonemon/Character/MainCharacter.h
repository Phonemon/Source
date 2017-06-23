// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Engine.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "../Include.h"
#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MainCharacter.generated.h"

class AMonster;

UCLASS(Blueprintable)
class PHONEMON_API AMainCharacter : public ACharacter {
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMainCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

private:

	// Process movement
	UFUNCTION()
	void processMovement();

	// Stop movement
	UFUNCTION()
		void endMoveForward();

	// Stop movement
	UFUNCTION()
		void endMoveBackward();

	// Stop movement
	UFUNCTION()
		void endMoveLeft();

	// Stop movement
	UFUNCTION()
		void endMoveRight();

	// Move forward
	UFUNCTION()
	void startMoveForward();

	// Move right
	UFUNCTION()
	void startMoveRight();

	// Move backward
	UFUNCTION()
	void startMoveBackward();

	// Move left
	UFUNCTION()
	void startMoveLeft();

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	bool addMonster(AMonster* Monster);

private:
	// Monsters
	TArray<AMonster*> m_Monsters;

	// Movement
	EMovement m_Movement;

	// Movement
	bool keyPressed[4];

	
	
};

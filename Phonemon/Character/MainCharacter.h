// 

#pragma once

#include "Engine.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Runtime/Engine/Classes/GameFramework/Controller.h"
#include "../Include.h"
#include "../Libs/LIB_Bp.h"
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
	UFUNCTION()
	void MoveForward(float Value);

	UFUNCTION()
	void MoveRight(float Value);

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	bool addMonster(AMonster* Monster);

    // Equip the bike
    UFUNCTION()
    bool equipBike();

private:
	// Monsters
	TArray<AMonster*> m_Monsters;

	// Running
   bool m_isRunning;

   // Bike
   bool m_isOnBike;
	
};

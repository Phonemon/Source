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


class UMonsterEntity;
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
	UFUNCTION(BlueprintCallable)
	void MoveForward(float Value);

	UFUNCTION(BlueprintCallable)
	void MoveRight(float Value);

	UFUNCTION()
	void processMovement();

	//UFUNCTION()
	void SetActorRotation(const EDirection Dir);

public:	

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION()
	bool addMonster(UMonsterEntity* Monster);

    // Equip the bike
    UFUNCTION(BlueprintCallable)
    void equipBike();

	UFUNCTION(BlueprintCallable)
	void run(float Val);

	UFUNCTION()
	void setSpeed(const float Speed);

public:
	UFUNCTION()
	void setMoving(const bool isMoving);

	UFUNCTION()
	FTimerHandle& getMovementTimerHandle();

protected:
	// Monsters
	UPROPERTY(BlueprintReadOnly)
	TArray<UMonsterEntity*> m_Monsters;

	// Movement
	UPROPERTY(BlueprintReadOnly)
	bool m_isMoving;
	UPROPERTY()
	FVector m_NextLocation;
	UPROPERTY()
	FTimerHandle m_MovementTimer;
	UPROPERTY(BlueprintReadOnly)
	float m_Speed;

	// Action
	UPROPERTY(BlueprintReadOnly)
	bool m_isInteract;

public: // To avoid blueprint issues

	// Running
	UPROPERTY(BlueprintReadOnly)
	bool m_isRunning;

	// Bike
	UPROPERTY(BlueprintReadOnly)
	bool m_isOnBike;

protected:
	// Name
	UPROPERTY()
	FString m_Name;
	
public:

	// Save the game
	UFUNCTION(BlueprintCallable)
	void saveGame();

private:
	// Load the game
	UFUNCTION()
	void loadGame();

	// The data saved
	UPROPERTY()
	UMainSaveGame* m_SaveGame;
};

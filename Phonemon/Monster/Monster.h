// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Experience/Experience.h"
#include "../Include.h"
#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Monster.generated.h"

UCLASS()
class PHONEMON_API AMonster : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMonster();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	// Exp
	Experience m_Experience;

	// Stats
	UPROPERTY(BlueprintReadOnly)
	int32 m_MaxHp;
	UPROPERTY(BlueprintReadOnly)
	int32 m_Hp;

	int32 m_Strength;
	int32 m_Vitality;
	int32 m_Agility;
	int32 m_Cleverness;

	EMonsterType m_Type;   
	
};

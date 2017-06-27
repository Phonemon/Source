// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Include.h"
#include "CoreMinimal.h"
#include "Object.h"
#include "Experience/Experience.h"
#include "MonsterEntity.generated.h"

/**
 * Entity monster
 */
UCLASS()
class PHONEMON_API UMonsterEntity : public UObject {
	GENERATED_BODY()

public:
	UMonsterEntity();
	~UMonsterEntity();

    FString serialize();

protected:
	// Name
	FName m_Name;

	// Exp
	Experience m_Experience;

	// Stats
	int32 m_MaxHp;
	int32 m_Hp;

	int32 m_Strength;
	int32 m_Vitality;
	int32 m_Agility;
	int32 m_Cleverness;

	EMonsterType m_Type;
};

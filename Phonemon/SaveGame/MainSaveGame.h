// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "MainSaveGame.generated.h"

/**
 *  Class used to save the game
 */
UCLASS()
class PHONEMON_API UMainSaveGame : public USaveGame {
	GENERATED_BODY()

public:

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString PlayerName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	FString SaveSlotName;

	UPROPERTY(VisibleAnywhere, Category = Basic)
	uint32 UserIndex;
	
	
	
	
};

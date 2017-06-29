// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "MainPlayerController.generated.h"

/**
 * 
 */
UCLASS()
class PHONEMON_API AMainPlayerController : public APlayerController {
	GENERATED_BODY()
	
public:
	UFUNCTION(BlueprintNativeEvent, BlueprintCallable, Category = Dialog)
	void addDialog(const FString &Text);
	void addDialog_Implementation(const FString &Text);
};

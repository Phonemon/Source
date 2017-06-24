// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Include.h"
#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "LIB_Bp.generated.h"

/**
 *	Lib blueprint
 */
UCLASS()
class PHONEMON_API ULIB_Bp : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
		
public:

	UFUNCTION(BlueprintCallable, BlueprintPure)
	static FVector getMappedPosition(FVector Position);
	
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "../Character/MainCharacter.h"
#include "Runtime/Engine/Classes/Components/BoxComponent.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Teleporter.generated.h"

UCLASS()
class PHONEMON_API ATeleporter : public AActor {
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ATeleporter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UFUNCTION()
	void Overlapp(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult);

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Place where the player will be teleportated
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Destination")
	FVector m_Destination;

private:
	// Collision
	UPROPERTY()
	UBoxComponent *m_Box;
	
};

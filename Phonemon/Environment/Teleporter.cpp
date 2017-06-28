// Fill out your copyright notice in the Description page of Project Settings.

#include "Teleporter.h"


// Sets default values
ATeleporter::ATeleporter() {
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Create collision
	UBoxComponent *Box = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxCollision"));

	// Assign the box
	if (Box) {
		m_Box = Box;
		m_Box->AttachToComponent(RootComponent, FAttachmentTransformRules(EAttachmentRule::SnapToTarget, false));

		// Add function on overlapp
		m_Box->OnComponentBeginOverlap.AddDynamic(this, &ATeleporter::Overlapp);
	}

}


void ATeleporter::Overlapp(class UPrimitiveComponent* HitComp, class AActor* OtherActor, class UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult) {
	// If this is from a character walk
	if (bFromSweep) {
		AMainCharacter *Character = Cast<AMainCharacter>(OtherActor);

		// If this is a character
		if (Character) {
			Character->SetActorLocation(m_Destination);
			Character->setMoving(false);
		}
	}
}

// Called when the game starts or when spawned
void ATeleporter::BeginPlay() {
	Super::BeginPlay();
	
}

// Called every frame
void ATeleporter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}


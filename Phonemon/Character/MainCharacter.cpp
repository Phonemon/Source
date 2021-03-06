// Fill out your copyright notice in the Description page of Project Settings.


#include "MainCharacter.h"
#include "../Monster/Monster.h"
#include "../Monster/MonsterEntity.h"

// Sets default values
AMainCharacter::AMainCharacter() {
 	// Set this character to call Tick() every frame. 
	PrimaryActorTick.bCanEverTick = true;

	// Init
	m_isRunning = false;
	m_isOnBike = false;
	m_isMoving = false;
	m_isInteract = false;


	
}

// Called when the game starts or when spawned
void AMainCharacter::BeginPlay() {
	Super::BeginPlay();

	// We load the saved game
	loadGame();
}

// Called every frame
void AMainCharacter::Tick(float DeltaTime) {
	Super::Tick(DeltaTime);

}

// Change the rotation of the actor
void AMainCharacter::SetActorRotation(const EDirection Dir) {
	float rotZ = 0;
	switch (Dir) {
	case EDirection::DIRECTION_UP:    rotZ =    0.f; break;
	case EDirection::DIRECTION_DOWN:  rotZ =  180.f; break;
	case EDirection::DIRECTION_RIGHT: rotZ =   90.f; break;
	case EDirection::DIRECTION_LEFT:  rotZ =  270.f; break;
	}
	ACharacter::SetActorRotation(FRotator(0.f, rotZ, 0.f));
}

// Move to the location in m_NextLocation
void AMainCharacter::processMovement() {
	// Get the current location
	FVector Location = GetActorLocation();
	m_NextLocation.Z = Location.Z;

	// If we're near enough to the target
	if (m_NextLocation.X + 0.1f > Location.X && m_NextLocation.X - 0.1f < Location.X && m_NextLocation.Y + 0.1f > Location.Y && m_NextLocation.Y - 0.1f < Location.Y) {
		// We move to the target
		SetActorLocation(m_NextLocation);

		// We stop moving
		m_isMoving = false;

		// We remove the boucled timer
		GetWorld()->GetTimerManager().ClearTimer(m_MovementTimer);
	}

	// If we should move to this location
	else {
		// Get the next location distance
		float mX = Location.X - m_NextLocation.X;
		mX *= -1;

		float mY = Location.Y - m_NextLocation.Y;
		mY *= -1;

		// Rotate the character in the orientation of the movement
		// Get a partial path to the location
		if (mX > 1) {
			SetActorRotation(EDirection::DIRECTION_UP);
			Location.X += TILE_SIZE * m_Speed;
			if (Location.X > m_NextLocation.X)
				Location.X = m_NextLocation.X;
		}
		else if (mX < -1) {
			SetActorRotation(EDirection::DIRECTION_DOWN);
			Location.X -= TILE_SIZE * m_Speed;
			if (Location.X < m_NextLocation.X)
				Location.X = m_NextLocation.X;
		}
		if (mY > 1) {
			SetActorRotation(EDirection::DIRECTION_RIGHT);
			Location.Y += TILE_SIZE * m_Speed;
			if (Location.Y > m_NextLocation.Y)
				Location.Y = m_NextLocation.Y;
		}
		else if (mY < -1) {
			SetActorRotation(EDirection::DIRECTION_LEFT);
			Location.Y -= TILE_SIZE * m_Speed;
			if (Location.Y < m_NextLocation.Y)
				Location.Y = m_NextLocation.Y;
		}

		// If we're unable to continue
		if (!SetActorLocation(Location, true)) {
			m_NextLocation = ULIB_Bp::getMappedPosition(GetActorLocation());

			// We move to the old target
			SetActorLocation(m_NextLocation);

			// We stop moving
			m_isMoving = false;

			// We remove the boucled timer
			GetWorld()->GetTimerManager().ClearTimer(m_MovementTimer);
		}

		// If the timer isn't set
		else if (!GetWorld()->GetTimerManager().IsTimerActive(m_MovementTimer))
			GetWorld()->GetTimerManager().SetTimer(m_MovementTimer, this, &AMainCharacter::processMovement, 0.01f, true, 0.f);

	}
}

// Equip / unequip the bike
void AMainCharacter::equipBike(){
	m_isOnBike = !m_isOnBike;
}

// Run / not run
void AMainCharacter::run(float Val) {
	m_isRunning = (Val >= .9f);
}

// Move forward - backward
void AMainCharacter::MoveForward(float Value) {
	// If we aren't moving
	if (!m_isMoving && abs(int(Value)) == 1) {

		// Get the mov location on the map
		FVector NextLocation = GetActorLocation();
		NextLocation.X += TILE_SIZE * Value;
		NextLocation = ULIB_Bp::getMappedPosition(NextLocation);

		// Add full val
		if (Value < 0) {
			Value = -1;
		}
		else if (Value > 0) {
			Value = 1;
		}

		// We move
		m_isMoving = true;
		
		// Set the location we want to reach
		m_NextLocation = NextLocation;

		// Set the speed
		if (m_isOnBike)
			m_Speed = BIKE_SPEED;
		else if (m_isRunning)
			m_Speed = RUN_SPEED;
		else
			m_Speed = WALK_SPEED;

		processMovement();
		
	}
}

// Move right
void AMainCharacter::MoveRight(float Value) {
	// If we aren't moving
	if (!m_isMoving && abs(int(Value)) == 1) {

		// Get the mov location on the map
		FVector NextLocation = GetActorLocation();
		NextLocation.Y += TILE_SIZE * Value;
		NextLocation = ULIB_Bp::getMappedPosition(NextLocation);

		// Add full val
		if (Value < 0) {
			Value = -1;
		}
		else if (Value > 0) {
			Value = 1;
		}

		// We move
		m_isMoving = true;

		// Set the location we want to reach
		m_NextLocation = NextLocation;

		// Set the speed
		if (m_isOnBike)
			m_Speed = BIKE_SPEED;
		else if (m_isRunning)
			m_Speed = RUN_SPEED;
		else
			m_Speed = WALK_SPEED;

		processMovement();
	}
}

// Called to bind functionality to input
void AMainCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) {
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	//Bind Axis
	PlayerInputComponent->BindAxis("MoveForward", this, &AMainCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight",   this, &AMainCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Run",		  this, &AMainCharacter::run);

	//Bind actions
	PlayerInputComponent->BindAction("EquipBike", IE_Pressed,  this, &AMainCharacter::equipBike);


}

// Accessor
void AMainCharacter::setMoving(const bool isMoving) {
	m_isMoving = isMoving;
}

// Add a monster to this character
bool AMainCharacter::addMonster(UMonsterEntity* Monster) {
	if (m_Monsters.Num() >= MAX_MONSTERS)
		return false;

	m_Monsters.Add(Monster);
	return true;	
}

void AMainCharacter::setSpeed(const float Speed) {
	m_Speed = Speed;
}


// Save the game
void AMainCharacter::saveGame() {
	if (m_SaveGame) {
		// Set data
		m_SaveGame->PlayerLocation = GetActorLocation();
		m_SaveGame->PlayerName = m_Name;

		// Flush
		UGameplayStatics::SaveGameToSlot(m_SaveGame, TEXT("MyGame"), 0);
	}
}

// Load the game
void AMainCharacter::loadGame() {
	// Load the save
	m_SaveGame = Cast<UMainSaveGame>(UGameplayStatics::LoadGameFromSlot(TEXT("MyGame"), 0));
	if (m_SaveGame) {
		// Get data ----

		//Location
		SetActorLocation(m_SaveGame->PlayerLocation);
		// Name
		m_Name = m_SaveGame->PlayerName;
		
		/*// Monsters
		for (auto& Monster : m_SaveGame->Monsters) {
			if (Monster.)
			m_Monsters.Add(&Monster);
		}*/
			
	}
}

FTimerHandle& AMainCharacter::getMovementTimerHandle() {
	return m_MovementTimer;
}
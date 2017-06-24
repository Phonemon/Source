/**
*	This file contains all the macros
**/

#pragma once

//Used to print some text on screen
#define DEBUG(x) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, TEXT(x)); 
#define DEBUG_Vector(x) if (GEngine) GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(x.X) + " " + FString::FromInt(x.Y) + " " + FString::FromInt(x.Z))
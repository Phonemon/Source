/**
*	This file contains all the macros
**/

#pragma once

//Used to print some text on screen
#define DEBUG(x) if (GEngine) GEngine->AddOnScreenDebugMessage(MyNumberKey, 5.f, FColor::Red, TEXT(x)); 
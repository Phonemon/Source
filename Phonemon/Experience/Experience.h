// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
  Used to handle monsters lvl
 */
class PHONEMON_API Experience {
public:
	Experience();
	~Experience();


	int32 getLevel() const;
	void addExperience(const int32 Exp);

private:
	void updateLevel();

	int32 m_Experience;
	int32 m_Level;

	static TArray<int32> m_Levels;
};

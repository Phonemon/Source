// Fill out your copyright notice in the Description page of Project Settings.

#include "Experience.h"

TArray<int32> Experience::m_Levels = {
	0,
	10,
	100,
	1000,
	2000,
	4000,
	6000,
	8000,
	10000,
	15000
};

Experience::Experience() : m_Level(0), m_Experience(0) {

}

Experience::~Experience() {

}

int32 Experience::getLevel() const {
	return m_Level;
}

void Experience::addExperience(const int32 Exp) {
	m_Experience += Exp;
	updateLevel();
}

void Experience::updateLevel() {
	for (m_Level = 1; m_Level <= m_Levels.Num() || m_Experience > m_Levels[m_Level - 1]; ++m_Level);
}
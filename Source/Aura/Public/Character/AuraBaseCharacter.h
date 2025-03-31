// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AuraBaseCharacter.generated.h"

UCLASS(Abstract)
class AURA_API AAuraBaseCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	AAuraBaseCharacter();

protected:
	virtual void BeginPlay() override;
	

};

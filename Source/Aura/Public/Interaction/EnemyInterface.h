// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "EnemyInterface.generated.h"

// This class does not need to be modified.
UINTERFACE(MinimalAPI)
class UEnemyInterface : public UInterface
{
	GENERATED_BODY()
};

/**
 * 
 */
class AURA_API IEnemyInterface
{
	GENERATED_BODY()

	
public:
	// f() = 0 意为纯虚函数 不用实现 要求继承自接口的类重写
	virtual void HighlightActor() = 0;
	virtual void UnHighlightActor() = 0;
};

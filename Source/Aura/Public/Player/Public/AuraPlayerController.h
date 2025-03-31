// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "AuraPlayerController.generated.h"

class UInputMappingContext;
class UInputAction;

/**
 * 
 */
UCLASS()
class AURA_API AAuraPlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AAuraPlayerController();
	
protected:
	virtual void BeginPlay() override;

	virtual void SetupInputComponent() override;

private:
	//IMC
	UPROPERTY(EditAnywhere,Category="输入")
	TObjectPtr<UInputMappingContext> AuraContext;
	
	//IA_Move
	UPROPERTY(EditAnywhere,Category="输入")
	TObjectPtr<UInputAction> MoveAction;

	//const:参数为只读，禁止在函数内修改输入值，保证数据安全。
	//& 表示引用传递，避免复制大型结构体，提升性能。
	void Move(const struct FInputActionValue& InputActionValue);
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Public/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
    check(AuraContext);
	//创建单例增强输入本地玩家系统并分配创建好的InputMappingContext设置优先级
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext,0);
	
}

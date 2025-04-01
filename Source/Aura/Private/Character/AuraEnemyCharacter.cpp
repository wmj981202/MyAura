// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraEnemyCharacter.h"

#include "Aura/Aura.h"
#include "Tests/AutomationCommon.h"

AAuraEnemyCharacter::AAuraEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);
	
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AAuraEnemyCharacter::HighlightActor()
{
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_DEPTH_RED);
}

void AAuraEnemyCharacter::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	GetMesh()->SetCustomDepthStencilValue(0);
	Weapon->SetRenderCustomDepth(false);
	Weapon->SetCustomDepthStencilValue(0);
}

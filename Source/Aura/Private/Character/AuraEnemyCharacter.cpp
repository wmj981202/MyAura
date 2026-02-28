// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraEnemyCharacter.h"
#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Aura/Aura.h"


AAuraEnemyCharacter::AAuraEnemyCharacter()
{
	PrimaryActorTick.bCanEverTick = false;
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);
	//05 Constructing the ASC and AS 中 Enemay从生成赋值asc和as
	//构建自定义子类AuraAbilitySystemComponent
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");
	//设置网络可复制
	AbilitySystemComponent->SetIsReplicated(true);
	AbilitySystemComponent->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);

	//设置自定义子类AuraAttributeSet
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet");
	
	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);
}

void AAuraEnemyCharacter::BeginPlay()
{
	Super::BeginPlay();
	//1.不存在被玩家控制 也不存在asc并非在thisclass上创建的时 在开始使用时即可调用init确定OwnerActor和AvatorActor
	AbilitySystemComponent->InitAbilityActorInfo(this,this);
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



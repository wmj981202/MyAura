// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/AuraCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"

AAuraCharacter::AAuraCharacter()
{
	PrimaryActorTick.bCanEverTick = false;

	Weapon = CreateDefaultSubobject<USkeletalMeshComponent>("Weapon");
	Weapon->SetupAttachment(GetMesh(),FName("WeaponHandSocket"));
	Weapon->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	//设置角色朝输入轴方向旋转
	GetCharacterMovement()->bOrientRotationToMovement = true;
	//设置旋转速率
	GetCharacterMovement()->RotationRate = FRotator(0.0f,400.0f,0.0f);
	//设置角色移动受制于平面
	GetCharacterMovement()->bConstrainToPlane = true;
	//TopDown类游戏典型参数设置
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	//设置不应用玩家控制器控制旋转
	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

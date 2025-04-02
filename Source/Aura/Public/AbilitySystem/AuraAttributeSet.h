// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AttributeSet.h"
#include "AuraAttributeSet.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API UAuraAttributeSet : public UAttributeSet
{
	GENERATED_BODY()

public:
	UAuraAttributeSet();

	//网络同步中需要获取属性的生命周期
	//网络复制任何变量都要重写中函数
	virtual void GetLifetimeReplicatedProps(TArray<class FLifetimeProperty>& OutLifetimeProps) const override;

	//设置复制 ReplicatedUsing 指定回调函数
	//属性同步后的回调：当一个被标记为复制的属性（Replicated）在客户端或服务器上更新时，自动调用指定的函数
	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_Health,Category = "characterAttribute")
	FGameplayAttributeData Health;

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_MaxHealth,Category = "characterAttribute")
	FGameplayAttributeData MaxHealth;

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_Health,Category = "characterAttribute")
	FGameplayAttributeData Mana;

	UPROPERTY(BlueprintReadOnly,ReplicatedUsing = OnRep_MaxHealth,Category = "characterAttribute")
	FGameplayAttributeData MaxMana;

	//复制属性值更新后通知GAS
	UFUNCTION()
	void OnRep_Health(const FGameplayAttributeData& OldHealth) const;
	
	UFUNCTION()
	void OnRep_MaxHealth(const FGameplayAttributeData& OldMaxHealth) const;

	//复制属性值更新后通知GAS
	UFUNCTION()
	void OnRep_Mana(const FGameplayAttributeData& OldMana) const;
	
	UFUNCTION()
	void OnRep_MaxMana(const FGameplayAttributeData& OldMaxMana) const;
};



#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "AuraBaseCharacter.generated.h"


//接口隔离原则 前置声明 C++ 编译器需要明确的类型信息才能编译代码，而 C# 编译器可以看到整个项目。
class UAbilitySystemComponent;
class UAttributeSet;


UCLASS(Abstract)
//IAbilitySystemInterface 让所有继承自的actor都可以访问asc 有可能在playerstate上都过重载函数GetAbilitySystemComponent()获取
class AURA_API AAuraBaseCharacter : public ACharacter,public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	AAuraBaseCharacter();
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override;
	virtual UAttributeSet* GetAttributeSet() const { return AttributeSet; }

protected:
	virtual void BeginPlay() override;

	UPROPERTY()
	TObjectPtr<UAbilitySystemComponent> AbilitySystemComponent;

	UPROPERTY()
	TObjectPtr<UAttributeSet> AttributeSet;

};

// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/Public/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"

AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	//断言检查
    check(AuraContext);
	//创建单例增强输入本地玩家系统并分配创建好的InputMappingContext设置优先级
	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(AuraContext,0);


	//设置输入属性 对应蓝图操作
	//是否显示鼠标
	bShowMouseCursor = true;
	//鼠标样式
	DefaultMouseCursor = EMouseCursor::Default;

	//设置输入方式
	FInputModeGameAndUI InputModeData;
	//点击游戏界面不锁定在边界内
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	//确定设置
	SetInputMode(InputModeData);
	
}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	// 将InputComponent强制类型转换成增强输入  Tips:CastChecked 强转加断言
	UEnhancedInputComponent* EnhancedInputComponent =CastChecked<UEnhancedInputComponent>(InputComponent);

	//成员函数指针的精确类型信息
	//FInputActionValue
	//1.标量值（浮点数）：如扳机键压力值（0.0~1.0）。
	//2.二维向量（FVector2D）：如摇杆输入方向（X/Y 分量）。
	//3.布尔值：如按键是否按下。
	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const struct FInputActionValue& InputActionValue)
{
	//1.获取输入方向 模板函数InputActionValue.Get<T>();
	const FVector2D InputAxisVect = InputActionValue.Get<FVector2D>();
	//2.获取当前玩家控制器向前向右的向量
	const FRotator YawRotation(0.0f,GetControlRotation().Yaw,0.0f); \
	const FVector FDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlPawn = GetPawn<APawn>())
	{
		ControlPawn->AddMovementInput(FDirection,InputAxisVect.Y);
		ControlPawn->AddMovementInput(RDirection,InputAxisVect.X);
	}
	
	
}

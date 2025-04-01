// Fill out your copyright notice in the Description page of Project Settings.


#include "Player/AuraPlayerState.h"

AAuraPlayerState::AAuraPlayerState()
{
	//服务器尝试更新客户端的频率(每秒100次)
	NetUpdateFrequency = 100.f;
}

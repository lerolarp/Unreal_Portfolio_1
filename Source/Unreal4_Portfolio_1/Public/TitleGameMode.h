// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameMode.h"
#include "TitleGameMode.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL4_PORTFOLIO_1_API ATitleGameMode : public AGameMode
{
	GENERATED_BODY()

public:
	ATitleGameMode();
	virtual void BeginPlay() override;

private:
	TSubclassOf<UUserWidget> TitleWidgetClass;
	class UUW_Title* TitleWidget;
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_NaviMenu.generated.h"

/**
 * 
 */
UCLASS()
class UI_API UUW_NaviMenu : public UUserWidget
{
	GENERATED_BODY()

private:
	UPROPERTY(Meta = (BindWidgetAnim), Transient)
	class UWidgetAnimation* ShowUp;

public:
	//virtual void NativeConstruct() override;


public:
	void ShowUpAnim();

	
};

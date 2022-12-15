// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "UW_Title.generated.h"

/**
 * 
 */
UCLASS()
class UI_API UUW_Title : public UUserWidget
{
	GENERATED_BODY()
	
public:
	UPROPERTY(Meta = (BindWidget))
		class UUW_NaviMenu* WB_NaviMenu;

	void StartAnim();

};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Kismet/GameplayStatics.h"
#include "Components/Button.h"

#include "UW_NaviMenu.generated.h"

/**
 * 
 */
UCLASS()
class UI_API UUW_NaviMenu : public UUserWidget
{
	GENERATED_BODY()

protected:
	virtual void NativeConstruct() override;

private:
	UPROPERTY(Meta = (BindWidgetAnim), Transient)
	class UWidgetAnimation* ShowUp;

private:
	// ��ư�� ������ ��, ȣ��� ��������Ʈ�� ����� �Լ�
	UFUNCTION(BlueprintCallable)
	void StartButtonCallback();

	UFUNCTION(BlueprintCallable)
	void EndButtonCallback();

public:
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UButton* StartButton;

	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
	class UButton* ExitButton;


public:
	void ShowUpAnim();

	
};

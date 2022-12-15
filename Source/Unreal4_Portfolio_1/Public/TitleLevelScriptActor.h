// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/LevelScriptActor.h"
#include "TitleLevelScriptActor.generated.h"

/**
 * 
 */
UCLASS()
class UNREAL4_PORTFOLIO_1_API ATitleLevelScriptActor : public ALevelScriptActor
{
	GENERATED_BODY()
	
public:
	ATitleLevelScriptActor();
	virtual void BeginPlay() override;

public:
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = UI)
	TSubclassOf<class UUW_Title> TitleUIClass;
	class UUW_Title* TitleUIObject;
};

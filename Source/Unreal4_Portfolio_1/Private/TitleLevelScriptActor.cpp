// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleLevelScriptActor.h"
#include "UI/Public/UW_Title.h"


ATitleLevelScriptActor::ATitleLevelScriptActor()
{
	static ConstructorHelpers::FClassFinder<UUW_Title> WB_Title(TEXT("WidgetBlueprint'/Game/UI/WB_Title.WB_Title_C'"));
	if (WB_Title.Succeeded())
	{
		TitleUIClass = WB_Title.Class;
	}
}

void ATitleLevelScriptActor::BeginPlay()
{
	Super::BeginPlay();

	TitleUIObject = CreateWidget<UUW_Title>(GetWorld(), TitleUIClass);
	TitleUIObject->AddToViewport();
	TitleUIObject->SetVisibility(ESlateVisibility::Hidden);


	FTimerHandle StartAnimDelayTimerHandle;
	GetWorld()->GetTimerManager().SetTimer(StartAnimDelayTimerHandle, FTimerDelegate::CreateLambda([&]()
		{
			TitleUIObject->SetVisibility(ESlateVisibility::Visible);
			TitleUIObject->StartAnim();
		}), 1.0f, false);

}

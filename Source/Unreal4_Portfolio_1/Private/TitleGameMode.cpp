// Fill out your copyright notice in the Description page of Project Settings.


#include "TitleGameMode.h"
#include "UI/Public/UW_Title.h"

ATitleGameMode::ATitleGameMode()
{
	static ConstructorHelpers::FClassFinder<UUW_Title> WidgetClass(TEXT("WidgetBlueprint'/Game/UI/WB_Title.WB_Title_C'"));
	
	if (WidgetClass.Succeeded())
		TitleWidgetClass = WidgetClass.Class;
}


void ATitleGameMode::BeginPlay()
{
	Super::BeginPlay();

	if (IsValid(TitleWidgetClass))
	{
		// 위젯을 생성한다
		TitleWidget = Cast<UUW_Title>(CreateWidget(GetWorld(), TitleWidgetClass));
	
		if (IsValid(TitleWidget))
		{
			// 위젯을 뷰포트에 추가한다
			TitleWidget->AddToViewport();
			TitleWidget->SetVisibility(ESlateVisibility::Hidden);
	
			FTimerHandle StartAnimDelayTimerHandle;
			GetWorld()->GetTimerManager().SetTimer(StartAnimDelayTimerHandle, FTimerDelegate::CreateLambda([&]()
				{
					TitleWidget->SetVisibility(ESlateVisibility::Visible);
					TitleWidget->StartAnim();
				}), 1.0f, false);
		}
	}

}

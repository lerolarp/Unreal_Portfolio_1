// Fill out your copyright notice in the Description page of Project Settings.

#include "UW_NaviMenu.h"


void UUW_NaviMenu::ShowUpAnim()
{
	PlayAnimation(ShowUp);
}

void UUW_NaviMenu::NativeConstruct()
{
	Super::NativeConstruct();

	// 위젯 블루프린트의 버튼을 이름을 통해 가져온다
	StartButton = Cast<UButton>(GetWidgetFromName(TEXT("StartBtn")));
	ExitButton = Cast<UButton>(GetWidgetFromName(TEXT("QuitBtn")));

	// 버튼 클릭시 호출될 델리게이트에 함수를 등록한다
	StartButton->OnClicked.AddDynamic(this, &UUW_NaviMenu::StartButtonCallback);
	ExitButton->OnClicked.AddDynamic(this, &UUW_NaviMenu::EndButtonCallback);
}

// Start 버튼 클릭시 실행될 함수
void UUW_NaviMenu::StartButtonCallback()
{
	// 레벨을 바꿔주는 함수
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainLevel"));
	UE_LOG(LogTemp, Log, TEXT("Start Button"));
}

// End 버튼 클릭시 실행될 함수
void UUW_NaviMenu::EndButtonCallback()
{
	// 게임 종료 함수
	UKismetSystemLibrary::QuitGame(GetWorld(), GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, true);
}
// Fill out your copyright notice in the Description page of Project Settings.

#include "UW_NaviMenu.h"


void UUW_NaviMenu::ShowUpAnim()
{
	PlayAnimation(ShowUp);
}

void UUW_NaviMenu::NativeConstruct()
{
	Super::NativeConstruct();

	// ���� �������Ʈ�� ��ư�� �̸��� ���� �����´�
	StartButton = Cast<UButton>(GetWidgetFromName(TEXT("StartBtn")));
	ExitButton = Cast<UButton>(GetWidgetFromName(TEXT("QuitBtn")));

	// ��ư Ŭ���� ȣ��� ��������Ʈ�� �Լ��� ����Ѵ�
	StartButton->OnClicked.AddDynamic(this, &UUW_NaviMenu::StartButtonCallback);
	ExitButton->OnClicked.AddDynamic(this, &UUW_NaviMenu::EndButtonCallback);
}

// Start ��ư Ŭ���� ����� �Լ�
void UUW_NaviMenu::StartButtonCallback()
{
	// ������ �ٲ��ִ� �Լ�
	UGameplayStatics::OpenLevel(GetWorld(), TEXT("MainLevel"));
	UE_LOG(LogTemp, Log, TEXT("Start Button"));
}

// End ��ư Ŭ���� ����� �Լ�
void UUW_NaviMenu::EndButtonCallback()
{
	// ���� ���� �Լ�
	UKismetSystemLibrary::QuitGame(GetWorld(), GetWorld()->GetFirstPlayerController(), EQuitPreference::Quit, true);
}
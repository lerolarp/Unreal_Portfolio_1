// Fill out your copyright notice in the Description page of Project Settings.


#include "MainGameModeBase.h"
#include "MyCharacter.h"

AMainGameModeBase::AMainGameModeBase()
{
	DefaultPawnClass = AMyCharacter::StaticClass();


	//static ConstructorHelpers::FClassFinder<ACharacter> 
	//	BP_Char(TEXT("Blueprint'/Game/Blueprints/BP_MyChracter.BP_MyChracter_C'"));
	//if (BP_Char.Succeeded())
	//{
	//	DefaultPawnClass = BP_Char.Class;
	//}
}
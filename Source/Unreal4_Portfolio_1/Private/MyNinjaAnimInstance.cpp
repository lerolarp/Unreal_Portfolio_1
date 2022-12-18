// Fill out your copyright notice in the Description page of Project Settings.


#include "MyNinjaAnimInstance.h"
#include "MyNinjaCharacter.h"

UMyNinjaAnimInstance::UMyNinjaAnimInstance()
{

}

void UMyNinjaAnimInstance::NativeUpdateAnimation(float DeltaSeconds)
{
	Super::NativeUpdateAnimation(DeltaSeconds);

	auto pawn = TryGetPawnOwner();
	if (IsValid(pawn))
	{
		Speed = pawn->GetVelocity().Size();

		auto Character = Cast<AMyNinjaCharacter>(pawn);
		if (Character)
		{
			Vertical = Character->UpDownValue;
			Horizontal = Character->LeftRightValue;
		}
	}
}
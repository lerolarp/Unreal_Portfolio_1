// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyCharacter.generated.h"

UCLASS()
class UNREAL4_PORTFOLIO_1_API AMyCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void PostInitializeComponents() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;



	//Camera
private:
	UPROPERTY(VisibleAnywhere)
		class USpringArmComponent* SpringArm;

	UPROPERTY(VisibleAnywhere)
		class UCameraComponent* Camera;

	UPROPERTY(VisibleAnywhere)
		class UMyAnimInstance* AnimInstance;

	UPROPERTY(VisibleAnywhere, Category = Pawn)
		bool IsAttacking = false;

	//Move
public:
	UPROPERTY()
		float UpDownValue = 0;

	UPROPERTY()
		float LeftRightValue = 0;

	void UpDown(float value);
	void LeftRight(float value);
	void Yaw(float value);

	void Attack();
	UFUNCTION()
		void OnAttackMontageEnded(UAnimMontage* Montage, bool binterrupted);

};

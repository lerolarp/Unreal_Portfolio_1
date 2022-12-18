// Fill out your copyright notice in the Description page of Project Settings.
#include "MyNinjaCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"


// Sets default values
AMyNinjaCharacter::AMyNinjaCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set Camera
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));

	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);

	SpringArm->TargetArmLength = 300.f;
	SpringArm->SetRelativeRotation(FRotator(-35.0f, 0.f, 0.f));


	// 에셋을 불러올 때는 FObjectFinder 를 이용한다.
	static ConstructorHelpers::FObjectFinder<USkeletalMesh> 
		SK_CARDBOARD(TEXT("SkeletalMesh'/Game/Characters/SK_Ninja.SK_Ninja'"));
	
	if (SK_CARDBOARD.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_CARDBOARD.Object);

		GetMesh()->SetRelativeLocationAndRotation(
			FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));

		//애니메이션 모드 설정
		GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

		//애니메이션 블루프린트 가져오기 클래스를 가져오는 것이기 때문에 맨 마지막에 _C를 붙여아함
		static ConstructorHelpers::FClassFinder<UAnimInstance> BLADER_ANIM(
			TEXT("AnimBlueprint'/Game/BluePrint/NinjaAnimInstance.NinjaAnimInstance_C'"));

		if (BLADER_ANIM.Succeeded())
			GetMesh()->SetAnimInstanceClass(BLADER_ANIM.Class);
	}
}

// Called when the game starts or when spawned
void AMyNinjaCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyNinjaCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyNinjaCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyNinjaCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyNinjaCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Yaw"), this, &AMyNinjaCharacter::Yaw);
}


void AMyNinjaCharacter::UpDown(float value)
{
	UpDownValue = value;
	AddMovementInput(GetActorForwardVector(), value);
}

void AMyNinjaCharacter::LeftRight(float value)
{
	LeftRightValue = value;
	AddMovementInput(GetActorRightVector(), value);
}

void AMyNinjaCharacter::Yaw(float value)
{
	AddControllerYawInput(value);
}


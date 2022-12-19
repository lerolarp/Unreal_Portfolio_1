// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "MyAnimInstance.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Set Camera
	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SPRINGARM"));
	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("CAMERA"));


	SpringArm->SetupAttachment(GetCapsuleComponent());
	Camera->SetupAttachment(SpringArm);


	SpringArm->TargetArmLength = 800.0f;
	SpringArm->SetRelativeRotation(FRotator(-45.0f, 0.0f, 0.0f));
	SpringArm->bUsePawnControlRotation = false;
	SpringArm->bInheritPitch = false;
	SpringArm->bInheritRoll = false;
	SpringArm->bInheritYaw = false;
	SpringArm->bDoCollisionTest = false;
	bUseControllerRotationYaw = true;
	bUseControllerRotationYaw = false;

	GetCharacterMovement()->bOrientRotationToMovement = false;
	GetCharacterMovement()->bUseControllerDesiredRotation = true;
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 720.f, 0.0f);







	// 에셋을 불러올 때는 FObjectFinder 를 이용한다.
	static ConstructorHelpers::FObjectFinder<USkeletalMesh>
		SK_CARDBOARD(TEXT("SkeletalMesh'/Game/ParagonSerath/Characters/Heroes/Serath/Meshes/Serath.Serath'"));

	if (SK_CARDBOARD.Succeeded())
	{
		GetMesh()->SetSkeletalMesh(SK_CARDBOARD.Object);

		GetMesh()->SetRelativeLocationAndRotation(FVector(0.f, 0.f, -88.f), FRotator(0.f, -90.f, 0.f));

		//애니메이션 모드 설정
		GetMesh()->SetAnimationMode(EAnimationMode::AnimationBlueprint);

		//애니메이션 블루프린트 가져오기 클래스를 가져오는 것이기 때문에 맨 마지막에 _C를 붙여아함
		static ConstructorHelpers::FClassFinder<UAnimInstance> BLADER_ANIM(
			TEXT("AnimBlueprint'/Game/BluePrint/SerathAnimInstance.SerathAnimInstance_C'"));

		if (BLADER_ANIM.Succeeded())
			GetMesh()->SetAnimInstanceClass(BLADER_ANIM.Class);
	}

}

void AMyCharacter::PostInitializeComponents()
{
	Super::PostInitializeComponents();

	AnimInstance = Cast<UMyAnimInstance>(GetMesh()->GetAnimInstance());
	if (AnimInstance != NULL)
	{
		AnimInstance->OnMontageEnded.AddDynamic(this, &AMyCharacter::OnAttackMontageEnded);
	}
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	FVector dir = FVector(UpDownValue, LeftRightValue, 0);
	if (dir.IsZero() == false && IsAttacking == false)
	{
		GetController()->SetControlRotation(FRotationMatrix::MakeFromX(dir).Rotator());
		AddMovementInput(dir);
	}
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("UpDown"), this, &AMyCharacter::UpDown);
	PlayerInputComponent->BindAxis(TEXT("LeftRight"), this, &AMyCharacter::LeftRight);
	PlayerInputComponent->BindAxis(TEXT("Yaw"), this, &AMyCharacter::Yaw);
	PlayerInputComponent->BindAction(TEXT("Attack"), EInputEvent::IE_Pressed, this, &AMyCharacter::Attack);
}


void AMyCharacter::UpDown(float value)
{
	UpDownValue = value;
}

void AMyCharacter::LeftRight(float value)
{
	LeftRightValue = value;
}

void AMyCharacter::Yaw(float value)
{
	AddControllerYawInput(value);
}

void AMyCharacter::Attack()
{
	if (IsAttacking)
		return;

	if (AnimInstance != NULL)
	{
		AnimInstance->PlayAttackMontage();
		AnimInstance->IsAttacking = true;
		IsAttacking = true;
	}
}

void AMyCharacter::OnAttackMontageEnded(UAnimMontage* Montage, bool binterrupted)
{
	IsAttacking = false;
	if (AnimInstance != NULL)
	{
		AnimInstance->IsAttacking = false;
	}
}


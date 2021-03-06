#include "Player/SGCharacter.h"

#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

ASGCharacter::ASGCharacter()
	: SpringArm{ CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm")) },
	Camera{ CreateDefaultSubobject<UCameraComponent>(TEXT("Camera")) }
{
	SpringArm->bUsePawnControlRotation = true;
	SpringArm->TargetArmLength = 400.f;
	SpringArm->SetupAttachment(RootComponent);

	Camera->SetupAttachment(SpringArm);
	
	PrimaryActorTick.bCanEverTick = true;
}

void ASGCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void ASGCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

void ASGCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &ASGCharacter::Jump);
	PlayerInputComponent->BindAction(TEXT("Dash"), IE_Pressed, this, &ASGCharacter::Dash);
	PlayerInputComponent->BindAction(TEXT("Dash"), IE_Released, this, &ASGCharacter::Dash);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &ASGCharacter::MoveForward);
	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &ASGCharacter::MoveRight);
	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &ASGCharacter::AddControllerYawInput);
	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &ASGCharacter::AddControllerPitchInput);
}

void ASGCharacter::Dash()
{
	static bool bDash = false;
	bDash = !bDash;
	GetCharacterMovement()->MaxWalkSpeed = bDash ? 900.f : 600.f;
}

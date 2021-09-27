#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "SGCharacter.generated.h"

UCLASS()
class SMALLGIANTS_API ASGCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	ASGCharacter();

protected:
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

private:
	void MoveForward(const float AxisValue) { AddMovementInput(GetActorForwardVector(), AxisValue); }
	void MoveRight(const float AxisValue) { AddMovementInput(GetActorRightVector(), AxisValue); }

private:
	UPROPERTY()
	class USpringArmComponent* SpringArm;

	UPROPERTY()
	class UCameraComponent* Camera;
};

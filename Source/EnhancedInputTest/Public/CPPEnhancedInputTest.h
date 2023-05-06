// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InputMappingContext.h" // �ǉ�
#include "InputAction.h" // �ǉ�
#include "InputActionValue.h" // �ǉ�
#include "CPPEnhancedInputTest.generated.h"

UCLASS()
class ENHANCEDINPUTTEST_API ACPPEnhancedInputTest : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ACPPEnhancedInputTest();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	/** Called for Action input */
	void EventAction(const FInputActionValue& Value);

	/** Called for Axis input */
	void EventAxis(const FInputActionValue& Value);

	/** MappingContext */
	UPROPERTY(EditAnywhere, Category = Input)
		class UInputMappingContext* DefaultMappingContext;

	/** Action Input */
	UPROPERTY(EditAnywhere, Category = Input)
		class UInputAction* ActionInput;

	/** Axis Input */
	UPROPERTY(EditAnywhere, Category = Input)
		class UInputAction* AxisInput;

private:
	// Input�ݒ�
	void SetupInput();

	// Input Event(Action) �C�x���g�n���h���[�֐�
	void PressedAction();
	void ReleasedAction();

	// Input Event(Axis) �C�x���g�n���h���[�֐�
	void PressedAxis(const FInputActionValue& Value);

	// Press��Ԃ��Ǘ�
	bool IsPressed = false;
};

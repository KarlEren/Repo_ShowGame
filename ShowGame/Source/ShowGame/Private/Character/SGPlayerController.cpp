// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/SGPlayerController.h"

#include "GameFramework/Character.h"



void ASGPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent *EnhancedInputComponent = Cast<UEnhancedInputComponent>(InputComponent);
	if (!EnhancedInputComponent)
	{
		return;
	}
	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered,this,&ASGPlayerController::Move);
	EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Started,this,&ASGPlayerController::Jump);
	EnhancedInputComponent->BindAction(JumpAction,ETriggerEvent::Completed,this,&ASGPlayerController::StopJump);
	EnhancedInputComponent->BindAction(LookAction,ETriggerEvent::Triggered,this,&ASGPlayerController::Look);
	
}


void ASGPlayerController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);
	//同理，如果输入相关没有初始化失败，直接崩溃比较好
	checkf(SGInputContext,TEXT("输入映射初始化失败"));

	ULocalPlayer *LocalPlayer = GetLocalPlayer();
	checkf(LocalPlayer,TEXT("LocalPlayer获取失败"));
	
	UEnhancedInputLocalPlayerSubsystem *Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(LocalPlayer);
	checkf(Subsystem,TEXT("输入系统初始化失败"));

	Subsystem->AddMappingContext(SGInputContext,0);
}

void ASGPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisValue=InputActionValue.Get<FVector2D>();
	const FRotator Rotation=GetControlRotation();
	const FRotator YawRotation(0.0f,Rotation.Yaw,0.0f);
	const FVector FowardDirection=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection=FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn*ControlledPawn=GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(FowardDirection,InputAxisValue.Y);
		ControlledPawn->AddMovementInput(RightDirection,InputAxisValue.X);
	}
}

void ASGPlayerController::Jump(const FInputActionValue& InputActionValue)
{
	ACharacter *SGCharacter=GetCharacter();
	if (SGCharacter)
	{
		SGCharacter->Jump();
	}
}

void ASGPlayerController::StopJump(const FInputActionValue& InputActionValue)
{
	ACharacter *SGCharacter=GetCharacter();
	if (SGCharacter)
	{
		SGCharacter->StopJumping();
	}
}

void ASGPlayerController::Look(const FInputActionValue& InputActionValue)
{
	APawn *SGPawn=GetPawn<APawn>();
	if (SGPawn)
	{
		SGPawn->AddControllerYawInput(InputActionValue.Get<FVector2D>().X);
		SGPawn->AddControllerPitchInput(InputActionValue.Get<FVector2D>().Y);
	}
}

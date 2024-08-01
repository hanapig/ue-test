// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "Camera/CameraComponent.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "InputActionValue.h"
#include "InputMappingContext.h"
#include "fire.h"
#include "MyPawn.generated.h" 

UCLASS()
class P4_API AMyPawn : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AMyPawn();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	USceneComponent* MCommpont;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UCameraComponent* MCamera;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Input")
	TObjectPtr<UInputMappingContext>InputMC;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Input")
	TObjectPtr<UInputAction>A;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Input")
	TObjectPtr<UInputAction>S;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Input")
	TObjectPtr<UInputAction>W;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Input")
	TObjectPtr<UInputAction>D;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Input")
	TObjectPtr<UInputAction>MouseX;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Input")
	TObjectPtr<UInputAction>MouseY;
	//子弹偏移
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Fire")
	FVector Offset;
	//子弹生成类
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Fire")
	TSubclassOf<class Afire>CreatActor;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Fire")
	float FireRate;
	FTimerHandle FireTimer;
	void MA(const FInputActionValue& Value);
	void MD(const FInputActionValue& Value);
	void MW(const FInputActionValue& Value);
	void MS(const FInputActionValue& Value);
	void Fire();
	void SFire();
	void EFire();
};

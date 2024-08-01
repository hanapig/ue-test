// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "E.generated.h"

UCLASS()
class P4_API AE : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	AE();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;
	void AutoFire();
	UPROPERTY(EditAnywhere,BlueprintReadWrite)
	FTimerHandle Stimer;
	FTimerHandle Stimer1;
	FTimerHandle Stimer2;
	void ReFire();
	void TCol();
	void FCol();
	void DCol();
	UPROPERTY(EditAnywhere, BlueprintReadWrite, category = "Fire1")
	TSubclassOf<class Afire>ECreatActor;
	TArray<Afire*> Espawnactors;
};

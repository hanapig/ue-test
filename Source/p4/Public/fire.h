// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "Components/BoxComponent.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "fire.generated.h"

UCLASS()
class P4_API Afire : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Afire();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere)
	USphereComponent* Col;
	UPROPERTY(EditAnywhere)
	UProjectileMovementComponent* Move1;
	void FireSpeed(const FVector& FireDriection);
};

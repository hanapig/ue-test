// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/DefaultPawn.h"
#include "testpawn.generated.h"

/**
 * 
 */
UCLASS()
class P4_API Atestpawn : public ADefaultPawn
{
	GENERATED_BODY()
	
public:
	virtual void BeginPlay() override;
	UFUNCTION(BlueprintCallable)
	void Events(APawn* test);
	UStaticMeshComponent* MeshComponent;
};

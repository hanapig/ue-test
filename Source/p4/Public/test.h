// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "test.generated.h"

UCLASS()
class P4_API Atest : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	Atest();

protected:
	// Called when the game starts cor when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	USceneComponent* S;
	UPROPERTY(VisibleAnywhere, Category = "Mesh")
	UStaticMeshComponent* M1;
	void test1(AActor* ParentActor, const FAttachmentTransformRules& AttachmentRules, FName SocketName);
	void AttachToComponent(USceneComponent* Parent, const FAttachmentTransformRules& AttachmentRules, FName SocketName);
};

// Fill out your copyright notice in the Description page of Project Settings.


#include "testpawn.h"




void Atestpawn::BeginPlay()
{
	Super::BeginPlay();
	MeshComponent->SetRelativeLocation(FVector(100, 100, 100));
}

void Atestpawn::Events(APawn* test)
{
	MeshComponent->SetRelativeLocation(FVector(100, 100, 100));
}


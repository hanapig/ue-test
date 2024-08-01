// Fill out your copyright notice in the Description page of Project Settings.


#include "test.h"

// Sets default values
Atest::Atest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
    RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
    S = CreateDefaultSubobject<USceneComponent>(("123"));
    S->SetupAttachment(RootComponent);
    if (RootComponent) {
        UE_LOG(LogTemp, Warning, TEXT("ParentActor is valid and will call test1."));
    }
    M1 = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
    M1->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void Atest::BeginPlay()
{
	Super::BeginPlay();
    M1->SetRelativeLocation(FVector(500, 500, 500));
}

// Called every frame
void Atest::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	

}
//void Atest::test1(AActor* ParentActor, const FAttachmentTransformRules& AttachmentRules, FName SocketName)
//{
//    if (RootComponent && ParentActor)
//    {
//        USceneComponent* ParentDefaultAttachComponent = ParentActor->GetDefaultAttachComponent();
//        if (ParentDefaultAttachComponent)
//        {
//            RootComponent->AttachToComponent(ParentDefaultAttachComponent, AttachmentRules, SocketName);
//
//        }
//    }
//}
//
//void Atest::AttachToComponent(USceneComponent* Parent, const FAttachmentTransformRules& AttachmentRules, FName SocketName)
//{
//    if (RootComponent && Parent)
//    {
//        RootComponent->AttachToComponent(Parent, AttachmentRules, SocketName);
//    }
//}



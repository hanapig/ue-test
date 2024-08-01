// Fill out your copyright notice in the Description page of Project Settings.


#include "fire.h"
#include "E.h"
/*1.发射物组件
*	2.定义初始速度方向
*		3.发射位置，获取世界
*/

Afire::Afire()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	RootComponent = CreateDefaultSubobject<USceneComponent>(TEXT("Scence1"));
	if(!Col)
	{
		UE_LOG(LogTemp, Warning, TEXT("have"));
		Col = CreateDefaultSubobject<USphereComponent>(TEXT("Com1"));
		Col->InitSphereRadius(5.0f);
		RootComponent = Col;
	}
	Move1 = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("Move"));
	Move1->SetUpdatedComponent(Col);
	Move1->InitialSpeed = 2000.0f;
	Move1->bShouldBounce = true;
	Move1->bRotationFollowsVelocity = true;
	Move1->MaxSpeed = 3000.0f;
	Move1->Bounciness = 0.3f;
	Move1->ProjectileGravityScale = 0.2f;
	UE_LOG(LogTemp, Warning, TEXT("Start"));
}


// Called when the game starts or when spawned
void Afire::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void Afire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
//发射方向和速度的乘积
void Afire:: FireSpeed(const FVector& FireDriection)
{
	Move1->Velocity = FireDriection * Move1->InitialSpeed;
	UE_LOG(LogTemp, Warning, TEXT("Firetest"));
}


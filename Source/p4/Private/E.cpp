// Fill out your copyright notice in the Description page of Project Settings.


#include "E.h"
#include "fire.h"

// Sets default values
AE::AE()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AE::BeginPlay()
{
	Super::BeginPlay();
	ReFire();
}

// Called every frame
void AE::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	
}

// Called to bind functionality to input
void AE::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AE::AutoFire()
{
	UE_LOG(LogTemp, Warning, TEXT("Enemy"));
	if (ECreatActor)
	{
		//获取敌人位置传入变量
		FVector  ELocation = GetActorLocation();
		FRotator ERocation = GetActorRotation();
		//四个方向
		TArray<FRotator>Rotas;
		Rotas.Add(FRotator(0.0f, 0.0f, 0.0f));
		Rotas.Add(FRotator(0.0f, 180.0f, 0.0f));
		Rotas.Add(FRotator(0.0f, 90.0f, 0.0f));
		Rotas.Add(FRotator(0.0f, -90.0f, 0.0f));
		FVector Eoffset(100.0f, 0.0f, 0.0f);
		//获取世界引用
		UWorld* world = GetWorld();
		//存储所有生成物体

		if (world)
		{
			FRotator ERo;
			FActorSpawnParameters ESpawnActor;
			//ESpawnActor.Owner = this;//指定所属对象
			//ESpawnActor.Instigator = GetInstigator();//获取触发者
			for (FRotator& CopyRot : Rotas) 
			{
				ERo = ERocation + CopyRot;
				FVector RotatedOffset = ERo.RotateVector(Eoffset);
				FVector EndLocation = ELocation + RotatedOffset;
				ERo = ERocation + CopyRot;
				Afire*Espawnactor = world->SpawnActor<Afire>(ECreatActor, ELocation, ERo, ESpawnActor);
				FCol();
				if (Espawnactor)
				{
					Espawnactors.Add(Espawnactor);
					//设置初速度和方向，传入函数方法
					FVector Ro1 = ERo.Vector();
					Espawnactor->FireSpeed(Ro1);
				}
			} 
		}

	}
}


void AE::ReFire()
{
	GetWorld()->GetTimerManager().SetTimer(Stimer, this, &AE::ReFire, 3.0f, true);
	AutoFire();
}

void AE::TCol()
{
	for (Afire* copyactor : Espawnactors) {
		copyactor->SetActorEnableCollision(true);
	}
	GetWorld()->GetTimerManager().SetTimer(Stimer2, this, &AE::DCol, 1.0f, false);
}

void AE::FCol()
{
	for (Afire* copyactor : Espawnactors) {
		if (copyactor && !copyactor->IsPendingKillPending()) {
			copyactor->SetActorEnableCollision(false);
		}
	}
		GetWorld()->GetTimerManager().SetTimer(Stimer1, this, &AE::TCol, 0.5f, false);
	
}

void AE::DCol()
{
	for (Afire* copyactor : Espawnactors) {
		copyactor->Destroy();
	}
	Espawnactors.Empty();
}

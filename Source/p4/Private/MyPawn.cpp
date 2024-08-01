// Fill out your copyright notice in the Description page of Project Settings.

#include "MyPawn.h"
#include "GameFramework/FloatingPawnMovement.h"

// Sets default values
AMyPawn::AMyPawn()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	AutoPossessPlayer = EAutoReceiveInput::Player0;
	RootComponent= CreateDefaultSubobject<USceneComponent>(TEXT("RootComponent"));
	MCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("MCamera"));
	MCommpont=CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MCommpont"));
	MCamera->SetupAttachment(RootComponent);
	MCommpont->SetupAttachment(RootComponent);
	UFloatingPawnMovement*Pawnmove = CreateDefaultSubobject<UFloatingPawnMovement>(TEXT("Floating"));
	FireRate = 0.1f;
}

// Called when the game starts or when spawned
void AMyPawn::BeginPlay()
{
	Super::BeginPlay();
	if (GetMovementComponent() == nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Movement component not found!"));
	}
}

// Called every frame
void AMyPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	if (APlayerController* Mplay = Cast<APlayerController>(GetController()))
	{
		if(UEnhancedInputLocalPlayerSubsystem*MplayEn=ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(Mplay->GetLocalPlayer()))
		{
			MplayEn->AddMappingContext(InputMC, 0);
			 
		}

	}
	if(UEnhancedInputComponent*Icommponent=Cast<UEnhancedInputComponent>(PlayerInputComponent))
	{
		//绑定
		Icommponent->BindAction(A, ETriggerEvent::Triggered, this, &AMyPawn::MA);
		Icommponent->BindAction(D, ETriggerEvent::Triggered, this, &AMyPawn::MD);
		Icommponent->BindAction(S, ETriggerEvent::Triggered, this, &AMyPawn::MS);
		Icommponent->BindAction(W, ETriggerEvent::Triggered, this, &AMyPawn::MW);
		Icommponent->BindAction(MouseX, ETriggerEvent::Triggered, this, &AMyPawn::SFire);
		Icommponent->BindAction(MouseY, ETriggerEvent::Completed, this, &AMyPawn::EFire);
		
	}
}

void AMyPawn::MA(const FInputActionValue& Value)
{
	float LeftValue = Value.Get<float>();
	AddMovementInput(GetActorRightVector (), LeftValue);
}

void AMyPawn::MD(const FInputActionValue& Value)
{
	float LeftR = Value.Get<float>();
	AddMovementInput(GetActorRightVector(), LeftR);
}

void AMyPawn::MW(const FInputActionValue& Value)
{
	float Ward = Value.Get<float>();
	AddMovementInput(GetActorForwardVector(), Ward);
}

void AMyPawn::MS(const FInputActionValue& Value)
{
	float Bw = Value.Get<float>();
	AddMovementInput(GetActorForwardVector(), Bw);
}

void AMyPawn::Fire()
{
	UE_LOG(LogTemp, Warning, TEXT("FIRE TEST5"));
	if(CreatActor)
	{
		//获取摄像机位置传入变量
		FVector  CLocation;
		FRotator CRocation;
		GetActorEyesViewPoint(CLocation, CRocation);
		//设置偏移
		Offset.Set(50.0f, 0.0f, 0.0f);
		//向上发射
		FRotator Ro = CRocation;
		Ro.Pitch+= 5.0f;
		//转换摄像机偏移到世界位置
		FVector WorldOffset = CLocation + FTransform(CRocation).TransformVector(Offset);

		//获取世界引用
		UWorld* world = GetWorld();
		if(world)
		{
			FActorSpawnParameters SpawnActor;
			SpawnActor.Owner = this;//指定所属对象
			SpawnActor.Instigator = GetInstigator();//获取触发者
			UE_LOG(LogTemp, Warning, TEXT("Fire test3"));
			Afire* spawnactor = world->SpawnActor<Afire>(CreatActor, CLocation, CRocation, SpawnActor);
			if(spawnactor)
			{
				//设置初速度和方向，传入函数方法
				FVector Ro1 = Ro.Vector();
				spawnactor->FireSpeed(Ro1);
				UE_LOG(LogTemp, Warning, TEXT("FIRE TEST4"));
			}
		}

	}
}

void AMyPawn::SFire()
{
	UE_LOG(LogTemp, Warning, TEXT("SFire called - Starting fire"));
	Fire();
	GetWorld()->GetTimerManager().SetTimer(FireTimer, this, &AMyPawn::Fire, FireRate, true);
}

void AMyPawn::EFire()
{
	UE_LOG(LogTemp, Warning, TEXT("BFire called - Stopping fire"));
	GetWorld()->GetTimerManager().ClearTimer(FireTimer);
}


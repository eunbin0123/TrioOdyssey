// Fill out your copyright notice in the Description page of Project Settings.


#include "CircleItemActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "ArrowDestroyActor.h"
#include "CircleDestroyActor.h"
#include "../../../../../../../Source/Runtime/Engine/Classes/Components/ArrowComponent.h"

ACircleItemActor::ACircleItemActor()
{
	PrimaryActorTick.bCanEverTick = true;

	//boxComp 持失
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	this->SetRootComponent(boxComp);
	boxComp->SetBoxExtent(FVector(50));
	boxComp->SetRelativeScale3D(FVector(0.5f));
	//meshComp 持失
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);
	meshComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//ArrowComp 持失
	makePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("firePosition"));
	makePosition->SetupAttachment(RootComponent);
}

// Called when the game starts or when spawned
void ACircleItemActor::BeginPlay()
{
	Super::BeginPlay();
	
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &ACircleItemActor::OnMyCompBeginOverlap);
	
}

// Called every frame
void ACircleItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ACircleItemActor::OnMyCompBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	
	//// CircleItem引 CircleDestroy亜 中宜 獣 
	//if (OtherActor->IsA<ACircleDestroyActor>()) {
	//	boxComp->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	//	FTransform t = makePosition->GetComponentTransform();
	//	GetWorld()->SpawnActor<ACircleDestroyActor>(circleFactory, t); // CircleDestroyActor 持失
	//}
}



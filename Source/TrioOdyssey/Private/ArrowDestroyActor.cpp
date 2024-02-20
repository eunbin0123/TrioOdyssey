

#include "ArrowDestroyActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

AArrowDestroyActor::AArrowDestroyActor()
{
	PrimaryActorTick.bCanEverTick = true;
	//boxComp 持失
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	this->SetRootComponent(boxComp);
	boxComp->SetBoxExtent(FVector(10.f));
	//meshComp 持失
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);
}

void AArrowDestroyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void AArrowDestroyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	Move();
}

void AArrowDestroyActor::Move()
{
	FVector dir = GetActorForwardVector();
	FVector P0 = GetActorLocation();
	FVector vt = dir * speed * GetWorld()->GetDeltaSeconds();
	SetActorLocation(P0 + vt);
}




#include "CircleDestroyActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

ACircleDestroyActor::ACircleDestroyActor()
{
	PrimaryActorTick.bCanEverTick = true;
	//boxComp 积己
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	this->SetRootComponent(boxComp);
	boxComp->SetBoxExtent(FVector(50));
	boxComp->SetRelativeScale3D(FVector(0.5f));
	//meshComp 积己
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);
}

void ACircleDestroyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACircleDestroyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	//float x = GetActorScale3D().X;
	//float y = GetActorScale3D().Y;
	//// 割檬 悼救 目瘤霸 
	//if (x <= 35) {
	//	SetActorScale3D(FVector(x + 0.2, y + 0.2, 1));
	//}
	//else {
	//	this->Destroy();
	//}
}

// CircleDestroy客 Player 面倒矫
// Player Damage

// CircleDestroy客 Gumba 面倒 矫
// Gumba Destroy & Coin 积己
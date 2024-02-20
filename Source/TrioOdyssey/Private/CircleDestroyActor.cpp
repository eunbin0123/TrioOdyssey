

#include "CircleDestroyActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

ACircleDestroyActor::ACircleDestroyActor()
{
	PrimaryActorTick.bCanEverTick = true;
	//boxComp ����
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	this->SetRootComponent(boxComp);
	boxComp->SetBoxExtent(FVector(50));
	boxComp->SetRelativeScale3D(FVector(0.5f));
	//meshComp ����
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
	//// ���� ���� Ŀ���� 
	//if (x <= 35) {
	//	SetActorScale3D(FVector(x + 0.2, y + 0.2, 1));
	//}
	//else {
	//	this->Destroy();
	//}
}

// CircleDestroy�� Player �浹��
// Player Damage

// CircleDestroy�� Gumba �浹 ��
// Gumba Destroy & Coin ����
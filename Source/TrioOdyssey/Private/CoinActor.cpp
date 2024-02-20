

#include "CoinActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

ACoinActor::ACoinActor()
{
	PrimaryActorTick.bCanEverTick = true;
	//boxComp ����
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	this->SetRootComponent(boxComp);
	boxComp->SetBoxExtent(FVector(50,20,50));
	boxComp->SetRelativeScale3D(FVector(0.5f));
	//meshComp ����
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);

	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("/Script/Engine.StaticMesh'/Game/EB/Mesh/Coin.Coin'"));

	if (tempMesh.Succeeded()) { //�ε� ����
		// meshComp�� staticmesh�� �ε��� ������ ����
		meshComp->SetStaticMesh(tempMesh.Object);

	}
}

void ACoinActor::BeginPlay()
{
	Super::BeginPlay();
	
}

void ACoinActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FRotator r = FRotator(0, 3, 0);
	FQuat qr = FQuat(r);
	AddActorLocalRotation(qr, false, 0, ETeleportType::None);

}


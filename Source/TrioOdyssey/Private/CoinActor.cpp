

#include "CoinActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"

ACoinActor::ACoinActor()
{
	PrimaryActorTick.bCanEverTick = true;
	//boxComp 생성
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	this->SetRootComponent(boxComp);
	boxComp->SetBoxExtent(FVector(50,20,50));
	boxComp->SetRelativeScale3D(FVector(0.5f));
	//meshComp 생성
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);

	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("/Script/Engine.StaticMesh'/Game/EB/Mesh/Coin.Coin'"));

	if (tempMesh.Succeeded()) { //로드 성공
		// meshComp의 staticmesh를 로드한 것으로 지정
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


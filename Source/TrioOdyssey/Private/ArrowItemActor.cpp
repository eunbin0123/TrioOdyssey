

#include "ArrowItemActor.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Components/ArrowComponent.h"
#include "ArrowDestroyActor.h"
#include "HatActor.h"

AArrowItemActor::AArrowItemActor()
{
	PrimaryActorTick.bCanEverTick = true;
	//boxComp 생성
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	this->SetRootComponent(boxComp);
	boxComp->SetBoxExtent(FVector(50, 50, 20));

	//meshComp 생성
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);

	//ArrowComp 생성
	firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("firePosition"));
	firePosition->SetupAttachment(RootComponent);

}

void AArrowItemActor::BeginPlay()
{
	Super::BeginPlay();
	boxComp->OnComponentBeginOverlap.AddDynamic(this, &AArrowItemActor::OnMyCompBeginOverlap);
	//Attack();
	
}

void AArrowItemActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}
void AArrowItemActor::OnMyCompBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	////this->Destroy();
	//if (OtherActor->IsA<AHatActor>()) {
	//	//Attack();
	//	//OtherActor->Destroy();
	//}
}

void AArrowItemActor::Attack()
{

	//Attack이 호출되는 경우 - player 모자에 맞는 경우
	FTransform t = firePosition->GetComponentTransform();
	GetWorld()->SpawnActor<AArrowDestroyActor>(bulletFactory, t);
}


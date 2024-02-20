

#include "BulletSpawnActor.h"
#include "Components/BoxComponent.h"
#include "Components/ArrowComponent.h"
#include "BulletActor.h"

ABulletSpawnActor::ABulletSpawnActor()
{
	PrimaryActorTick.bCanEverTick = true;

	//boxComp ����
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	this->SetRootComponent(boxComp);

	//meshComp ����
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);

	//mesh�� StaticMesh ���� �ε�
	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("/Script/Engine.StaticMesh'/Game/EB/Mesh/BulletBillLauncher.BulletBillLauncher'"));

	if (tempMesh.Succeeded()) { //�ε� ����
		// meshComp�� staticmesh�� �ε��� ������ ����
		meshComp->SetStaticMesh(tempMesh.Object);

		//������, ���� ����
		meshComp->SetRelativeLocation(FVector(0, 0, -32));
		meshComp->SetRelativeScale3D(FVector(0.005f));
		meshComp->SetRelativeRotation(FRotator(0, -90, 0));

	}


	////ArrowComp ����
	//firePosition = CreateDefaultSubobject<UArrowComponent>(TEXT("firePosition"));
	//firePosition->SetupAttachment(RootComponent);
}

void ABulletSpawnActor::BeginPlay()
{
	Super::BeginPlay();
	/*FTransform t = firePosition->GetComponentTransform();
	GetWorld()->SpawnActor<ABulletActor>(bulletFactory, t);*/
}

void ABulletSpawnActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


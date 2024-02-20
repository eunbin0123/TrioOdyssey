

#include "BulletSpawnActor.h"
#include "Components/BoxComponent.h"
#include "Components/ArrowComponent.h"
#include "BulletActor.h"

ABulletSpawnActor::ABulletSpawnActor()
{
	PrimaryActorTick.bCanEverTick = true;

	//boxComp 생성
	boxComp = CreateDefaultSubobject<UBoxComponent>(TEXT("boxComp"));
	this->SetRootComponent(boxComp);

	//meshComp 생성
	meshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("meshComp"));
	meshComp->SetupAttachment(RootComponent);

	//mesh에 StaticMesh 파일 로드
	ConstructorHelpers::FObjectFinder<UStaticMesh> tempMesh(TEXT("/Script/Engine.StaticMesh'/Game/EB/Mesh/BulletBillLauncher.BulletBillLauncher'"));

	if (tempMesh.Succeeded()) { //로드 성공
		// meshComp의 staticmesh를 로드한 것으로 지정
		meshComp->SetStaticMesh(tempMesh.Object);

		//사이즈, 방향 조정
		meshComp->SetRelativeLocation(FVector(0, 0, -32));
		meshComp->SetRelativeScale3D(FVector(0.005f));
		meshComp->SetRelativeRotation(FRotator(0, -90, 0));

	}


	////ArrowComp 생성
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


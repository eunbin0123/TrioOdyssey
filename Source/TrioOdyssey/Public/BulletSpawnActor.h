// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BulletSpawnActor.generated.h"

UCLASS()
class TRIOODYSSEY_API ABulletSpawnActor : public AActor
{
	GENERATED_BODY()
	
public:	
	ABulletSpawnActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

public:
	//���� �浹ü ����
	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;

	//arrow ����
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* firePosition;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABulletActor> bulletFactory;


};

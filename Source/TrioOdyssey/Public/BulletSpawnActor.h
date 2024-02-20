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
	//倖引 中宜端 持失
	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;

	//arrow 持失
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* firePosition;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class ABulletActor> bulletFactory;


};

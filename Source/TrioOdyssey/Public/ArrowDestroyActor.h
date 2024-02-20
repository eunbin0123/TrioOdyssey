// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArrowDestroyActor.generated.h"

UCLASS()
class TRIOODYSSEY_API AArrowDestroyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AArrowDestroyActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;


	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;

	// speed
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float speed = 500;

	void Move();

};

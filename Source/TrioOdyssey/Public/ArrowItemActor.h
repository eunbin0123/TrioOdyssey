// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ArrowItemActor.generated.h"

UCLASS()
class TRIOODYSSEY_API AArrowItemActor : public AActor
{
	GENERATED_BODY()

public:	
	AArrowItemActor();

protected:
	virtual void BeginPlay() override;

public:	 
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	class UArrowComponent* firePosition;

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AArrowDestroyActor> bulletFactory;

	UFUNCTION()
	void OnMyCompBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
	// 모자랑 충돌했을 때, 출력되게 하는 함수.  
	void Attack();

};

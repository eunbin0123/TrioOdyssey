
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CoinActor.generated.h"

UCLASS()
class TRIOODYSSEY_API ACoinActor : public AActor
{
	GENERATED_BODY() 
	
public:	
	ACoinActor();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere)
	class UStaticMeshComponent* meshComp;

	UPROPERTY(EditAnywhere)
	class UBoxComponent* boxComp;

};

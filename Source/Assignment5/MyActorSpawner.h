// Fill out your copyright notice in the Description page of Project Settings.
 
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActorSpawner.generated.h"

UCLASS()
class ASSIGNMENT5_API AMyActorSpawner : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMyActorSpawner();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Spawning")
	TSubclassOf<AActor> ActorToSpawn;

	UFUNCTION(BlueprintCallable, Category = "Spawning")
	void SpawnActorAtLocation(FVector Location, FRotator Rotation);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

};

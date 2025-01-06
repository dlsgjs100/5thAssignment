// Fill out your copyright notice in the Description page of Project Settings.

 
#include "MyActorSpawner.h"

// Sets default values
AMyActorSpawner::AMyActorSpawner()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActorSpawner::BeginPlay()
{
	Super::BeginPlay();

    FVector SpawnLocation(0.f, 0.f, 500.f);
    FRotator SpawnRotation(0.f, 0.f, 0.f);
    SpawnActorAtLocation(SpawnLocation, SpawnRotation);
	
}

void AMyActorSpawner::SpawnActorAtLocation(FVector Location, FRotator Rotation)
{
    if (ActorToSpawn) // ActorToSpawn이 유효한지 확인
    {
        FActorSpawnParameters SpawnParams;
        SpawnParams.Owner = this;
        SpawnParams.Instigator = GetInstigator();

        // 액터 스폰
        GetWorld()->SpawnActor<AActor>(ActorToSpawn, Location, Rotation, SpawnParams);
    }
}


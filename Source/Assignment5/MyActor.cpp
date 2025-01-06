// Fill out your copyright notice in the Description page of Project Settings.

 
#include "MyActor.h"

// Sets default values
AMyActor::AMyActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();

	TArray<FVector2D> VectorArray;

	UE_LOG(LogTemp, Warning, TEXT("Start the Coordinate Translation program========"));
	UE_LOG(LogTemp, Warning, TEXT("The start coordinates are %f : %f"), start.X, start.Y);
	VectorArray.Add(start);
	for (int32 i = 0; i < 10; i++)
	{
		move();
		UE_LOG(LogTemp, Warning, TEXT("The current coordinates are %f : %f"), start.X, start.Y);
		VectorArray.Add(start);
		distance(VectorArray[i], VectorArray[i + 1]);
		createEvent(50);
	}
	UE_LOG(LogTemp, Warning, TEXT("Total distance travelled : %f"),totDist);
	UE_LOG(LogTemp, Warning, TEXT("Total number of events: %d"),evCnt);



}

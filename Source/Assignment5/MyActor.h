// Fill out your copyright notice in the Description page of Project Settings.
 
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MyActor.generated.h"

UCLASS()
class ASSIGNMENT5_API AMyActor : public AActor
{
	GENERATED_BODY()

public:	
	// Sets default values for this actor's properties
	FVector2D start;
	int32 evCnt;
	float totDist = 0;
	AMyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// 시작점은 (0,0)이고 한번 이동시 x좌표와 y좌표2미만
	// (0.1), (1.1) 
	// (0,0), (1.0) 
	//랜덤하게 10회 이동

	// 0 혹은 1을 랜덤으로 반환
	int32_t step() {
		int32 RandomValue = FMath::RandRange(0, 1);
		return RandomValue;
	}
	// (0,0)부터 10회 움직이면서 좌표를 출력
	// 이동시 step 함수 활용
	// 출력은 UE_LOG를 활용
	void move() {
		start += FVector2D(step(), step());
	}

	// 도전
	// 10회 이동시 각 스텝마다 이전 좌표기준 이동거리를 계산해서 출력
	float distance(FVector2D first, FVector2D second) {
		float dx = first.X - second.X;
		float dy = first.Y - second.Y;
		float dist = FMath::Sqrt(dx * dx + dy * dy);
		totDist += dist;
		UE_LOG(LogTemp, Warning, TEXT("The distance travelled : %f"), dist);
		return dist;
	}

	// 10회 이동시 각 스텝마다, 50% 확률로 랜덤하게 이벤트가 발생
	// 각 스텝마다 이벤트 발생여부를 출력
	
	// 10회 이동 후에는 총 이동거리와 총 이벤트 발생횟수를 출력

	int32 createEvent(float Probability)
	{
		int32 RandomValue = FMath::RandRange(1, 100); // 1 ~ 100의 난수 생성
		if (RandomValue <= Probability)
		{
			evCnt++;
			UE_LOG(LogTemp, Error, TEXT("Event Triggered!"));
		}
		else
		{
			UE_LOG(LogTemp, Log, TEXT("Event Not Triggered"));
		}

		return evCnt;
	}


	
};

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
	// �������� (0,0)�̰� �ѹ� �̵��� x��ǥ�� y��ǥ2�̸�
	// (0.1), (1.1) 
	// (0,0), (1.0) 
	//�����ϰ� 10ȸ �̵�

	// 0 Ȥ�� 1�� �������� ��ȯ
	int32_t step() {
		int32 RandomValue = FMath::RandRange(0, 1);
		return RandomValue;
	}
	// (0,0)���� 10ȸ �����̸鼭 ��ǥ�� ���
	// �̵��� step �Լ� Ȱ��
	// ����� UE_LOG�� Ȱ��
	void move() {
		start += FVector2D(step(), step());
	}

	// ����
	// 10ȸ �̵��� �� ���ܸ��� ���� ��ǥ���� �̵��Ÿ��� ����ؼ� ���
	float distance(FVector2D first, FVector2D second) {
		float dx = first.X - second.X;
		float dy = first.Y - second.Y;
		float dist = FMath::Sqrt(dx * dx + dy * dy);
		totDist += dist;
		UE_LOG(LogTemp, Warning, TEXT("The distance travelled : %f"), dist);
		return dist;
	}

	// 10ȸ �̵��� �� ���ܸ���, 50% Ȯ���� �����ϰ� �̺�Ʈ�� �߻�
	// �� ���ܸ��� �̺�Ʈ �߻����θ� ���
	
	// 10ȸ �̵� �Ŀ��� �� �̵��Ÿ��� �� �̺�Ʈ �߻�Ƚ���� ���

	int32 createEvent(float Probability)
	{
		int32 RandomValue = FMath::RandRange(1, 100); // 1 ~ 100�� ���� ����
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

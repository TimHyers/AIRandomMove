// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "NPC_AIController.generated.h"

/**
 * 
 */
UCLASS()
class AIRANDOMMOVE_API ANPC_AIController : public AAIController
{
	GENERATED_BODY()
public:
	ANPC_AIController(FObjectInitializer const& ObjectInitializer = FObjectInitializer::Get());
	void BeginPlay() override;
	void OnPossess(APawn* const pawn) override;

private:
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	class UBehaviorTree* BehaviorTree;

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "AI", meta = (AllowPrivateAccess = "true"))
	class UBehaviorTreeComponent* BTComponent;
	
	UBlackboardComponent* BBComponent;

	
};

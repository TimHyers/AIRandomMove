// Fill out your copyright notice in the Description page of Project Settings.


#include "NPC_AIController.h"
#include "BehaviorTree/BehaviorTreeComponent.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "UObject/ConstructorHelpers.h"
#include "AIRandomMoveCharacter.h"

ANPC_AIController::ANPC_AIController(FObjectInitializer const& ObjectInitializer)
{
	static ConstructorHelpers::FObjectFinder<UBehaviorTree> Obj(TEXT("BehaviorTree'/Game/AI/NPC_BT.NPC_BT'"));
	if (Obj.Succeeded())
	{
		BehaviorTree = Obj.Object;
	}
	BTComponent = ObjectInitializer.CreateDefaultSubobject<UBehaviorTreeComponent>(this, TEXT("BehaviorComp"));
	BBComponent = ObjectInitializer.CreateDefaultSubobject<UBlackboardComponent>(this, TEXT("BlackBoardComp"));
}

void ANPC_AIController::BeginPlay()
{
	Super::BeginPlay();
	RunBehaviorTree(BehaviorTree);
	BTComponent->StartTree(*BehaviorTree);
}

void ANPC_AIController::OnPossess(APawn* const pawn)
{
	Super::OnPossess(pawn);
	if (BBComponent)
	{
		BBComponent->InitializeBlackboard(*BehaviorTree->BlackboardAsset);
	}
}

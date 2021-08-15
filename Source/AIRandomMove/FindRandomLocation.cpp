// Fill out your copyright notice in the Description page of Project Settings.


#include "FindRandomLocation.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Runtime/NavigationSystem/Public/NavigationSystem.h"
#include "NPC_AIController.h"
#include "BehaviorTree/Blackboard/BlackboardKeyType_Vector.h"
#include "BlackboardKeys.h"

UFindRandomLocation::UFindRandomLocation(FObjectInitializer const& ObjectInitializer)
{
	NodeName = TEXT("Find Random Location");
}

EBTNodeResult::Type UFindRandomLocation::ExecuteTask(UBehaviorTreeComponent& owner_comp, uint8* node_memory)
{
	auto const Controller = Cast<ANPC_AIController>(owner_comp.GetOwner());
	auto const NPC = Controller->GetPawn();

	//Get NPC's original location
	FVector OriginalLocation = NPC->GetActorLocation();
	FNavLocation NewLocation;

	//Get the nav system to generate a new location to move to
	UNavigationSystemV1* const NavigationSys = UNavigationSystemV1::GetCurrent(GetWorld());
	if (NavigationSys->GetRandomPointInNavigableRadius(OriginalLocation, SearchRadius, NewLocation, nullptr))
	{
		Controller->GetBlackboardComponent()->SetValueAsVector(BlackboardKeys::TargetLocation, NewLocation.Location);
	}

	FinishLatentTask(owner_comp, EBTNodeResult::Succeeded);

	return EBTNodeResult::Succeeded;
}


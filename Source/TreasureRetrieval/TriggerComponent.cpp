// Fill out your copyright notice in the Description page of Project Settings.


#include "TriggerComponent.h"

// Sets default values for this component's properties
UTriggerComponent::UTriggerComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
}

// Called when the game starts
void UTriggerComponent::BeginPlay()
{
	Super::BeginPlay();
}

// Called every frame
void UTriggerComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);  

    if(Mover == nullptr)
    {
        return;
    }

    AActor* UnlockActor = GetUnlockActor();
    if(UnlockActor != nullptr)
    {
        UPrimitiveComponent* RootComponent = Cast<UPrimitiveComponent>(UnlockActor->GetRootComponent());
        if(RootComponent != nullptr)
        {
            RootComponent->SetSimulatePhysics(false);
        }
        UnlockActor->AttachToComponent(this, FAttachmentTransformRules::KeepWorldTransform);
        Mover->SetShouldMove(true);
        UE_LOG(LogTemp, Display, TEXT("Moving"));
    }
    else
    {
        Mover->SetShouldMove(false);
    }
}

AActor* UTriggerComponent::GetUnlockActor() const
{
    TArray<AActor*> Actors;
    GetOverlappingActors(Actors);
    for(AActor* Actor : Actors)
    {
        bool Unlock = Actor->ActorHasTag(UnlockTag);
        bool Grabbed = Actor->ActorHasTag("Grabbed");
        if(Unlock && !Grabbed){
            return Actor;
        }
    }
    return nullptr;
}

void UTriggerComponent::SetMover(UMover* NewMover)
{
    Mover = NewMover;
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "CoalaMapBase.h"

// Sets default values
ACoalaMapBase::ACoalaMapBase()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACoalaMapBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoalaMapBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


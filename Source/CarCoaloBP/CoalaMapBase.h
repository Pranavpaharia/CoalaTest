// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CoalaRemoteTileRequest.h"
#include "GameFramework/Actor.h"
#include "CoalaMapBase.generated.h"


UENUM(BlueprintType)
enum class EMapExpansion : uint8
{
	NorthExp,
	SouthExp,
	EastExp,
	WestExp,
	None
};


UCLASS()
class CARCOALOBP_API ACoalaMapBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACoalaMapBase();
	EMapExpansion mapExpansionMode;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(BlueprintReadWrite, Category = "MapTiles")
	TArray<FCoalaRemoteTileRequest> TileList;
	
	UPROPERTY(BlueprintReadWrite, Category = "MapTiles")
	TArray<FCoalaRemoteTileRequest> EastCoastTileList;
	
	UPROPERTY(BlueprintReadWrite, Category = "MapTiles")
	TArray<FCoalaRemoteTileRequest> WestCoastTileList;
	
	UPROPERTY(BlueprintReadWrite, Category = "MapTiles")
	TArray<FCoalaRemoteTileRequest> NorthCoastTileList;
	
	UPROPERTY(BlueprintReadWrite, Category = "MapTiles")
	TArray<FCoalaRemoteTileRequest> SouthCoastTileList;


	UFUNCTION(BlueprintCallable, Category = "MapTiles")
	void InitializeMapList(bool bResetMainList);

	UFUNCTION(BlueprintCallable, Category = "MapTiles")
	void CreateMapTileDataBase(TArray<FCoalaRemoteTileRequest> newAreasInRange);

	UFUNCTION(BlueprintCallable, Category = "MapTiles")
	void NeedToExpandMapInDir(EMapExpansion ExpansionMode, TArray<FCoalaRemoteTileRequest>& newTileArray);

	void ShowListItems(TArray<FCoalaRemoteTileRequest> mList);

	void IntializeCoalaServices();

	void SpawnCenteralActor();

public:
    //For the variables only
	float CoalaMainScale = 1.f;
	FString CoalaAPIKey = TEXT("5F799927B35D0544");
	AActor* MapCentralActor;

};

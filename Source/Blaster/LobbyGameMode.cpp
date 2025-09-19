// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGameMode.h"
#include "GameFramework/GameStateBase.h"

void ALobbyGameMode::PostLogin(APlayerController* NewPlayer)
{
	Super::PostLogin(NewPlayer);

	int32 NumberOfPlayers = GameState.Get()->PlayerArray.Num();
	if (NumberOfPlayers == 2)
	{
		UWorld* World = GetWorld();
		if (World)
		{
			// Start 5 second delay before starting the game
			World->GetTimerManager().SetTimer(
				LobbyStartTimerHandle,
				this,
				&ALobbyGameMode::StartGame,
				5.f,
				false
			);
		}
	}
}

void ALobbyGameMode::StartGame()
{
	UWorld* World = GetWorld();
	if (World)
	{
		bUseSeamlessTravel = false;
		World->ServerTravel(FString("/Game/Maps/BlasterMap?listen"));
	}
}

// Fill out your copyright notice in the Description page of Project Settings.


#include "CharacterOverlay.h"
#include "Blaster/BlasterCharacter.h"
#include "Components/TextBlock.h"

void UCharacterOverlay::NativeConstruct()
{
	Super::NativeConstruct();

	if (DefeatScreen)
	{
		DefeatScreen->SetVisibility(ESlateVisibility::Collapsed);
	}
}

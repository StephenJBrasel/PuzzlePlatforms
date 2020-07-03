// Fill out your copyright notice in the Description page of Project Settings.


#include "InGameMenu.h"
#include "Components/Button.h"


bool UInGameMenu::Initialize() {
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(Btn_CancelIGM != nullptr)) return false;
	Btn_CancelIGM->OnClicked.AddDynamic(this, &UInGameMenu::CancelPressed);
	if (!ensure(Btn_QuitIGM != nullptr)) return false;
	Btn_QuitIGM->OnClicked.AddDynamic(this, &UInGameMenu::QuitPressed);

	return true;
}
void UInGameMenu::CancelPressed()
{
	Teardown();
}

void UInGameMenu::QuitPressed()
{
	if (MenuInterface != nullptr) {
		Teardown();
		MenuInterface->LoadMainMenu();
	}
}

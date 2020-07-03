// Fill out your copyright notice in the Description page of Project Settings.


#include "MainMenu.h"
#include "Components/Button.h"
#include "Components/WidgetSwitcher.h"
#include "Components/EditableTextBox.h"


bool UMainMenu::Initialize() {
	bool Success = Super::Initialize();
	if (!Success) return false;

	if (!ensure(Btn_Host != nullptr)) return false;
	Btn_Host->OnClicked.AddDynamic(this, &UMainMenu::HostServer);
	if (!ensure(Btn_Join != nullptr)) return false;
	Btn_Join->OnClicked.AddDynamic(this, &UMainMenu::OpenJoinMenu);
	if (!ensure(Btn_Exit != nullptr)) return false;
	Btn_Exit->OnClicked.AddDynamic(this, &UMainMenu::ExitGame);
	if (!ensure(Btn_CancelJoin != nullptr)) return false;
	Btn_CancelJoin->OnClicked.AddDynamic(this, &UMainMenu::OpenMainMenu);
	if (!ensure(Btn_JoinGame != nullptr)) return false;
	Btn_JoinGame->OnClicked.AddDynamic(this, &UMainMenu::JoinServer);

	return true;
}

void UMainMenu::HostServer()
{
	if (MenuInterface != nullptr) {
		MenuInterface->Host();
	}
	//UE_LOG(LogTemp, Warning, TEXT("I'm gonna host a serrver!"));
}

void UMainMenu::JoinServer()
{
	if (MenuInterface != nullptr) {
		if (!ensure(IPAddressField != nullptr)) return;
		const FString& Address = IPAddressField->GetText().ToString();
		MenuInterface->Join(Address);
	}
}

void UMainMenu::OpenJoinMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(JoinMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(JoinMenu);
}

void UMainMenu::OpenMainMenu()
{
	if (!ensure(MenuSwitcher != nullptr)) return;
	if (!ensure(MainMenu != nullptr)) return;
	MenuSwitcher->SetActiveWidget(MainMenu);
}

void UMainMenu::ExitGame()
{
	if (MenuInterface != nullptr) {
		MenuInterface->QuitGame();
	}
}


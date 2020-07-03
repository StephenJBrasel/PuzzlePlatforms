// Fill out your copyright notice in the Description page of Project Settings.


#include "MenuWidget.h"


void UMenuWidget::SetMenuInterface(IMenuInterface*  newMenuInterface) {
	this->MenuInterface = newMenuInterface;
}

void UMenuWidget::Setup()
{
	this->bIsFocusable = true;
	this->AddToViewport();

	UWorld* world = GetWorld();
	if (!ensure(world != nullptr)) return;
	APlayerController* PlayerController = world->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetWidgetToFocus(this->TakeWidget());
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	UE_LOG(LogTemp, Warning, TEXT("Game And UI. "));

	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = true;
}

void UMenuWidget::Teardown()
{
	this->RemoveFromViewport();

	//Get Player Controller
	UWorld* world = GetWorld();
	if (!ensure(world != nullptr)) return;
	APlayerController* PlayerController = world->GetFirstPlayerController();
	if (!ensure(PlayerController != nullptr)) return;

	//Create InputGameMode
	FInputModeGameOnly InputModeData;

	//Set the Input Mode to Game Only, hide the cursor
	PlayerController->SetInputMode(InputModeData);
	PlayerController->bShowMouseCursor = false;
}
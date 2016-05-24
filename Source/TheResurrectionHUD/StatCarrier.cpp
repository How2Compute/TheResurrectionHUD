// Fill out your copyright notice in the Description page of Project Settings.

#include "TheResurrectionHUD.h"
#include "StatCarrier.h"


// Sets default values for this component's properties
UStatCarrier::UStatCarrier()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	bWantsBeginPlay = true;
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UStatCarrier::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UStatCarrier::TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction )
{
	Super::TickComponent( DeltaTime, TickType, ThisTickFunction );

	// ...
}

float UStatCarrier::GetAmmountOfMoney()
{
	return Money;
}

float UStatCarrier::GetAmmountOfBullets()
{
	return AmmountOfBullets;
}

float UStatCarrier::GetMaxAmmountOfBullets()
{
	return MaxAmmountOfBullets;
}

float UStatCarrier::GetAmmountOfHealth()
{
	return Health;
}

float UStatCarrier::GetMaxAmmountOfHealth()
{
	return MaxHealth;
}

float UStatCarrier::GetAmmountOfEnergy()
{
	return Energy;
}

float UStatCarrier::GetMaxAmmountOfEnergy()
{
	return MaxEnergy;
}

float UStatCarrier::GetAmmountOfFood()
{
	return Food;
}

float UStatCarrier::GetMaxAmmountOfFood()
{
	return MaxFood;
}

bool UStatCarrier::AddFood(int Ammount)
{
	int OldFood = Food;
	Food += Ammount;
	if (Food != OldFood + Ammount) {
		//Something went horribly wrong!
		return false;
	}
	else {
		//Things must have gone fine!
		return true;
	}
}

bool UStatCarrier::RemoveFood(int Ammount)
{
	int OldFood = Food;
	Food -= Ammount;
	if (Food != OldFood - Ammount) {
		//Something went horribly wrong!
		return false;
	}
	else {
		//Things must have gone fine!
		return true;
	}
}



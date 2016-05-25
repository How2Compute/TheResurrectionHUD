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
	if (Food >= MaxFood) {
		return false;
	}
	int OldFood = Food;
	Food += Ammount;
	if (Food != OldFood + Ammount) {
		//Something went horribly wrong!
		return false;
	}
	else {
		if (Food >= MaxFood) {
			Food = MaxFood;
		}
		//Things must have gone fine!
		return true;
	}
}

bool UStatCarrier::RemoveFood(int Ammount)
{
	//Do very basic errorchecking before attempting more
	if (Food <= 0) {
		//We are already at 0 food so we cant subtract even more!
		return false;
	}
	else {
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
}

bool UStatCarrier::DoHeal(int Ammount)
{
	//Do very basic errorchecking before attempting more
	if (Health >= MaxHealth) {
		return false;
	}
	else {
		int OldHealth = Health;
		Health += Ammount;
		if (Food != OldHealth + Ammount) {
			//Something went horribly wrong!
			return false;
		}
		else {
			//Things must have gone fine!
			return true;
		}
	}
}

bool UStatCarrier::DoDamage(int Ammount)
{
	//Do very basic errorchecking before attempting more
	if (Health <= 0) {
		//We are already at 0 health so we cant subtract even more!
		return false;
	}
	else {
		if (Health - Ammount < 0) {
			Health = 0;
			return false;
		}
		int OldHealth = Health;
		Health -= Ammount;
		if (Health != OldHealth - Ammount) {
			//Something went horribly wrong!
			return false;
		}
		else {
			//Things must have gone fine!
			return true;
		}
	}
}

bool UStatCarrier::AddEnergy(int Ammount)
{
	//Do very basic errorchecking before attempting more
	if (Energy >= MaxEnergy) {
		return false;
	}
	else {
		int OldEnergy = Energy;
		Energy += Ammount;
		if (Energy != OldEnergy + Ammount) {
			//Something went horribly wrong!
			return false;
		}
		else {
			//Things must have gone fine!
			return true;
		}
	}
}

bool UStatCarrier::RemoveEnergy(int Ammount)
{
	//Do very basic errorchecking before attempting more
	if (Energy <= 0) {
		//We are already at 0 energy so we cant subtract even more!
		return false;
	}
	else {
		int OldEnergy = Energy;
		if (Energy - Ammount < 0) {
			Energy = 0;
			return false;
		}
		Energy -= Ammount;
		if (Energy != OldEnergy - Ammount) {
			//Something went horribly wrong!
			return false;
		}
		else {
			//Things must have gone fine!
			return true;
		}
	}
}



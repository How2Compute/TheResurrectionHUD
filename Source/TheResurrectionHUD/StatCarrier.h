// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "StatCarrier.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class THERESURRECTIONHUD_API UStatCarrier : public UActorComponent
{
	GENERATED_BODY()
private:
	int AmmountOfBullets = 25;
	int MaxAmmountOfBullets = 25;
	float Money = 0.0f;
	int Health = 100;
	int MaxHealth = 100;
	int Energy = 10;
	int MaxEnergy = 10;
	int Food = 10;
	int MaxFood = 10;
public:	
	// Sets default values for this component's properties
	UStatCarrier();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;
	UFUNCTION(BlueprintCallable, category = "Money")
		float GetAmmountOfMoney();
	UFUNCTION(BlueprintCallable, category = "Bullets")
		float GetAmmountOfBullets();
	UFUNCTION(BlueprintCallable, category = "Bullets")
		float GetMaxAmmountOfBullets();
	UFUNCTION(BlueprintCallable, category = "Health")
		float GetAmmountOfHealth();
	UFUNCTION(BlueprintCallable, category = "Health")
		float GetMaxAmmountOfHealth();
	UFUNCTION(BlueprintCallable, category = "Energy")
		float GetAmmountOfEnergy();
	UFUNCTION(BlueprintCallable, category = "Energy")
		float GetMaxAmmountOfEnergy();
	UFUNCTION(BlueprintCallable, category = "Food")
		float GetAmmountOfFood();
	UFUNCTION(BlueprintCallable, category = "Food")
		float GetMaxAmmountOfFood();

	UFUNCTION(BlueprintCallable, category = "Food")
		bool AddFood(int Ammount);
	UFUNCTION(BlueprintCallable, category = "Food")
		bool RemoveFood(int Ammount);

	UFUNCTION(BlueprintCallable, category = "Health")
		bool DoHeal(int Ammount);
	UFUNCTION(BlueprintCallable, category = "Health")
		bool DoDamage(int Ammount);
	
};

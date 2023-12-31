// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/GSCGameplayAbility_MeleeBase.h"
#include "CombatGameplayAbility_MeleeBase.generated.h"

/**
 * 
 */

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnActivateCombatAbilityMelee);

class UCombatSystemComponent;

UCLASS()
class PROJECT_MOONFALL_API UCombatGameplayAbility_MeleeBase : public UGSCGameplayAbility_MeleeBase
{
	GENERATED_BODY()
public:

	UPROPERTY(BlueprintAssignable)
	FOnActivateCombatAbilityMelee OnActivateCombatAbility;

protected:

	UPROPERTY()
	UCombatSystemComponent* CombatSystemComponent;

	UPROPERTY(EditDefaultsOnly, Category = "Combat|Effect")
	TSubclassOf<UGameplayEffect> AttackEffect;

	UPROPERTY(EditDefaultsOnly, Category = "Combat|Effect")
	TSubclassOf<UGameplayAbility> ReactAbility;

	UPROPERTY(EditDefaultsOnly, Category = "Combat|Effect")
	TSubclassOf<UGameplayEffect> ReactEffect;

	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle, const FGameplayAbilityActorInfo* ActorInfo, const FGameplayAbilityActivationInfo ActivationInfo, const FGameplayEventData* TriggerEventData) override;
	
	UFUNCTION(BlueprintCallable)
	void OnCombatReceived(FGameplayEventData EventData);

};

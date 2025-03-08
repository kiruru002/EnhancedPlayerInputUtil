// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "EnhancedPlayerInput.h"
#include "InputMappingContext.h"
#include "EnhancedPlayerInputUtilClass.generated.h"

/**
 * 
 */
UCLASS()
class ENHANCEDPLAYERINPUTUTIL_API UEnhancedPlayerInputUtilClass : public UEnhancedPlayerInput
{
	GENERATED_BODY()
	
public:

	const TMap<TObjectPtr<const UInputMappingContext>, int32>& GetAppliedInputContexts() const;

};

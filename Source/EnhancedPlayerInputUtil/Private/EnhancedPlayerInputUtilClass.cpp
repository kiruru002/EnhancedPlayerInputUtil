// Fill out your copyright notice in the Description page of Project Settings.


#include "EnhancedPlayerInputUtilClass.h"

const TMap<TObjectPtr<const UInputMappingContext>, int32>& UEnhancedPlayerInputUtilClass::GetAppliedInputContexts() const
{
	return Super::GetAppliedInputContexts();
}

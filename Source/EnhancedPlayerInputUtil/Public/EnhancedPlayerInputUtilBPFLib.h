// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedPlayerInputUtilBPFLib.generated.h"


USTRUCT(BlueprintType)
struct FMappingContextInfo
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly, Category = "Input")
    const UInputMappingContext* MappingContext;

    UPROPERTY(BlueprintReadOnly, Category = "Input")
    int32 Priority;
};

UCLASS()
class ENHANCEDPLAYERINPUTUTIL_API UEnhancedPlayerInputUtilBPFLib : public UBlueprintFunctionLibrary
{
    GENERATED_BODY()

public:

    /** 現在アクティブな InputMappingContext のリストを取得し、優先度順にソートして Blueprint に返す */
    UFUNCTION(BlueprintPure = false, Category = "Input")
    static TArray<FMappingContextInfo> GetSortedActiveMappingContexts(UEnhancedInputLocalPlayerSubsystem* InputSubsystem);

};

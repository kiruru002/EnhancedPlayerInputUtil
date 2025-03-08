// Fill out your copyright notice in the Description page of Project Settings.


#include "EnhancedPlayerInputUtilBPFLib.h"
#include "EnhancedPlayerInputUtilClass.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedPlayerInput.h"
#include "InputMappingContext.h"

static UEnhancedPlayerInputUtilClass* GetMyPlayerInput(UEnhancedInputLocalPlayerSubsystem* Subsystem)
{
    if (ULocalPlayer* LP = Subsystem->GetLocalPlayer())
    {
        if (APlayerController* PlayerController = LP->GetPlayerController(Subsystem->GetWorld()))
        {
            return Cast<UEnhancedPlayerInputUtilClass>(PlayerController->PlayerInput);
        }
    }

    return nullptr;
}

TArray<FMappingContextInfo> UEnhancedPlayerInputUtilBPFLib::GetSortedActiveMappingContexts(UEnhancedInputLocalPlayerSubsystem* InputSubsystem)
{
    TArray<FMappingContextInfo> MappingContexts;

    if (!InputSubsystem)
    {
        UE_LOG(LogTemp, Warning, TEXT("InputSubsystem is null."));
        return MappingContexts;
    }

    UEnhancedPlayerInputUtilClass* PlayerInput = GetMyPlayerInput(InputSubsystem);
    if (!PlayerInput)
    {
        UE_LOG(LogTemp, Warning, TEXT("PlayerInput is null."));
        return MappingContexts;
    }

    // ���ݓK�p����Ă��� InputMappingContext �̃��X�g���擾
    const TMap<TObjectPtr<const UInputMappingContext>, int32>& ActiveContexts = PlayerInput->GetAppliedInputContexts();

    for (const auto& ContextPair : ActiveContexts)
    {
        if (ContextPair.Key)
        {
            FMappingContextInfo ContextInfo;
            ContextInfo.MappingContext = Cast<const UInputMappingContext>(ContextPair.Key); // Blueprint �Ŏg����悤�ϊ�
            ContextInfo.Priority = ContextPair.Value;
            MappingContexts.Add(ContextInfo);
        }
    }

    // �D��x�iPriority�j�̍~���Ń\�[�g
    MappingContexts.Sort([](const FMappingContextInfo& A, const FMappingContextInfo& B)
    {
        return A.Priority > B.Priority;
    });

    return MappingContexts;
}

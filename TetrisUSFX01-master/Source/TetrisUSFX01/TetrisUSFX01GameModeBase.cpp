// Copyright Epic Games, Inc. All Rights Reserved.


#include "TetrisUSFX01GameModeBase.h"

void ATetrisUSFX01GameModeBase::BeginPlay()
{
    residuo = TM % TT;
    TiempoMaximo -= residuo;
    GetWorldTimerManager().SetTimer(TimerHandle, this, &ATetrisUSFX01GameModeBase::GenerarBloque, Tiempops, true);
    // Call the parent class version of this function
    Super::BeginPlay();
    // Displays a red message on the screen for 10 seconds
    // Spawn an instance of the AMyFirstActor class at the
    //default location.


}

void ATetrisUSFX01GameModeBase::GenerarBloque()
{

    TiempoTranscurrido += Tiempops;

    if (TiempoTranscurrido >= TiempoMaximo + TT) {
        GetWorldTimerManager().ClearTimer(TimerHandle);
        GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, TEXT("Pasaron los 30 segundos"));
        for (int i = 0; i < contador; i++) {
            index = mapita[i]->GetIndex();
            switch (index) {
            case 0:
                GEngine->AddOnScreenDebugMessage(-1, 30, FColor::Blue, TEXT("Pieza larga generada y su posicion es: (") + FString::FromInt(mapita[i]->getPosicionX()) + TEXT(", ") + FString::FromInt(mapita[i]->getPosicionY()) + TEXT(", ") + FString::FromInt(mapita[i]->getPosicionZ()) + TEXT(")"));
                break;
            case 1:
                GEngine->AddOnScreenDebugMessage(-1, 30, FColor::Blue, TEXT("L invertida y su posicion es: (") + FString::FromInt(mapita[i]->getPosicionX()) + TEXT(", ") + FString::FromInt(mapita[i]->getPosicionY()) + TEXT(", ") + FString::FromInt(mapita[i]->getPosicionZ()) + TEXT(")"));
                break;
            case 2:
                GEngine->AddOnScreenDebugMessage(-1, 30, FColor::Blue, TEXT("L y su posicion es: (") + FString::FromInt(mapita[i]->getPosicionX()) + TEXT(", ") + FString::FromInt(mapita[i]->getPosicionY()) + TEXT(", ") + FString::FromInt(mapita[i]->getPosicionZ()) + TEXT(")"));
                break;
            case 3:
                GEngine->AddOnScreenDebugMessage(-1, 30, FColor::Blue, TEXT("Cuadrado y su posicion es: (") + FString::FromInt(mapita[i]->getPosicionX()) + TEXT(", ") + FString::FromInt(mapita[i]->getPosicionY()) + TEXT(", ") + FString::FromInt(mapita[i]->getPosicionZ()) + TEXT(")"));
                break;
            case 4:
                GEngine->AddOnScreenDebugMessage(-1, 30, FColor::Blue, TEXT("S y su posicion es: (") + FString::FromInt(mapita[i]->getPosicionX()) + TEXT(", ") + FString::FromInt(mapita[i]->getPosicionY()) + TEXT(", ") + FString::FromInt(mapita[i]->getPosicionZ()) + TEXT(")"));
                break;
            case 5:
                GEngine->AddOnScreenDebugMessage(-1, 30, FColor::Blue, TEXT("T invertida y su posicion es: (") + FString::FromInt(mapita[i]->getPosicionX()) + TEXT(", ") + FString::FromInt(mapita[i]->getPosicionY()) + TEXT(", ") + FString::FromInt(mapita[i]->getPosicionZ()) + TEXT(")"));
                break;
            case 6:
                GEngine->AddOnScreenDebugMessage(-1, 30, FColor::Blue, TEXT("Z y su posicion es: (") + FString::FromInt(mapita[i]->getPosicionX()) + TEXT(", ") + FString::FromInt(mapita[i]->getPosicionY()) + TEXT(", ") + FString::FromInt(mapita[i]->getPosicionZ()) + TEXT(")"));
                break;
            }
            //GEngine->AddOnScreenDebugMessage(-1, 30, FColor::Blue, TEXT("El valor de miVariable es: ") + FString::FromInt(miVariable));
        }
    }
    else {
        posicionY += 100.0;
        GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Pasaron 5 segundos"));
        FTransform SpawnLocation;

        SpawnedPiece = GetWorld()->SpawnActor<APiece>(APiece::StaticClass(), SpawnLocation);
        SpawnedPiece->SetActorRelativeLocation(FVector(posicionX, posicionY, posicionZ));
        SpawnedPiece->SpawnBlocks();
        SpawnedPiece->setPosicionX(posicionX);
        SpawnedPiece->setPosicionY(posicionY);
        SpawnedPiece->setPosicionZ(posicionZ);
        mapita.Add(contador, SpawnedPiece);
        contador++;
    }


}


void ATetrisUSFX01GameModeBase::DestroyActorFunction()
{
    if (SpawnedActor != nullptr)
    {
        // Displays a red message on the screen for 10 seconds
        GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Actor Block destruido"));
        SpawnedActor->Destroy();
    }
}
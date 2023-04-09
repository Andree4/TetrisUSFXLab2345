// Copyright Epic Games, Inc. All Rights Reserved.
/*Integrantes:
Jhamil Crespo Rojas Ing en Ciencias de la Computación
David Fernando Lujan Renteria Ing en Ciencias de la Computación
Jose David Ledezma Delgado Ing en Sistemas
Jorge Isaac Velasco Barriga Ing en Sistemas
Matias Ezequiel Gutierrez Coronado Ing en Sistemas
Daniel Andree Arancibia Aguilar Ing en Ciencias de la Computación

*/

#include "TetrisUSFX01GameModeBase.h"
//
void ATetrisUSFX01GameModeBase::BeginPlay()
{
    //Evita que se genere una pieza extra si el tiempo esta de más
    residuo = TM % TS;
    TiempoMaximo -= residuo;
    //ciclo que genera bloques
    GetWorldTimerManager().SetTimer(Temporizador, this, &ATetrisUSFX01GameModeBase::GenerarBloque, Tiempops, true);
    
    Super::BeginPlay();
    
}
//funcion que genera los bloques
void ATetrisUSFX01GameModeBase::GenerarBloque()
{

    TiempoTranscurrido += Tiempops;
    //Determina si detener o no el ciclo
    if (TiempoTranscurrido >= TiempoMaximo + TS) {
        GetWorldTimerManager().ClearTimer(Temporizador);//cancela el temporizador
        GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Blue, TEXT("Pasaron los 30 segundos"));
        //muestra el Tmap
        for (int i = 0; i < contador; i++) {
            index = mapita[i]->GetIndex();
            //nombres y posicion de los objetos 
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
        }
    }
    else {
        //genera la pieza
        posicionY += 100.0;
        GEngine->AddOnScreenDebugMessage(-1, 10, FColor::Red, TEXT("Pasaron 5 segundos"));
        FTransform SpawnLocation;
        
        SpawnedPiece = GetWorld()->SpawnActor<APiece>(APiece::StaticClass(), SpawnLocation);
        SpawnedPiece->SetActorRelativeLocation(FVector(posicionX, posicionY, posicionZ));
        SpawnedPiece->SpawnBlocks();
        SpawnedPiece->setPosicionX(posicionX);
        SpawnedPiece->setPosicionY(posicionY);
        SpawnedPiece->setPosicionZ(posicionZ);
        //guarda el nombre y posicion de la pieza
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
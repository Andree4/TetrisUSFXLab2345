#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Block.h"
#include "Piece.h"
#include "TetrisUSFX01GameModeBase.generated.h"

UCLASS()
//clase actor
class TETRISUSFX01_API ATetrisUSFX01GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
private:
	//estructura del temporizador
	FTimerHandle Temporizador;
	//variables que se usan en el ciclo
	float TiempoTranscurrido = 0.0f;
	float TiempoMaximo = 30.0f;
	float Tiempops = 5.0f;//tiempo por segundo
	int TM = TiempoMaximo;
	int TS = Tiempops;
	float residuo;
	//variables para el Tmap 
	int contador = 0;//llave
	int index;//posicion del vector de vectores
	float posicionX = 0.0;
	float posicionY = 0.0;
	float posicionZ = 0.0;

protected:
	virtual void BeginPlay() override;
public:
	//punteros
	UPROPERTY()
		ABlock* SpawnedActor;

	UPROPERTY()
		APiece* SpawnedPiece;

	UFUNCTION()
		void DestroyActorFunction();

	void GenerarBloque();
	//Declaracion del Tmap
	TMap<int, APiece*> mapita;

};
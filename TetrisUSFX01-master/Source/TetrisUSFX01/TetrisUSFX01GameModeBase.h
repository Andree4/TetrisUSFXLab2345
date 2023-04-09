#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "Block.h"
#include "Piece.h"
#include "TetrisUSFX01GameModeBase.generated.h"

UCLASS()
class TETRISUSFX01_API ATetrisUSFX01GameModeBase : public AGameModeBase
{
	GENERATED_BODY()
private:
	FTimerHandle TimerHandle;

	float TiempoTranscurrido = 0.0f;
	float TiempoMaximo = 30.0f;
	float Tiempops = 5.0f;
	int TM = TiempoMaximo;
	int TT = Tiempops;
	float residuo;
	int contador = 0;
	int index;
	float posicionX = 0.0;
	float posicionY = 0.0;
	float posicionZ = 0.0;

protected:
	virtual void BeginPlay() override;
public:
	UPROPERTY()
		ABlock* SpawnedActor;

	UPROPERTY()
		APiece* SpawnedPiece;

	UFUNCTION()
		void DestroyActorFunction();
	void GenerarBloque();
	TMap<int, APiece*> mapita;

};
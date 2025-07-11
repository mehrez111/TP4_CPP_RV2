// CelestialBody.h

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CelestialBody.generated.h"

UENUM(BlueprintType)
enum class EOrbitType : uint8
{
	Circular UMETA(DisplayName = "Circular"),
	Elliptic UMETA(DisplayName = "Elliptic")
};

UCLASS()
class SOLARSYSTEM_API ACelestialBody : public AActor
{
	GENERATED_BODY()

public:
	ACelestialBody();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;

	// Mesh visuel du corps céleste
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Components")
	UStaticMeshComponent* Mesh;

	// --- Rotation sur soi-même ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Rotation")
	float RotationSpeed = 20.0f; // degrés par seconde

	// --- Paramètres d’orbite ---
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	bool bHasOrbit = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	EOrbitType OrbitType = EOrbitType::Circular;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	FVector OrbitCenter = FVector::ZeroVector;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	float OrbitRadiusA = 300.0f; // rayon (cercle) ou demi-grand axe (ellipse)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	float OrbitRadiusB = 300.0f; // demi-petit axe (utilisé si ellipse)

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Orbit")
	float OrbitSpeed = 10.0f; // degrés par seconde

private:
	float OrbitAngle = 0.0f; // angle actuel (en degrés)
};

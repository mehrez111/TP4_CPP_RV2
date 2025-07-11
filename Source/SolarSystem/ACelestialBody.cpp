// CelestialBody.cpp

#include "CelestialBody.h"
#include "Components/StaticMeshComponent.h"
#include "Math/UnrealMathUtility.h"

ACelestialBody::ACelestialBody()
{
	PrimaryActorTick.bCanEverTick = true;

	Mesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh"));
	RootComponent = Mesh;
}

void ACelestialBody::BeginPlay()
{
	Super::BeginPlay();
}

void ACelestialBody::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// --- Rotation sur soi-même ---
	FRotator NewRotation = GetActorRotation();
	NewRotation.Yaw += RotationSpeed * DeltaTime;
	SetActorRotation(NewRotation);

	// --- Mouvement orbital ---
	if (bHasOrbit)
	{
		OrbitAngle += OrbitSpeed * DeltaTime;

		float AngleRad = FMath::DegreesToRadians(OrbitAngle);
		float X = 0.0f;
		float Y = 0.0f;

		if (OrbitType == EOrbitType::Circular)
		{
			X = OrbitRadiusA * FMath::Cos(AngleRad);
			Y = OrbitRadiusA * FMath::Sin(AngleRad);
		}
		else if (OrbitType == EOrbitType::Elliptic)
		{
			X = OrbitRadiusA * FMath::Cos(AngleRad);
			Y = OrbitRadiusB * FMath::Sin(AngleRad);
		}

		FVector NewLocation = OrbitCenter + FVector(X, Y, 0);
		SetActorLocation(NewLocation);
	}
}

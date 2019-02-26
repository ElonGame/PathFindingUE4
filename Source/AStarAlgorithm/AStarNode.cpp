// Rommulluss Caraiman

#include "AStarNode.h"
#include "ConstructorHelpers.h"
#include "DrawDebugHelpers.h"


// Sets default values
AAStarNode::AAStarNode()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SceneComponent = CreateDefaultSubobject<USceneComponent>(TEXT("SceneComponent"));
	this->RootComponent = SceneComponent;

	//MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MeshComponent"));
	//MeshComponent->SetupAttachment(RootComponent);

	BoxComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("BoxComponent"));
	
	BoxComponent->SetCollisionProfileName(FName("NodePreset"));
	//BoxComponent->CanEverAffectNavigation(false);
	BoxComponent->SetUseCCD(true);
	BoxComponent->SetupAttachment(GetRootComponent());

	
}

// Called when the game starts or when spawned
void AAStarNode::BeginPlay()
{	
	Super::BeginPlay();	
	
}

// Called every frame
void AAStarNode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (bNodeDrawExtent)
	{		
		DrawDebugBox(GetWorld(), this->GetActorLocation(), this->GetComponentsBoundingBox().GetExtent(), FColor::Green, true, 5);		
	}
}



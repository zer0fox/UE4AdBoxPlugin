#pragma once
#include "ChartboostComponent.generated.h"

UCLASS(ClassGroup = Advertising, HideCategories = (Activation, "Components|Activation", Collision), meta = (BlueprintSpawnableComponent))
class UChartboostComponent : public UActorComponent
{
   GENERATED_UCLASS_BODY()

public:
   ~UChartboostComponent();
   /**
 * Comment
 * @param Comment
 * @return Comment
 */
   UFUNCTION(BlueprintCallable, Category = "Default")
   void CacheChartboostInterstitial(const FString& location);

   UFUNCTION(BlueprintCallable, Category = "Default")
   bool HasInterstitial(const FString& location);

   UFUNCTION(BlueprintCallable, Category = "Default")
   void ShowChartboostInterstitial(const FString& location);

   UFUNCTION(BlueprintCallable, Category = "Default")
   void CacheChartboostRewardVideo(const FString& location);

   UFUNCTION(BlueprintCallable, Category = "Default")
   bool HasRewardedVideo(const FString& location);

   UFUNCTION(BlueprintCallable, Category = "Default")
   void ShowChartboostRewardVideo(const FString& location);

   DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCacheInterstitialDelegate, FString, location);
   DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDisplayInterstitialDelegate, FString, location);
   DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFailToLoadInterstitialDelegate, FString, location, FString, error);
   DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FCompleteRewardedVideoDelegate, FString, location, int32, Reward);
   DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCacheRewardedVideoDelegate, FString, location);
   DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FFailToLoadRewardedVideoDelegate, FString, location, FString, error);
   DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FDismissRewardedVideo, FString, location);
   DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FCloseRewardedVideo, FString, location);

   UPROPERTY(BlueprintAssignable)
   FCacheInterstitialDelegate DidCacheInterstitial;

   UPROPERTY(BlueprintAssignable)
   FDisplayInterstitialDelegate DidDisplayInterstitial;

   UPROPERTY(BlueprintAssignable)
   FFailToLoadInterstitialDelegate DidFailToLoadInterstitial;

   UPROPERTY(BlueprintAssignable)
   FCompleteRewardedVideoDelegate DidCompleteRewardedVideo;

   UPROPERTY(BlueprintAssignable)
   FCacheRewardedVideoDelegate DidCacheRewardedVideo;

   UPROPERTY(BlueprintAssignable)
   FFailToLoadRewardedVideoDelegate DidFailToLoadRewardedVideo;

   UPROPERTY(BlueprintAssignable)
   FDismissRewardedVideo DidDismissRewardedVideo;

   UPROPERTY(BlueprintAssignable)
   FCloseRewardedVideo DidCloseRewardedVideo;

   static void OnDidCacheInterstitial_Broadcast(FString location) {
      ActiveComponent->DidCacheInterstitial.Broadcast(location);
   }

   static void OnDidDisplayInterstitial_Broadcast(FString location) {
      ActiveComponent->DidDisplayInterstitial.Broadcast(location);
   }

   static void OnDidFailToLoadInterstitial_Broadcast(FString location, FString error) {
      ActiveComponent->DidFailToLoadInterstitial.Broadcast(location, error);
   }

   static void OnDidCompleteRewardedVideo_Broadcast(FString location, int32 reward) {
      ActiveComponent->DidCompleteRewardedVideo.Broadcast(location, reward);
   }

   static void OnDidCacheRewardedVideo_Broadcast(FString location) {
      ActiveComponent->DidCacheRewardedVideo.Broadcast(location);
   }

   static void OnDidFailToLoadRewardedVideo_Broadcast(FString location, FString error) {
      ActiveComponent->DidFailToLoadRewardedVideo.Broadcast(location, error);
   }

   static void OnDidDismissRewardedVideo_Broadcast(FString location) {
      ActiveComponent->DidDismissRewardedVideo.Broadcast(location);
   }

   static void OnDidCloseRewardedVideo_Broadcast(FString location) {
      ActiveComponent->DidCloseRewardedVideo.Broadcast(location);
   }
protected:

private:
   static UChartboostComponent* ActiveComponent;
};


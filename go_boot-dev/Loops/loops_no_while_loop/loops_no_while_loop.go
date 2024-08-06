package main

func getMaxMessagesToSend(costMultiplier float64, maxCostInPennies int) int {
  actualCostInPennies := 1.0
  maxMessageToSend := 1
  for {
    actualCostInPennies *= costMultiplier
    if actualCostInPennies >= float64(maxCostInPennies) {
      return maxMessageToSend
    }
    maxMessageToSend++
  }
}

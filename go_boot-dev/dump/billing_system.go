package main

func calculateFinalBill(costPerMessage float64, numMessages int) float64 {
  var dicountAmount float64 = calculateDiscount(numMessages)
  var baseBill float64 = calculateBaseBill(costPerMessage, numMessages)

  return baseBill - (baseBill * dicountAmount)
}

func calculateDiscount(messageSent int) float64 {
	if messageSent <= 1000 {
		return 0
	}
	if messageSent > 2000 {
		return .2
	}
	return .1
}

func calculateBaseBill(costPerMessage float64, messageSent int) float64 {
	return costPerMessage * float64(messageSent)
}

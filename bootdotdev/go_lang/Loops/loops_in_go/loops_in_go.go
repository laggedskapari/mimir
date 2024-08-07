package main

func bulkSend(numMessages int) float64 {
	initFee := 0.00
	var finalAmount float64
	for i := 0; i < numMessages; i++ {
		finalAmount += 1 + initFee
		initFee += 0.01
	}
	return finalAmount
}

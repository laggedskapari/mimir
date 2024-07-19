package main

func getPacketSize(message string) int {
	messageSize := len(message)
	for i := messageSize; i >= 1; i-- {
		if messageSize%i == 0 {
			numOfPackets := messageSize / i
			if !isPrime(numOfPackets) && numOfPackets > 2 {
				return i
			}
		}
	}
  return 0
}

func isPrime(num int) bool {
	if num == 2 {
		return true
	}

	if num%2 == 0 {
		return false
	}

	for i := 3; i*i <= num; i += 2 {
		if num%i == 0 {
			return false
		}
	}
	return true
}


package main

func maxMessages(thresh int) int {
	messagesCost := 0
	for i := 0; ; i++ {
		messagesCost += 100 + i
		if messagesCost > thresh {
			return i
		}
	}
}

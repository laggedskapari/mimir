package main

func getMessageCosts(messages []string) []float64 {
  messagesCostSlice := make([]float64, len(messages))

  for i := 0; i < len(messages); i++ {
    messagesCostSlice[i] = 0.01 * float64(len(messages[i]))
  }

  return messagesCostSlice
}

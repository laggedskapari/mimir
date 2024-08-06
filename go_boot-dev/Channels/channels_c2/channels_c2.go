package main

func processMessages(messages []string) []string {
	check := make(chan string, len(messages))
  processedMessages := make([]string, len(messages))
	for i := 0; i < len(messages); i++ {
		go func(message string) {
			messages[i] = messages[i] + "-processed"
			check <- messages[i]
		}(messages[i])
	}
  for i := 0; i < len(messages); i++ {
    processedMessages[i] = <- check
  }
  close(check)
	return processedMessages
}

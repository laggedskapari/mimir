package main

type Analytics struct {
	MessagesTotal     int
	MessagesFailed    int
	MessagesSucceeded int
}

type Message struct {
	Recipient string
	Success   bool
}

func getMessageText(analytics *Analytics, message Message) {
	if message.Success {
		analytics.MessagesTotal++
		analytics.MessagesSucceeded++
	} else {
    analytics.MessagesFailed++
		analytics.MessagesTotal++
	}
}

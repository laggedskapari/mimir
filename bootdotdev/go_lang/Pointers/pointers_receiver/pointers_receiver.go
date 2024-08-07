package main

func (e *email) setMessage(newMessage string) {
  e.message = newMessage
}

type email struct {
  message string
  fromAddress string
  toAddress string
}

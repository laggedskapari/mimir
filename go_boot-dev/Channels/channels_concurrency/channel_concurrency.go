package main

import (
  "fmt"
  "time"
)

func sendEmail(message string) {
  go func() {
    time.Sleep(time.Millisecond * 250)
    fmt.Printf("Email received: '%s'\n", message)
  }()
  fmt.Printf("Email sent: '%s'\n", message)
}

func test(message string) {
  sendEmail(message)
  time.Sleep(time.Millisecond * 500)
  fmt.Println("---------------------------")
}

func main() {
  test("Hello there kaladin!")
  test("Hello there shallan!")
  test("Hey there Dalinar!")
}

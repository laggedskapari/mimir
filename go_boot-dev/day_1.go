//package main

//import "fmt"

//func main() {
//  fmt.Println("Hello World!")
//}
package main

import "fmt"

func main(){
  messagesFromDoris := []string {
    "You doing anything later??",
    "Did you get my last message?",
    "Don't leave me hanging...",
    "Please respond I'm lonely!",
  }

  numMessages := float64(len(messagesFromDoris))
  costPerMessage := .02

  totalCost := costPerMessage * numMessages

  fmt.Printf("Doris spent %.2f on text messages today \n", totalCost)
}

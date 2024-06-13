package main

import "fmt"

//func main() {
//  fmt.Println("Hello World!")
//}

// func main(){
//   messagesFromDoris := []string {
//     "You doing anything later??",
//     "Did you get my last message?",
//     "Don't leave me hanging...",
//     "Please respond I'm lonely!",
//   }
//
//   numMessages := float64(len(messagesFromDoris))
//   costPerMessage := .02
//
//   totalCost := costPerMessage * numMessages
//
//   fmt.Printf("Doris spent %.2f on text messages today \n", totalCost)
// }

// func main() {
//   fmt.Println("the compiled textio server is starting")
// }

// func main() {
//   var username string = "presidentSkroob"
//   var password string = "12345"
//
//   fmt.Println("Authentication: Basic", username+":"+password)
// }

func main() {
	var startup string = "Textio SMS service booting up..."
	var message string = "Sending text message"
	var confirm string = "Message sent!"

	fmt.Println(confirm)
	fmt.Println(message)
	fmt.Println(startup)
}

package main 

import "fmt"

func sendSMSToCouple(msgToCustomer, msgToSpouse string) (int, error) {
  costCust, errCust := sendSMS(msgToCustomer)
  costSpouse, errorSpouse := sendSMS(msgToSpouse)
  
  if errCust != nil{
    return 0, errCust
  } 
  if errorSpouse != nil {
    return 0, errorSpouse
  }

  return (costCust + costSpouse), nil
}

func sendSMS(message string) (int, error) {
  const maxTextLength = 25
  const costPerChar = 2

  if len(message) > maxTextLength {
    return 0, fmt.Errorf("can't send texts over %v characters", maxTextLength)
  }
  return costPerChar * len(message), nil 
}

package main

func getMessageWithRetries(primary, secondary, tertiary string) ([3]string, [3]int) {
  lenPri := len(primary)
  lenSec := len(secondary)
  lenTer := len(tertiary)

  return [3]string{primary, secondary, tertiary}, [3]int{lenPri, lenPri + lenSec, lenPri + lenSec + lenTer}
}

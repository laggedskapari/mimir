package main

func isValidPassword(password string) bool {
  upperCasePresent := false
  digitPresent := false
  if len(password) < 5 || len(password) > 12 {
    return false
  }
  for _, char := range password {
    if char >= 'A' && char <= 'Z' {
      upperCasePresent = true
    }
    if char >= '0' && char <= '9' {
      digitPresent = true
    }
  }
  if upperCasePresent && digitPresent {
    return true
  }
  return false
}

func main() {
  isValidPassword("Pass123")
}

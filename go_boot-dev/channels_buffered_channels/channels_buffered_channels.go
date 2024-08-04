package main

func addEmailsToQueue(emails []string) chan string {
  result := 0
  for _, email := range emails {
    result += len(email)
  }

  emailChan := make(chan string, result)

  for _, email := range emails {
    emailChan <- email
  }

  return emailChan
}

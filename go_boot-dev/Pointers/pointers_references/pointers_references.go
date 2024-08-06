package main

import (
	"strings"
)

func removeProfanity(message *string) {
  profanityMap := map[string]string{
    "fubb": "****",
    "shiz": "****",
    "witch": "*****",
  }

  for word, replacement := range(profanityMap) {
    *message = strings.ReplaceAll(*message, word, replacement)
  }
}

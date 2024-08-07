package main

func indexOfFirstBadWord(msg []string, badWords []string) int {
  for i, word := range msg {
    for j := 0; j < len(badWords); j++ {
      if badWords[j] == word {
        return i
      }
    }
  }
  return -1
}

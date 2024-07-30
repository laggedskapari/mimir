package main

import "strings"

func countDistinctWords(messages []string) int {
	result := 0
	words := []string{}
	wordCounts := map[string]int{}
	for _, element := range messages {
		words = append(words, strings.Fields(element)...)
	}

	for _, word := range words {
		lowerCaseWord := strings.ToLower(word)
		if _, ok := wordCounts[lowerCaseWord]; !ok {
			wordCounts[lowerCaseWord] = 0
		}
		wordCounts[lowerCaseWord] += 1
	}

	result = len(wordCounts)

	return result
}

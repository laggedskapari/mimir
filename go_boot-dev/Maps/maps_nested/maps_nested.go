package main

func getNameCounts(names []string) map[rune]map[string]int {
	result := make(map[rune]map[string]int)
	for _, name := range names {
    firstChar := []rune(name)[0]
		if _, ok := result[firstChar]; !ok {
			result[firstChar] = make(map[string]int)
		}
		result[firstChar][name] += 1
	}
	return result
}


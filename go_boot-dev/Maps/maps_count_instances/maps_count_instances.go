package main

func getCounts(messageUsers []string, validUsers map[string]int) {
	for _, messagedUser := range messageUsers {
		if _, ok := validUsers[messagedUser]; ok {
			validUsers[messagedUser] = validUsers[messagedUser] + 1
		}
	}
}

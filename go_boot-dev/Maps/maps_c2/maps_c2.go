package main

func findSuggestedFriends(username string, friendships map[string][]string) []string {
	tempArray := []string{}
	for _, friends := range friendships[username] {
		for _, friend := range friendships[friends] {
			tempArray = append(tempArray, friend)
		}
	}
	resultMap := map[string]int{}
	for _, friend := range tempArray {
		if _, ok := resultMap[friend]; !ok {
			resultMap[friend] = 0
		}
		resultMap[friend] += 1
	}
	result := []string{}
	for commonFriend := range resultMap {
		if commonFriend != username {
			result = append(result, commonFriend)
		}
	}
	if len(result) == 0 {
		return nil
	}

	return result
}

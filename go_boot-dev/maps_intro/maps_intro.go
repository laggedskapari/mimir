package main

import "errors"

func getUserMap(names []string, phoneNumber []int) (map[string]user, error) {
  userMap := make(map[string]user)
  if len(names) != len(phoneNumber) {
    return userMap, errors.New("invalid sizes")
  }
  for i := 0; i < len(names); i++ {
    userMap[names[i]] = user{names[i], phoneNumber[i]}
  }
  return userMap, nil
}

type user struct {
  name string
  phoneNumber int
}

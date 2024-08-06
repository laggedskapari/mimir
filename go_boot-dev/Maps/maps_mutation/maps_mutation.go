package main

import "errors"

func deleteIfNecessary(user map[string]user, name string) (deleted bool, err error) {
	usr, ok := user[name]
	if ok == true {
		if usr.scheduleForDeletion == true {
			delete(user, name)
			return true, nil
		} else {
			return false, nil
		}
	}
	return false, errors.New("not found")
}

type user struct {
	name                string
	number              int
	scheduleForDeletion bool
}

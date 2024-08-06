package main

import "fmt"

type email struct {
	isSubscribed bool
	body         string
}

type format interface {
	format() string
}

type expense interface {
	cost() string
}

func (e email) cost() int {
	if e.isSubscribed {
		return len(e.body) * 2
	}
	return len(e.body) * 5
}

func (e email) format() string {
	if e.isSubscribed {
		return fmt.Sprintf("'%s' | Subscribed", e.body)
	}
	return fmt.Sprintf("'%s' | Not Subscribed", e.body)
}

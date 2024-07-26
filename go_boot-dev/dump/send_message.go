// package main
//
// func (user User) SendMessage(message string, messageLength int) (string, bool) {
//   if messageLength <= user.MessageCharLimit {
//     return message, true
//   }
//   return "", false
// }
//
// type User struct {
// 	Name string
// 	Membership
// }
//
// type Membership struct {
// 	Type             membershipType
// 	MessageCharLimit int
// }
//
// type membershipType string
//
// const (
// 	TypeStandard membershipType = "standard"
// 	TypePremium  membershipType = "premium"
// )
//
// func newUser(name string, membershipType membershipType) User {
// 	membership := Membership{Type: membershipType}
// 	if membershipType == TypeStandard {
// 		membership.MessageCharLimit = 100
// 	} else if membershipType == TypePremium {
// 		membership.MessageCharLimit = 1000
// 	}
// 	return User{Name: name, Membership: membership}
// }

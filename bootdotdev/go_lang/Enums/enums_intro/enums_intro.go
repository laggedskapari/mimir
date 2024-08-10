package main

import "fmt"

func (a *analytics) handleEmailBounce(em email) error {
	updateErr := em.recipient.updateStatus(em.status)
	if updateErr != nil {
		return fmt.Errorf("error updating user status: %w", updateErr)
	}
	trackErr := a.track(em.status)
	if trackErr != nil {
		return fmt.Errorf("error updating user status: %w", trackErr)
	}
	return nil
}

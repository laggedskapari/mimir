package main

import (
	"time"
)

func saveBackups(snapshotTicker, safeAfter <-chan time.Time, logChan chan string) {
	for i := 0; ; i++ {
		select {
		case <-snapshotTicker:
			takeSnapshot(logChan)
		case <-safeAfter:
			saveSnapshot(logChan)
			return
		default:
			waitForData(logChan)
			time.Sleep(500 * time.Millisecond)
		}
	}
}

func takeSnapshot(logChan chan string) {
	logChan <- "Taking a backup snapshot..."
}

func saveSnapshot(logChan chan string) {
	logChan <- "All backups saved!"
	close(logChan)
}

func waitForData(logChan chan string) {
	logChan <- "Nothing to do, waiting..."
}

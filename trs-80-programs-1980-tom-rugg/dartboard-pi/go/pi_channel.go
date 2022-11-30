package main

import (
	"fmt"
	"math/rand"
	"time"

	"github.com/inancgumus/screen"
)

func main() {
	// pi

	total := 0
	totalHits := 0
	title()
	var pi float64
	channelDepth := inputChannelDepth()
	sampleSize := getSampleSize()
	results := make(chan int) //, channelDepth)
	// title()
	fmt.Printf("%-10s %-10s %15s\n", "# HITS", "# THROWN", "PI")

	for ch := 0; ch < channelDepth; ch++ {
		go func(ch int) {
			rand := rand.New(rand.NewSource(time.Now().Unix()))
			for {
				results <- countInsideHits(sampleSize, rand)
			}
		}(ch)
	}
	for {
		numberOfHits, ok := <-results
		if !ok {
			break
		}
		totalHits += numberOfHits
		total += sampleSize
		pi = float64(4.0) * float64(totalHits) / float64(total)
		fmt.Printf("%10d %10d %15.13f\n", totalHits, total, pi)
	}
}

func inputChannelDepth() int {
	var input int
	fmt.Print("Input buffer capacity: ")
	fmt.Scanf("%d", &input)
	return input
}

func getSampleSize() int {
	var sampleSize int
	for {
		fmt.Print("SAMPLE SIZE FOR PRINTING ")
		fmt.Scanf("%d", &sampleSize)
		if sampleSize >= 1 {
			break
		}
	}
	return sampleSize
}

func countInsideHits(sampleSize int, rand *rand.Rand) int {
	numberOfHits := 0
	for j := 0; j < sampleSize; j++ {
		// https://akbir.dev/post/golangs-rand-and-concurrency/
		x := rand.Float64()
		y := rand.Float64()
		if (x*x + y*y) < 1.0 {
			numberOfHits += 1
		}
	}
	return numberOfHits
}

func title() {
	screen.Clear()
	fmt.Printf("%6s%s\n", "", "A DARTBOARD PI CALCULATOR")
}

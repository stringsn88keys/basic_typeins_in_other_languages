package main

import (
	"fmt"
	"math/rand"

	"github.com/inancgumus/screen"
)

func main() {
	// pi

	t := 0
	th := 0
	_600()
	var np int
	var p float64
	for {
		fmt.Print("SAMPLE SIZE FOR PRINTING ")
		fmt.Scanf("%d", &np)
		if np >= 1 {
			break
		}
	}
	_600()
	fmt.Printf("%-10s %-10s %15s\n", "# HITS", "# THROWN", "PI")
	for {
		nh := _500(np)
		th += nh
		t += np
		p = float64(4.0) * float64(th) / float64(t)
		fmt.Printf("%10d %10d %15.13f\n", th, t, p)
	}
}

func _500(np int) int {
	nh := 0
	for j := 0; j < np; j++ {
		x := rand.Float64()
		y := rand.Float64()
		if (x*x + y*y) < 1.0 {
			nh += 1
		}
	}
	return nh
}

func _600() {
	screen.Clear()
	fmt.Printf("%6s%s\n", "", "A DARTBOARD PI CALCULATOR")
}

package main

import (
	"fmt"
	"math"
)

func Index(s string, c byte) int {
	for i := 0; i < len(s); i++ {
		if s[i] == c {
			return i
		}
	}
	panic("not found")
}

func main() {
	s := "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
	var t string
	fmt.Scan(&t)

	res := 0
	for i := 1; i < 26; i++ {
		res += int(math.Abs(float64(Index(t, s[i]) - Index(t, s[i - 1]))))
	}

	fmt.Println(res)
}
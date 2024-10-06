package main

import "fmt"

func main() {
	var a, b, c int
	fmt.Scan(&a, &b, &c)

	if a < b {
		a += 24
	}
	if c < b {
		c += 24
	}

	if (a - b) * (c - a) < 0 {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
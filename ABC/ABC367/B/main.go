package main

import "fmt"

func main() {
	var x string
	fmt.Scan(&x)

	for x[len(x) - 1] == '0' {
		x = x[:len(x) - 1]
	}

	if x[len(x) - 1] == '.' {
		x = x[:len(x) - 1]
	}

	fmt.Println(x)
}
package main

import "fmt"

func main() {
	var n int
	var s string
	fmt.Scan(&n, &s)

	res := 0
	for i := 0; i < n - 2; i++ {
		if s[i: i + 3] == "#.#" {
			res++
		}
	}

	fmt.Println(res)
}
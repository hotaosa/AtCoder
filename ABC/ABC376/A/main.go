package main

import "fmt"

func main() {
	var n, c int
	fmt.Scan(&n, &c)

	res := 0
	prev := -c
	for i := 0; i < n; i++ {
		var t int
		fmt.Scan(&t)
		if t >= prev+c {
			res++
			prev = t
		}
	}

	fmt.Println(res)
}

package main

import "fmt"

func main() {
	var n int
	fmt.Scan(&n)
	k := make([]int, n)
	for i := 0; i < n; i++ {
		fmt.Scan(&k[i])
	}

	res := 1 << 30
	for b := 0; b < (1 << n); b++ {
		x := 0
		y := 0
		for i := 0; i < n; i++ {
			if b >> i & 1 == 1 {
				x += k[i]
			} else {
				y += k[i]
			}
		}
		if x < y {
			x = y
		}
		if x < res {
			res = x
		}
	}

	fmt.Println(res)
}
package main

import (
	"bytes"
	"fmt"
)

func Check(s []byte, idx int) bool {
	return bytes.Equal(s[idx:idx+3], []byte("ABC"))
}

func main() {
	var n, q int
	var s string
	fmt.Scan(&n, &q, &s)

	sb := []byte(s)
	cur := 0
	for i := 0; i < n - 2; i++ {
		if Check(sb, i) {
			cur++
		}
	}

	for q > 0 {
		q--
		var x int
		var str string
		fmt.Scan(&x, &str)
		c := str[0]
		x--

		diff := 0
		for i := x - 2; i <= x; i++ {
			if i >= 0 && i < n - 2 && Check(sb, i) {
				diff--
			}
		}
		sb[x] = byte(c)
		for i := x - 2; i <= x; i++ {
			if i >= 0 && i < n - 2 && Check(sb, i) {
				diff++
			}
		}

		cur += diff
		fmt.Println(cur)
	}
}
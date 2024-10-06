package main

import (
	"fmt"
	"strings"
)

func main() {
	var s, t string
	fmt.Scan(&s, &t)

	if len(s) > len(t) {
		t += strings.Repeat("0", len(s) - len(t))
	} else {
		s += strings.Repeat("0", len(t) - len(s))
	}

	res := -1
	for i := len(s) - 1; i >= 0; i-- {
		if s[i] != t[i] {
			res = i
		}
	}

	fmt.Println(res + 1)
}
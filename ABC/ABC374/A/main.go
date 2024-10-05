package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	if strings.HasSuffix(s, "san") {
		fmt.Println("Yes")
	} else {
		fmt.Println("No")
	}
}
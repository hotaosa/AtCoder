package main

import (
	"fmt"
	"strings"
)

func main() {
	var s string
	fmt.Scan(&s)
	fmt.Println(strings.ReplaceAll(s, ".", ""))
}

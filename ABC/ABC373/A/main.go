package main

import "fmt"

func main() {
	res := 0
	for i := 0; i < 12; i++ {
		var s string
		fmt.Scan(&s)
		if len(s) == i + 1 {
			res++;
		}
	}
	fmt.Println(res)
}
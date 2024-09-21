package main

import "fmt"

func main() {
	var m int
	fmt.Scan(&m)

	cnt := 0
	cur := 1
	for cur * 3 <= m {
		cnt++;
		cur *= 3;
	}

	var res []int
	for m > 0 {
		for cur <= m {
			res = append(res, cnt)
			m -= cur
		}
		cnt--
		cur /= 3
	}

	fmt.Println(len(res))
	for _, r := range res {
		fmt.Printf("%d ", r)
	}
	fmt.Println()
}

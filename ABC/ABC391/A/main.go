package main

import (
	"bufio"
	"fmt"
	"os"
)

func main() {
	opposite := map[rune]rune{
		'N': 'S',
		'S': 'N',
		'E': 'W',
		'W': 'E',
	}

	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	d := scanner.Text()

	result := make([]rune, len(d))
	for i, v := range d {
		result[i] = opposite[v]
	}

	fmt.Println(string(result))
}

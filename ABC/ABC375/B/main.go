package main

import (
	"bufio"
	"fmt"
	"math"
	"os"
)

type Point2d struct {
	x float64
	y float64
}

func Distance(p1 Point2d, p2 Point2d) float64 {
	dx := p1.x - p2.x
	dy := p1.y - p2.y
	return math.Sqrt(dx*dx+dy*dy)
}

func main() {
	reader := bufio.NewReader(os.Stdin)
	writer := bufio.NewWriter(os.Stdout)
	defer writer.Flush()

	var n int
	fmt.Fscan(reader, &n)

	p := Point2d{x: 0.0, y: 0.0}

	var res float64
	for i := 0; i < n; i++ {
		var x, y float64
		fmt.Fscan(reader, &x, &y)
		q := Point2d{x: x, y: y}
		res += Distance(p, q)
		p, q = q, p
	}
	res += Distance(p, Point2d{x: 0.0, y: 0.0})
	writer.WriteString(fmt.Sprintf("%.7f", res))
}
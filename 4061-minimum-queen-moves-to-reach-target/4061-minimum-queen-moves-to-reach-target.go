package main
func minQueenMoves(source []int, target []int) int {
    sr := source[0]
    sc := source[1]
    tr := target[0]
    tc := target[1]

    if sr==tr && sc==tc {
        return 0
    }
    if sr==tr || sc==tc{
        return 1
    }
    if math.Abs(float64(sr-tr)) == math.Abs(float64(sc-tc)){
        return 1;
    }

    return 2
}
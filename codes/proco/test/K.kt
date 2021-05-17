//code by ky
import java.lang.Integer.max
import java.lang.Integer.min

private fun readLn() = readLine()!! // string line
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val (n, k) = readInts()
    val marbles = readLn()

    val trimmed = marbles.trim('W')
    val initial = marbles.length - trimmed.length

    val blackMarbles = trimmed.split(Regex("W+")).map { it.length }
    val whiteMarbles = trimmed.trim('B').split(Regex("B+")).map { it.length }

    val fromRight = IntArray(k + 1)
    var rightIndex = blackMarbles.size - 1
    var total = 0
    for (i in 1..k) {
        var sum = 0
        if (i >= total + blackMarbles[rightIndex] && rightIndex != 0) {
            total += blackMarbles[rightIndex]
            sum += whiteMarbles[--rightIndex]
        }
        fromRight[i] = fromRight[i - 1] + sum
    }

    var white = 0
    var black = 0
    var leftIndex = -1
    var score = 0
    val sum = blackMarbles.sum()

    while (true) {
        // This is not elegant code
        if (leftIndex >= 0) {
            black += blackMarbles[leftIndex]
            if (black > k || leftIndex == whiteMarbles.size) break
            white += whiteMarbles[leftIndex]
        }

        val tempWhite = white + fromRight[min(k, sum) - black]

        score = max(score, tempWhite)
        leftIndex++
    }

    println(initial + score)
}

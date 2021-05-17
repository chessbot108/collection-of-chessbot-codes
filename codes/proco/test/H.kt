//code by ky, is in kotlin
private fun readLn() = readLine()!! // string line
private fun readInt() = readLn().toInt() // single int
private fun readStrings() = readLn().split(" ") // list of strings
private fun readInts() = readStrings().map { it.toInt() } // list of ints

fun main() {
    val n = readInt()
    val alice = readInts().toSortedSet { a, b -> b - a }
    val bob = readInts().toSortedSet { a, b -> b - a }

    var sum = 0
    while (alice.size != 0 && bob.size != 0) {
        val aliceCard = alice.first()
        val bobCard = bob.first()

        if (aliceCard > bobCard) {
            sum++
            alice.remove(aliceCard)
        }
        bob.remove(bobCard)
    }

    println(sum)
}

n = int(input())
s = input()

print(sum([1 for i in range(n - 2) if s[i : i + 3] == "#.#"]))

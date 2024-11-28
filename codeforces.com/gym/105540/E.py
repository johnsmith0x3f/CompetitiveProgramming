def solve():
    A, B, C, X, Y, D = map(int, input().split())

    # A...A
    ans = (D + X - 1) // X * A

    if D <= X:
        return ans

    # A...AB
    if D // X * Y >= D % X:
        ans = min(ans, D // X * A + D % X * B)
    # AB...AB
    if D % (X + Y) == 0:
        k = D // (X + Y)
        ans = min(ans, k * (A + Y * B))
    else:
        k = D // (X + Y) + 1
        ans = min(ans, k * A + max(D - k * X, 0) * B)

    if D <= X + Y:
        return ans

    # ABC...C
    ans = min(ans, A + Y * B + (D - X - Y) * C)
    # ABC...CA...A
    ans = min(ans, A + Y * B + (D - X - Y) // X * A + ((D - X - Y) % X) * C)
    # ABC...CAB...AB
    ans = min(ans, D // (X + Y) * (A + Y * B) + (D % (X + Y)) * C)

    return ans


t = int(input())

for i in range(t):
    print(solve())

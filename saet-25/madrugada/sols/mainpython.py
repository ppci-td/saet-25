# codigo em python para testar o boca

n, b, v = map(int, input().split())

if (b - v) % n == 0:
    print((b - v) // n)
else:
    print(-1)


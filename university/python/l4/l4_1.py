for i in range(3):
    print(*(chr(c) + chr(c + 32) for c in range(ord('A') + 8 * i, ord('A') + 8 * i + 8)))


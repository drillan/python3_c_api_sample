import time

MaxNum = 1000000


def prim(n):
    start = time.time()
    prime_box = [0 for i in range(n)]
    prime_box[0], prime_box[1] = 1, 1
    for i in range(n)[2:]:
        j = 1
        while i * (j + 1) < n:
            prime_box[i * (j + 1)] = 1
            j += 1
    end = time.time()
    return end - start

if __name__ == '__main__':
    print(prim(MaxNum))

from math import log
digits_arr = []

def generate_number(n):
    global digits_arr
    i = 1
    c = 1
    while c < n:
        i += 1
        c += len(str(i))
        # if log(c, 10) == floor(log(c, 10))
        print(i, "[", c, "]")
    return 2

ij = generate_number(100)
print(ij)
print(len(str(ij)))
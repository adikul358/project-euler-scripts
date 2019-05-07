from math import factorial as fact

values = 0

def generate_ncr(n, r):
    return int(fact(n)/(fact(r)*fact(n-r)))

for i in range(100):
    for j in range(i+1):
        c = generate_ncr(i+1, j+1)
        print(i, j, c)
        if c > 1000000:
            values += 1

print(values)
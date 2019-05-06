import time

def nth_prime_number(n):
    prime_list = [2]
    summ, num = 0, 3
    while num < n:
        for p in prime_list:
            if num % p == 0:
                break
        else:
            prime_list.append(num)
            summ += num
            # print(num, "is a prime [", len(prime_list), "] [", summ, "]")
        num += 2
    print(summ)
    return prime_list[-1]

i = time.time()
nth_prime_number(2000000)
f = time.time()
print(f - i)
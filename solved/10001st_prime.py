def nth_prime_number(n):
    prime_list = [2]
    num = 3
    while len(prime_list) < n:
        for p in prime_list:
            if num % p == 0:
                print(num, "isn't a prime")
                break
        else:
            prime_list.append(num)
            print(num, "is a prime [", len(prime_list), "]")
        num += 2
    return prime_list[-1]

nth_prime_number(10001)
prime_list = [2]
diag_primes = []

def add_prime(n):
    global prime_list
    if n < prime_list[-1]:
        return 0
    for p in prime_list:
        if n % p == 0:
            return False
    else:
        prime_list.append(n)
        return True

def check_prime(n):
    global prime_list
    for p in prime_list:
        if n % p == 0:
            return False
    else:
        prime_list.append(n)
        return True

def generate_matrix(n):
    matrix = []
    if n%2 == 0:
        return 0
    for i in range(n):
        m_r = []
        for j in range(n):
            m_r.append(0)
        matrix.append(m_r)
    return matrix

def fill_matrix(m):
    matrix = m
    count = [1,2]
    cen = int((len(m)-1)/2)
    foc = [cen, cen]
    matrix[foc[1]][foc[0]] = 1
    for x in range(cen):
        for a in range(count[0]):
            add_prime(count[1])
            foc[0] += 1
            matrix[foc[1]][foc[0]] = count[1]
            count[1] += 1
        for a in range(count[0]):
            add_prime(count[1])
            foc[1] -= 1
            matrix[foc[1]][foc[0]] = count[1]
            count[1] += 1
        count[0] += 1
        for a in range(count[0]):
            add_prime(count[1])
            foc[0] -= 1
            matrix[foc[1]][foc[0]] = count[1]
            count[1] += 1
        for a in range(count[0]):
            add_prime(count[1])
            foc[1] += 1
            matrix[foc[1]][foc[0]] = count[1]
            count[1] += 1
        count[0] += 1
    for a in range(count[0]-1):
        add_prime(count[1])
        foc[0] += 1
        matrix[foc[1]][foc[0]] = count[1]
        count[1] += 1
    return matrix

def layer_matrix(m):
    matrix = generate_matrix(len(m)+2)
    for i in range(len(m)):
        for j in range(len(m)):
            matrix[i+1][j+1] = m[i][j]
    foc = [len(m)+1,len(m)]
    count = [len(m),m[-1][-1]]
    count[1] += 1
    matrix[foc[1]][foc[0]] = count[1]
    count[1] += 1
    for a in range(count[0]):
        add_prime(count[1])
        foc[1] -= 1
        matrix[foc[1]][foc[0]] = count[1]
        count[1] += 1
    count[0] += 1
    for a in range(count[0]):
        add_prime(count[1])
        foc[0] -= 1
        matrix[foc[1]][foc[0]] = count[1]
        count[1] += 1
    for a in range(count[0]):
        add_prime(count[1])
        foc[1] += 1
        matrix[foc[1]][foc[0]] = count[1]
        count[1] += 1
    for a in range(count[0]):
        add_prime(count[1])
        foc[0] += 1
        matrix[foc[1]][foc[0]] = count[1]
        count[1] += 1
    
    return matrix

def percent_diags(m, ini=False):
    global prime_list
    global diag_primes
    diag = (2*len(m)) -1
    cen = int((len(m)-1)/2)
    foc = [0, 0]
    for i in range(len(m)):
        for p in prime_list:
            if foc[0] == cen:
                continue
            if m[foc[0]][foc[1]] == p:
                diag_primes.append(m[foc[0]][foc[1]])
                break
        foc[0] += 1
        foc[1] += 1
    foc = [len(m)-1, 0]
    for i in range(len(m)):
        for p in prime_list:
            if foc[0] == cen:
                continue
            if m[foc[0]][foc[1]] == p:
                diag_primes.append(m[foc[0]][foc[1]])
                break
        foc[0] -= 1
        foc[1] += 1
    return len(diag_primes)/diag

def con_diags(m):
    global prime_list
    global diag_primes
    diag = (2*len(m)) -1
    corners = [m[0][0], m[0][-1], m[-1][0], m[-1][-1]]
    for c in corners:
        for p in prime_list:
            if c == p:
                diag_primes.append(c)
                break

    return len(diag_primes)/diag

i = 3003
main_matrix = fill_matrix(generate_matrix(i))
main_percent = percent_diags(main_matrix, True)
print(main_matrix)
print(i, main_percent)
while main_percent > 0.1:
    main_matrix = layer_matrix(main_matrix)
    main_percent = con_diags(main_matrix)
    i += 2
    print(i, main_percent)
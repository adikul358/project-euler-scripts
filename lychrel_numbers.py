lychrels = []

def pro_rev(n):
    numm = n
    rev = 0
    while(numm > 0):
        r = numm %10
        rev = (rev *10) + r
        numm = numm //10
    return rev

def pro_palin(n):
    return n + pro_rev(n)

def check_palin(n):
    return n == pro_rev(n)

def check_lychrel(n):
    global lychrels
    num = n
    for i in range(50):
        v = pro_palin(num)
        if check_palin(num):
            break
        num = v
    else:
        lychrels.append(n)
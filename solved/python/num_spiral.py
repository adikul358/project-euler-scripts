import time

main_spiral = []

def generate_spiral(n):
    global main_spiral
    for i in range(n):
        row_array = []
        for j in range(n):
            row_array.append(0)
        main_spiral.append(row_array)
    n = len(main_spiral)
    if (n%2) == 0:
        print("Error: Wrong Matrix Size")      
        return -1  
    count = [1,1,1]
    c = int((n+1)/2)-1
    foc_point = [c, c]
    while count[1] < (n**2)-(n-1):
        for a in range(count[0]):
            main_spiral[foc_point[1]][foc_point[0]] = count[1]
            foc_point[0] += 1
            count[1] += 1
        for a in range(count[0]):
            main_spiral[foc_point[1]][foc_point[0]] = count[1]
            foc_point[1] += 1
            count[1] += 1
        count[0] += 1
        for a in range(count[0]):
            main_spiral[foc_point[1]][foc_point[0]] = count[1]
            foc_point[0] -= 1
            count[1] += 1
        for a in range(count[0]):
            main_spiral[foc_point[1]][foc_point[0]] = count[1]
            foc_point[1] -= 1
            count[1] += 1
        count[0] += 1
    for a in range(count[0]):
        main_spiral[foc_point[1]][foc_point[0]] = count[1]
        foc_point[0] += 1
        count[1] += 1
    print(main_spiral)
        
def sum_diagonals():
    global main_spiral
    n = len(main_spiral)
    c = int((n+1)/2)-1
    sum = 0
    foc = [0,0]
    for a in range(n):
        sum += main_spiral[foc[1]][foc[0]]
        foc[0] += 1
        foc[1] += 1
    foc = [n-1,0]
    for a in range(n):
        sum += main_spiral[foc[1]][foc[0]]
        foc[0] -= 1
        foc[1] += 1
    sum -= main_spiral[c][c]
    print(sum)
    
nu = int(input())
ini = time.time()
generate_spiral(nu)
ini_sum = time.time()
sum_diagonals()
fin = time.time()
print("Time taken to generate matrix: " + str(ini_sum - ini))
print("Time taken to sum_diagonals: " + str(fin - ini_sum))
print("Total time taken: " + str(fin - ini))
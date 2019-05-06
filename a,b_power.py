max_digit_sum = 0

for i in range(100):
    for j in range(100):
        value = (i+1)**(j+1)
        digit_sum = 0
        for k in list(str(value)):
            digit_sum += int(k)
        if digit_sum > max_digit_sum:
            max_digit_sum = digit_sum

print(max_digit_sum)
def num2words(num):
    nums_20_90 =	['Twenty','Thirty','Forty','Fifty','Sixty','Seventy','Eighty','Ninety']
    nums_0_19 = ['Zero','One','Two','Three','Four','Five','Six','Seven','Eight',"Nine", 'Ten','Eleven','Twelve','Thirteen','Fourteen','Fifteen','Sixteen','Seventeen','Eighteen','Nineteen']
    nums_dict = {100: 'hundredand',1000:'thousand', 1000000:'million', 1000000000:'billion'}
    if num < 20:
        return nums_0_19[num]
    if num < 100:
        return nums_20_90[int(num/10-2)] + ('' if num%10 == 0 else nums_0_19[num%10])
    # find the largest key smaller than num
    maxkey = max([key for key in nums_dict.keys() if key <= num])
    return num2words(int(num/maxkey)) + nums_dict[maxkey] + ('' if num%maxkey == 0 else num2words(num%maxkey))

str_length = 0

for i in range(1000):
    name = num2words(i+1)
    print(name)
    str_length += len(name)

print(str_length-27)
